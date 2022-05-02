CC=gcc

ARCH := $(shell uname -m)

BINS=prueba

OBJS=$(BINS:=.o)

all: $(BINS)

# Dependencias
prueba.o: prueba.c

clean:
	rm -rf $(OBJS) $(BINS)
