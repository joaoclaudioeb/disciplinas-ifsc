#include <stdio.h>
#include <stdlib.h>

/* Obs.: haverá mais comentários neste doc., atualizações serão feitas com o tempo. */

/* #define DEBUG */
/* #define NIVEL 2 */
/* #define USAR_FOR */
/* #define USAR_WHILE */
/* #define USAR_MACRO */
/* #define SOMA(x, y) ((x) + (y)) */

int main() {

    /*
     *  Parte 1 – Modo DEBUG
     */

    #ifdef DEBUG
        printf("DEBUG: Executando em modo de depuração.\n");
    #endif


    /*
     *  Parte 2 – Seleção de nível (com #if, #elif, #else)
     */

    #ifdef NIVEL
        #if NIVEL == 1
            printf("Nível 1 selecionado\n");
        #elif NIVEL == 2
            printf("Nível 2 selecionado\n");
        #else
            printf("Nível desconhecido\n");
        #endif
    #else
        printf("Nível não definido\n");
    #endif


    /*
     *  Parte 3 – Estrutura de repetição: for
     */

    #ifdef USAR_FOR
        printf("Executando for:\n");
        for (int i = 0; i < 3; i++) {
            printf("  i = %d\n", i);
        }
    #endif


    /*
     *  Parte 4 – Estrutura de repetição: while
     */

    #ifdef USAR_WHILE
        printf("Executando while:\n");
        int j = 0;
        while (j < 3) {
            printf("  j = %d\n", j);
            j++;
        }
    #endif


    /*
     *  Parte 5 – Macro com parâmetro
     */

    #ifdef USAR_MACRO
        #ifndef SOMA
            #define SOMA(x, y) ((x) + (y))
        #endif
        int resultado = SOMA(3, 4);
        printf("Resultado da macro SOMA: %d\n", resultado);
    #endif

    return 0;
}
