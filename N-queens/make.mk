a.out : main.o utils.o 
	gcc -o a main.o utils.o 
main.o : main.c header.h
	gcc -c main.c
utils.o : utils.c header.h
	gcc -c utils.c
clean :
	del a main.o utils.o 
