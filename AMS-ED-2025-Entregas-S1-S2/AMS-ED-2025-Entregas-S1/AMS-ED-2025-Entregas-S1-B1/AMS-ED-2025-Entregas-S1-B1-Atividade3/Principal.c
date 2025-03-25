/*----------------------------------------------------------------------------------*/
/*   FATEC-São Caetano do Sul                 Estrutura de Dados                    */
/*                         Id da Atividade: AMS-ED-2025-Entregas-S1-B1-Atividade3"  */
/*             Objetivo: Manipulação de Lista Ligada                                */
/*                                                                                  */
/*                                  Autor: Diego Correia Bares                      */
/*                                                                   Data:25/03/2025*/
/*----------------------------------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STRING 100

typedef enum {
	PENDENTE,
	EM_PREPARO,
	PRONTO,
	ENTREGUE
} StatusPedido;

typedef struct Pedido {
	int numero;
	char nomeCliente[MAX_STRING];
	char descricao[MAX_STRING];
	int quantidade;
	StatusPedido status;
	struct Pedido* proximo;
} Pedido;

void limparBuffer() {
	int c;
	while ((c = getchar()) != '\n' && c != EOF);
}

const char* statusParaString(StatusPedido status) {
	switch (status) {
	case PENDENTE:
		return "Pendente";
	case EM_PREPARO:
		return "Em preparo";
	case PRONTO:
		return "Pronto";
	case ENTREGUE:
		return "Entregue";
	default:
		return "Desconhecido";
	}
}

void criarEInserirPedido(Pedido** lista, int numero, char* nomeCliente, char* descricao, int quantidade) {
	Pedido* novo = (Pedido*)malloc(sizeof(Pedido));
	if (!novo) {
		printf("Erro ao alocar memC3ria!\n");
		return;
	}
	novo->numero = numero;
	strcpy(novo->nomeCliente, nomeCliente);
	strcpy(novo->descricao, descricao);
	novo->quantidade = quantidade;
	novo->status = PENDENTE;
	novo->proximo = *lista;
	*lista = novo;
}

Pedido* obterPedido(Pedido* lista, int numero) {
	while (lista) {
		if (lista->numero == numero) {
			return lista;
		}
		lista = lista->proximo;
	}
	return NULL;
}

int atualizarStatusPedido(Pedido* lista, int numero, StatusPedido novoStatus) {
	Pedido* pedido = obterPedido(lista, numero);
	if (pedido) {
		pedido->status = novoStatus;
		return 1;
	}
	return 0;
}

int deletarPedido(Pedido** lista, int numero) {
	Pedido *atual = *lista, *anterior = NULL;
	while (atual && atual->numero != numero) {
		anterior = atual;
		atual = atual->proximo;
	}
	if (!atual) return 0;
	if (anterior)
		anterior->proximo = atual->proximo;
	else
		*lista = atual->proximo;
	free(atual);
	return 1;
}

void liberarLista(Pedido** lista) {
	Pedido* atual = *lista;
	while (atual) {
		Pedido* temp = atual;
		atual = atual->proximo;
		free(temp);
	}
	*lista = NULL;
}

void exibirPedido(Pedido* pedido) {
	if (pedido) {
		printf("=======================\n");
		printf("Pedido #%d\nCliente: %s\nPrato: %s\nQuantidade: %d\nStatus: %s\n\n",
		       pedido->numero, pedido->nomeCliente, pedido->descricao, pedido->quantidade, statusParaString(pedido->status));
		printf("=======================\n");
	} else {
		printf("Pedido nC#o encontrado!\n");
	}
}

void exibirTodosPedidos(Pedido* lista) {
     Pedido* pedidos[100];
    int count = 0;
    
    if (!lista) {
        printf("Nenhum pedido na lista.\n");
        return;
    }
    
    while (lista && count < 100) {
        pedidos[count++] = lista;
        lista = lista->proximo;
    }
    
    for (int i = count - 1; i >= 0; i--) {
        exibirPedido(pedidos[i]);
    }
// 	Pedido* Pedidos[100];
// 	if (!lista) {
// 		printf("Nenhum pedido na lista.\n");
// 		return;
// 	}
// 		for(int i=0; i<99; i++) {
// 			Pedidos[i] = lista;
// 			lista = lista->proximo;
// 		}
// 		for(int i=99; i > 0; i--) {
// 			exibirPedido(Pedidos[i]);
// 		}
}

void menu(Pedido** listaPedidos) {
	int opcao;
	do {
		printf("\nMenu:\n");
		printf("1. Adicionar Pedido\n");
		printf("2. Buscar Pedido\n");
		printf("3. Atualizar Status de Pedido\n");
		printf("4. Remover Pedido\n");
		printf("5. Exibir Todos os Pedidos\n");
		printf("6. Sair\n");
		printf("Escolha uma opC'C#o: ");
		scanf("%d", &opcao);
		limparBuffer();

		int numero, quantidade, status;
		char nomeCliente[MAX_STRING], descricao[MAX_STRING];
		Pedido* pedido;

		switch (opcao) {
		case 1:
			printf("NC:mero do Pedido: ");
			scanf("%d", &numero);
			limparBuffer();
			printf("Nome do Cliente: ");
			fgets(nomeCliente, MAX_STRING, stdin);
			strtok(nomeCliente, "\n");
			printf("DescriC'C#o do Prato: ");
			fgets(descricao, MAX_STRING, stdin);
			strtok(descricao, "\n");
			printf("Quantidade: ");
			scanf("%d", &quantidade);
			limparBuffer();
			criarEInserirPedido(listaPedidos, numero, nomeCliente, descricao, quantidade);
			break;
		case 2:
			printf("NC:mero do Pedido: ");
			scanf("%d", &numero);
			limparBuffer();
			pedido = obterPedido(*listaPedidos, numero);
			exibirPedido(pedido);
			break;
		case 3:
			printf("NC:mero do Pedido: ");
			scanf("%d", &numero);
			limparBuffer();
			printf("Novo Status (0: PENDENTE, 1: EM_PREPARO, 2: PRONTO, 3: ENTREGUE): ");
			scanf("%d", &status);
			limparBuffer();
			if (atualizarStatusPedido(*listaPedidos, numero, (StatusPedido)status))
				printf("Status atualizado com sucesso!\n");
			else
				printf("Pedido nC#o encontrado!\n");
			break;
		case 4:
			printf("NC:mero do Pedido: ");
			scanf("%d", &numero);
			limparBuffer();
			if (deletarPedido(listaPedidos, numero))
				printf("Pedido removido com sucesso!\n");
			else
				printf("Pedido nC#o encontrado!\n");
			break;
		case 5:
			exibirTodosPedidos(*listaPedidos);
			break;
		case 6:
			liberarLista(listaPedidos);
			printf("Saindo...\n");
			break;
		default:
			printf("OpC'C#o invC!lida!\n");
		}
	} while (opcao != 6);
}

int main() {
	Pedido* listaPedidos = NULL;
	menu(&listaPedidos);
	return 0;
}
