CC = g++
CFLAG = -Wall -pedantic
STD = -std=c++17
SRC = src/
INC = inc/
OBJ = obj/
BIN = bin/

$(BIN)AOC.exe: $(OBJ)main.o $(OBJ)daytwo.o $(OBJ)dayone.o $(OBJ)exercice.o
	$(CC) $(STD) -o $@ $^ $(CFLAG)

$(OBJ)main.o: main.cpp $(INC)daytwo.h $(INC)dayone.h $(INC)exercice.h
	$(CC) $(STD) -o $@ -c $< $(CFLAG)

$(OBJ)daytwo.o: $(SRC)daytwo.cpp $(INC)daytwo.h $(INC)exercice.h
	$(CC) $(STD) -o $@ -c $< $(CFLAG)

$(OBJ)dayone.o: $(SRC)dayone.cpp $(INC)dayone.h $(INC)exercice.h
	$(CC) $(STD) -o $@ -c $< $(CFLAG)

$(OBJ)exercice.o: $(SRC)exercice.cpp $(INC)exercice.h
	$(CC) $(STD) -o $@ -c $< $(CFLAG)

clean:
	rm -Rf $(OBJ)\*.o
	rm -Rf \*~

mrproper: clean
	rm -f $(BIN)\*