# nshell

Um shell Unix simples, escrito em C, feito como projeto de aprendizado.

## O que é

`nshell` é um interpretador de linha de comando (shell) que lê comandos digitados pelo usuário e os executa. Tanto comandos internos próprios do shell quanto programas externos do sistema (como `ls`, `pwd`, `whoami`).

## Funcionalidades atuais

- Loop de leitura de comandos (REPL: read-eval-print loop)
- Parsing de linha de comando em argumentos (`args[]`)
- Comandos internos (builtins):
  - `ajuda` — lista os comandos disponíveis
  - `sair` — encerra o shell
  - `cd` — muda o diretório de trabalho (aceita caminho absoluto, relativo, ou vazio para ir à home)
- Execução de comandos externos do sistema via `fork()` + `execvp()`

## Estrutura do projeto

```
nshell/
├── main.c              # loop principal do shell
├── include/
│   └── nshell.h         # declarações das funções e constantes globais
├── src/
│   ├── parser.c         # quebra a linha digitada em argumentos
│   ├── builtin.c        # comandos internos do shell
│   └── process.c        # execução de comandos externos (fork/exec)
└── makefile             # automatiza a compilação do projeto
```

## Como compilar e rodar

```bash
make
./nshell
```

Para limpar o executável gerado:

```bash
make clean
```

## Exemplo de uso

```
--- nshell iniciado ---
nshell> ajuda
Comandos disponíveis: ajuda, sair
nshell> ls
main.c  include  src  makefile  README.md
nshell> pwd
/home/felipe/projetos/nshell
nshell> sair
Saindo do nshell
```

## Autor

Projeto desenvolvido por Felipe, estudante de Ciência da Computação, como forma de ganhar experiência prática em C e construir portfólio.