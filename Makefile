CC = g++
LIBS = -lcurl -lncurses
a.out: main.cc map.h class.h
	$(CC) main.cc -lcurl -lncurses

clean:
	rm -rf a.out core *.o
