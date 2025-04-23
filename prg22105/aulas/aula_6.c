#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 * Aula: Manipulação de arquivos em C
 * Objetivo: Apresentar a estrutura básica para abrir, escrever, ler e modificar arquivos.
 */

int main() {

    /*
     * Parte 1 – Criação e escrita em arquivo
     *         – Modo "w" cria ou sobrescreve o arquivo.
     */

    /* FILE *fp = fopen("dados.txt", "w"); */

    /* if (fp == NULL) { */
    /*     perror("Erro ao criar arquivo"); */
    /*     return 1; */
    /* } */

    /* fprintf(fp, "Tensão;Corrente\n"); */
    /* fprintf(fp, "5.00;1.20\n"); */
    /* fprintf(fp, "5.13;1.15\n"); */

    /* fclose(fp); */
    /* printf("Arquivo criado e conteúdo escrito com sucesso.\n"); */

    /*
     * Parte 2 – Leitura simples de um arquivo (linha a linha)
     *         – Modo "r" abre arquivo existente.
     */

    /* FILE *fp = fopen("dados.txt", "r"); */

    /* if (fp == NULL) { */
    /*     perror("Erro ao abrir arquivo para leitura"); */
    /*     return 1; */
    /* } */

    /* char buffer[100]; */
    /* while (fgets(buffer, sizeof(buffer), fp) != NULL) { */
    /*     printf("%s", buffer); */
    /* } */

    /* fclose(fp); */

    /*
     * Parte 3 – Append no arquivo existente
     *         – Modo "a" adiciona conteúdo ao final.
     */

    /* FILE *fp = fopen("dados.txt", "a"); */

    /* if (fp == NULL) { */
    /*     perror("Erro ao abrir arquivo para append"); */
    /*     return 1; */
    /* } */

    /* fprintf(fp, "4.95;1.1\n"); */

    /* fclose(fp); */
    /* printf("Conteúdo adicional gravado com sucesso.\n"); */

    /*
     * Parte 4 – Manipulação de arquivos: comandos complementares
     *           – fgetc(fp)      (leitura)         lê um caractere do arquivo
     *           – fputc(c, fp)   (escrita)         escreve um caractere no arquivo
     *           – ftell(fp)      (posição)         retorna a posição atual do cursor no arquivo
     *           – fseek(fp, pos, origem) (posição) move o cursor para uma posição específica
     *           – rewind(fp)     (posição)         volta o cursor para o início do arquivo
     *           – feof(fp)       (verificação)     retorna verdadeiro se chegou ao fim do arquivo
     *           – ferror(fp)     (verificação)     verifica se houve erro durante leitura ou escrita
     *           – ungetc(c, fp)  (fluxo reverso)   devolve um caractere lido para o fluxo
     */
    
    return 0;
}
