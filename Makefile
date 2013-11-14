CFLAGS+=-std=c99 -O0 -g

mac2ipc: mac2ipc.c main.c defs.h

clean:
	rm -f *.o mac2ipc
