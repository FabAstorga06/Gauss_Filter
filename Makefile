IDIR = ./include
SDIR = ./src
ODIR = ./obj

CC = gcc
CXX = g++
MPI = mpicc
CPPFLAGS = -std=c++11 -O3 -I$(IDIR) `libpng-config --cflags`
PNG = `libpng-config --ldflags`

EXEC = main

_DEPS = constants.h image_utils.hpp gaussian_blur.hpp
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

_OBJ = $(EXEC).o
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))


$(ODIR)/%.o: $(SDIR)/%.cpp $(DEPS)
	$(CXX) -c -o $@ $< $(CPPFLAGS) 

$(EXEC): $(OBJ)
	$(CXX) -o $@ $^ $(CPPFLAGS) $(PNG)

.PHONY: clean
clean:
	rm -f $(ODIR)/*.o $(EXEC)
