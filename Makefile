all : main

main : main.o
	gcc -Wall main.o -o main
	./main

main.o : main.c
	gcc -c  main.c -o main.o