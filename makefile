OBJS = bin/rcforth.o
CC = clang++
DEBUG = -g
CFLAGS = -Wall -c $(DEBUG)
LFLAGS = -Wall $(DEBUG)

.PHONY: go clean before

rcforth: before $(OBJS)

	$(CC) $(LFLAGS) $(OBJS) -o rcforth

bin/rcforth.o: src/main.cc

	$(CC) $(CFLAGS) src/main.cc -o bin/rcforth.o

go: rcforth

	./rcforth

clean:

	\rm */*.o *~ rcforth

before:

	if [ ! -d bin ]; then mkdir bin; fi
