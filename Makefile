CC = g++
LIBS = -lcurl -lncurses
a.out: rpg.cc *.h *.cc
	$(CC) rpg.cc -lcurl -lncurses

clean:
	rm -rf a.out core *.o
