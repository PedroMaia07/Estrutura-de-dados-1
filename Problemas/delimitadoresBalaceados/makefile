all: teste

teste: pilha.o main.o
	gcc -o teste pilha.o main.o

pilha.o: pilha.c pilha.h
	gcc -c pilha.c -Wall -Werror -Wextra

main.o: main.c pilha.h
	gcc -c main.c -Wall -Werror -Wextra

clean:
	rm -rf *.o teste