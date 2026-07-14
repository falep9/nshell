#include <stdio.h>
#include <string.h>
#include <stdlib.h>  
#include <unistd.h>   
#include "../include/nshell.h"

void mostrar_ajuda() {
  printf("Comandos disponíveis: ajuda, sair, cd\n");
}

int executar_builtin(char *args[], int *rodando) {
  if (strcmp(args[0], "ajuda") == 0) {
    mostrar_ajuda();
    return 1;
  }

  if (strcmp(args[0], "sair") == 0) {
    printf("Saindo do nshell\n");
    *rodando = 0;
    return 1;
  }

  if (strcmp(args[0], "cd") == 0) {
    // args[1] é o caminho pedido
    if (args[1] == NULL) {
      // Se a pessoa só digitou "cd" sem destino, mando pra HOME.
      char *home = getenv("HOME");
      if (home != NULL) {
        chdir(home);
      }
    } else {
      // chdir() retorna 0 se deu certo, e um valor diferente de 0 se deu algum erro
      if (chdir(args[1]) != 0) {
        perror("nshell: cd");
      }
    }
    return 1;
  }

  return 0;
}