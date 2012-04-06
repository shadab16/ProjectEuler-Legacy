CC =		gcc

CFLAGS =	-O3 -Wall -Wextra -pedantic -std=c99 -Ilib

LIBS =		-lm -lgmp -leuler -Llib

VPATH =		src/

euler:		lib/euler.o
	ar rcs lib/libeuler.a lib/euler.o

3:		3.o
	$(CC) -o problem$@ $@.o $(LIBS)

7:		7.o
	$(CC) -o problem$@ $@.o $(LIBS)

9:		9.o
	$(CC) -o problem$@ $@.o $(LIBS)

10:		10.o
	$(CC) -o problem$@ $@.o $(LIBS)

11:		11.o
	$(CC) -o problem$@ $@.o $(LIBS)

12:		12.o
	$(CC) -o problem$@ $@.o $(LIBS)

13:		13.o
	$(CC) -o problem$@ $@.o $(LIBS)

16:		16.o
	$(CC) -o problem$@ $@.o $(LIBS)

18:		18.o
	$(CC) -o problem$@ $@.o $(LIBS)

19:		19.o
	$(CC) -o problem$@ $@.o $(LIBS)

20:		20.o
	$(CC) -o problem$@ $@.o $(LIBS)

22:		22.o
	$(CC) -o problem$@ $@.o $(LIBS)

23:		23.o
	$(CC) -o problem$@ $@.o $(LIBS)

24:		24.o
	$(CC) -o problem$@ $@.o $(LIBS)

25:		25.o
	$(CC) -o problem$@ $@.o $(LIBS)

26:		26.o
	$(CC) -o problem$@ $@.o $(LIBS)

27:		27.o
	$(CC) -o problem$@ $@.o $(LIBS)

28:		28.o
	$(CC) -o problem$@ $@.o $(LIBS)

29:		29.o
	$(CC) -o problem$@ $@.o $(LIBS)

30:		30.o
	$(CC) -o problem$@ $@.o $(LIBS)

32:		32.o
	$(CC) -o problem$@ $@.o $(LIBS)

33:		33.o
	$(CC) -o problem$@ $@.o $(LIBS)

34:		34.o
	$(CC) -o problem$@ $@.o $(LIBS)

36:		36.o
	$(CC) -o problem$@ $@.o $(LIBS)

37:		37.o
	$(CC) -o problem$@ $@.o $(LIBS)

38:		38.o
	$(CC) -o problem$@ $@.o $(LIBS)

39:		39.o
	$(CC) -o problem$@ $@.o $(LIBS)

40:		40.o
	$(CC) -o problem$@ $@.o $(LIBS)

41:		41.o
	$(CC) -o problem$@ $@.o $(LIBS)

42:		42.o
	$(CC) -o problem$@ $@.o $(LIBS)

43:		43.o
	$(CC) -o problem$@ $@.o $(LIBS)

45:		45.o
	$(CC) -o problem$@ $@.o $(LIBS)

46:		46.o
	$(CC) -o problem$@ $@.o $(LIBS)

47:		47.o
	$(CC) -o problem$@ $@.o $(LIBS)

48:		48.o
	$(CC) -o problem$@ $@.o $(LIBS)

49:		49.o
	$(CC) -o problem$@ $@.o $(LIBS)

50:		50.o
	$(CC) -o problem$@ $@.o $(LIBS)

53:		53.o
	$(CC) -o problem$@ $@.o $(LIBS)

56:		56.o
	$(CC) -o problem$@ $@.o $(LIBS)

57:		57.o
	$(CC) -o problem$@ $@.o $(LIBS)

62:		62.o
	$(CC) -o problem$@ $@.o $(LIBS)

63:		63.o
	$(CC) -o problem$@ $@.o $(LIBS)

65:		65.o
	$(CC) -o problem$@ $@.o $(LIBS)

66:		66.o
	$(CC) -o problem$@ $@.o $(LIBS)

67:		67.o
	$(CC) -o problem$@ $@.o $(LIBS)

69:		69.o
	$(CC) -o problem$@ $@.o $(LIBS)

70:		70.o
	$(CC) -o problem$@ $@.o $(LIBS)

71:		71.o
	$(CC) -o problem$@ $@.o $(LIBS)

76:		76.o
	$(CC) -o problem$@ $@.o $(LIBS)

79:		79.o
	$(CC) -o problem$@ $@.o $(LIBS)

81:		81.o
	$(CC) -o problem$@ $@.o $(LIBS)

85:		85.o
	$(CC) -o problem$@ $@.o $(LIBS)

87:		87.o
	$(CC) -o problem$@ $@.o $(LIBS)

92:		92.o
	$(CC) -o problem$@ $@.o $(LIBS)

97:		97.o
	$(CC) -o problem$@ $@.o $(LIBS)

99:		99.o
	$(CC) -o problem$@ $@.o $(LIBS)

102:		102.o
	$(CC) -o problem$@ $@.o $(LIBS)

104:		104.o
	$(CC) -o problem$@ $@.o $(LIBS)

112:		112.o
	$(CC) -o problem$@ $@.o $(LIBS)

145:		145.o
	$(CC) -o problem$@ $@.o $(LIBS)

162:		162.o
	$(CC) -o problem$@ $@.o $(LIBS)

164:		164.o
	$(CC) -o problem$@ $@.o $(LIBS)

179:		179.o
	$(CC) -o problem$@ $@.o $(LIBS)

179b:		179b.o
	$(CC) -o problem$@ $@.o $(LIBS)

197:		197.o
	$(CC) -o problem$@ $@.o $(LIBS)

206:		206.o
	$(CC) -o problem$@ $@.o $(LIBS)

clean:
	$(RM) *.o problem*

