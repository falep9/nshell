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
        // --- Este bloco só roda no PROCESSO FILHO ---

        // execvp substitui o programa atual (que era uma cópia do nshell)
        // pelo programa pedido (args[0]), passando os argumentos (args).
        // Se execvp der certo, ele NUNCA retorna — o processo já virou outro programa.
        execvp(args[0], args);

        // Se o código chegou até aqui, é porque execvp falhou
        perror("nshell");

        // _exit em vez de return: encerra o processo filho imediatamente,
        // sem voltar pro loop do nshell (que só existe no pai).
        _exit(1);
    }
    else {
        // --- Este bloco só roda no PROCESSO PAI ---

        int status;

        // Espera o processo filho
        waitpid(pid, &status, 0);
    }
}