CFLAGS= -g -Wall -DDEBUG

all: bin/arbre

bin/arbre:  obj/main.o obj/arbre.o
	gcc $(CFLAGS) -o $@ $^

obj/%.o: src/%.c
	gcc $(CFLAGS) -Iinclude -o $@ -c $<

clean:
	rm -f obj/* *~

mrproper: clean
	rm bin/*

