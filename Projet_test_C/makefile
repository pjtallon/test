CC=gcc
CFLAGS=
LDFLAGS=

EXEC=appli_test.exe

_DEPS = parser.h
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

_SRC = parser.c main.c
SRC = $(patsubst %,$(SDIR)/%,$(_SRC))

all: appli_test.exe

appli_test.exe: parser.o test.o
	gcc -o $@ $^ $(LDFLAGS)	
	
%.o: %.c
	$(CC) -c $(CFLAGS) -o $@ $<

.PHONY: clean mrproper

clean:
	del *.o

mrproper: clean
	del $(EXEC)
	
std: 
	gcc -o $(EXEC) parser.c test.c
