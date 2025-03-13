/*----------------------------------------------------------------------------------*/
/* FATEC-São Caetano do Sul  Estrutura de Dados */
/* Id da Atividade: S1-B1-2 */
/* Objetivo: <<  Manipulação de Array com ponteiro  >>  */
/* */
/* Autor: Diego Correia Bares */
/* Data:12/03/2025 */
/*----------------------------------------------------------------------------------*/

#include <stdio.h>
#include <string.h>

struct Candidato {
    char Nome[50];
    float PE[4];
    float AC[5];
    float PP[10];
    float EB[3];
    float NF;
};

float MergeResults(float *Notas, int QtdNotas) {
    float NotaSomada = 0, MaiorN = Notas[0], MenorN = Notas[0];

    for (int i = 0; i < QtdNotas; i++) {
        NotaSomada += Notas[i];
        if (Notas[i] > MaiorN) MaiorN = Notas[i];
        if (Notas[i] < MenorN) MenorN = Notas[i];
    }

    return (NotaSomada - MaiorN - MenorN);
}

void Classificar(struct Candidato *Candidato, int N_Candidatos) {
    struct Candidato CandidatoC;
    int i, j;

    for (i = 0; i < N_Candidatos - 1; i++) {
        for (j = 0; j < N_Candidatos - 1 - i; j++) {
            if (Candidato[j].NF < Candidato[j + 1].NF) {
                CandidatoC = Candidato[j];
                Candidato[j] = Candidato[j + 1];
                Candidato[j + 1] = CandidatoC;
            }
        }
    }
}

int main() {
    struct Candidato Candidatos[50];
    int qtd_candidatos = 0;
    char continuar, input[20];
    float nota;

    printf("========= Seja bem-vindo ao sistema de classificação para residência médica ========= \n\n");

    for (int i = 0; i < 50; i++) {
        printf("\nInsira o nome do(a) %i° candidato(a): \n", qtd_candidatos + 1);
        scanf(" %49[^\n]", Candidatos[i].Nome);

        printf("\nInsira as 4 notas de Provas Escritas (PE):\n");
        for (int j = 0; j < 4; j++) {
            do {
                printf("Nota PE %d: ", j + 1);
                scanf("%19s", input);
                char *comma = strchr(input, ',');
                if (comma) {
                    printf("Use ponto (.) em vez de vírgula (,) para números decimais.\n");
                } else if (sscanf(input, "%f", &nota) != 1) {
                    printf("Entrada inválida. Digite um número válido.\n");
                } else if (nota < 0 || nota > 10) {
                    printf("Nota inválida. Digite uma nota entre 0 e 10.\n");
                } else {
                    Candidatos[i].PE[j] = nota;
                    break;
                }
            } while (1);
        }

        printf("\nInsira as 5 notas de Analises Curriculares (AC):\n");
        for (int j = 0; j < 5; j++) {
            do {
                printf("Nota AC %d: ", j + 1);
                scanf("%19s", input);
                char *comma = strchr(input, ',');
                if (comma) {
                    printf("Use ponto (.) em vez de vírgula (,) para números decimais.\n");
                } else if (sscanf(input, "%f", &nota) != 1) {
                    printf("Entrada inválida. Digite um número válido.\n");
                } else if (nota < 0 || nota > 10) {
                    printf("Nota inválida. Digite uma nota entre 0 e 10.\n");
                } else {
                    Candidatos[i].AC[j] = nota;
                    break;
                }
            } while (1);
        }

        printf("\nInsira as 10 notas de Provas Praticas (PP):\n");
        for (int j = 0; j < 10; j++) {
            do {
                printf("Nota PP %d: ", j + 1);
                scanf("%19s", input);
                char *comma = strchr(input, ',');
                if (comma) {
                    printf("Use ponto (.) em vez de vírgula (,) para números decimais.\n");
                } else if (sscanf(input, "%f", &nota) != 1) {
                    printf("Entrada inválida. Digite um número válido.\n");
                } else if (nota < 0 || nota > 10) {
                    printf("Nota inválida. Digite uma nota entre 0 e 10.\n");
                } else {
                    Candidatos[i].PP[j] = nota;
                    break;
                }
            } while (1);
        }

        printf("\nInsira as 3 notas de Entrevistas em Banca Avaliadora (EB):\n");
        for (int j = 0; j < 3; j++) {
            do {
                printf("Nota EB %d: ", j + 1);
                scanf("%19s", input);
                char *comma = strchr(input, ',');
                if (comma) {
                    printf("Use ponto (.) em vez de vírgula (,) para números decimais.\n");
                } else if (sscanf(input, "%f", &nota) != 1) {
                    printf("Entrada inválida. Digite um número válido.\n");
                } else if (nota < 0 || nota > 10) {
                    printf("Nota inválida. Digite uma nota entre 0 e 10.\n");
                } else {
                    Candidatos[i].EB[j] = nota;
                    break;
                }
            } while (1);
        }

        float NF_PE = MergeResults(Candidatos[i].PE, 4);
        float NF_AC = MergeResults(Candidatos[i].AC, 5);
        float NF_PP = MergeResults(Candidatos[i].PP, 10);
        float NF_EB = MergeResults(Candidatos[i].EB, 3);

        Candidatos[i].NF = (NF_PE * 0.3f) + (NF_AC * 0.1f) + (NF_PP * 0.4f) + (NF_EB * 0.2f);

        qtd_candidatos++;

        printf("\nDeseja adicionar outro candidato? (S/N): ");
        scanf(" %c", &continuar);
        while (continuar != 'N' && continuar != 'S' && continuar != 'n' && continuar != 's') {
            printf("Insira uma resposta Valida.\n'S' para adicionar mais candidatos\n'N' para nao adicionar mais candidatos.\n- ");
            scanf(" %c", &continuar);
        }
        if (continuar == 'N' || continuar == 'n') {
            break;
        }

    }

    Classificar(Candidatos, qtd_candidatos);

    printf("\nClassificacao dos 5 melhores candidatos:\n");
    for (int i = 0; i < qtd_candidatos && i < 5; i++) {
        printf("%d°: %s - Nota Final: %.2f\n", i + 1, Candidatos[i].Nome, Candidatos[i].NF);
    }

    return 0;
}
