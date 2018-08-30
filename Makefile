.RECIPEPREFIX = \t
OBJS=kmeans.o
EXE=example1 example2 movie1 actor1

CFLAGS=-g -O0

all: $(EXE)

clean:
	@rm -f *.o $(EXE)

example1: $(OBJS) example1.o
	$(CC) $(CFLAGS) $^ -o $@

example2: $(OBJS) example2.o
	$(CC) $(CFLAGS) $^ -o $@

movie1: $(OBJS) movie1.o
	$(CC) $(CFLAGS) $^ -o $@

actor1: $(OBJS) actor1.o
	$(CC) $(CFLAGS) $^ -o $@

test:
	#running tests
	./example1
	#
	./example2
	#
	./movie1
	#
	./actor1
