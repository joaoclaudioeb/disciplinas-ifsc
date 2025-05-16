#include <stdio.h>

int main() {
    FILE *entrada = fopen("medidas.csv", "r");
    FILE *saida = fopen("resultado.csv", "w");
    
    if (entrada == NULL || saida == NULL) {
        printf("Erro ao abrir arquivos\n");
        return 1;
    }
    
    // Pular cabeçalho
    char linha[100];
    fgets(linha, 100, entrada);
    
    // Escrever novo cabeçalho
    fprintf(saida, "Corrente (A);Tensão (V);Potência (W)\n");
    
    float corrente, tensao;
    while (fscanf(entrada, "%f;%f", &corrente, &tensao) == 2) {
        float potencia = corrente * tensao;
        fprintf(saida, "%.2f;%.2f;%.2f\n", corrente, tensao, potencia);
    }
    
    fclose(entrada);
    fclose(saida);
    return 0;
}
