
CFLAGS = -Wall -g -O0 
all: get_primes get_primes_compiler_optimization_level_0 get_primes_compiler_optimization_level_1 get_primes_compiler_optimization_level_2 get_primes_compiler_optimization_level_3

get_primes: get_primes.c
	gcc $(CFLAGS) get_primes.c -o get_primes -lm

get_primes_compiler_optimization_level_0: get_primes.c
	gcc -Wall -g -O0 get_primes.c -o get_primes_compiler_optimization_level_0 -lm

get_primes_compiler_optimization_level_1: get_primes.c
	gcc -Wall -g -O1 get_primes.c -o get_primes_compiler_optimization_level_1 -lm

get_primes_compiler_optimization_level_2: get_primes.c
	gcc -Wall -g -O2 get_primes.c -o get_primes_compiler_optimization_level_2 -lm

get_primes_compiler_optimization_level_3: get_primes.c
	gcc -Wall -g -O3 get_primes.c -o get_primes_compiler_optimization_level_3 -lm

clean:
	rm -f get_primes

