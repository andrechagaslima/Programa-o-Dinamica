# Define os caminhos para os arquivos fonte e cabeçalhos
SRC_DIR = principal
HDR_DIR = modulos
OBJ_DIR = objetos

# Nome do executável
EXEC = tp2

# Compilador e flags
CC = gcc
CFLAGS = -g -I$(HDR_DIR)

# Define os arquivos fonte, objeto e cabeçalho
SOURCES = $(wildcard $(SRC_DIR)/*.c)
OBJECTS = $(SOURCES:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)
HEADERS = $(wildcard $(HDR_DIR)/*.h)

# Alvo padrão
all: $(EXEC)

# Liga os arquivos objeto para criar um binário
$(EXEC): $(OBJECTS)
	$(CC) $^ -o $@

# Compila cada arquivo fonte em um arquivo objeto
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(HEADERS)
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Alvo de limpeza para remover arquivos objeto e o executável
clean:
	rm -rf $(OBJ_DIR) $(EXEC)

# Declaração .PHONY para especificar alvos que não são arquivos
.PHONY: all clean
