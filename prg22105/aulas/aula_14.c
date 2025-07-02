#include <stdio.h>
#include <stdbool.h>

// ===============================
// Escolha o tipo de partição:
// ===============================
// Defina LOMUTO para usar Lomuto Partition
// Defina HOARE  para usar Hoare Partition
// #define HOARE
#define LOMUTO

/*
 * Quick Sort:
 * - Algoritmo "Divide and Conquer"
 * - Escolhe um pivô e reorganiza os elementos em torno dele
 * - Aplica-se recursivamente às partições à esquerda e à direita do pivô
 *
 * O funcionamento da quickSort é o mesmo.
 * O que muda é a forma de "particionar" o array.
 */

/* 
 * 🔹 Lomuto Partition:
 * - Pivô = último elemento
 * - i rastreia a posição de inserção de elementos menores
 * - j percorre o array e compara com o pivô
 * - Troca elementos menores com i
 * - Simples, mas menos eficiente para alguns padrões
 *
 * Exemplo:
 * Array: [10, 80, 30, 90, 40, 50, 70]
 * Pivô = 70
 * Resultado após partição: [10, 30, 40, 50, 70, 90, 80]
 */
int lomutoPartition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            int tmp = arr[i];
            arr[i] = arr[j];
            arr[j] = tmp;
        }
    }

    int tmp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = tmp;

    return i + 1;
}

/*
 * 🔸 Hoare Partition:
 * - Pivô = primeiro elemento
 * - i começa à esquerda e avança até encontrar valor ≥ pivô
 * - j começa à direita e recua até encontrar valor ≤ pivô
 * - Quando i < j, troca os dois
 * - Para quando i ≥ j, e retorna j
 * - Menor número de trocas que Lomuto
 *
 * Exemplo:
 * Array: [5, 3, 8, 4, 2, 7, 1, 10]
 * Pivô = 5
 * Resultado após partição (exemplo): [1, 3, 2, 4, 5, 7, 8, 10]
 */
int hoarePartition(int arr[], int low, int high) {
    int pivot = arr[low];
    int i = low - 1;
    int j = high + 1;

    while (true) {
        do {
            i++;
        } while (arr[i] < pivot);

        do {
            j--;
        } while (arr[j] > pivot);

        if (i >= j)
            return j;

        int tmp = arr[i];
        arr[i] = arr[j];
        arr[j] = tmp;
    }
}

// ==========================================
// Quick Sort (funciona com ambos os métodos)
// ==========================================
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int p;

#ifdef LOMUTO
        p = lomutoPartition(arr, low, high);
        quickSort(arr, low, p - 1);
        quickSort(arr, p + 1, high);
#endif

#ifdef HOARE
        p = hoarePartition(arr, low, high);
        quickSort(arr, low, p);
        quickSort(arr, p + 1, high);
#endif
    }
}

// ==========================================
void printArray(int *arr, int size) {
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    int arr[] = {10, 7, 8, 9, 1, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Array original:\n");
    printArray(arr, n);

    quickSort(arr, 0, n - 1);

    printf("Array ordenado:\n");
    printArray(arr, n);

    return 0;
}
