# Fancy uptime make file
# A fancy uptime reader that makes a nicer output than the uptime command. 
# Made by: awesomelewis2007
# Github: https://www.github.com/awesomelewis2007/fancy_uptime
# License: GNU General Public License v3.0

COMPILER = g++
STD = c++17

SRC = src/main.cpp
LIB = lib

OUTPUT = fuptime
BIN = bin

all: init $(OUTPUT)

init:
	@echo "MKDIR $(BIN)"
	@mkdir -p $(BIN)

$(OUTPUT): $(SRC)
	@echo "CC $<"
	@$(COMPILER) -std=$(STD) -I$(LIB) $< -o $(BIN)/$@

clean:
	@echo "RM $(BIN)"
	@rm -rf $(BIN)

.PHONY: clean