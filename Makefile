CXX=g++

CXXFLAGS=-Wall -Wextra -lm -g

CXXSRC=$(wildcard *.cpp)

EXE=humansVSzombies

OBJ=$(addprefix build/,$(CXXSRC:.cpp=.o))
DEP=$(addprefix build/,$(SRC:.cpp=.d))

all: $(OBJ)
	$(CXX) -o $(EXE) $^ $(LDFLAGS)

build/%.o: %.cpp
	@mkdir -p build
	$(CXX) $(CXXFLAGS) -o $@ -c $<

clean:
	rm -rf build core *.gch

mrproper: clean
	rm -f $(EXE)
