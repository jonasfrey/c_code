
CFLAGS = -Wall -Wno-unused-but-set-variable -Wno-unused-parameter -Wno-unused-variable -g -O0

# simple_game_engine: simple_game_engine.cpp
# 	# gcc $(CFLAGS) simple_game_engine.cpp -o simple_game_engine
# 	g++ -o simple_game_engine simple_game_engine.cpp -lcurses

simple_game_engine_no_vector: simple_game_engine_no_vector.c
# simple_game_engine_no_vector: simple_game_engine_no_vector.cpp
	gcc $(CFLAGS) simple_game_engine_no_vector.c -o simple_game_engine_no_vector
	# g++ -o simple_game_engine_no_vector simple_game_engine_no_vector.cpp -lcurses

clean:
	# rm -f simple_game_engine
	rm -f simple_game_engine_no_vector

