# Fancy uptime make file
# A fancy uptime reader that makes a nicer output than the uptime command. 
# Github: https://www.github.com/lewisevans2007/fancy_uptime
# Licence: GNU General Public License v3.0
# By: Lewis Evans

COMPILER = g++
STD = c++17

SRC = src
MAIN = main.cpp
LIB = lib

OUTPUT = fuptime
BIN = bin

all: init $(OUTPUT)

init:
	@echo "MKDIR $(BIN)"
	@mkdir -p $(BIN)

$(OUTPUT): $(SRC)/$(MAIN)
	@echo "CC $<"
	@$(COMPILER) -std=$(STD) -I$(LIB) $< -o $(BIN)/$@

clean:
	@echo "RM $(BIN)"
	@rm -rf $(BIN)

.PHONY: clean
