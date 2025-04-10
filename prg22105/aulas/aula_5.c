#include <stdio.h>
#include <stdlib.h>

union ExemploUnion {
    int i;
    float f;
};

struct ExemploStruct {
    int i;
    float f;
};

int main() {
    /*
     * Parte 1 – union vs struct (compartilhamento de memória)
     */
    /* union ExemploUnion u; */
    /* struct ExemploStruct s; */

    /* u.i = 42; */
    /* u.f = 3.14f;  // sobrescreve u.i */

    /* s.i = 42; */
    /* s.f = 3.14f; */

    /* printf("Union: i = %d, f = %f\n", u.i, u.f);   // a variável i estará "corrompida" */
    /* printf("Struct: i = %d, f = %f\n", s.i, s.f);   // aqui a variável estará "normal" */

    /*
     * Parte 2 – Alocação dinâmica com malloc, calloc, free
     */

    /*
     * 2.1 – malloc com int
     */
    /* int *p = malloc(sizeof(int)); */
    /* if (p != NULL) { */
    /*     *p = 123; */
    /*     printf("Valor alocado com malloc: %d\n", *p); */
    /*     free(p); */
    /* } */

    /*
     * 2.2 – calloc com int
     */
    /* int *q = calloc(1, sizeof(int)); */
    /* if (q != NULL) { */
    /*     printf("Valor inicial com calloc: %d\n", *q); // deve ser 0 */
    /*     *q = 456; */
    /*     printf("Novo valor: %d\n", *q); */
    /*     free(q); */
    /* } */

    /*
     * 2.3 – malloc para array
     */
    /* int *vet = malloc(3 * sizeof(int)); */
    /* if (vet != NULL) { */
    /*     vet[0] = 10; */
    /*     vet[1] = 20; */
    /*     vet[2] = 30; */
    /*     for (int i = 0; i < 3; i++) { */
    /*         printf("vet[%d] = %d\n", i, vet[i]); */
    /*     } */
    /*     free(vet); */
    /* } */

    /*
     * 2.4 – calloc para array
     */
    /* int *z = calloc(3, sizeof(int)); */
    /* if (z != NULL) { */
    /*     for (int i = 0; i < 3; i++) { */
    /*         printf("z[%d] = %d\n", i, z[i]); // tudo 0 inicialmente */
    /*     } */
    /*     free(z); */
    /* } */

    /*
     * 2.5 – O que acontece se esquecer free?
     */
    /* int *leak = malloc(sizeof(int)); */
    /* if (leak != NULL) { */
    /*     *leak = 999; */
    /*     printf("Alocado mas não liberado! Valor: %d\n", *leak); */
    /*     // free(leak); // propositalmente comentado */
    /* } */

    return 0;
}
