#include <stdio.h>

#define TOTAL_ALUNOS 30

// Definição da estrutura
typedef struct {
    float nota1;
    float nota2;
    float media;
} Aluno;

// Protótipos das funções
void lerNotas(Aluno alunos[], int n);
void calcularMedias(Aluno alunos[], int n);
float obterMediaTurma(Aluno alunos[], int n);
void imprimirDestaques(Aluno alunos[], int n, float mediaTurma);

int main() {
    Aluno alunos[TOTAL_ALUNOS];
    float mediaTurma;

    printf("--- Cadastro de Notas dos Alunos ---\n");
    
    lerNotas(alunos, TOTAL_ALUNOS);
    calcularMedias(alunos, TOTAL_ALUNOS);
    
    mediaTurma = obterMediaTurma(alunos, TOTAL_ALUNOS);

    printf("\nMedia Geral da Turma: %.2f\n", mediaTurma);
    printf("------------------------------------\n");
    
    imprimirDestaques(alunos, TOTAL_ALUNOS, mediaTurma);

    return 0;
}

// Função para leitura dos dados
void lerNotas(Aluno alunos[], int n) {
    for (int i = 0; i < n; i++) {
        printf("Aluno [%d] - Nota 1: ", i + 1);
        scanf("%f", &alunos[i].nota1);
        printf("Aluno [%d] - Nota 2: ", i + 1);
        scanf("%f", &alunos[i].nota2);
    }
}

// Função para calcular a média ponderada: (N1*2 + N2*3) / 5
void calcularMedias(Aluno alunos[], int n) {
    for (int i = 0; i < n; i++) {
        alunos[i].media = (alunos[i].nota1 * 2 + alunos[i].nota2 * 3) / 5;
    }
}

// Função para calcular a média da turma
float obterMediaTurma(Aluno alunos[], int n) {
    float soma = 0;
    for (int i = 0; i < n; i++) {
        soma += alunos[i].media;
    }
    return soma / n;
}

// Função para imprimir alunos acima da média da turma
void imprimirDestaques(Aluno alunos[], int n, float mediaTurma) {
    printf("Alunos com media acima da media da turma:\n");
    printf("ID\tNota 1\tNota 2\tMedia Final\n");
    
    for (int i = 0; i < n; i++) {
        if (alunos[i].media > mediaTurma) {
            printf("%d\t%.1f\t%.1f\t%.2f\n", i + 1, alunos[i].nota1, alunos[i].nota2, alunos[i].media);
        }
    }
}
