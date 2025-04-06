CXX = g++
CXXFLAGS = -g -Wall -std=gnu++11
SHELL = bash

DIJKSTRAS = src/dijkstras
GENERATEMAP = generatemap
PROGRAMS = $(DIJKSTRAS) $(GENERATEMAP)

all: $(PROGRAMS)

$(DIJKSTRAS): src/dijkstras.cpp
	$(CXX) $(CXXFLAGS) -o $@ $^

$(GENERATEMAP): generatemap.cpp
	$(CXX) $(CXXFLAGS) -o $@ $^

.PHONY: test test-output test-memory clean benchmark

clean:
	rm -f $(PROGRAMS) input_temp.txt output_temp.txt mem_temp.txt

test: test-output test-memory

test-output: $(DIJKSTRAS)
	@echo Testing output 0...
	@./src/dijkstras < data/input0.txt | ~semrich/Public/checkproj4 data/input0.txt data/output0.txt
	@echo Testing output 1...
	@./src/dijkstras < data/input1.txt | ~semrich/Public/checkproj4 data/input1.txt data/output1.txt
	@echo Testing output 2...
	@./src/dijkstras < data/input2.txt | ~semrich/Public/checkproj4 data/input2.txt data/output2.txt
	@echo Testing output 3...
	@./src/dijkstras < data/input3.txt | ~semrich/Public/checkproj4 data/input3.txt data/output3.txt

test-memory: $(DIJKSTRAS)
	@echo Testing memory...
	@[ `valgrind --leak-check=full ./src/dijkstras < data/input1.txt 2>&1 | grep ERROR | awk '{print $$4}'` = 0 ]

test: $(GENERATEMAP) $(DIJKSTRAS)
	@echo "Running benchmark using ./generatemap..."
	@./generatemap
