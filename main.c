#include <stdio.h>
#include <string.h>
#include "include/nshell.h"

int main(){
  char linha[TAM_MAX];
  char *args[MAX_ARGS];
  int rodando = 1; 

  printf("--- nshell iniciado ---\n");

  while (rodando == 1){
    printf("nshell> ");

    if (fgets(linha, TAM_MAX, stdin) == NULL){
      break; 
    }

    linha[strcspn(linha, "\n")] = '\0';

    if (strlen(linha) == 0){
      continue;
    }

    int argc = parse_linha(linha, args);
    if (argc == 0){
      continue;
    }

    int era_builtin = executar_builtin(args, &rodando);

    if (!era_builtin) {
        executar_processo(args);
    }
  }
  return 0;
}