//exercico 1 corrigido pelo professor

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

typedef struct {
    char nome[50];
    int idade;
    char sexo;
} ALUNO;

ALUNO aula[500];  // Array global paara armazenar os dados dos alunos

// Função para cadastrar um aluno no arquivo
void cadastrarAluno(FILE *aulas) {
    char nome[50], sexo;
    int idade;

    printf("Digite o nome, idade e sexo (M/F): ");
    scanf("%s %d %c", nome, &idade, &sexo);

    fprintf(aulas, "%s ; %d ; %c\n", nome, idade, sexo);
}

// Função para calcular médias e encontrar a idade mais próxima da média
void calcularMedias(FILE *aulas, FILE *relatorio) {
    int cont = 0;
    while (fscanf(aulas, "%s ; %d ; %c\n", aula[cont].nome, &aula[cont].idade, &aula[cont].sexo) != EOF) {
        cont++;
    }
    printf("%s ; %d ; %c\n",aula[cont].nome, aula[cont].idade, aula[cont].sexo);

    // Cálculo das médias para homens e mulheres
    float somaM = 0, somaF = 0;
    int contM = 0, contF = 0;

    for (int i = 0; i < cont; i++) {
        if (aula[i].sexo == 'M') {
            somaM += aula[i].idade;
            contM++;
        } else if (aula[i].sexo == 'F') {
            somaF += aula[i].idade;
            contF++;
        }
    }

    float mediaM = somaM / contM;
    float mediaF = somaF / contF;

    float media_da_media = (mediaM + mediaF) / 2;
    int idadeMaisProxima = aula[0].idade;
    char nomeMaisProxima[50];

    float diff = fabs(media_da_media - aula[0].idade);

    for(int i = 1; i < cont; i++) {
        if (fabs(media_da_media - aula[i].idade) <= diff) {
            diff = fabs(media_da_media - aula[i].idade);
            idadeMaisProxima = aula[i].idade;
            strcpy(nomeMaisProxima, aula[i].nome);
        }
    }
    //printf("mediaM: %f, mediaF: %f, nomeMaisProxima: %s, idadeMaisProxima: %d",mediaM, mediaF, nomeMaisProxima, idadeMaisProxima);
    relatorio = fopen("relatorio.txt", "w+");
    fprintf(relatorio, "Masculino: %f\nFeminino: %f\n%s: %d", mediaM, mediaF, nomeMaisProxima, idadeMaisProxima);
    fclose(relatorio);
}

int main() {
    FILE *aulas;
    FILE *relatorio;

    int op;
    
    aulas = fopen("aula.txt", "a+");  // Abre o arquivo para escrita e leitura

    if (aulas == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return 1;
    }

    printf("(1) Cadastrar aluno\n(2) Encerrar\n");
    scanf("%d", &op);

    while (op != 2) {
        if (op == 1) {
            cadastrarAluno(aulas);
        } else {
            printf("Opção inválida. Tente novamente.\n");
        }
        printf("(1) Cadastrar aluno\n(2) Encerrar\n");
        scanf("%d", &op);
    }

    calcularMedias(aulas, relatorio);

    fclose(aulas);
    return 0;
}
