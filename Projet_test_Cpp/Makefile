#makefile for test project in c++
#Flags and common declarations
export DEBUG=yes
export CC=g++

# NAME
export NAME=appli_test

# Directories
export ROOT_DIR=C:/Users/Strip/Dev/Projet_test_Cpp
export SOURCE_DIR=${ROOT_DIR}/src
# export BIN_DIR=$(ROOT_DIR)/bin
# export OBJ_DIR=$(ROOT_DIR)/obj

ifeq ($(DEBUG),yes)
	export CFLAGS=-W -Wall -pedantic -g
	export LDFLAGS=
else
	export CFLAGS=-W -Wall -pedantic
	export LDFLAGS=
endif

all: 
	make appli_test

appli_test: 
	cd $(SOURCE_DIR) && make appli_test

shopping_list:
	cd $(SOURCE_DIR)) && make $@.o

.PHONY: clean mp

clean: 
	@(cd $(SOURCE_DIR)) && make $@)


mp: clean
	@(cd $(SOURCE_DIR)) && make $@)