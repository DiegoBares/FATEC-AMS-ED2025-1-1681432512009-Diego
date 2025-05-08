/*-----------------------------------------------------------------------------------*/
/*   FATEC-São Caetano do Sul                 Estrutura de Dados                     */
/*                         Id da Atividade: S1-B2-2                                  */
/*             Objetivo: <<  Bubblesort  >>                                          */
/*                                                                                   */
/*                                  Autor: Diego Correia Bares                       */
/*                                                                    Data:06/05/2025*/
/*-----------------------------------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>

void BubbleSort(int arr[], int n) {
    int i, j, temp;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int* IncluirDados(int* n) {
    printf("Digite o número de elementos que deseja: ");
    scanf("%d", n);

    int* arr = (int*) malloc(*n * sizeof(int));
    if (arr == NULL) {
        printf("Erro ao alocar memória.\n");
        exit(1);
    }

    printf("\nDigite %d números:\n", *n);
    for (int i = 0; i < *n; i++) {
        scanf("%d", &arr[i]);
    }

    return arr;
}

void MostrarSaida(int arr[], int n) {
    printf("\nSequência dos números ordenados em ordem ascendente:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int n;
    int* arr = IncluirDados(&n);

    BubbleSort(arr, n);

    MostrarSaida(arr, n);

    free(arr);

    return 0;
}
