CC=gcc

ARCH := $(shell uname -m)

BINS=ej5 ej6

OBJS=$(BINS:=.o)

all: $(BINS)

# Dependencias
ej5.o: ej5.c
ej6.o: ej6.c


clean:
	rm -rf $(OBJS) $(BINS)
