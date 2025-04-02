/*----------------------------------------------------------------------------------*/
/*   FATEC-São Caetano do Sul                 Estrutura de Dados                    */
/*                         Id da Atividade: AMS-ED-2025-Entregas-S1-B1-Atividade4   */
/*             Objetivo: <<  Manipulação de Pilha - Implementando HP12c  >>         */
/*                                                                                  */
/*                                  Autora: Diego Correia Bares                     */
/*                                                                   Data:02/04/2025*/
/*----------------------------------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_SIZE 4  

typedef struct {
    double data[MAX_SIZE];
    char expr[MAX_SIZE][50];
    int top;
} Pilha;

Pilha* criar_pilha() {
    Pilha* p = (Pilha*)malloc(sizeof(Pilha));
    p->top = -1;
    return p;
}

int vazia(Pilha* p) {
    return p->top == -1;
}

int cheia(Pilha* p) {
    return p->top == MAX_SIZE - 1;
}

void push(Pilha* p, double valor, const char* expr) {
    if (cheia(p)) { 
        printf("Erro: Pilha cheia! Não é possível adicionar mais elementos.\n");
        return;
    }

    p->top++;
    p->data[p->top] = valor;
    strcpy(p->expr[p->top], expr);
}

double pop(Pilha* p, char* expr) {
    if (vazia(p)) {
        printf("Erro: Pilha vazia!\n");
        exit(1);
    }
    strcpy(expr, p->expr[p->top]);
    return p->data[p->top--];
}

double top(Pilha* p, char* expr) {
    if (vazia(p)) {
        printf("Erro: Pilha vazia!\n");
        exit(1);
    }
    strcpy(expr, p->expr[p->top]);
    return p->data[p->top];
}

int is_number(const char* token) {
    char* endptr;
    strtod(token, &endptr);
    return *endptr == '\0';
}

void calcular_RPN(char* expressao) {
    Pilha* pilha = criar_pilha();
    char* token = strtok(expressao, " ");
    
    while (token != NULL) {
        if (is_number(token)) {
            double num = atof(token);
            char temp[20];
            sprintf(temp, "%.2f", num);
            push(pilha, num, temp);
        } else {
            if (pilha->top < 1) {
                printf("\nErro: Expressão inválida!\n\n");
                free(pilha);  
                return;
            }
            char exprA[50], exprB[50];
            double b = pop(pilha, exprB);
            double a = pop(pilha, exprA);
            double resultado;
            char operador = token[0];
            char novaExpr[150];
            
            switch (operador) {
                case '+': resultado = a + b; break;
                case '-': resultado = a - b; break;
                case '*': resultado = a * b; break;
                case '/':
                    if (b == 0) {
                        printf("Erro: Divisão por zero!\n");
                        free(pilha); 
                        return;
                    }
                    resultado = a / b;
                    break;
                default:
                    printf("Erro: Operador inválido!\n");
                    free(pilha); 
                    return;
            }
            
            snprintf(novaExpr, sizeof(novaExpr), "(%s %c %s)", exprA, operador, exprB);
            push(pilha, resultado, novaExpr);
        }
        token = strtok(NULL, " ");
    }
    
    if (pilha->top != 0) {
        printf("\nErro: Expressão inválida!\n");
        free(pilha);  
        return;
    }
    
    char resultadoExpr[100];
    double resultadoFinal = pop(pilha, resultadoExpr);
    printf("\nResultado: %s = %.2f\n", resultadoExpr , resultadoFinal);
    printf("\n");
    free(pilha);  
}

void menu() {
    int opcao;
    char expressao[MAX_SIZE * 20];
    Pilha* pilha = NULL;  

    do {
        printf("\n------------------------------------");
        printf("\nMENU:\n");
        printf("1) Inserir expressão RPN\n");
        printf("2) Sair\n");
        printf("\nEscolha uma das opções:\n");
        scanf("%d", &opcao);
        getchar();  
        
        switch (opcao) {
            case 1:
                if (pilha == NULL) {
                    pilha = criar_pilha();  
                }
                printf("\nDigite a expressão RPN (Ex: x y + z -):\n");
                fgets(expressao, sizeof(expressao), stdin);
                expressao[strcspn(expressao, "\n\n")] = 0; 
                calcular_RPN(expressao);  
                break;
            case 2:
                printf("\nSistema finalizado.");
                if (pilha != NULL) {
                    free(pilha);  
                }
                break;
            default:
                printf("\nOpção inválida!\n\n");
        }
    } while (opcao != 2);  
}

int main() {
    menu();
    return 0;
}