#include <stdio.h>

// Função para aplicar desconto percentual usando ponteiros
void aplicarDescontoPercentual(float *preco, float percentualDesconto) {
    float valorDesconto = *preco * (percentualDesconto / 100.0);
    *preco = *preco - valorDesconto; // Modifica o valor da variável 'preco' diretamente
}

int main() {
    float precoProduto, percentualDesconto, precoFinal, valorDesconto;

    // Solicita o preço do produto ao usuário
    printf("Digite o preço do produto: R$ ");
    scanf("%f", &precoProduto);

    // Solicita o percentual de desconto ao usuário
    printf("Digite o percentual de desconto em (%%): ");
    scanf("%f", &percentualDesconto);

    // Aplica o desconto percentual usando a função com ponteiro
    aplicarDescontoPercentual(&precoProduto, percentualDesconto);

    // Calcula o valor do desconto aplicado
    valorDesconto = (precoProduto + (precoProduto * (percentualDesconto/ (100 - percentualDesconto)) )) * (percentualDesconto/100);

    // Exibe os resultados
    printf("\nPreço original do produto: R$ %.2f\n", precoProduto + valorDesconto);
    printf("Desconto aplicado: %.2f%%\n", percentualDesconto);
    printf("Preço final: R$ %.2f\n", precoProduto);

    return 0;
}