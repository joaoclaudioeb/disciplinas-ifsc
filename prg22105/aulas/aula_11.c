#include <stdio.h>
#include <stdlib.h>

/*
 * Aula - Listas Duplamente Encadeadas e Circulares
 * Objetivo: apresentar as estruturas de lista duplamente encadeada e lista circular,
 *           e suas operações básicas.
 */

#define PARTE1 1  // Lista Duplamente Encadeada
#define PARTE2 0  // Lista Circular

/*
 * Parte 1 – Lista Duplamente Encadeada
 *         – Cada nó possui ponteiros para o próximo e para o anterior.
 *         – Permite navegação em ambas as direções.
 *
 * Representação visual de uma lista duplamente encadeada:
 *
 *    NULL <-- +-----+-----+ <--> +-----+-----+ <--> +-----+-----+ --> NULL
 *             | 100 |     |      | 200 |     |      | 300 |     |
 *             |     |     |      |     |     |      |     |     |
 *             +-----+-----+      +-----+-----+      +-----+-----+
 *               ^
 *             início
 *
 * Cada nó contém:
 *    - Um dado (ex.: 100, 200, 300)
 *    - Um ponteiro para o próximo nó
 *    - Um ponteiro para o nó anterior
 *
 * Estrutura de um nó:
 *
 *    struct NoDuplo {
 *        int dado;
 *        struct NoDuplo *ant;
 *        struct NoDuplo *prox;
 *    };
 */
#if PARTE1
/* 
 * Estrutura do nó duplo:
 *    +-----+-----+-----+
 *    | ant | dado| prox|
 *    +-----+-----+-----+
 */
typedef struct NoDuplo {
    int dado;
    struct NoDuplo *ant;
    struct NoDuplo *prox;
} NoDuplo;

/* 
 * Estrutura da lista duplamente encadeada:
 *    +------+
 *    | inicio | --> NULL (vazia) ou aponta para o primeiro nó
 *    +------+
 */
typedef struct {
    NoDuplo *inicio;
} ListaDupla;

/* 
 * Função: inicializar_lista_dupla
 * ------------------------------
 * Inicializa a lista com inicio = NULL (vazia).
 */
void inicializar_lista_dupla(ListaDupla *l) {
    l->inicio = NULL;
}

/* 
 * Função: esta_vazia_dupla
 * -----------------------
 * Verifica se a lista está vazia (inicio == NULL).
 */
int esta_vazia_dupla(ListaDupla *l) {
    return l->inicio == NULL;
}

/* 
 * Função: inserir_inicio_dupla
 * ---------------------------
 * Adiciona um novo nó no início da lista duplamente encadeada.
 * 
 * Visualização (inserir_inicio_dupla 100, 200, 300):
 * 
 *    1. inserir_inicio_dupla(100):
 *       NULL <-- +-----+-----+ --> NULL
 *                | 100 |     |
 *                |     |     |
 *                +-----+-----+
 *                  ^
 *                inicio
 * 
 *    2. inserir_inicio_dupla(200):
 *       NULL <-- +-----+-----+ <--> +-----+-----+ --> NULL
 *                | 200 |     |      | 100 |     |
 *                |     |     |      |     |     |
 *                +-----+-----+      +-----+-----+
 *                  ^
 *                inicio
 * 
 *    3. inserir_inicio_dupla(300):
 *       NULL <-- +-----+-----+ <--> +-----+-----+ <--> +-----+-----+ --> NULL
 *                | 300 |     |      | 200 |     |      | 100 |     |
 *                |     |     |      |     |     |      |     |     |
 *                +-----+-----+      +-----+-----+      +-----+-----+
 *                  ^
 *                inicio
 */
void inserir_inicio_dupla(ListaDupla *l, int valor) {
    NoDuplo *novo = malloc(sizeof(NoDuplo));
    if (novo == NULL) {
        printf("Erro ao alocar memória\n");
        return;
    }
    
    novo->dado = valor;
    novo->ant = NULL;
    novo->prox = l->inicio;
    
    if (l->inicio != NULL) {
        l->inicio->ant = novo;
    }
    
    l->inicio = novo;
}

/* 
 * Função: inserir_fim_dupla
 * ------------------------
 * Adiciona um novo nó no fim da lista duplamente encadeada.
 * 
 * Visualização (após inserir_inicio_dupla 300, 200, 100, inserir_fim_dupla 400):
 * 
 *    NULL <-- +-----+-----+ <--> +-----+-----+ <--> +-----+-----+ <--> +-----+-----+ --> NULL
 *             | 300 |     |      | 200 |     |      | 100 |     |      | 400 |     |
 *             |     |     |      |     |     |      |     |     |      |     |     |
 *             +-----+-----+      +-----+-----+      +-----+-----+      +-----+-----+
 *               ^
 *             inicio
 */
void inserir_fim_dupla(ListaDupla *l, int valor) {
    NoDuplo *novo = malloc(sizeof(NoDuplo));
    if (novo == NULL) {
        printf("Erro ao alocar memória\n");
        return;
    }
    
    novo->dado = valor;
    novo->prox = NULL;
    
    if (esta_vazia_dupla(l)) {
        novo->ant = NULL;
        l->inicio = novo;
    } else {
        // Percorre até o último nó
        NoDuplo *atual = l->inicio;
        while (atual->prox != NULL) {
            atual = atual->prox;
        }
        
        atual->prox = novo;
        novo->ant = atual;
    }
}

/* 
 * Função: inserir_posicao_dupla
 * ----------------------------
 * Adiciona um novo nó na posição especificada da lista duplamente encadeada.
 * Posição 0 = início, posição 1 = segundo elemento, etc.
 * 
 * Visualização (após inserir_inicio_dupla 300, 200, 100, inserir_posicao_dupla(1, 250)):
 * 
 *    NULL <-- +-----+-----+ <--> +-----+-----+ <--> +-----+-----+ <--> +-----+-----+ --> NULL
 *             | 300 |     |      | 250 |     |      | 200 |     |      | 100 |     |
 *             |     |     |      |     |     |      |     |     |      |     |     |
 *             +-----+-----+      +-----+-----+      +-----+-----+      +-----+-----+
 *               ^
 *             inicio
 */
void inserir_posicao_dupla(ListaDupla *l, int posicao, int valor) {
    // Se posição for 0, insere no início
    if (posicao == 0) {
        inserir_inicio_dupla(l, valor);
        return;
    }
    
    // Verifica se a lista está vazia
    if (esta_vazia_dupla(l)) {
        printf("Lista vazia, impossível inserir na posição %d\n", posicao);
        return;
    }
    
    // Cria o novo nó
    NoDuplo *novo = malloc(sizeof(NoDuplo));
    if (novo == NULL) {
        printf("Erro ao alocar memória\n");
        return;
    }
    novo->dado = valor;
    
    // Percorre até a posição desejada
    NoDuplo *atual = l->inicio;
    int i = 0;
    while (i < posicao - 1 && atual->prox != NULL) {
        atual = atual->prox;
        i++;
    }
    
    // Verifica se a posição é válida
    if (i < posicao - 1) {
        printf("Posição %d inválida, inserindo no fim\n", posicao);
        novo->prox = NULL;
        novo->ant = atual;
        atual->prox = novo;
    } else {
        // Insere na posição desejada
        novo->prox = atual->prox;
        novo->ant = atual;
        
        if (atual->prox != NULL) {
            atual->prox->ant = novo;
        }
        
        atual->prox = novo;
    }
}

/* 
 * Função: remover_inicio_dupla
 * ---------------------------
 * Remove o nó do início da lista duplamente encadeada e retorna seu valor.
 * 
 * Visualização (após inserir_inicio_dupla 300, 200, 100):
 * 
 *    1. remover_inicio_dupla() → 300:
 *       NULL <-- +-----+-----+ <--> +-----+-----+ --> NULL
 *                | 200 |     |      | 100 |     |
 *                |     |     |      |     |     |
 *                +-----+-----+      +-----+-----+
 *                  ^
 *                inicio
 */
int remover_inicio_dupla(ListaDupla *l) {
    if (esta_vazia_dupla(l)) {
        printf("Lista vazia, impossível remover do início\n");
        return -1;
    }
    
    NoDuplo *remover = l->inicio;
    int valor = remover->dado;
    
    l->inicio = remover->prox;
    
    if (l->inicio != NULL) {
        l->inicio->ant = NULL;
    }
    
    free(remover);
    return valor;
}

/* 
 * Função: remover_fim_dupla
 * ------------------------
 * Remove o nó do fim da lista duplamente encadeada e retorna seu valor.
 * 
 * Visualização (após inserir_inicio_dupla 300, 200, 100):
 * 
 *    1. remover_fim_dupla() → 100:
 *       NULL <-- +-----+-----+ <--> +-----+-----+ --> NULL
 *                | 300 |     |      | 200 |     |
 *                |     |     |      |     |     |
 *                +-----+-----+      +-----+-----+
 *                  ^
 *                inicio
 */
int remover_fim_dupla(ListaDupla *l) {
    if (esta_vazia_dupla(l)) {
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
    
    // Percorre até o último nó
    NoDuplo *atual = l->inicio;
    while (atual->prox != NULL) {
        atual = atual->prox;
    }
    
    int valor = atual->dado;
    atual->ant->prox = NULL;
    free(atual);
    
    return valor;
}

/* 
 * Função: remover_posicao_dupla
 * ----------------------------
 * Remove o nó da posição especificada da lista duplamente encadeada e retorna seu valor.
 * Posição 0 = início, posição 1 = segundo elemento, etc.
 * 
 * Visualização (após inserir_inicio_dupla 300, 200, 100):
 * 
 *    1. remover_posicao_dupla(1) → 200:
 *       NULL <-- +-----+-----+ <--> +-----+-----+ --> NULL
 *                | 300 |     |      | 100 |     |
 *                |     |     |      |     |     |
 *                +-----+-----+      +-----+-----+
 *                  ^
 *                inicio
 */
int remover_posicao_dupla(ListaDupla *l, int posicao) {
    // Se posição for 0, remove do início
    if (posicao == 0) {
        return remover_inicio_dupla(l);
    }
    
    // Verifica se a lista está vazia
    if (esta_vazia_dupla(l)) {
        printf("Lista vazia, impossível remover da posição %d\n", posicao);
        return -1;
    }
    
    // Percorre até a posição desejada
    NoDuplo *atual = l->inicio;
    int i = 0;
    while (i < posicao && atual != NULL) {
        atual = atual->prox;
        i++;
    }
    
    // Verifica se a posição é válida
    if (atual == NULL) {
        printf("Posição %d inválida\n", posicao);
        return -1;
    }
    
    // Remove o nó da posição desejada
    int valor = atual->dado;
    
    if (atual->ant != NULL) {
        atual->ant->prox = atual->prox;
    }
    
    if (atual->prox != NULL) {
        atual->prox->ant = atual->ant;
    }
    
    free(atual);
    return valor;
}

/* 
 * Função: buscar_dupla
 * -------------------
 * Busca um valor na lista duplamente encadeada e retorna sua posição (0-based).
 * Retorna -1 se o valor não for encontrado.
 */
int buscar_dupla(ListaDupla *l, int valor) {
    if (esta_vazia_dupla(l)) {
        return -1;
    }
    
    NoDuplo *atual = l->inicio;
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
 * Função: mostrar_lista_dupla
 * --------------------------
 * Exibe a lista duplamente encadeada do início ao fim (com setas bidirecionais).
 */
void mostrar_lista_dupla(ListaDupla *l) {
    printf("Lista Dupla: NULL <--> ");
    NoDuplo *atual = l->inicio;
    while (atual != NULL) {
        printf("%d <--> ", atual->dado);
        atual = atual->prox;
    }
    printf("NULL\n");
}

/* 
 * Função: liberar_lista_dupla
 * --------------------------
 * Desaloca todos os nós da lista duplamente encadeada para evitar vazamento de memória.
 */
void liberar_lista_dupla(ListaDupla *l) {
    NoDuplo *atual = l->inicio;
    while (atual != NULL) {
        NoDuplo *prox = atual->prox;
        free(atual);
        atual = prox;
    }
    l->inicio = NULL;
}
#endif

/*
 * Parte 2 – Lista Circular
 *         – O último nó aponta para o primeiro, formando um ciclo.
 *         – Pode ser simplesmente ou duplamente encadeada.
 *
 * Representação visual de uma lista circular simplesmente encadeada:
 *
 *    +-----+      +-----+      +-----+
 *    | 100 | ---> | 200 | ---> | 300 |
 *    +-----+      +-----+      +-----+
 *      ^                          |
 *      |                          |
 *      +---------------------------+
 *
 * Representação visual de uma lista circular duplamente encadeada:
 *
 *    +-----+      +-----+      +-----+
 *    | 100 | <--> | 200 | <--> | 300 |
 *    +-----+      +-----+      +-----+
 *      ^  ^                      |  |
 *      |  |                      |  |
 *      |  +----------------------+  |
 *      +-----------------------------+
 */
#if PARTE2
/* 
 * Estrutura do nó circular:
 *    +-----+-----+
 *    | dado| prox|
 *    +-----+-----+
 */
typedef struct NoCircular {
    int dado;
    struct NoCircular *prox;
} NoCircular;

/* 
 * Estrutura da lista circular:
 *    +------+
 *    | inicio | --> NULL (vazia) ou aponta para o primeiro nó
 *    +------+
 */
typedef struct {
    NoCircular *inicio;
} ListaCircular;

/* 
 * Função: inicializar_lista_circular
 * ---------------------------------
 * Inicializa a lista circular com inicio = NULL (vazia).
 */
void inicializar_lista_circular(ListaCircular *l) {
    l->inicio = NULL;
}

/* 
 * Função: esta_vazia_circular
 * --------------------------
 * Verifica se a lista circular está vazia (inicio == NULL).
 */
int esta_vazia_circular(ListaCircular *l) {
    return l->inicio == NULL;
}

/* 
 * Função: inserir_inicio_circular
 * ------------------------------
 * Adiciona um novo nó no início da lista circular.
 * 
 * Visualização (inserir_inicio_circular 100, 200, 300):
 * 
 *    1. inserir_inicio_circular(100):
 *       +-----+
 *       | 100 |
 *       +-----+
 *         ^ |
 *         +-+
 *       inicio
 * 
 *    2. inserir_inicio_circular(200):
 *       +-----+      +-----+
 *       | 200 | ---> | 100 |
 *       +-----+      +-----+
 *         ^            |
 *         |            |
 *         +------------+
 *       inicio
 * 
 *    3. inserir_inicio_circular(300):
 *       +-----+      +-----+      +-----+
 *       | 300 | ---> | 200 | ---> | 100 |
 *       +-----+      +-----+      +-----+
 *         ^                          |
 *         |                          |
 *         +---------------------------+
 *       inicio
 */
void inserir_inicio_circular(ListaCircular *l, int valor) {
    NoCircular *novo = malloc(sizeof(NoCircular));
    if (novo == NULL) {
        printf("Erro ao alocar memória\n");
        return;
    }
    
    novo->dado = valor;
    
    if (esta_vazia_circular(l)) {
        novo->prox = novo; // Aponta para si mesmo
        l->inicio = novo;
    } else {
        // Encontra o último nó
        NoCircular *ultimo = l->inicio;
        while (ultimo->prox != l->inicio) {
            ultimo = ultimo->prox;
        }
        
        novo->prox = l->inicio;
        ultimo->prox = novo;
        l->inicio = novo;
    }
}

/* 
 * Função: inserir_fim_circular
 * ---------------------------
 * Adiciona um novo nó no fim da lista circular.
 * 
 * Visualização (após inserir_inicio_circular 300, 200, 100, inserir_fim_circular 400):
 * 
 *    +-----+      +-----+      +-----+      +-----+
 *    | 300 | ---> | 200 | ---> | 100 | ---> | 400 |
 *    +-----+      +-----+      +-----+      +-----+
 *      ^                                       |
 *      |                                       |
 *      +---------------------------------------+
 *    inicio
 */
void inserir_fim_circular(ListaCircular *l, int valor) {
    NoCircular *novo = malloc(sizeof(NoCircular));
    if (novo == NULL) {
        printf("Erro ao alocar memória\n");
        return;
    }
    
    novo->dado = valor;
    
    if (esta_vazia_circular(l)) {
        novo->prox = novo; // Aponta para si mesmo
        l->inicio = novo;
    } else {
        // Encontra o último nó
        NoCircular *ultimo = l->inicio;
        while (ultimo->prox != l->inicio) {
            ultimo = ultimo->prox;
        }
        
        novo->prox = l->inicio;
        ultimo->prox = novo;
    }
}

/* 
 * Função: remover_inicio_circular
 * ------------------------------
 * Remove o nó do início da lista circular e retorna seu valor.
 * 
 * Visualização (após inserir_inicio_circular 300, 200, 100):
 * 
 *    1. remover_inicio_circular() → 300:
 *       +-----+      +-----+
 *       | 200 | ---> | 100 |
 *       +-----+      +-----+
 *         ^            |
 *         |            |
 *         +------------+
 *       inicio
 */
int remover_inicio_circular(ListaCircular *l) {
    if (esta_vazia_circular(l)) {
        printf("Lista vazia, impossível remover do início\n");
        return -1;
    }
    
    int valor = l->inicio->dado;
    
    // Se há apenas um elemento
    if (l->inicio->prox == l->inicio) {
        free(l->inicio);
        l->inicio = NULL;
    } else {
        // Encontra o último nó
        NoCircular *ultimo = l->inicio;
        while (ultimo->prox != l->inicio) {
            ultimo = ultimo->prox;
        }
        
        NoCircular *remover = l->inicio;
        l->inicio = remover->prox;
        ultimo->prox = l->inicio;
        free(remover);
    }
    
    return valor;
}

/* 
 * Função: remover_fim_circular
 * ---------------------------
 * Remove o nó do fim da lista circular e retorna seu valor.
 * 
 * Visualização (após inserir_inicio_circular 300, 200, 100):
 * 
 *    1. remover_fim_circular() → 100:
 *       +-----+      +-----+
 *       | 300 | ---> | 200 |
 *       +-----+      +-----+
 *         ^            |
 *         |            |
 *         +------------+
 *       inicio
 */
int remover_fim_circular(ListaCircular *l) {
    if (esta_vazia_circular(l)) {
        printf("Lista vazia, impossível remover do fim\n");
        return -1;
    }
    
    // Se há apenas um elemento
    if (l->inicio->prox == l->inicio) {
        int valor = l->inicio->dado;
        free(l->inicio);
        l->inicio = NULL;
        return valor;
    }
    
    // Encontra o penúltimo nó
    NoCircular *penultimo = l->inicio;
    while (penultimo->prox->prox != l->inicio) {
        penultimo = penultimo->prox;
    }
    
    NoCircular *ultimo = penultimo->prox;
    int valor = ultimo->dado;
    
    penultimo->prox = l->inicio;
    free(ultimo);
    
    return valor;
}

/* 
 * Função: buscar_circular
 * ----------------------
 * Busca um valor na lista circular e retorna sua posição (0-based).
 * Retorna -1 se o valor não for encontrado.
 */
int buscar_circular(ListaCircular *l, int valor) {
    if (esta_vazia_circular(l)) {
        return -1;
    }
    
    NoCircular *atual = l->inicio;
    int posicao = 0;
    
    do {
        if (atual->dado == valor) {
            return posicao;
        }
        atual = atual->prox;
        posicao++;
    } while (atual != l->inicio);
    
    return -1; // Valor não encontrado
}

/* 
 * Função: mostrar_lista_circular
 * -----------------------------
 * Exibe a lista circular do início, dando uma volta completa (com setas).
 */
void mostrar_lista_circular(ListaCircular *l) {
    if (esta_vazia_circular(l)) {
        printf("Lista Circular: [vazia]\n");
        return;
    }
    
    printf("Lista Circular: ");
    NoCircular *atual = l->inicio;
    
    do {
        printf("%d -> ", atual->dado);
        atual = atual->prox;
    } while (atual != l->inicio);
    
    printf("[volta ao início: %d]\n", l->inicio->dado);
}

/* 
 * Função: liberar_lista_circular
 * -----------------------------
 * Desaloca todos os nós da lista circular para evitar vazamento de memória.
 */
void liberar_lista_circular(ListaCircular *l) {
    if (esta_vazia_circular(l)) {
        return;
    }
    
    NoCircular *atual = l->inicio->prox;
    NoCircular *prox;
    
    // Se há apenas um elemento
    if (atual == l->inicio) {
        free(l->inicio);
        l->inicio = NULL;
        return;
    }
    
    // Libera todos os nós exceto o primeiro
    while (atual != l->inicio) {
        prox = atual->prox;
        free(atual);
        atual = prox;
    }
    
    // Libera o primeiro nó
    free(l->inicio);
    l->inicio = NULL;
}
#endif

int main() {

#if PARTE1
    printf("\n===== LISTA DUPLAMENTE ENCADEADA =====\n\n");
    
    ListaDupla lista_dupla;
    inicializar_lista_dupla(&lista_dupla);
    
    // Inserções no início
    printf("Inserindo no início: 100, 200, 300\n");
    inserir_inicio_dupla(&lista_dupla, 100);
    inserir_inicio_dupla(&lista_dupla, 200);
    inserir_inicio_dupla(&lista_dupla, 300);
    mostrar_lista_dupla(&lista_dupla);
    
    // Inserção no fim
    printf("\nInserindo no fim: 400\n");
    inserir_fim_dupla(&lista_dupla, 400);
    mostrar_lista_dupla(&lista_dupla);
    
    // Inserção em posição específica
    printf("\nInserindo 250 na posição 1\n");
    inserir_posicao_dupla(&lista_dupla, 1, 250);
    mostrar_lista_dupla(&lista_dupla);
    
    // Busca
    int valor = 250;
    int posicao = buscar_dupla(&lista_dupla, valor);
    printf("\nBuscando valor %d: encontrado na posição %d\n", valor, posicao);
    
    // Remoção do início
    printf("\nRemovendo do início: %d\n", remover_inicio_dupla(&lista_dupla));
    mostrar_lista_dupla(&lista_dupla);
    
    // Remoção do fim
    printf("\nRemovendo do fim: %d\n", remover_fim_dupla(&lista_dupla));
    mostrar_lista_dupla(&lista_dupla);
    
    // Remoção de posição específica
    printf("\nRemovendo da posição 1: %d\n", remover_posicao_dupla(&lista_dupla, 1));
    mostrar_lista_dupla(&lista_dupla);
    
    // Liberação de memória
    printf("\nLiberando a lista duplamente encadeada\n");
    liberar_lista_dupla(&lista_dupla);
    mostrar_lista_dupla(&lista_dupla);
#endif

#if PARTE2
    printf("\n===== LISTA CIRCULAR =====\n\n");
    
    ListaCircular lista_circular;
    inicializar_lista_circular(&lista_circular);
    
    // Inserções no início
    printf("Inserindo no início: 100, 200, 300\n");
    inserir_inicio_circular(&lista_circular, 100);
    inserir_inicio_circular(&lista_circular, 200);
    inserir_inicio_circular(&lista_circular, 300);
    mostrar_lista_circular(&lista_circular);
    
    // Inserção no fim
    printf("\nInserindo no fim: 400\n");
    inserir_fim_circular(&lista_circular, 400);
    mostrar_lista_circular(&lista_circular);
    
    // Busca
    valor = 200;
    posicao = buscar_circular(&lista_circular, valor);
    printf("\nBuscando valor %d: encontrado na posição %d\n", valor, posicao);
    
    // Remoção do início
    printf("\nRemovendo do início: %d\n", remover_inicio_circular(&lista_circular));
    mostrar_lista_circular(&lista_circular);
    
    // Remoção do fim
    printf("\nRemovendo do fim: %d\n", remover_fim_circular(&lista_circular));
    mostrar_lista_circular(&lista_circular);
    
    // Liberação de memória
    printf("\nLiberando a lista circular\n");
    liberar_lista_circular(&lista_circular);
    mostrar_lista_circular(&lista_circular);
#endif

    return 0;
}
