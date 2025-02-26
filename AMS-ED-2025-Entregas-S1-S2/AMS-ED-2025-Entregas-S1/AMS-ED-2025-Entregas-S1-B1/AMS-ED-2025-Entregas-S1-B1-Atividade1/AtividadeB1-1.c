#include <stdio.h>

void AplicarDesconto(float *Preco, float Desconto) {
    *Preco -= *Preco * (Desconto / 100);
}

int main() {
    float Preco, Desconto, PreçoOriginal;

    do {
        printf("Insira o preço do produto: R$");
        scanf("%f", &Preco);
        if (Preco < 0) {
            printf("O preço deve ser maior que zero.\n");
        }
    } while (Preco < 0);

    do {
        printf("Insira o desconto do produto em porcentagem: ");
        scanf("%f", &Desconto);
        if (Desconto <= 0) {
            printf("O desconto não pode ser um valor negativo.\n");
        }
    } while (Desconto <= 0);

    PreçoOriginal = Preco;
    AplicarDesconto(&Preco, Desconto);
    printf("\nPreço original do produto: R$%.2f\nDesconto aplicado no produto em porcentagem: %.2f%%\nPreço final do produto: R$%.2f\n", PreçoOriginal, Desconto, Preco);
    return 0;
}