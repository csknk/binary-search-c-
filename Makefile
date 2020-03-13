CXXFLAGS = -W -Wall -pedantic -std=c++17 -g
CXX = g++ ${CXXFLAGS}
OUT:= bin
NAME = main

# The target has the dependencies util.o, main.o & grade.o
$(NAME): main.cpp recursive.o iterative.o
	$(CXX) -o $(OUT)/$@ main.cpp bin/recursive.o bin/iterative.o

iterative.o: iterative.cpp
	$(CXX) -c $< -o $(OUT)/$@

recursive.o: recursive.cpp
	$(CXX) -c $< -o $(OUT)/$@

iterative.o: iterative.h

recursive.o: recursive.h

debug: $(SOURCES)
	g++ -W -Wall -std=c++17 -g -o $(OUT) $(OBJECTS)
