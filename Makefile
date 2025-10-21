CC = cc
CFLAGS = -Wall -Werror -Wextra -g3
COMPILATE_OBJECT = @$(CC) $(CFLAGS) $^ -o $@

N_QUEENS = nqueens.c
PERMUTATIONS = permutations.c
PERMUTATIONS_TYPE2 = permutations_type2.c
POWESET = powerset.c

ALL_FILES = $(N_QUEENS) $(PERMUTATIONS) $(PERMUTATIONS_TYPE2) $(POWESET)
ALL_EXECUTABLE := $(ALL_FILES:%.c=%)

nqueens: nqueens.o
	$(COMPILATE_OBJECT)

permutations: permutations.o
	$(COMPILATE_OBJECT)

permutations_type2: permutations_type2.o
	$(COMPILATE_OBJECT)

powerset: powerset.o
	$(COMPILATE_OBJECT)

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -rf *.o

fclean: clean
	@rm -rf $(ALL_EXECUTABLE)

.PHONY: all clean fclean
