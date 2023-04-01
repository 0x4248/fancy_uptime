# Fancy uptime make file
# A fancy uptime reader that makes a nicer output than the uptime command. 
# Made by: awesomelewis2007
# Github: https://www.github.com/awesomelewis2007/fancy_uptime
# License: GNU General Public License v3.0
COMPILER = g++
STD = c++17
OUTPUT = fuptime
SRC = src/main.cpp
LIB = lib
all: compile run 

compile:
	$(COMPILER) $(SRC) -std=$(STD) -o $(OUTPUT) -I $(LIB)

run:
	./$(OUTPUT) -a

clean:
	rm  -f $(OUTPUT)
