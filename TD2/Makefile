all : main

main : affichage portee

portee : portee.c
	gcc -Wall portee.c -o portee

affichage : affichage.c affichage.h
	gcc -Wall affichage.c -o affichage

clean :
	rm *.o