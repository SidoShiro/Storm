#Simple MakeFile

CC=gcc
CPPFLAGS=
CFLAGS= -Wall -Wextra -std=c99 -O3
LDFLAGS=
LDLIBS=

SRC= storm.c parser.c
OBJ= ${SRC:.c=.o}

#Empty def rule
all: storm

storm: ${OBJ}

clean:
	rm -f *.o *~
	rm storm

