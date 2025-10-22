CC = cc
CFLAGS = -Wall -Werror -Wextra -g3
COMPILATE_OBJECT = @$(CC) $(CFLAGS) $^ -o $@

N_QUEENS = nqueens.c
N_QUEENS2 = nqueens2.c
PERMUTATIONS = permutations.c
PERMUTATIONS_TYPE2 = permutations_type2.c
PERMUTATIONS_TYPE2_2 = permutations_type2_2.c
POWESET = powerset.c
POWESET2 = powerset2.c
RIP = rip.c

ALL_FILES = $(N_QUEENS) $(N_QUEENS2) $(PERMUTATIONS) $(PERMUTATIONS_TYPE2) $(PERMUTATIONS_TYPE2_2) $(POWESET) $(POWESET2) $(RIP)
ALL_EXECUTABLE := $(ALL_FILES:%.c=%)

nqueens: nqueens.o
	$(COMPILATE_OBJECT)

nqueens2: nqueens2.o
	$(COMPILATE_OBJECT)

permutations: permutations.o
	$(COMPILATE_OBJECT)

permutations_type2: permutations_type2.o
	$(COMPILATE_OBJECT)

permutations_type2_2: permutations_type2_2.o
	$(COMPILATE_OBJECT)

powerset: powerset.o
	$(COMPILATE_OBJECT)

powerset2: powerset2.o
	$(COMPILATE_OBJECT)

rip: rip.o
	$(COMPILATE_OBJECT)

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -rf *.o

fclean: clean
	@rm -rf $(ALL_EXECUTABLE)

.PHONY: all clean fclean
