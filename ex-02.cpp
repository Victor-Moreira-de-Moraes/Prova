#include <stdio.h>

/*
arr = Array[]
n = Tamanho do Array
med = M�dia
max = M�ximo
min = M�nimo
contPar = Vai contar os n�meros pares do Array (Contador)
numPar = Vai armazenar n�meros pares do array original
indicePares = Vai rastrear a posi��o atual no novo array
*/

// Fun��o para calcular a m�dia, o m�ximo e o m�nimo
void calculateStats(const int arr[], int n, float *med, int *max, int *min) {
    if (n <= 0) {
        // Se o array estiver vazio, retornar valores padr�o
        *med = 0;
        *max = 0;
        *min = 0;
        return;
    }

    // Inicializa as vari�veis
    *max = *min = arr[0];
    int soma = 0;
    int contPar = 0;

    // Percorre o array elemento por elemento para calcular a soma, o m�ximo, o m�nimo e contar n�meros pares
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

    // Calcular a m�dia
    // (float)soma - converte soma(int) para soma(float)
    *med = (float)soma / n;

    // Criar um novo array para armazenar n�meros pares
    int numPar[contPar];
    int indicePares = 0;

    // Preencher o novo array com n�meros pares
    for (int i = 0; i < n; i++) {
        if (arr[i] % 2 == 0) {
            numPar[indicePares] = arr[i];
            indicePares++;
        }
    }

    // Imprimir o novo array com n�meros pares
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
    // n = Tamanho total em bytes do array / Tamanho em bytes de um �nico elemento do array
    int n = sizeof(arr) / sizeof(arr[0]);
    float med;
    int max, min;

	// Chama a fun��o calculateStats 
    calculateStats(arr, n, &med, &max, &min);

    printf("Media: %.2f\n", med);
    printf("Maximo: %d\n", max);
    printf("Minimo: %d\n", min);

    return 0;
}

