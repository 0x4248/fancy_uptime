COMPILER = g++
STD = c++17
OUTPUT = fuptime
SRC = src/main.cpp

all: compile run 

compile:
	$(COMPILER) $(SRC) -std=$(STD) -o $(OUTPUT) 

run:
	./$(OUTPUT) -a

clean:
	rm  -f $(OUTPUT)
