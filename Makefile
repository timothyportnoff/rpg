C = g++
CFLAGS = -g -w -Wall -Wextra -std=c++2a
DEBUG = -fsanitize=addrress
LIBS = -lcurl -lncurses

a.out: rpg.cc *.h *.cc
	$(C) $(CFLAGS) rpg.cc $(LIBS)

clean:
	rm -rf a.out core *.o
