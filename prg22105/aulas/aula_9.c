#include <stdio.h>
#include <stdlib.h>

/*
 * Aula 8 – Filas Estáticas e Dinâmicas
 * Objetivo: apresentar a estrutura de fila em memória estática (vetor) e dinâmica (lista encadeada).
 */

#define PARTE1 0  // Fila Estática
#define PARTE2 1  // Fila Dinâmica

/*
 * Parte 1 – Fila Estática
 *         – Utiliza um vetor fixo para armazenar os elementos.
 *         – FIFO: First in, first out (primeiro a entrar, primeiro a sair).
 */
#if PARTE1
#define TAM 5 // Capacidade máxima da fila

typedef struct {
    int dados[TAM];  // Armazena os elementos
    int inicio;      // Índice do primeiro elemento
    int fim;         // Índice do último elemento (-1 = "fila vazia")
} FilaEstatica;

/* 
 * Função: inicializar_fila_estatica
 * ---------------------------------
 * Prepara a fila para uso, definindo inicio = 0 e fim = -1 ("vazia").
 * 
 * Visualização:
 * 
 *    dados: [ ?,  ?,  ?,  ?,  ? ]  (lixo de memória)
 *    inicio: 0
 *    fim: -1
 */
void inicializar_fila_estatica(FilaEstatica *f) {
    f->inicio = 0;
    f->fim = -1;
}

/* 
 * Função: esta_vazia_estatica
 * ---------------------------
 * Verifica se a fila está vazia (fim == -1).
 */
int esta_vazia_estatica(FilaEstatica *f) {
    return f->fim == -1;
}

/* 
 * Função: esta_cheia_estatica
 * ---------------------------
 * Verifica se a fila está cheia (fim == TAM - 1).
 */
int esta_cheia_estatica(FilaEstatica *f) {
    return f->fim == TAM - 1;
}

/* 
 * Função: enfileirar_estatica
 * ---------------------------
 * Adiciona um elemento no final da fila.
 * 
 * Visualização (enfileirar 10, 20, 30):
 * 
 *    1. enfileirar(10):
 *       dados: [10,  ?,  ?,  ?,  ? ]
 *       inicio: 0
 *       fim: 0
 *    2. enfileirar(20):
 *       dados: [10, 20,  ?,  ?,  ? ]
 *       inicio: 0
 *       fim: 1
 *    3. enfileirar(30):
 *       dados: [10, 20, 30,  ?,  ? ]
 *       inicio: 0
 *       fim: 2
 */
void enfileirar_estatica(FilaEstatica *f, int valor) {
    if (esta_cheia_estatica(f)) {
        printf("Fila estática cheia!\n");
        return;
    }
    f->dados[++(f->fim)] = valor; // ++fim ANTES de usar
}

/* 
 * Função: desenfileirar_estatica
 * -----------------------------
 * Remove e retorna o elemento do início da fila.
 * 
 * Visualização (após enfileirar 10, 20, 30):
 * 
 *    1. desenfileirar() → 10:
 *       dados: [10, 20, 30,  ?,  ? ]  (10 ainda na memória, mas inacessível)
 *       inicio: 1
 *       fim: 2
 */
int desenfileirar_estatica(FilaEstatica *f) {
    if (esta_vazia_estatica(f)) {
        printf("Fila estática vazia!\n");
        return -1;
    }
    int valor = f->dados[f->inicio];
    
    // Move todos os elementos uma posição para frente
    for (int i = 0; i < f->fim; i++) {
        f->dados[i] = f->dados[i+1];
    }
    f->fim--;
    
    return valor;
}

/* 
 * Função: mostrar_fila_estatica
 * ----------------------------
 * Exibe a fila do início ao fim.
 */
void mostrar_fila_estatica(FilaEstatica *f) {
    printf("Fila Estática: [ ");
    for (int i = f->inicio; i <= f->fim; i++) {
        if(i < f->fim)
            printf("%d, ", f->dados[i]);
        else
            printf("%d ]", f->dados[i]);
    }
    printf("\n");
}
#endif

/*
 * Parte 2 – Fila Dinâmica
 *         – Utiliza alocação dinâmica de memória (struct com ponteiros).
 *         – Cresce e diminui conforme as inserções e remoções.
 *
 * Representação visual de uma fila dinâmica:
 *
 *    +-----+      +-----+      +-----+
 *    | 100 | ---> | 200 | ---> | 300 |
 *    +-----+      +-----+      +-----+
 *     inicio                   fim
 *
 * Cada nó contém:
 *    - Um dado (ex.: 100, 200, 300)
 *    - Um ponteiro para o próximo nó
 * Quando um elemento é inserido (enfileirar), ele se torna o novo fim.
 * Quando um elemento é removido (desenfileirar), o início é desalocado e o ponteiro anda para o próximo.
 *
 * Estrutura de um nó:
 *
 *    struct No {
 *        int dado;
 *        struct No *prox;
 *    };
 */
#if PARTE2
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
 * Estrutura da fila:
 *    +---------+---------+
 *    | inicio  | fim     | --> NULL (vazia) ou apontam para os nós
 *    +---------+---------+
 */
typedef struct {
    No *inicio;
    No *fim;
} FilaDinamica;

/* 
 * Função: inicializar_fila_dinamica
 * --------------------------------
 * Inicializa a fila com inicio = fim = NULL (vazia).
 */
void inicializar_fila_dinamica(FilaDinamica *f) {
    f->inicio = NULL;
    f->fim = NULL;
}

/* 
 * Função: esta_vazia_dinamica
 * ---------------------------
 * Verifica se a fila está vazia (inicio == NULL).
 */
int esta_vazia_dinamica(FilaDinamica *f) {
    return f->inicio == NULL;
}

/* 
 * Função: enfileirar_dinamica
 * --------------------------
 * Adiciona um novo nó no fim da fila.
 * 
 * Visualização (enfileirar 100, 200, 300):
 * 
 *    1. enfileirar(100):
 *       +-----+-----+
 *       | 100 | NULL|
 *       +-----+-----+
 *       ^     ^
 *    inicio  fim
 * 
 *    2. enfileirar(200):
 *       +-----+-----+    +-----+-----+
 *       | 100 |  ---|--> | 200 | NULL|
 *       +-----+-----+    +-----+-----+
 *         ^              ^
 *      inicio           fim
 * 
 *    3. enfileirar(300):
 *       +-----+-----+    +-----+-----+    +-----+-----+
 *       | 100 |  ---|--> | 200 |  ---|--> | 300 | NULL|
 *       +-----+-----+    +-----+-----+    +-----+-----+
 *         ^                               ^
 *      inicio                            fim
 */
void enfileirar_dinamica(FilaDinamica *f, int valor) {
    No *novo = malloc(sizeof(No));
    if (novo == NULL) {
        printf("Erro ao alocar memória\n");
        return;
    }
    novo->dado = valor;
    novo->prox = NULL;
    
    if (esta_vazia_dinamica(f)) {
        f->inicio = novo;
    } else {
        f->fim->prox = novo;
    }
    f->fim = novo;
}

/* 
 * Função: desenfileirar_dinamica
 * ------------------------------
 * Remove o nó do início e retorna seu valor.
 * 
 * Visualização (após enfileirar 100, 200, 300):
 * 
 *    1. desenfileirar() → 100:
 *       +-----+-----+    +-----+-----+
 *       | 200 |  ---|--> | 300 | NULL|
 *       +-----+-----+    +-----+-----+
 *       ^                ^
 *    inicio             fim
 */
int desenfileirar_dinamica(FilaDinamica *f) {
    if (esta_vazia_dinamica(f)) {
        printf("Fila dinâmica vazia!\n");
        return -1;
    }
    No *remover = f->inicio;
    int valor = remover->dado;
    
    f->inicio = remover->prox;
    if (f->inicio == NULL) { // Se ficou vazia
        f->fim = NULL;
    }
    
    free(remover);           // Libera memória do nó removido
    return valor;
}

/* 
 * Função: mostrar_fila_dinamica
 * ----------------------------
 * Exibe a fila do início ao fim (com setas).
 */
void mostrar_fila_dinamica(FilaDinamica *f) {
    printf("Fila Dinâmica: INÍCIO -> ");
    No *atual = f->inicio;
    while (atual != NULL) {
        printf("%d -> ", atual->dado);
        atual = atual->prox;
    }
    printf("FIM\n");
}

/* 
 * Função: liberar_fila_dinamica
 * ----------------------------
 * Desaloca todos os nós da fila para evitar vazamento de memória.
 */
void liberar_fila_dinamica(FilaDinamica *f) {
    No *atual = f->inicio;
    while (atual != NULL) {
        No *prox = atual->prox; // Guarda referência para o próximo
        free(atual);            // Libera o nó atual 
        atual = prox;           // Avança para o próximo
    }
    f->inicio = NULL;           // Fila vazia
    f->fim = NULL;
}
#endif

int main() {

#if PARTE1
    FilaEstatica fila;
    inicializar_fila_estatica(&fila);

    enfileirar_estatica(&fila, 10);
    enfileirar_estatica(&fila, 20);
    enfileirar_estatica(&fila, 30);
    mostrar_fila_estatica(&fila);
    printf("Desenfileirado: %d\n", desenfileirar_estatica(&fila));
    mostrar_fila_estatica(&fila);
#endif

#if PARTE2
    FilaDinamica fila;
    inicializar_fila_dinamica(&fila);

    enfileirar_dinamica(&fila, 100);
    enfileirar_dinamica(&fila, 200);
    enfileirar_dinamica(&fila, 300);
    mostrar_fila_dinamica(&fila);
    printf("Desenfileirado: %d\n", desenfileirar_dinamica(&fila));
    mostrar_fila_dinamica(&fila);

    liberar_fila_dinamica(&fila);
#endif

    return 0;
}
