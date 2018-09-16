all : tp8.exe tp8_reines.exe

tp8.exe : pile.o file.o es.o
	gcc es.o pile.o file.o tp8.c -o tp8.exe

pile.o : pile.c es.c
	gcc -c pile.c

file.o : file.c es.c
	gcc -c file.c

es.o : es.c es.h
	gcc -c es.c

clean :
	rm *.o *.exe




