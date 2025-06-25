#include <stdio.h>
#include <stdbool.h>

/*
 * Bubble Sort:
 * - Compara elementos adjacentes e os troca se estiverem na ordem errada.
 * - A cada passagem, o maior elemento "borbulha" para o final.
 * - Otimização: Se nenhuma troca ocorrer em uma passagem, o array está ordenado.
 *
 * Visualização para array [5, 1, 4, 2, 8]:
 *
 * Passo 1: [1, 5, 4, 2, 8] → Troca (5 > 1)
 *          [1, 4, 5, 2, 8] → Troca (5 > 4)
 *          [1, 4, 2, 5, 8] → Troca (5 > 2)
 *          [1, 4, 2, 5, 8] → Não troca (5 < 8)
 * Passo 2: [1, 2, 4, 5, 8] → Array ordenado (mais passagens verificam a otimização)
 */

// Bubble Sort não-otimizado
void bubbleSort(int *arr, int n) {
    int arr_temp = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n-1; j++) {
            if (arr[j] > arr[j+1]) {
                arr_temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = arr_temp;
            }
        }
    }
}
// Quais pontos poderiam ser otimizados nesse algoritmo?

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

    bubbleSort(arr, n);

    printf("Array ordenado:\n");
    printArray(arr, n);

    return 0;
}
