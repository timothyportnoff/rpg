CC = g++
LIBS = -lcurl -lncurses
a.out: rpg.cc map.h class.h actorOrderListAgain.cc
	$(CC) rpg.cc -lcurl -lncurses

clean:
	rm -rf a.out core *.o
