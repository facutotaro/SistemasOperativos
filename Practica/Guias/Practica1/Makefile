CC=gcc

ARCH := $(shell uname -m)

BINS=ej5

OBJS=$(BINS:=.o)

all: $(BINS)

# Dependencias
ej5.o: ej5.c

clean:
	rm -rf $(OBJS) $(BINS)
