all: stringsorter.c
	gcc -Wall -Werror -fsanitize=address -o stringsorter stringsorter.c
clean:
	rm stringsorter




