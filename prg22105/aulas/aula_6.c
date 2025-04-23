#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 * Aula: Manipulação de arquivos em C
 * Objetivo: Apresentar a estrutura básica para abrir, escrever, ler e modificar arquivos.
 */

#define PARTE1 0
#define PARTE2 0
#define PARTE3 0
#define PARTE4_EX1 0
#define PARTE4_EX2 0
#define PARTE4_EX3 1
#define PARTE4_EX4 0
#define PARTE4_EX5 0

int main() {


    /*
     * Parte 1 - Criação e escrita em arquivo
     *         - Modo "w" cria ou sobrescreve o arquivo.
     */
#if PARTE1
    FILE *fp = fopen("dados.txt", "w");

    if (fp == NULL) {
        perror("Erro ao criar arquivo");
        return 1;
    }

    fprintf(fp, "Tensão;Corrente\n");
    fprintf(fp, "5.00;1.20\n");
    fprintf(fp, "5.13;1.15\n");

    fclose(fp);
    printf("Arquivo criado e conteúdo escrito com sucesso.\n");
#endif

    /*
     * Parte 2 - Leitura simples de um arquivo (linha a linha)
     *         - Modo "r" abre arquivo existente.
     */
#if PARTE2
    FILE *fp = fopen("dados.txt", "r");

    if (fp == NULL) {
        perror("Erro ao abrir arquivo para leitura");
        return 1;
    }

    char buffer[100];
    while (fgets(buffer, sizeof(buffer), fp) != NULL) {
        printf("%s", buffer);
    }

    fclose(fp);
#endif

    /*
     * Parte 3 - Append no arquivo existente
     *         - Modo "a" adiciona conteúdo ao final.
     */
#if PARTE3
    FILE *fp = fopen("dados.txt", "a");

    if (fp == NULL) {
        perror("Erro ao abrir arquivo para append");
        return 1;
    }

    fprintf(fp, "4.95;1.1\n");

    fclose(fp);
    printf("Conteúdo adicional gravado com sucesso.\n");
#endif

    /*
     * Parte 4 - Manipulação de arquivos: comandos complementares
     *         - fgetc(fp), fputc(c, fp), ftell(), fseek(), rewind(),
     *           feof(), ferror(), ungetc(c, fp)
     */
#if PARTE4_EX1 || PARTE4_EX2 || PARTE4_EX3 || PARTE4_EX4 || PARTE4_EX5
    FILE *fp = fopen("dados.txt", "r");
    if (fp == NULL) {
        perror("Erro ao abrir arquivo para testes complementares");
        return 1;
    }
    int c;
#endif

#if PARTE4_EX1
    /* Exemplo 1 - fgetc() e fputc() */
    while ((c = fgetc(fp)) != EOF) {
        fputc(c, stdout);
    }
    rewind(fp);
#endif

#if PARTE4_EX2
    /* Exemplo 2 - ftell() */
    long pos = ftell(fp);
    c = fgetc(fp);
    printf("\nPosição atual do cursor: %ld\n", pos);
    pos = ftell(fp);
    printf("\nPosição atual do cursor: %ld\n", pos);
#endif

#if PARTE4_EX3
    /* Exemplo 3 - fseek() */
    fseek(fp, 10, SEEK_SET);
    c = fgetc(fp);
    printf("Caractere na posição 10: %c\n", c);
#endif

#if PARTE4_EX4
    /* Exemplo 4 - ungetc() */
    c = fgetc(fp);
    printf("Lido: %c\n", c);
    ungetc(c, fp);
    c = fgetc(fp);
    printf("Relido com ungetc: %c\n", c);
#endif

#if PARTE4_EX5
    /* Exemplo 5 - feof() e ferror() */
    while ((c = fgetc(fp)) != EOF);

    if (feof(fp)) {
        printf("[Fim do arquivo atingido]\n");
    }

    if (ferror(fp)) {
        printf("[Erro de leitura detectado]\n");
    }
#endif

#if PARTE4_EX1 || PARTE4_EX2 || PARTE4_EX3 || PARTE4_EX4 || PARTE4_EX5
    fclose(fp);
#endif

    return 0;
}
