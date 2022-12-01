CC = gcc -g# -std='gnu2x'
CFLAGS = -Wall -Wextra -pedantic -ansi
DAYS: 01-12

DAYS = 01-12
OBJ = $(DAYS)_problem1.o
OBJ2 = $(DAYS)_problem2.o
all: $(DAYS)

%.o: %.c
	@echo Compiling $<...
	$(CC) $(CFLAGS) -c -o $@ $<

$(DAYS): $(OBJ) $(OBJ2)
	@echo Compiling $<...
	$(CC) $(CFLAGS) -o $(DAYS)_problem1 $(OBJ)
	$(CC) $(CFLAGS) -o $(DAYS)_problem2 $(OBJ2)

clean:
	@echo Removing files
	rm -f *.o $(DAYS)_problem1 $(DAYS)_problem2