#include <stdio.h>
#include <unistd.h>    // fork(), execvp()
#include <sys/wait.h>  // wait()
#include "../include/nshell.h"

// Executa um comando externo do sistema
void executar_processo(char *args[]) {

    pid_t pid = fork();

    if (pid < 0) {
        // fork falhou
        perror("nshell: erro ao criar processo");
        return;
    }

    if (pid == 0) {
        execvp(args[0], args);
        // Se o código chegou até aqui, é porque execvp falhou
        perror("nshell");
        _exit(1);
    }
    else {

        int status;

        // Espera o processo filho
        waitpid(pid, &status, 0);
    }
}