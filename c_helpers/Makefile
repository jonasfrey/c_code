all: a_array c_helpers dynamic_array int_to_string

a_array: a_array.c
	gcc -Wall -g -O0 a_array.c -o a_array -lm

c_helpers: c_helpers.c
	gcc -Wall -g -O1 c_helpers.c -o c_helpers -lm

dynamic_array: dynamic_array.c
	gcc -Wall -g -O2 dynamic_array.c -o dynamic_array -lm

int_to_string: int_to_string.c
	gcc -Wall -g -O3 int_to_string.c -o int_to_string -lm

clean:
	rm -f a_array 
	rm -f c_helpers
	rm -f dynamic_array
	rm -f int_to_string

