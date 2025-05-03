/*
 * Verificador de palíndromos
 * ------------------------------------------------
 * Este programa verifica se uma palavra é um palíndromo (lê-se igual de
 * trás para frente) utilizando uma pilha estática implementada com um vetor.
 * 
 * Comentários e adaptações: Prof. João Cláudio Elsen Barcellos
 * Autor: Dev. Élisson Michael (https://gist.github.com/elissonmichael/b24f0bb2b5154fc1b419d726c51a7f01)
 */

#include <stdio.h>
#include <string.h>

#define TAMANHO_MAXIMO 100  // Tamanho máximo da pilha

// Estrutura da Pilha
typedef struct {
    int topo;               // Índice do topo da pilha
    char letras[TAMANHO_MAXIMO];  // Vetor que armazena os caracteres
} Pilha;

Pilha pilha;  // Variável global para a pilha (simplificação didática)

/* 
 * Função: inicializa
 * ------------------
 * Prepara a pilha para uso, definindo o topo como 0 (pilha vazia).
 */
void inicializa() {
    pilha.topo = 0;  // Pilha vazia (próxima posição livre é 0)
}

/* 
 * Função: empilhar
 * ----------------
 * Adiciona um caractere no topo da pilha.
 * 
 * Parâmetro:
 *   letra - Caractere a ser empilhado.
 */
void empilhar(char letra) {
    pilha.letras[pilha.topo] = letra;  // Armazena no topo atual
    pilha.topo++;                      // Move o topo para a próxima posição
}

/* 
 * Função: desempilhar
 * -------------------
 * Remove e retorna o caractere do topo da pilha.
 * 
 * Retorno:
 *   O caractere removido (ou lixo se a pilha estiver vazia).
 */
char desempilhar() {
    pilha.topo--;                      // Decrementa o topo (volta para o último elemento)
    return pilha.letras[pilha.topo];   // Retorna o caractere no topo
}

/* 
 * Função: exibirPilha
 * -------------------
 * Mostra o conteúdo da pilha (do topo para a base).
 * Útil para debug e entendimento do funcionamento.
 */
void exibirPilha() {
    printf("Conteúdo da Pilha (Topo -> Base):\n");
    for (int i = pilha.topo - 1; i >= 0; i--) {
        printf("%i - %c\n", i, pilha.letras[i]);
    }
}

/* 
 * Função: palindromo
 * ------------------
 * Lê uma palavra do usuário, empilha seus caracteres e verifica se é um palíndromo.
 */
void palindromo() {
    char entradaDoUsuario[TAMANHO_MAXIMO];  // Buffer para a palavra do usuário

    printf("Digite uma palavra: ");
    scanf("%s", entradaDoUsuario);

    // Empilha cada caractere da palavra
    for (int i = 0; i < strlen(entradaDoUsuario); i++) {
        empilhar(entradaDoUsuario[i]);
    }

    printf("\nPalavra Digitada: %s\n", entradaDoUsuario);
    exibirPilha();  // Mostra a pilha para visualização

    // Verifica se é palíndromo
    char *resultado = "É um Palíndromo";  // Assume que é palíndromo inicialmente
    for (int i = 0; i < strlen(entradaDoUsuario); i++) {
        if (entradaDoUsuario[i] != desempilhar()) {
            resultado = "Não é um Palíndromo";
            break;  // Interrompe se encontrar um caractere diferente
        }
    }

    printf("\nResultado: %s\n", resultado);
}

/* 
 * Função: main
 * ------------
 * Ponto de entrada do programa. Chama a função principal `palindromo`.
 */
int main() {
    while(1){
        inicializa();  // Garante que a pilha está vazia no início
        palindromo();
    }
    return 0;
}
