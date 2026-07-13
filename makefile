# --- ATENÇÃO ---
# Esse makefile foi gerado com ajuda do Claude (IA pois não tenho conhecimento p de sintaxe de makefile. 


# Nome do compilador que vamos usar
CC = gcc

# Flags (opções) passadas pro compilador:
# -Wall  = mostra (quase) todos os avisos de possíveis problemas no código
# -Wextra = avisos extras, ainda mais rigorosos
# -Iinclude = fala pro compilador procurar headers também na pasta include/
CFLAGS = -Wall -Wextra -Iinclude

# Nome do programa final que queremos gerar
TARGET = nshell

# Lista de todos os arquivos .c que precisam ser compilados juntos
SRCS = main.c src/parser.c src/builtin.c src/process.c

# Regra padrão: quando rodar só "make", ele constrói o TARGET
all: $(TARGET)

# Como construir o nshell: compila todos os SRCS de uma vez e gera o executável
$(TARGET): $(SRCS)
	$(CC) $(CFLAGS) $(SRCS) -o $(TARGET)

# Regra pra limpar o projeto: apaga o executável gerado
clean:
	rm -f $(TARGET)

# .PHONY avisa o make que "all" e "clean" não são nomes de arquivos de verdade,
# são só "apelidos" de tarefas. Evita confusão caso exista um arquivo chamado "clean".
.PHONY: all clean