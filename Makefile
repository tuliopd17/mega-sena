CFLAGS = -Wall -g -std=c99
LDLIBS = -lm

objs = mega.o

all: mega

mega: $(objs)
	cc -o mega $(objs) $(CFLAGS) $(LDLIBS)

mega.o: mega.c
	cc -c mega.c $(CFLAGS)

clean:
	-rm -f mega $(objs)

purge: clean
	-rm -f mega