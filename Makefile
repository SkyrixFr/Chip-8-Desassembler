CXX = gcc
CXXFLAGS = -Wall -Wextra# Mettre -O1 ou -O2 à la place de -g pour la version prod
HEADERS_LOCALISATION = include

LDFLAGS = -lmingw32 # -mwindows pour supprimer l'affichage de la console
LIB_LOCALISATION = lib

EXEC = Chip8-Disassembler

SRC = main.c fileSize.c
OBJ = $(SRC:.c=.o)

all : program

program : $(OBJ)
	$(CXX) -L $(LIB_LOCALISATION) $(addprefix obj\, $(OBJ)) -o bin\$(EXEC) $(LDFLAGS)

%.o: src\%.c
	$(CXX) $(CXXFLAGS) -I $(HEADERS_LOCALISATION) -c $< -o obj\$@

clean:
	rm -r -f obj bin
	mkdir obj bin

.PHONY: all program clean