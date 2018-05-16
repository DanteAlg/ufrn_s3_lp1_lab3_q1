CC = g++

INC = ./include
BIN = ./bin
OBJ = ./build
SRC = ./src

CPPFLAGS = -O0 -Wall -pedantic -std=c++11 -I$(INC)
OBJECTS = $(OBJ)/produto.o $(OBJ)/fruta.o $(OBJ)/bebida.o $(OBJ)/roupa.o $(OBJ)/mercado.o $(OBJ)/main.o

PROG = $(BIN)/mercado

all: $(OBJECTS)
	$(CC) $(CPPFLAGS) -o $(PROG) $(OBJECTS)

$(OBJ)/produto.o:
	$(CC) $(CPPFLAGS) -c $(SRC)/produto.cpp -o $@

$(OBJ)/fruta.o: $(OBJ)/produto.o
	$(CC) $(CPPFLAGS) -c $(SRC)/fruta.cpp -o $@

$(OBJ)/bebida.o: $(OBJ)/produto.o
	$(CC) $(CPPFLAGS) -c $(SRC)/bebida.cpp -o $@

$(OBJ)/roupa.o: $(OBJ)/produto.o
	$(CC) $(CPPFLAGS) -c $(SRC)/roupa.cpp -o $@

$(OBJ)/mercado.o: $(INC)/mercado.h $(OBJ)/produto.o $(OBJ)/bebida.o $(OBJ)/roupa.o $(OBJ)/fruta.o
	$(CC) $(CPPFLAGS) -c $(SRC)/mercado.cpp -o $@

$(OBJ)/main.o: $(OBJ)/produto.o $(OBJ)/bebida.o $(OBJ)/roupa.o $(OBJ)/fruta.o
	$(CC) $(CPPFLAGS) -c $(SRC)/main.cpp -o $@

clean:
	rm -f $(PROG) $(OBJECTS)
