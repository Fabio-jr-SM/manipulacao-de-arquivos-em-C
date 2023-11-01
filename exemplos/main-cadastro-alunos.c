#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_ALUNOS 50
typedef struct
{
    char nome[50];
    float notas[4];
    int ativo;
} Aluno;

Aluno alunos[MAX_ALUNOS];
void menu();
void cadastrar();
void remover();
void aprovados();
void reprovados();
void pesquisar();
void listar();

int main()
{
    menu();
    return 0;
}
void menu()
{
    int op;
    do
    {
        system("cls"); 
        printf("\n1 - Cadastrar aluno\n2 - Remover aluno");
        printf("\n3 - Alunos reprovados\n4 - Pesquisar aluno\n");
        printf("\n5 - Listar alunos\n6 - Alunos Aprovados\n0 - Sair\n");
        scanf("%d", &op);
        getchar();
        switch (op)
        {
        case 1:
            cadastrar();
            break;
        case 2:
            remover();
            break;
        case 3:
            reprovados();
            break;
        case 4:
            pesquisar();
            break;
        case 5:
            listar();
            break;
        case 6:
            aprovados();
            break;
        }
        getchar();
    } while (op != 0);
}
void cadastrar()
{
    char nome[50];
    float notas[4];
    int op;
    do
    {
        system("cls"); 
        printf("\nNome: ");
        fgets(nome, sizeof(nome), stdin);
        printf("\n1 Bimestre:");
        scanf("%f", &notas[0]);
        printf("\n2 Bimestre:");
        scanf("%f", &notas[1]);
        printf("\n3 Bimestre:");
        scanf("%f", &notas[2]);
        printf("\n4 Bimestre:");
        scanf("%f", &notas[3]);
        for (int i = 0; i < MAX_ALUNOS; i++)
        {
            if (alunos[i].ativo == 0)
            {
                alunos[i].notas[0] = notas[0];
                alunos[i].notas[1] = notas[1];
                alunos[i].notas[2] = notas[2];
                alunos[i].notas[3] = notas[3];
                strcpy(alunos[i].nome, nome);
                alunos[i].ativo = 1;
                break;
            }
        }

        printf("\n1 - Continuar\n0 - Sair");
        scanf("%d", &op);
        getchar();
    } while (op != 0);
}

void remover()
{
}

void reprovados()
{
}

void aprovados()
{
}

void pesquisar()
{
}


void listar()
{
    system("cls");
    printf("\n LISTA DE ALUNOS\n");
    for (int i = 0; i < MAX_ALUNOS; i++)
    {
        if (alunos[i].ativo == 1)
        {
            printf("Matricula: %d\n", i + 1);
            printf("Nome: %s\n", alunos[i].nome);
            printf("1 Bim: %0.2f\n", alunos[i].notas[0]);
            printf("2 Bim: %0.2f\n", alunos[i].notas[1]);
            printf("3 Bim: %0.2f\n", alunos[i].notas[2]);
            printf("4 Bim: %0.2f\n", alunos[i].notas[3]);
            printf("-----------\n");
        }
    }
}