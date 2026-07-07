#include <stdio.h>
#include <string.h>
#include "include/nshell.h"

int main(){
  char linha[TAM_MAX];
  char *args[MAX_ARGS];
  int rodando = 1; // O shell já começa ativo

  printf("--- nshell iniciado ---\n");

  while (rodando == 1){
    printf("nshell> ");


    if (fgets(linha, TAM_MAX, stdin) == NULL){
      break; //Erro de leitura ou Ctrl + D --> Encerra o shell 
    }

    // fgets guarda o 'n' no final, então removemos ele
    linha[strcspn(linha, "\n")] = '\0';

    // se o user apertou enter, ignora e mostra o prompt de novo
    if (strlen(linha) == 0){
      continue;
    }
    
    // quebra a linha digitada em palavras separadas (args[])
    int argc = parse_linha(linha, args); 

    if (argc == 0){
      continue; 
    }
    
    // tenta executar como o comando interno do shell
    // se nao for builtin, vamos chamar ele futuramente (ls, pwd)
    
    int era_builtin = executar_builtin(args, &rodando){
     if (seila_builtin);
        printf("Comando nao encontrado: %s\n", args[0]);
    }
  }
  return 0;
}
