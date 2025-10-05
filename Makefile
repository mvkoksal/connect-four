CC := clang
CFLAGS := -g -Wall

all: connect-four

clean:
	rm -rf connect-four connect-four.dSYM

connect-four:
	$(CC) $(CFLAGS) -o connect-four connect-four.c

.PHONY: all clean
