CXX = g++
CXXFLAGS = -Wall -std=c++11

OBJECTS = wordrange.o bst.o
wordrange: $(OBJECTS)
	$(CXX) -g $(CXXFLAGS) -o $@ wordrange.o bst.o

bst.o: bst.cpp bst.h
	$(CXX) -g $(CXXFLAGS) -c bst.cpp

wordrange.o: bst.cpp wordrange.cpp
	$(CXX) -g $(CXXFLAGS) -c wordrange.cpp

clean:
	rm *.o
	rm wordrange