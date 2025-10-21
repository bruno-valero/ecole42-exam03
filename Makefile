CC = cc
CFLAGS = -Wall -Werror -Wextra -g3
N_QUEENS = nqueens.c
PERMUTATIONS = permutations.c
PERMUTATIONS_TYPE2 = permutations_type2.c

nqueens: nqueens.o
	@$(CC) $(CFLAGS) $^ -o $@

permutations: permutations.o
	@$(CC) $(CFLAGS) $^ -o $@

permutations_type2: permutations_type2.o
	@$(CC) $(CFLAGS) $^ -o $@

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf *.o
