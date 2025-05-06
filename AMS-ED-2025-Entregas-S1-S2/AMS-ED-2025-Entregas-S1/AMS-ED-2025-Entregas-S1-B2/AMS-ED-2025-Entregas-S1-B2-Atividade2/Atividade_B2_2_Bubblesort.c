/*----------------------------------------------------------------------------------*/
/*   FATEC-São Caetano do Sul                 Estrutura de Dados                    */
/*                        Id da Atividade: "AMS-ED-2025-Entregas-S1-B2-Atividade2"  */
/*             Objetivo: Utilizar Bubblesort e mostrar o array classificado em ordem*/
/*                       ascendente de n números.                                   */
/*                                                                                  */
/*                                  Autor: Diego Correia Bares                      */
/*                                                                   Data:06/05/2025*/
/*----------------------------------------------------------------------------------*/

#include <stdio.h>

int main() {
    int n, i, j, temp;

    // Solicita o tamanho do array
    printf("Digite uma quantidade n de números a serem inseridos: ");
    scanf("%d", &n);

    int array[n];

    // Entrada dos números
    printf("Digite os %d números:\n", n);
    for (i = 0; i < n; i++) {
        printf("Número %d: ", i + 1);
        scanf("%d", &array[i]);
    }

    // Algoritmo Bubble Sort
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (array[j] > array[j + 1]) {
                // Troca os elementos
                temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }

    // Exibe o array ordenado
    printf("\nO resultado do array classificado em ordem ascendente é:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", array[i]);
    }

    printf("\n");
    return 0;
}
