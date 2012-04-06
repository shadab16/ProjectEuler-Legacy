#include <stdio.h>
#include <stdlib.h>

typedef struct cnode {
	unsigned int val;
	struct cnode* next;
	struct cnode* prev;
} CNODE;

void merge_for(CNODE* (*tree)[50], CNODE* node, size_t exclude) {

	unsigned int v1 = node->val, v2 = node->next->val;
	CNODE* branch = 0;

	for (size_t i = 0; i < 50; ++i) {
		if (!(*tree)[i] || i == exclude) {
			continue;
		}
		if ((*tree)[i]->val == v1) {
			CNODE* last = (*tree)[i];
			while (last->next) {
				last = last->next;
			}
			if (last->val != v2) {
				continue;
			}
			branch = (*tree)[i];
			(*tree)[i] = 0;
			break;
		}
	}

	if (branch) {
		CNODE* middle = branch->next;
		CNODE* first  = node;
		CNODE* second = node->next;

		second->prev = middle;
		middle->next = second;
		middle->prev = first;
		first->next  = middle;
	}
}

void linearize(CNODE* (*tree)[50]) {

	for (size_t i = 0; i < 50; ++i) {

		CNODE* node = (*tree)[i];
		if (!node) {
			continue;
		}

		while (node->next) {
			merge_for(tree, node, i);
			node = node->next;
		}
	}
}

int main(void) {

	char filedata[250+1] = "";

	FILE* handle = fopen("resources/keylog.txt", "r");
	if (250 != fread(filedata, 1, 250, handle)) {
		return 1;
	}
	fclose(handle);

	CNODE nodes[150];
	CNODE* tree[50] = {0};

	CNODE* node = nodes;

	/* populate the value in nodes */
	for (char* digit = filedata; *digit; ++digit) {
		if (*digit == '\r' || *digit == '\n') continue;
		node->val = *digit - '0';
		node->next = 0;
		node->prev = 0;
		++node;
	}
	node = 0;

	/* link the ordered nodes */
	for (size_t i = 0; i < 150; ++i) {
		if ((i + 1) % 3 != 0) {
			nodes[i].next = &nodes[i+1];
		}
		if (i % 3 != 0) {
			nodes[i].prev = &nodes[i-1];
		}
	}

	/* link the tree to first of the ordered nodes */
	for (size_t i = 0; i < 50; ++i) {
		tree[i] = &nodes[i*3];
	}

	/*printf("Original ::\n");
	for (size_t i = 0; i < 50; ++i) {
		CNODE* d = tree[i];
		while (d) {
			printf("%u ", d->val);
			d = d->next;
		}
		printf("\n");
	}*/

	linearize(&tree);

	/*printf("\nLinear ::\n");*/
	for (size_t i = 0; i < 50; ++i) {
		CNODE* d = tree[i];
		if (!d) continue;
		while (d) {
			printf("%u", d->val);
			d = d->next;
		}
		printf("\n");
	}

	return 0;
}

