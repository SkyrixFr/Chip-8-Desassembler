SRC = $(wildcard src/*.c)
OBJ = ${SRC:.c=.o}
OUT = build/main

CC = gcc

$(OUT): $(OBJ)
	@echo Linking : $@
	@$(CC) $^ -o $@
	@echo Done

%.o: %.c
	@echo Compiling : $@
	@$(CC) -c $< -o $@

clean:
	@del build\*.exe
	@del src\*.o
	@echo All clear

run:
	@build\main.exe