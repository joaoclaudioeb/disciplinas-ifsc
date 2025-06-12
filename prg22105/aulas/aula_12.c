#include <stdio.h>
#include <stdlib.h>

/*
 * Aula 12 – Árvores Binárias de Busca (ABB)
 * Objetivo: apresentar a estrutura de árvore binária de busca,
 *           incluindo operações básicas como inserção, busca, remoção e percurso.
 *
 * Regra fundamental da ABB:
 *   - Todo nó à esquerda é menor que o pai
 *   - Todo nó à direita é maior ou igual ao pai
 */

// Estrutura do nó da árvore
typedef struct No {
    int dado;
    struct No *esq; // Ponteiro para filho à esquerda
    struct No *dir; // Ponteiro para filho à direita
} No;

// Função para criar um novo nó com valor inicial
No* criar_no(int valor) {
    No* novo = malloc(sizeof(No)); // Aloca memória para o novo nó
    if (!novo) {
        printf("Erro ao alocar memória.\n");
        return NULL;
    }
    novo->dado = valor;     // Define o valor do nó
    novo->esq = NULL;        // Inicializa filho esquerdo como NULL
    novo->dir = NULL;        // Inicializa filho direito como NULL
    return novo;
}

// Função recursiva para inserir um valor na ABB
No* inserir_ab(No* raiz, int valor) {
    if (raiz == NULL) {            // Se a posição estiver vazia
        return criar_no(valor);    // Cria e retorna um novo nó
    }

    if (valor < raiz->dado) {      // Se valor for menor que o atual
        raiz->esq = inserir_ab(raiz->esq, valor); // Insere à esquerda
    } else {                       // Se valor for maior ou igual
        raiz->dir = inserir_ab(raiz->dir, valor); // Insere à direita
    }

    return raiz;                   // Retorna a raiz modificada
}

// Função recursiva para buscar um valor na ABB
No* buscar_ab(No* raiz, int valor) {
    if (raiz == NULL || raiz->dado == valor) { // Nó vazio ou encontrado
        return raiz;
    }

    if (valor < raiz->dado) {       // Valor menor, procurar à esquerda
        return buscar_ab(raiz->esq, valor);
    } else {                        // Valor maior ou igual, procurar à direita
        return buscar_ab(raiz->dir, valor);
    }
}

// Função para encontrar o nó com menor valor em uma subárvore
No* encontrar_minimo(No* raiz) {
    while (raiz && raiz->esq != NULL) { // Enquanto houver filhos à esquerda
        raiz = raiz->esq;                // Desce à esquerda até o mínimo
    }
    return raiz;
}

// Função recursiva para remover um nó da ABB
No* remover_ab(No* raiz, int valor) {
    if (raiz == NULL) return raiz; // Nó não encontrado

    if (valor < raiz->dado) {                  // Vai para a esquerda
        raiz->esq = remover_ab(raiz->esq, valor);
    } else if (valor > raiz->dado) {           // Vai para a direita
        raiz->dir = remover_ab(raiz->dir, valor);
    } else {                                   // Achou o nó a ser removido
        // Caso 1: nó sem filhos
        if (raiz->esq == NULL && raiz->dir == NULL) {
            free(raiz);                        // Libera memória
            return NULL;
        }
        // Caso 2: nó com apenas um filho
        else if (raiz->esq == NULL) {
            No* temp = raiz->dir;              // Guarda o único filho
            free(raiz);                        // Libera o nó
            return temp;
        } else if (raiz->dir == NULL) {
            No* temp = raiz->esq;              // Guarda o único filho
            free(raiz);                        // Libera o nó
            return temp;
        }
        // Caso 3: nó com dois filhos
        else {
            No* temp = encontrar_minimo(raiz->dir); // Encontra o sucessor in-order
            raiz->dado = temp->dado;                // Copia o valor do sucessor
            raiz->dir = remover_ab(raiz->dir, temp->dado); // Remove o sucessor duplicado
        }
    }
    return raiz;
}

// Percorre a árvore em pré-ordem: Raiz -> Esquerda -> Direita
void pre_ordem(No* raiz) {
    if (raiz != NULL) {
        printf("%d ", raiz->dado);   // Primeiro visita a raiz
        pre_ordem(raiz->esq);        // Depois visita a esquerda
        pre_ordem(raiz->dir);        // Finalmente visita a direita
    }
}

// Percorre a árvore em ordem: Esquerda -> Raiz -> Direita
void em_ordem(No* raiz) {
    if (raiz != NULL) {
        em_ordem(raiz->esq);         // Primeiro visita a esquerda
        printf("%d ", raiz->dado);   // Depois visita a raiz
        em_ordem(raiz->dir);         // Finalmente visita a direita
    }
}

// Percorre a árvore em pós-ordem: Esquerda -> Direita -> Raiz
void pos_ordem(No* raiz) {
    if (raiz != NULL) {
        pos_ordem(raiz->esq);        // Primeiro visita a esquerda
        pos_ordem(raiz->dir);        // Depois visita a direita
        printf("%d ", raiz->dado);   // Finalmente visita a raiz
    }
}

// Função auxiliar para liberar todos os nós da árvore
void liberar_arvore(No* raiz) {
    if (raiz != NULL) {
        liberar_arvore(raiz->esq);   // Libera recursivamente a esquerda
        liberar_arvore(raiz->dir);   // Libera recursivamente a direita
        free(raiz);                  // Libera o nó atual
    }
}

int main() {
    No* raiz = NULL;

    // Inserindo elementos
    printf("=== Inserindo elementos ===\n");
    raiz = inserir_ab(raiz, 50);
    raiz = inserir_ab(raiz, 30);
    raiz = inserir_ab(raiz, 70);
    raiz = inserir_ab(raiz, 20);
    raiz = inserir_ab(raiz, 40);

    // Mostrando percursos
    printf("\nPré-ordem: ");
    pre_ordem(raiz);
    printf("\nEm ordem:  ");
    em_ordem(raiz);
    printf("\nPós-ordem: ");
    pos_ordem(raiz);
    printf("\n");

    // Buscando elemento
    int valor_busca = 40;
    No* resultado = buscar_ab(raiz, valor_busca);
    if (resultado != NULL) {
        printf("\n✅ Valor %d encontrado!\n", valor_busca);
    } else {
        printf("\n❌ Valor %d não encontrado.\n", valor_busca);
    }

    // Removendo elemento
    int valor_remover = 30;
    printf("\n=== Removendo valor %d ===\n", valor_remover);
    raiz = remover_ab(raiz, valor_remover);

    // Mostrando percursos após remoção
    printf("Pré-ordem: ");
    pre_ordem(raiz);
    printf("\nEm ordem:  ");
    em_ordem(raiz);
    printf("\nPós-ordem: ");
    pos_ordem(raiz);
    printf("\n");

    // Liberando memória
    printf("\n=== Liberando memória ===\n");
    liberar_arvore(raiz);
    printf("Árvore liberada.\n");

    return 0;
}
