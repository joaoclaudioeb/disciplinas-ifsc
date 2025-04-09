#include <stdio.h>
#include <stdlib.h>

/*
 * Funções auxiliares
 */
void incrementa(int *valor) {
    (*valor)++;
}

void troca(int *a, int *b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

int main() {
    /*
     * Parte 1 – Ponteiros com int
     */

    /*
     * 1.1 – Acessando e alterando valor por ponteiro
     */
    /* int a = 42; */
    /* int *pa = &a; */
    /* printf("Valor de a: %d\n", a); */
    /* printf("Endereço de a: %p\n", (void*)&a); */
    /* printf("Valor de pa (endereço guardado): %p\n", (void*)pa); */
    /* printf("Valor apontado por pa (*pa): %d\n", *pa); */
    /* *pa = 100; */
    /* printf("Novo valor de a: %d\n", a); */

    /*
     * 1.2 – Atribuindo novo endereço ao ponteiro
     */
    /* int x = 10, y = 20; */
    /* int *p = &x; */
    /* printf("*p (x): %d\n", *p); */
    /* p = &y; */
    /* printf("*p (y): %d\n", *p); */

    /*
     * 1.3 – Alterando duas variáveis com o mesmo ponteiro
     */
    /* int m = 1, n = 2; */
    /* int *ptr = &m; */
    /* *ptr = 10; */
    /* ptr = &n; */
    /* *ptr = 20; */
    /* printf("m: %d, n: %d\n", m, n); */

    /*
     * 1.4 – Ponteiro não inicializado (comportamento perigoso!)
     */
    /* int *p_invalido; */
    /* *p_invalido = 5; // Comentado para evitar erro de segmentação */

    /*
     * 1.5 – Usando NULL para segurança
     */
    /* int *p_seguro = NULL; */
    /* if (p_seguro != NULL) { */
    /*     *p_seguro = 99; */
    /* } else { */
    /*     printf("p_seguro é NULL, não posso acessar o conteúdo.\n"); */
    /* } */

    /*
     * 1.6 – Ponteiro como função auxiliar (incremento)
     */
    /* int v = 7; */
    /* incrementa(&v); */
    /* printf("v após incremento: %d\n", v); */

    /*
     * 1.7 – Trocando valores com ponteiros
     */
    /* int i = 3, j = 5; */
    /* troca(&i, &j); */
    /* printf("i: %d, j: %d\n", i, j); */

    /*
     * 1.8 – Ponteiro como contador em laço
     */
    // int vetor[] = {1, 2, 3};
    // int *pp = vetor;
    // for (int k = 0; k < 3; k++) {
    //     printf("*(pp + %d) = %d\n", k, *(pp + k));
    // }

    /*
     * 1.9 – Inicialização via malloc
     */
    // int *din = malloc(sizeof(int));
    // *din = 77;
    // printf("Valor alocado dinamicamente: %d\n", *din);
    // free(din);

    /*
     * Parte 2 – Ponteiro para ponteiro
     */
    /* int a = 5; */
    /* int *pa = &a; */
    /* int **ppa = &pa; */
    /* printf("ppa: %p\n", (void*)ppa); */
    /* printf("*ppa (mesmo que pa): %p\n", (void*)*ppa); */
    /* printf("**ppa (valor de a): %d\n", **ppa); */

    /*
     * Parte 3 – Ponteiro em função
     */
    /* int b = 10; */
    /* incrementa(&b); */
    /* printf("Valor de b após incremento: %d\n", b); */

    /*
     * Parte 4 – Array é ponteiro
     */
    /* int v[3] = {1, 2, 3}; */
    /* int *pv = v; */
    /* printf("v[0]: %d\n", v[0]); */
    /* printf("*pv: %d\n", *pv); */
    /* printf("*(pv + 1): %d\n", *(pv + 1)); */

    /*
     * Parte 5 – malloc e free
     */
    /* int *vet = malloc(3 * sizeof(int)); */
    /* vet[0] = 5; */
    /* vet[1] = 10; */
    /* vet[2] = 15; */
    /* for (int i = 0; i < 3; i++) { */
    /*     printf("vet[%d] = %d\n", i, vet[i]); */
    /* } */
    /* free(vet); */

    return 0;
}
