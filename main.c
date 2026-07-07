#include <stdio.h>
#include <string.h>

void mostrar_ajuda() {
    printf("Comandos disponíveis: ajuda, sair\n");
}

int main() {
    char comando[100];
    int rodando = 1; // 1 significa Verdadeiro. O shell começa ativo.

    printf("--- nshell Iniciado ---\n");

    // ENQUANTO rodando for igual a 1, repita tudo o que está aqui dentro
    while (rodando == 1) {
        printf("nshell> ");
        scanf("%s", comando);

        if (strcmp(comando, "ajuda") == 0) {
            mostrar_ajuda();
        } 
        else if (strcmp(comando, "sair") == 0) {
            printf("Saindo do nshell... Até logo!\n");
            rodando = 0; // Muda para 0 (Falso) para quebrar o loop
        } 
        else {
            printf("nshell: comando não encontrado: %s\n", comando);
        }
    }

    return 0;
}
