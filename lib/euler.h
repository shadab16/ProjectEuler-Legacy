#ifndef EULER_H
#define EULER_H

/**
 * Filters a sieve for prime numbers upto the specified limit.
 * And returns the filtered sieve.
 * 
 * @param size_t limit Number upto which primes should be processed
 *
 * @return char* Pointer to the first element in sieve
 */
char* filter_prime_sieve(size_t);

/**
 * Clears the given sieve and frees up any allocated memory.
 * Only pass those sieves which were allocated directly by filter_primes().
 *
 * @param char* sieve Pointer to the first element in sieve
 *
 * @return void
 */
void clear_prime_sieve(char*);

/**
 * Gets a list of prime numbers upto the specified limit.
 * If no sieve is supplied, one is built for internal usage.
 *
 * @param const char* sieve Pointer to the sieve from which the list of primes would be built
 * @param size_t      limit Number upto which primes should be fetched
 * @param size_t*     count Pointer to a variable for storing number of primes in list
 *
 * @return unsigned long* Pointer to the first element in list
 */
unsigned long* get_prime_list(const char*, size_t, size_t*);

/**
 * Clears the given list and frees up any allocated memory.
 * Only pass those lists which were allocated directly by get_primes().
 *
 * @param unsigned long* list Pointer to the first element in list
 *
 * @return void
 */
void clear_prime_list(unsigned long*);

/**
 * Sorts individual digits of the given integer in ascending order.
 * For example, the number 41397 is transformed into 13479.
 *
 * @param unsigned long long n Integer to sort
 *
 * @return unsigned long long Sorted integer
 */
unsigned long long sort_digits(unsigned long long);

/**
 * Reverses the order of digits in the given integer, including the zero.
 * For example, the number 56724 is transformed into 42765.
 *
 * @param unsigned long long n Integer to reverse
 *
 * @return unsigned long long Reversed integer
 */
unsigned long long reverse_digits(unsigned long long n);

#endif

