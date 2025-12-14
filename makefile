CC = g++
CFLAG = -Wall -pedantic -Wextra
STD = -std=c++17
SRC = src/
INC = inc/
OBJ = obj/
BIN = bin/

$(BIN)AOC.exe: $(OBJ)main.o $(OBJ)exercice.o $(OBJ)dayone.o $(OBJ)daytwo.o $(OBJ)daythree.o $(OBJ)dayfour.o $(OBJ)dayfive.o
	$(CC) $(STD) -o $@ $^ $(CFLAG)

$(OBJ)main.o: main.cpp $(INC)exercice.h $(INC)dayone.h $(INC)daytwo.h $(INC)daythree.h $(INC)dayfour.h $(INC)dayfive.h
	$(CC) $(STD) -o $@ -c $< $(CFLAG)

$(OBJ)dayfive.o: $(SRC)dayfive.cpp $(INC)exercice.h $(INC)dayfive.h
	$(CC) $(STD) -o $@ -c $< $(CFLAG)

$(OBJ)dayfour.o: $(SRC)dayfour.cpp $(INC)exercice.h $(INC)dayfour.h
	$(CC) $(STD) -o $@ -c $< $(CFLAG)

$(OBJ)daythree.o: $(SRC)daythree.cpp $(INC)exercice.h $(INC)daythree.h
	$(CC) $(STD) -o $@ -c $< $(CFLAG)

$(OBJ)daytwo.o: $(SRC)daytwo.cpp $(INC)exercice.h $(INC)daytwo.h
	$(CC) $(STD) -o $@ -c $< $(CFLAG)

$(OBJ)dayone.o: $(SRC)dayone.cpp $(INC)exercice.h $(INC)dayone.h
	$(CC) $(STD) -o $@ -c $< $(CFLAG)

$(OBJ)exercice.o: $(SRC)exercice.cpp $(INC)exercice.h
	$(CC) $(STD) -o $@ -c $< $(CFLAG)

clean:
	rm -Rf $(OBJ)\*.o
	rm -Rf \*~

mrproper: clean
	rm -f $(BIN)\*