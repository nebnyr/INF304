CC=clang -Wall -Werror -pedantic -g

all: ensembles

ensembles.o: ensembles.c operations_ens.h type_ensemble.h sac.h
	$(CC) -c ensembles.c

operations_ens.o: operations_ens.c operations_ens.h type_ensemble.h sac.h
	$(CC) -c operations_ens.c

sac.o: sac.c sac.h
	$(CC) -c sac.c


ensembles: ensembles.o operations_ens.o sac.o
	$(CC) ensembles.o operations_ens.o sac.o -o ensembles

clean:
	rm -f ensembles *.o