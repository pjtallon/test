#makefile for test project in c++
#Flags and common declarations
export DEBUG=yes
export CC=g++

# NAME
export NAME=appli_test

# Directories
export ROOT_DIR=/cygdrive/e/DEV_REPO/Projet_test_Cpp
export SOURCE_DIR=${ROOT_DIR}/src
export INCLUDE_DIR=$(ROOT_DIR)/include
export LIBS_FLAG=-I$(INCLUDE_DIR)

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
	cd $(SOURCE_DIR) && make $@.o

.PHONY: clean mp

clean: 
	cd $(SOURCE_DIR) && make $@


mp: clean
	cd $(SOURCE_DIR) && make $@
