

find_number_of_cores:
	clang -Wall -g -c find_number_of_cores.c

clean:
	rm find_number_of_cores.o
