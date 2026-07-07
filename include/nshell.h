#ifndef NSHELL_H
#define NSHELL_H

// --- Constantes globais do projeto ---
#define TAM_MAX 100      // tamanho máximo da linha digitada
#define MAX_ARGS 20      // número máximo de argumentos por comando

// --- parser.c ---
// Recebe a linha crua digitada pelo usuário e preenche o array args[]
// com cada palavra separada. Retorna o número de argumentos encontrados (argc).
int parse_linha(char *linha, char *args[]);
 
// --- builtin.c ---
// Verifica se o comando digitado é um comando interno do shell
// (ex: "ajuda", "sair"). Retorna 1 se era um builtin e já foi executado,
// ou 0 se não era builtin (nesse caso o main tenta executar como programa externo).
int executar_builtin(char *args[], int *rodando);

// --- process.c ---
// Executa um comando externo do sistema (ex: "ls", "pwd") usando fork + execvp.
void executar_processo(char *args[]);

#endif
