IDIR = ./include
SDIR = ./src
ODIR = ./obj

CC = gcc
CXX = g++
MPI = mpicc
CFLAGS = -I$(IDIR) `libpng-config --cflags` 
PNG = `libpng-config --ldflags`

EXEC = main

_DEPS = 
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

_OBJ = $(EXEC).o
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))


$(ODIR)/%.o: $(SDIR)/%.cpp $(DEPS)
	$(CXX) -c -o $@ $< $(CFLAGS) 

$(EXEC): $(OBJ)
	$(CXX) -o $@ $^ $(CFLAGS) $(PNG)

.PHONY: clean
clean:
	rm -f $(ODIR)/*.o $(EXEC)
