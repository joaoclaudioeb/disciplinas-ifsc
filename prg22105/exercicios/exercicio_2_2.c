#include <stdio.h>
#define MAX 5

int pilha[MAX];
int topo = -1;

void push(int valor) {
    if (topo == MAX - 1) {
        printf("Pilha cheia!\n");
        return;
    }
    pilha[++topo] = valor;
}

int pop() {
    if (topo == -1) {
        printf("Pilha vazia!\n");
        return -1;
    }
    return pilha[topo--];
}

void imprimir_pilha() {
    printf("Pilha (topo -> base): ");
    for (int i = topo; i >= 0; i--) {
        printf("%d ", pilha[i]);
    }
    printf("\n");
}

int main() {
    push(10);
    push(20);
    push(30);
    pop();
    push(40);
    push(50);
    
    imprimir_pilha();
    return 0;
}
