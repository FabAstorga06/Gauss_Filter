IDIR = ./include
SDIR = ./src
ODIR = ./obj

CC = gcc
MPI = mpicc
CFLAGS = -g -Wall -I$(IDIR) 
OPENCV = `pkg-config --libs --cflags opencv`

EXEC = main

_DEPS = constants.h utils.c gauss_filter.c 
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

_OBJ = $(EXEC).o
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))

LIBS = $(OPENCV)

$(ODIR)/%.o: $(SDIR)/%.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS) $(LIBS)

$(EXEC): $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)

.PHONY: clean
clean:
	rm -f $(ODIR)/*.o $(EXEC)
