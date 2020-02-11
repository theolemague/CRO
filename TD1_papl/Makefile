all : main

main : main.o pgcd.o
	gcc -Wall -L./lib main.o -o main -lpgcd
	./main

pgcd.o : ./src/util/pgcd.c ./include/pgcd.h
	gcc -c ./src/util/pgcd.c -I./include -o pgcd.o
	ar -crs ./lib/libpgcd.a pgcd.o

main.o : ./src/traitement/main.c ./include/pgcd.h
	gcc -Wall -c ./src/traitement/main.c -I./include -o main.o

clean :
	rm -f pgcd *.o