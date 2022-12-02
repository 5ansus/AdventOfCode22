CC = gcc -g# -std='gnu2x'
CFLAGS = -Wall -Wextra -pedantic -ansi

DAY = 02-12
OBJ = $(DAY)_problem1.o
OBJ2 = $(DAY)_problem2.o
all: $(DAY)

%.o: %.c
	@echo Compiling $<...
	$(CC) $(CFLAGS) -c -o $@ $<

$(DAY): $(OBJ) $(OBJ2)
	@echo Compiling $<...
	$(CC) $(CFLAGS) -o $(DAY)_problem1 $(OBJ)
	$(CC) $(CFLAGS) -o $(DAY)_problem2 $(OBJ2)

clean:
	@echo Removing files
	rm -f *.o $(DAY)_problem1 $(DAY)_problem2