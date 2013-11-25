CFLAGS+=-std=c99 -O0 -g

mac2ipc: main.c mac2ipc.c defs.h

clean:
	rm -f *.o mac2ipc
