#ifndef NSHELL_H
#define NSHELL_H

#define TAM_MAX 100      // tamanho máximo da linha digitada
#define MAX_ARGS 20      // número máximo de argumentos por comando


int parse_linha(char *linha, char *args[]);
 
// --- builtin.c ---
int executar_builtin(char *args[], int *rodando);

// --- process.c ---
void executar_processo(char *args[]);

#endif
