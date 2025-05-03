/*
 * Verificador de parênteses e colchetes balanceados
 * ------------------------------------------------
 * Este programa verifica se uma string contém uma sequência bem-formada
 * de parênteses '(' e ')' e colchetes '[' e ']', usando uma pilha.
 * 
 * Comentários e adaptações: Prof. João Cláudio Elsen Barcellos
 * Autor: Prof. Paulo Feofiloff (https://www.ime.usp.br/~pf/algoritmos/aulas/pilha.html)
 */

#include <stdio.h>

#define N 100  // Tamanho máximo da pilha (maior que o tamanho da string de entrada)

// Variáveis globais para a pilha (simplicidade didática)
char pilha[N];  // Vetor que armazena os caracteres da pilha
int t;          // Índice do topo da pilha

/* 
 * Função: criapilha
 * -----------------
 * Inicializa a pilha, definindo o topo como 0 (pilha vazia).
 */
void criapilha(void) {
    t = 0;
}

/* 
 * Função: empilha
 * ---------------
 * Adiciona um caractere `y` no topo da pilha.
 * 
 * Parâmetro:
 *   y - Caractere a ser empilhado (deve ser '(', '[', ou outros delimitadores esquerdos).
 */
void empilha(char y) {
    pilha[t++] = y;  // Coloca `y` na posição `t` e incrementa o topo
}

/* 
 * Função: desempilha
 * ------------------
 * Remove e retorna o caractere no topo da pilha.
 * 
 * Retorno:
 *   O caractere desempilhado (ou comportamento indefinido se a pilha estiver vazia).
 */
char desempilha(void) {
    return pilha[--t];  // Decrementa `t` antes de acessar o elemento
}

/* 
 * Função: pilhavazia
 * ------------------
 * Verifica se a pilha está vazia.
 * 
 * Retorno:
 *   1 (verdadeiro) se a pilha está vazia, 0 (falso) caso contrário.
 */
int pilhavazia(void) {
    return t <= 0;
}

/* 
 * Função: bemFormada
 * ------------------
 * Verifica se uma string `s` contém uma sequência bem-formada de parênteses e colchetes.
 * 
 * Pseudocódigo:
 *   1. Inicializa a pilha vazia.
 *   2. Para cada caractere em `s`:
 *      a. Se for ')', verifica se o topo da pilha é '('.
 *      b. Se for ']', verifica se o topo da pilha é '['.
 *      c. Se for '(', '[', ou outro caractere, empilha.
 *   3. No final, a pilha deve estar vazia.
 * 
 * Parâmetro:
 *   s - String contendo a sequência a ser verificada.
 * 
 * Retorno:
 *   1 se a sequência é bem-formada, 0 caso contrário.
 */
int bemFormada(char s[]) {
    criapilha();  // Inicializa a pilha vazia

    for (int i = 0; s[i] != '\0'; ++i) {
        char c;
        switch (s[i]) {
            // Caso 1: Encontrou um ')'
            case ')':
                if (pilhavazia()) return 0;   // Pilha vazia = malformado
                c = desempilha();             // Remove o topo da pilha
                if (c != '(') return 0;       // Não fecha corretamente
                break;

            // Caso 2: Encontrou um ']'
            case ']':
                if (pilhavazia()) return 0;   // Pilha vazia = malformado
                c = desempilha();             // Remove o topo da pilha
                if (c != '[') return 0;       // Não fecha corretamente
                break;

            // Caso 3: Empilha qualquer outro caractere (assumindo que são delimitadores esquerdos)
            default:
                empilha(s[i]);
        }
    }

    // Se a pilha estiver vazia no final, a sequência é bem-formada
    return pilhavazia();
}

/* 
 * Função: main (Exemplo de uso)
 * -----------------------------
 * Testa a função `bemFormada` com alguns casos de exemplo.
 */
int main() {
    char expr1[] = "(()[()])";       // Bem-formada
    char expr2[] = "([)]";           // Malformada
    char expr3[] = "[[]()]";         // Bem-formada
    char expr4[] = "((()]";          // Malformada

    printf("Testando sequências:\n");
    printf("1. %s → %s\n", expr1, bemFormada(expr1) ? "OK" : "Erro");
    printf("2. %s → %s\n", expr2, bemFormada(expr2) ? "OK" : "Erro");
    printf("3. %s → %s\n", expr3, bemFormada(expr3) ? "OK" : "Erro");
    printf("4. %s → %s\n", expr4, bemFormada(expr4) ? "OK" : "Erro");

    return 0;
}
