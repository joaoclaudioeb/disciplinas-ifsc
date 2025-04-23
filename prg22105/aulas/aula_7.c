#include <stdio.h>   /* Necessário para utilizar funções básicas como fopen(), fscanf()... */
#include <stdlib.h>  /* Necessário para utilizar a função exit() */

/*
 * Aula: Manipulação de arquivos em C
 * Objetivo: Apresentar exemplos mais concretos quanto a manipulação de arquivos .txt, .csv e .bin.
 */

#define TAM_BUFFER 64
#define PARTE1 0
#define PARTE2 0
#define PARTE3 1

int main() {


    /*
     * Parte 1 - Leitura básica de .txt (linha a linha)
     *         - Demonstra como abrir um arquivo de texto e ler seu conteúdo linha a linha usando fgets().
     *         - Ideal para leitura simples sem precisar interpretar os dados internamente.
     */
#if PARTE1
    FILE *fp = fopen("dados.txt", "r"); // Abre o arquivo em modo leitura
    char buffer[TAM_BUFFER];            // Cria um buffer para armazenar cada linha

    if (fp == NULL) {                   // Verifica se o arquivo foi aberto corretamente
        perror("Erro ao ler o arquivo dados.txt na main: fopen()");
        exit(EXIT_FAILURE);
    }

    printf("Conteúdo do arquivo:");
    while (fgets(buffer, TAM_BUFFER, fp) != NULL) { // Lê uma linha por vez até o fim do arquivo
        printf("Linha: %s", buffer);                // Imprime a linha lida
    }

    fclose(fp); // Fecha o arquivo após a leitura
#endif

    /*
     * Parte 2 - Leitura e escrita em .csv
     *         - Lê dados estruturados (separados por ponto e vírgula) de um arquivo CSV.
     *         - Classifica as pessoas por idade e escreve o resultado em um novo arquivo CSV.
     */
#if PARTE2
    char nome[TAM_BUFFER]; // Armazena o nome da pessoa
    int idade;             // Armazena a idade
    char sexo;             // Armazena o sexo (M/F/etc.)

    FILE *fp_in = fopen("entrada.csv", "r"); // Abre o arquivo de entrada (modo leitura)
    if (fp_in == NULL) {
        perror("Erro ao ler o arquivo entrada.csv na main: fopen()");
        fclose(fp_in);
        exit(EXIT_FAILURE);
    }

    FILE *fp_out = fopen("saida.csv", "w"); // Cria/abre o arquivo de saída (modo escrita)
    if (fp_out == NULL) {
        perror("Erro ao criar/escrever no arquivo saida.csv na main: fopen()");
        fclose(fp_in);
        exit(EXIT_FAILURE);
    }

    fprintf(fp_out, "Nome;Idade;Sexo;Classificacao"); // Escreve o cabeçalho no novo CSV

    while (fscanf(fp_in, "%63[^;];%d;%c", nome, &idade, &sexo) == 3) { // Lê cada linha no formato: nome;idade;sexo

        char classificacao[20];
        if (idade < 18)
            sprintf(classificacao, "Jovem");
        else if (idade < 60)
            sprintf(classificacao, "Adulto");
        else
            sprintf(classificacao, "Idoso");

        fprintf(fp_out, "%s;%d;%c;%s", nome, idade, sexo, classificacao); // Escreve os dados com a classificação no novo CSV
    }

    fclose(fp_in);  // Fecha o arquivo de entrada
    fclose(fp_out); // Fecha o arquivo de saída

    printf("Arquivo processado com sucesso! Verifique 'saida.csv'.");
#endif

    /*
     * Parte 3 - Escrita binária e leitura binária
     *         - Demonstra como escrever um array de inteiros em um arquivo binário com fwrite().
     *         - Depois, lê valores específicos usando fseek() para demonstrar acesso direto.
     */
#if PARTE3
    FILE *fp_bin = fopen("dados.bin", "wb"); // Cria o arquivo binário para escrita
    int numeros[] = {10, 20, 30, 40, 50};    // Vetor de inteiros a ser salvo

    if (fp_bin == NULL) {
        perror("Erro ao criar/escrever no arquivo dados.bin na main: fopen()");
        exit(EXIT_FAILURE);
    }

    fwrite(numeros, sizeof(int), 5, fp_bin); // Escreve os 5 inteiros no arquivo binário
    fclose(fp_bin);

    fp_bin = fopen("dados.bin", "rb"); // Reabre o arquivo para leitura binária
    int valor;

    if (fp_bin == NULL) {
        perror("Erro ao ler o arquivo dados.bin na main: fopen()");
        exit(EXIT_FAILURE);
    }

    printf("\nLeitura binária:\n");
    fseek(fp_bin, 2 * sizeof(int), SEEK_SET); // Pula os 2 primeiros inteiros
    fread(&valor, sizeof(int), 1, fp_bin);    // Lê o terceiro valor
    printf("Terceiro valor: %d\n", valor);

    fseek(fp_bin, -sizeof(int), SEEK_END); // Vai para o último inteiro
    fread(&valor, sizeof(int), 1, fp_bin); // Lê o último valor
    printf("Último valor: %d\n", valor);

    fclose(fp_bin);
#endif

    return 0;
}
