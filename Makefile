C = g++
CFLAGS = -g -w -Wall -Wextra -fsanitize=address -std=c++2a
LIBS = -lcurl -lncurses

a.out: rpg.cc *.h *.cc
	$(C) $(CFLAGS) rpg.cc $(LIBS)

clean:
	rm -rf a.out core *.o
