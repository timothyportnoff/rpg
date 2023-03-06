C = g++
CPPOPT = -Ofast
CFLAGS = -g -w -Wall -Wextra -std=c++2a
DEBUG = -fsanitize=addrress
# -fsanitize=addrress = memory leaks
# -Wextra = 
LIBS = -lcurl -lncurses

a.out: main.cc *.h *.cc
	$(C) $(CPPOPT) $(CFLAGS) main.cc $(LIBS)

clean:
	rm -rf a.out core *.o
