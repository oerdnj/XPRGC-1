all: toupper valec checkprime

CFLAGS ?= -Ofast -g

toupper: toupper.h
toupper: toupper.c
	$(CC) $(CFLAGS) $(LDFLAGS) -o $@ $<

valec: valec.h
valec: valec.c
	$(CC) $(CFLAGS) $(LDFLAGS) -o $@ $<

checkprime: checkprime.h
checkprime: checkprime.c checkprime-naive.c checkprime-sqrt.c checkprime-openssl.c
	$(CC) $(CFLAGS) $$(pkg-config --cflags libcrypto) $(LDFLAGS) -lm $$(pkg-config --libs libcrypto) -o $@ checkprime.c checkprime-naive.c checkprime-sqrt.c checkprime-openssl.c
