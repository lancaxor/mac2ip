CFLAGS=-std=c99

mac2ipc: mac2ipc.c defs.h

clean:
	rm -f *.o mac2ipc
