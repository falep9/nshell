#include <string.h>
#include "../include/nshell.h"

int parse_linha(char *linha, char *args[]) {
    int argc = 0;
    char *token = strtok(linha, " ");

    while (token != NULL && argc < MAX_ARGS - 1) {
        args[argc] = token;
        argc++;
        token = strtok(NULL, " ");
    }

    args[argc] = NULL;

    return argc;
}
