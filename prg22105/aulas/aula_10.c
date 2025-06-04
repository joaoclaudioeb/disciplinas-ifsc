#include <stdio.h>
#include <stdlib.h>

/*
 * Aula - Lista Simplesmente Encadeada
 * Objetivo: apresentar a estrutura de lista simplesmente encadeada e suas operações básicas.
 */

/*
 * Lista Simplesmente Encadeada
 * - Estrutura de dados dinâmica que armazena elementos em nós conectados por ponteiros.
 * - Cada nó contém um dado e um ponteiro para o próximo nó.
 * - O último nó aponta para NULL, indicando o fim da lista.
 * - Permite inserção e remoção de elementos em qualquer posição.
 *
 * Representação visual de uma lista simplesmente encadeada:
 *
 *    +-----+      +-----+      +-----+
 *    | 100 | ---> | 200 | ---> | 300 | ---> NULL
 *    +-----+      +-----+      +-----+
 *     início
 *
 * Cada nó contém:
 *    - Um dado (ex.: 100, 200, 300)
 *    - Um ponteiro para o próximo nó
 *
 * Estrutura de um nó:
 *
 *    struct No {
 *        int dado;
 *        struct No *prox;
 *    };
 */

/* 
 * Estrutura do nó:
 *    +-----+-----+
 *    | dado| prox|
 *    +-----+-----+
 */
typedef struct No {
    int dado;
    struct No *prox;
} No;

/* 
 * Estrutura da lista:
 *    +------+
 *    | inicio | --> NULL (vazia) ou aponta para o primeiro nó
 *    +------+
 */
typedef struct {
    No *inicio;
} ListaEncadeada;

/* 
 * Função: inicializar_lista
 * ------------------------
 * Inicializa a lista com inicio = NULL (vazia).
 */
void inicializar_lista(ListaEncadeada *l) {
    l->inicio = NULL;
}

/* 
 * Função: esta_vazia
 * -----------------
 * Verifica se a lista está vazia (inicio == NULL).
 */
int esta_vazia(ListaEncadeada *l) {
    return l->inicio == NULL;
}

/* 
 * Função: inserir_inicio
 * ---------------------
 * Adiciona um novo nó no início da lista.
 * 
 * Visualização (inserir_inicio 100, 200, 300):
 * 
 *    1. inserir_inicio(100):
 *       +-----+-----+
 *       | 100 | NULL|
 *       +-----+-----+
 *         ^
 *       inicio
 * 
 *    2. inserir_inicio(200):
 *       +-----+-----+    +-----+-----+
 *       | 200 |  ---|--> | 100 | NULL|
 *       +-----+-----+    +-----+-----+
 *         ^
 *       inicio
 * 
 *    3. inserir_inicio(300):
 *       +-----+-----+    +-----+-----+    +-----+-----+
 *       | 300 |  ---|--> | 200 |  ---|--> | 100 | NULL|
 *       +-----+-----+    +-----+-----+    +-----+-----+
 *         ^
 *       inicio
 */
void inserir_inicio(ListaEncadeada *l, int valor) {
    No *novo = malloc(sizeof(No));
    if (novo == NULL) {
        printf("Erro ao alocar memória\n");
        return;
    }
    novo->dado = valor;
    novo->prox = l->inicio; // Novo nó aponta para o antigo início
    l->inicio = novo;       // Início agora é o novo nó
}

/* 
 * Função: inserir_fim
 * ------------------
 * Adiciona um novo nó no fim da lista.
 * 
 * Visualização (após inserir_inicio 300, 200, 100, inserir_fim 400):
 * 
 *    +-----+-----+    +-----+-----+    +-----+-----+    +-----+-----+
 *    | 300 |  ---|--> | 200 |  ---|--> | 100 |  ---|--> | 400 | NULL|
 *    +-----+-----+    +-----+-----+    +-----+-----+    +-----+-----+
 *      ^
 *    inicio
 */
void inserir_fim(ListaEncadeada *l, int valor) {
    No *novo = malloc(sizeof(No));
    if (novo == NULL) {
        printf("Erro ao alocar memória\n");
        return;
    }
    novo->dado = valor;
    novo->prox = NULL; // Novo nó será o último
    
    if (esta_vazia(l)) {
        l->inicio = novo; // Se lista vazia, novo é o início
    } else {
        // Percorre até o último nó
        No *atual = l->inicio;
        while (atual->prox != NULL) {
            atual = atual->prox;
        }
        atual->prox = novo; // Último nó aponta para o novo
    }
}

/* 
 * Função: inserir_posicao
 * ----------------------
 * Adiciona um novo nó na posição especificada.
 * Posição 0 = início, posição 1 = segundo elemento, etc.
 * 
 * Visualização (após inserir_inicio 300, 200, 100, inserir_posicao(1, 250)):
 * 
 *    +-----+-----+    +-----+-----+    +-----+-----+    +-----+-----+
 *    | 300 |  ---|--> | 250 |  ---|--> | 200 |  ---|--> | 100 | NULL|
 *    +-----+-----+    +-----+-----+    +-----+-----+    +-----+-----+
 *      ^
 *    inicio
 */
void inserir_posicao(ListaEncadeada *l, int posicao, int valor) {
    // Se posição for 0, insere no início
    if (posicao == 0) {
        inserir_inicio(l, valor);
        return;
    }
    
    // Verifica se a lista está vazia
    if (esta_vazia(l)) {
        printf("Lista vazia, impossível inserir na posição %d\n", posicao);
        return;
    }
    
    // Cria o novo nó
    No *novo = malloc(sizeof(No));
    if (novo == NULL) {
        printf("Erro ao alocar memória\n");
        return;
    }
    novo->dado = valor;
    
    // Percorre até a posição anterior à desejada
    No *atual = l->inicio;
    int i = 0;
    while (i < posicao - 1 && atual->prox != NULL) {
        atual = atual->prox;
        i++;
    }
    
    // Verifica se a posição é válida
    if (i < posicao - 1) {
        printf("Posição %d inválida, inserindo no fim\n", posicao);
        atual->prox = novo;
        novo->prox = NULL;
    } else {
        // Insere na posição desejada
        novo->prox = atual->prox;
        atual->prox = novo;
    }
}

/* 
 * Função: remover_inicio
 * ---------------------
 * Remove o nó do início da lista e retorna seu valor.
 * 
 * Visualização (após inserir_inicio 300, 200, 100):
 * 
 *    1. remover_inicio() → 300:
 *       +-----+-----+    +-----+-----+
 *       | 200 |  ---|--> | 100 | NULL|
 *       +-----+-----+    +-----+-----+
 *         ^
 *       inicio
 */
int remover_inicio(ListaEncadeada *l) {
    if (esta_vazia(l)) {
        printf("Lista vazia, impossível remover do início\n");
        return -1;
    }
    
    No *remover = l->inicio;
    int valor = remover->dado;
    l->inicio = remover->prox; // Início agora é o próximo nó
    free(remover);             // Libera memória do nó removido
    return valor;
}

/* 
 * Função: remover_fim
 * ------------------
 * Remove o nó do fim da lista e retorna seu valor.
 * 
 * Visualização (após inserir_inicio 300, 200, 100):
 * 
 *    1. remover_fim() → 100:
 *       +-----+-----+    +-----+-----+
 *       | 300 |  ---|--> | 200 | NULL|
 *       +-----+-----+    +-----+-----+
 *         ^
 *       inicio
 */
int remover_fim(ListaEncadeada *l) {
    if (esta_vazia(l)) {
        printf("Lista vazia, impossível remover do fim\n");
        return -1;
    }
    
    // Se há apenas um elemento
    if (l->inicio->prox == NULL) {
        int valor = l->inicio->dado;
        free(l->inicio);
        l->inicio = NULL;
        return valor;
    }
    
    // Percorre até o penúltimo nó
    No *atual = l->inicio;
    while (atual->prox->prox != NULL) {
        atual = atual->prox;
    }
    
    // Remove o último nó
    int valor = atual->prox->dado;
    free(atual->prox);
    atual->prox = NULL;
    return valor;
}

/* 
 * Função: remover_posicao
 * ----------------------
 * Remove o nó da posição especificada e retorna seu valor.
 * Posição 0 = início, posição 1 = segundo elemento, etc.
 * 
 * Visualização (após inserir_inicio 300, 200, 100):
 * 
 *    1. remover_posicao(1) → 200:
 *       +-----+-----+    +-----+-----+
 *       | 300 |  ---|--> | 100 | NULL|
 *       +-----+-----+    +-----+-----+
 *         ^
 *       inicio
 */
int remover_posicao(ListaEncadeada *l, int posicao) {
    // Se posição for 0, remove do início
    if (posicao == 0) {
        return remover_inicio(l);
    }
    
    // Verifica se a lista está vazia
    if (esta_vazia(l)) {
        printf("Lista vazia, impossível remover da posição %d\n", posicao);
        return -1;
    }
    
    // Percorre até a posição anterior à desejada
    No *atual = l->inicio;
    int i = 0;
    while (i < posicao - 1 && atual->prox != NULL) {
        atual = atual->prox;
        i++;
    }
    
    // Verifica se a posição é válida
    if (atual->prox == NULL) {
        printf("Posição %d inválida\n", posicao);
        return -1;
    }
    
    // Remove o nó da posição desejada
    No *remover = atual->prox;
    int valor = remover->dado;
    atual->prox = remover->prox;
    free(remover);
    return valor;
}

/* 
 * Função: buscar
 * -------------
 * Busca um valor na lista e retorna sua posição (0-based).
 * Retorna -1 se o valor não for encontrado.
 */
int buscar(ListaEncadeada *l, int valor) {
    if (esta_vazia(l)) {
        return -1;
    }
    
    No *atual = l->inicio;
    int posicao = 0;
    
    while (atual != NULL) {
        if (atual->dado == valor) {
            return posicao;
        }
        atual = atual->prox;
        posicao++;
    }
    
    return -1; // Valor não encontrado
}

/* 
 * Função: mostrar_lista
 * --------------------
 * Exibe a lista do início ao fim (com setas).
 */
void mostrar_lista(ListaEncadeada *l) {
    printf("Lista: INÍCIO -> ");
    No *atual = l->inicio;
    while (atual != NULL) {
        printf("%d -> ", atual->dado);
        atual = atual->prox;
    }
    printf("NULL\n");
}

/* 
 * Função: liberar_lista
 * --------------------
 * Desaloca todos os nós da lista para evitar vazamento de memória.
 */
void liberar_lista(ListaEncadeada *l) {
    No *atual = l->inicio;
    while (atual != NULL) {
        No *prox = atual->prox; // Guarda referência para o próximo
        free(atual);            // Libera o nó atual 
        atual = prox;           // Avança para o próximo
    }
    l->inicio = NULL;           // Lista vazia
}

int main() {
    ListaEncadeada lista;
    inicializar_lista(&lista);
    
    // Inserções no início
    printf("Inserindo no início: 100, 200, 300\n");
    inserir_inicio(&lista, 100);
    inserir_inicio(&lista, 200);
    inserir_inicio(&lista, 300);
    mostrar_lista(&lista);
    
    // Inserção no fim
    printf("\nInserindo no fim: 400\n");
    inserir_fim(&lista, 400);
    mostrar_lista(&lista);
    
    // Inserção em posição específica
    printf("\nInserindo 250 na posição 1\n");
    inserir_posicao(&lista, 1, 250);
    mostrar_lista(&lista);
    
    // Busca
    int valor = 250;
    int posicao = buscar(&lista, valor);
    printf("\nBuscando valor %d: encontrado na posição %d\n", valor, posicao);
    
    // Remoção do início
    printf("\nRemovendo do início: %d\n", remover_inicio(&lista));
    mostrar_lista(&lista);
    
    // Remoção do fim
    printf("\nRemovendo do fim: %d\n", remover_fim(&lista));
    mostrar_lista(&lista);
    
    // Remoção de posição específica
    printf("\nRemovendo da posição 1: %d\n", remover_posicao(&lista, 1));
    mostrar_lista(&lista);
    
    // Liberação de memória
    printf("\nLiberando a lista\n");
    liberar_lista(&lista);
    mostrar_lista(&lista);
    
    return 0;
}
