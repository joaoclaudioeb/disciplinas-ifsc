#include <stdio.h>
#include <stdlib.h>

/*
 * Aula 7 – Pilhas Estáticas e Dinâmicas
 * Objetivo: apresentar a estrutura de pilha em memória estática (vetor) e dinâmica (lista encadeada).
 */

#define PARTE1 0  // Pilha Estática
#define PARTE2 1  // Pilha Dinâmica

/*
 * Parte 1 – Pilha Estática
 *         – Utiliza um vetor fixo para armazenar os elementos.
 *         – LIFO: Last in, first out (último a entrar, primeiro a sair).
 */
#if PARTE1
#define TAM 5 // Capacidade máxima da pilha

typedef struct {
    int dados[TAM];  // Armazena os elementos
    int topo;        // Índice do topo (-1 = "pilha vazia")
} PilhaEstatica;

/* 
 * Função: inicializar_pilha_estatica
 * ----------------------------------
 * Prepara a pilha para uso, definindo topo = -1 ("vazia").
 * 
 * Visualização:
 * 
 *    dados: [ ?,  ?,  ?,  ?,  ? ]  (lixo de memória)
 *    topo: -1
 */
void inicializar_pilha_estatica(PilhaEstatica *p) {
    p->topo = -1;
}

/* 
 * Função: esta_vazia_estatica
 * ---------------------------
 * Verifica se a pilha está vazia (topo == -1).
 */
int esta_vazia_estatica(PilhaEstatica *p) {
    return p->topo == -1;
}

/* 
 * Função: esta_cheia_estatica
 * ---------------------------
 * Verifica se a pilha está cheia (topo == TAM - 1).
 */
int esta_cheia_estatica(PilhaEstatica *p) {
    return p->topo == TAM - 1;
}

/* 
 * Função: push_estatica
 * ---------------------
 * Adiciona um elemento no topo da pilha.
 * 
 * Visualização (push 10, 20, 30):
 * 
 *    1. push(10):
 *       dados: [10,  ?,  ?,  ?,  ? ]
 *       topo: 0
 *    2. push(20):
 *       dados: [10, 20,  ?,  ?,  ? ]
 *       topo: 1
 *    3. push(30):
 *       dados: [10, 20, 30,  ?,  ? ]
 *       topo: 2
 */
void push_estatica(PilhaEstatica *p, int valor) {
    if (esta_cheia_estatica(p)) {
        printf("Pilha estática cheia!\n");
        return;
    }
    p->dados[++(p->topo)] = valor; // ++topo ANTES de usar
}

/* 
 * Função: pop_estatica
 * --------------------
 * Remove e retorna o elemento do topo.
 * 
 * Visualização (após push 10, 20, 30):
 * 
 *    1. pop() → 30:
 *       dados: [10, 20, 30,  ?,  ? ]  (30 ainda na memória, mas inacessível)
 *       topo: 1
 */
int pop_estatica(PilhaEstatica *p) {
    if (esta_vazia_estatica(p)) {
        printf("Pilha estática vazia!\n");
        return -1;
    }
    return p->dados[(p->topo)--]; // topo-- DEPOIS de usar
}

/* 
 * Função: mostrar_pilha_estatica
 * -----------------------------
 * Exibe a pilha do topo para a base.
 */
void mostrar_pilha_estatica(PilhaEstatica *p) {
    printf("Pilha Estática: [ ");
    for (int i = p->topo; i >= 0; i--) {
        if(i>0)
            printf("%d, ", p->dados[i]);
        else
            printf("%d ]", p->dados[i]);
    }
    printf("\n");
}
#endif

/*
 * Parte 2 – Pilha Dinâmica
 *         – Utiliza alocação dinâmica de memória (struct com ponteiros).
 *         – Cresce e diminui conforme as inserções e remoções.
 *
 * Representação visual de uma pilha dinâmica:
 *
 *    +-----+      +-----+      +-----+
 *    | 300 | ---> | 200 | ---> | 100 |
 *    +-----+      +-----+      +-----+
 *     topo
 *
 * Cada nó contém:
 *    - Um dado (ex.: 300, 200, 100)
 *    - Um ponteiro para o próximo nó
 * Quando um elemento é inserido (push), ele se torna o novo topo.
 * Quando um elemento é removido (pop), o topo é desalocado e o ponteiro anda para o próximo.
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
 * Estrutura da pilha:
 *    +------+
 *    | topo | --> NULL (vazia) ou aponta para o nó do topo
 *    +------+
 */
typedef struct {
    No *topo;
} PilhaDinamica;

/* 
 * Função: inicializar_pilha_dinamica
 * ---------------------------------
 * Inicializa a pilha com topo = NULL (vazia).
 */
void inicializar_pilha_dinamica(PilhaDinamica *p) {
    p->topo = NULL;
}

/* 
 * Função: esta_vazia_dinamica
 * ---------------------------
 * Verifica se a pilha está vazia (topo == NULL).
 */
int esta_vazia_dinamica(PilhaDinamica *p) {
    return p->topo == NULL;
}

/* 
 * Função: push_dinamica
 * ---------------------
 * Adiciona um novo nó no topo da pilha.
 * 
 * Visualização (push 100, 200, 300):
 * 
 *    1. push(100):
 *       +-----+-----+
 *       | 100 | NULL|
 *       +-----+-----+
 *         ^
 *        topo
 * 
 *    2. push(200):
 *       +-----+-----+    +-----+-----+
 *       | 200 |  ---|--> | 100 | NULL|
 *       +-----+-----+    +-----+-----+
 *         ^
 *        topo
 * 
 *    3. push(300):
 *       +-----+-----+    +-----+-----+    +-----+-----+
 *       | 300 |  ---|--> | 200 |  ---|--> | 100 | NULL|
 *       +-----+-----+    +-----+-----+    +-----+-----+
 *         ^
 *        topo
 */
void push_dinamica(PilhaDinamica *p, int valor) {
    No *novo = malloc(sizeof(No));
    if (novo == NULL) {
        printf("Erro ao alocar memória\n");
        return;
    }
    novo->dado = valor;
    novo->prox = p->topo; // Novo nó aponta para o antigo topo
    p->topo = novo;       // Topo agora é o novo nó
}

/* 
 * Função: pop_dinamica
 * --------------------
 * Remove o nó do topo e retorna seu valor.
 * 
 * Visualização (após push 100, 200, 300):
 * 
 *    1. pop() → 300:
 *       +-----+-----+    +-----+-----+
 *       | 200 |  ---|--> | 100 | NULL|
 *       +-----+-----+    +-----+-----+
 *         ^
 *        topo
 */
int pop_dinamica(PilhaDinamica *p) {
    if (esta_vazia_dinamica(p)) {
        printf("Pilha dinâmica vazia!\n");
        return -1;
    }
    No *remover = p->topo;
    int valor = remover->dado;
    p->topo = remover->prox; // Topo agora é o próximo nó
    free(remover);           // Libera memória do nó removido
    return valor;
}

/* 
 * Função: mostrar_pilha_dinamica
 * -----------------------------
 * Exibe a pilha do topo para a base (com setas).
 */
void mostrar_pilha_dinamica(PilhaDinamica *p) {
    printf("Pilha Dinâmica: TOPO -> ");
    No *atual = p->topo;
    while (atual != NULL) {
        printf("%d -> ", atual->dado);
        atual = atual->prox;
    }
    printf("NULL\n");
}

/* 
 * Função: liberar_pilha_dinamica
 * -----------------------------
 * Desaloca todos os nós da pilha para evitar vazamento de memória.
 */
void liberar_pilha_dinamica(PilhaDinamica *p) {
    No *atual = p->topo;
    while (atual != NULL) {
        No *prox = atual->prox; // Guarda referência para o próximo
        free(atual);            // Libera o nó atual 
        atual = prox;           // Avança para o próximo
    }
    p->topo = NULL;             // Pilha vazia
}
#endif

int main() {

#if PARTE1
    PilhaEstatica pilha;
    inicializar_pilha_estatica(&pilha);

    push_estatica(&pilha, 10);
    push_estatica(&pilha, 20);
    push_estatica(&pilha, 30);
    mostrar_pilha_estatica(&pilha);
    printf("Desempilhado: %d\n", pop_estatica(&pilha));
    mostrar_pilha_estatica(&pilha);
#endif

#if PARTE2
    PilhaDinamica pilha;
    inicializar_pilha_dinamica(&pilha);

    push_dinamica(&pilha, 100);
    push_dinamica(&pilha, 200);
    push_dinamica(&pilha, 300);
    mostrar_pilha_dinamica(&pilha);
    printf("Desempilhado: %d\n", pop_dinamica(&pilha));
    mostrar_pilha_dinamica(&pilha);

    liberar_pilha_dinamica(&pilha);
#endif

    return 0;
}
