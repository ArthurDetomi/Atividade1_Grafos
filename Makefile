CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++11
SRC_DIR = ./
OBJ_DIR = ./obj
INP_DIR = input

all: $(OBJ_DIR)/grafo

$(OBJ_DIR)/grafo: $(SRC_DIR)/grafo.cpp
	$(CXX) $(CXXFLAGS) -o $@ $^

rodar_programa: $(OBJ_DIR)/grafo
	./$^ < $(INP_DIR)/teste.txt

rodar_programa_saida_arquivo: $(OBJ_DIR)/grafo
	./$^ < $(INP_DIR)/teste.txt > output/out.txt

clean:
	rm -f $(OBJ_DIR)/grafo

.PHONY: all clean
