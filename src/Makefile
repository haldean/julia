BINARY=julia
CFLAGS=-c -Wall -I../include/ -I/usr/include/GL -I/usr/include -O2
SOURCES=$(wildcard *.c)
OBJECTS=$(SOURCES:.c=.o)
UNAME=$(shell uname)
CC=clang

ifeq ($(UNAME), Darwin)
LDFLAGS=-lm -framework OpenGL -framework GLUT
else
LDFLAGS=-L/usr/local/lib -L/usr/X11/lib -lm -lglut -lGL -lGLU
endif

all: $(SOURCES) $(BINARY)
	
$(BINARY): $(OBJECTS) 
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.cpp.o:
	$(CC) $(EXTRA_FLAGS) $(CFLAGS) $< -o $@

clean:
	rm -f ${OBJECTS} ${BINARY}
