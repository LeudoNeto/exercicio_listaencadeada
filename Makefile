# Variáveis
CC = g++
CFLAGS = -Wall -g

# Alvo principal
all: main.exe

# Regras
main.exe: main.cpp
	$(CC) $(CFLAGS) -o main.exe main.cpp

# Limpeza
clean:
	rm -f *.exe
