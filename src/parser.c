#include <string.h>
#include "../include/nshell.h"

// Recebe a linha digitada pelo usuário e quebra ela em palavras separadas,
// guardando cada palavra dentro do array args[].
// Retorna quantas palavras (argumentos) foram encontradas.
int parse_linha(char *linha, char *args[]) {
    int argc = 0;

    // strtok quebra a string em pedaços usando " " (espaço) como separador.
    // na primeira chamada, passamos a linha original.
    char *token = strtok(linha, " ");

    while (token != NULL && argc < MAX_ARGS - 1) {
        args[argc] = token;
        argc++;
        token = strtok(NULL, " ");
    }

    // Importante: o último espaço do array DEVE ser NULL.
    // Isso marca "o fim da lista de argumentos" e é exigido por funções.
    args[argc] = NULL;

    return argc;
}
