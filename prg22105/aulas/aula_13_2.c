#include <stdio.h>

/*
 * Selection Sort:
 * - Divide o array em uma parte ordenada (esquerda) e não ordenada (direita).
 * - A cada iteração, seleciona o menor elemento da parte não ordenada e o move para o final da parte ordenada.
 *
 * Visualização para array [5, 1, 4, 2, 8]:
 *
 * Passo 1: [1, 5, 4, 2, 8] → Menor elemento (1) trocado com a posição 0.
 * Passo 2: [1, 2, 4, 5, 8] → Menor elemento (2) trocado com a posição 1.
 * Passo 3: [1, 2, 4, 5, 8] → Array já ordenado.
 */

void selectionSort(int *arr, int n) {
    for (int i = 0; i < n-1; i++) {
        int min_idx = i;
        // Encontra o índice do menor elemento na parte não ordenada
        for (int j = i+1; j < n; j++)
            if (arr[j] < arr[min_idx])
                min_idx = j;
            
        // Troca o menor elemento com o primeiro da parte não ordenada
        int temp = arr[i];
        arr[i] = arr[min_idx];
        arr[min_idx] = temp;
    }
}

// Função para imprimir o array
void printArray(int *arr, int size) {
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(arr)/sizeof(arr[0]);

    printf("Array original:\n");
    printArray(arr, n);

    selectionSort(arr, n);

    printf("Array ordenado:\n");
    printArray(arr, n);

    return 0;
    
}
