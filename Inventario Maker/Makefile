CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++11 -I.

# Nome do executável
TARGET = inventario_maker

# Lista de arquivos fonte
SRCS = main.cpp Itens.cpp TabelaHash.cpp FilaDeEspera.cpp Usuario.cpp FilaDeColisoes.cpp

# Gera os nomes dos arquivos objeto
OBJS = $(SRCS:.cpp=.o)

# Regra padrão
all: $(TARGET)

# Regra para compilar o executável
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

# Regra para compilar cada arquivo fonte
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Limpar arquivos objeto e o executável
clean:
	del /f /q *.o $(TARGET).exe 2>nul

# Executar o programa
run: $(TARGET)
	.\$(TARGET)

.PHONY: all clean run
