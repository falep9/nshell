#include <stdio.h>
#include <string.h>
#include "../include/nshell.h"


void mostrar_ajuda() {
  printf("Comandos disponíves: ajuda, sair\n");
}

int executar_builtin(char *args[], int *rodando){

  if (strcmp(args[0], "ajuda") == 0){
    mostrar_ajuda();
    return 1;
  }

  if (strcmp(args[0], "sair") == 0){
    printf("Saindo do nshell\n");
    *rodando = 0;
    return 1;
  }
  
  return 0;

}
