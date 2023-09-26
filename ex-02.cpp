#include <stdio.h>

/*
arr = Array[]
n = Tamanho do Array
med = Média
max = Máximo
min = Mínimo
contPar = Vai contar os números pares do Array (Contador)
numPar = Vai armazenar números pares do array original
indicePares = Vai rastrear a posição atual no novo array
*/

// Função para calcular a média, o máximo e o mínimo
void calculateStats(const int arr[], int n, float *med, int *max, int *min) {
    if (n <= 0) {
        // Se o array estiver vazio, retornar valores padrão
        *med = 0;
        *max = 0;
        *min = 0;
        return;
    }

    // Inicializa as variáveis
    *max = *min = arr[0];
    int soma = 0;
    int contPar = 0;

    // Percorre o array elemento por elemento para calcular a soma, o máximo, o mínimo e contar números pares
    for (int i = 0; i < n; i++) {
        soma += arr[i];

        if (arr[i] > *max) {
            *max = arr[i];
        }

        if (arr[i] < *min) {
            *min = arr[i];
        }

        if (arr[i] % 2 == 0) {
            contPar++;
        }
    }

    // Calcular a média
    // (float)soma - converte soma(int) para soma(float)
    *med = (float)soma / n;

    // Criar um novo array para armazenar números pares
    int numPar[contPar];
    int indicePares = 0;

    // Preencher o novo array com números pares
    for (int i = 0; i < n; i++) {
        if (arr[i] % 2 == 0) {
            numPar[indicePares] = arr[i];
            indicePares++;
        }
    }

    // Imprimir o novo array com números pares
    printf("Array com numeros pares: ");
    for (int i = 0; i < contPar; i++) {
        printf("%d ", numPar[i]);
    }
    printf("\n");

    // Retornar o tamanho do novo array
    printf("Tamanho do array de numeros pares: %d\n", contPar);
}

int main() {
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    // n = Tamanho total em bytes do array / Tamanho em bytes de um único elemento do array
    int n = sizeof(arr) / sizeof(arr[0]);
    float med;
    int max, min;

	// Chama a função calculateStats 
    calculateStats(arr, n, &med, &max, &min);

    printf("Media: %.2f\n", med);
    printf("Maximo: %d\n", max);
    printf("Minimo: %d\n", min);

    return 0;
}

