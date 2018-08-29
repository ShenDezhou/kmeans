OBJS=kmeans.o
EXE=example1

CFLAGS=-g -O0

all: $(EXE)

clean:
	@rm -f *.o $(EXE)

example1: $(OBJS) example1.o
	$(CC) $(CFLAGS) $^ -o $@
