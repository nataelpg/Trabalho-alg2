CC = gcc
CFLAGS = -g -Wall
program = megaQuadra

all:
	$(CC) $(CFLAGS) -c megaQuadra.c
	$(CC) $(CFLAGS) -c vetor.c
	$(CC) $(CFLAGS) -c ordenacao.c
	$(CC) $(CFLAGS) -c pesquisa.c
	$(CC) megaQuadra.o vetor.o ordenacao.o pesquisa.o -o megaQuadra

clean :
	rm *.o $(program)