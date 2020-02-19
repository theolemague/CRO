#########################################################
# Makefile pour les programme du TD1 AGP
# Tanguy Risset
#########################################################
CC            =gcc 
LD            =gcc 
CFLAGS        =-Wall -g

SRC= main.c utils.c trame.c 
OBJ=$(SRC:.c=.o)

#cible principales: on construit les executables et les test
all: main


main:	 $(OBJ)
	$(LD) $(OBJ) -g -o $@ -D DEBUG

utils.o: utils.c 
	$(CC) $(CFLAGS) -c $<  -o $@

trame.o: trame.c 
	$(CC) $(CFLAGS) -c $<  -o $@ -D DEBUG

main.o: main.c
	$(CC) $(CFLAGS) -c $<  -o $@


tar:	dummy 
	make clean
	cd ..;tar cvf faultatif_TD2.tar facultatif_TD2

dummy:

clean:
	-rm -f *~ main $(EXE) *.o *.old *.paquet*




