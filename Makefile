CC=gcc
CFLAGS=-Wall -Wextra -std=c99
targets=my_octave

build:$(targets)

my_octave:my_octave.c
	 $(CC) $(CFLAGS) my_octave.c -o my_octave

clean:
	rm -f $(targets)
