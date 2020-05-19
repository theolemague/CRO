CFLAGS= -g -Wall -DDEBUG

all: bin/exe

bin/exe:  obj/main.o obj/tab_entier.o
	gcc $(CFLAGS) -o $@ $^

obj/%.o: src/%.c
	gcc $(CFLAGS) -Iinclude -o $@ -c $<

clean:
	rm -f obj/* *~

mrproper: clean
	rm bin/*

