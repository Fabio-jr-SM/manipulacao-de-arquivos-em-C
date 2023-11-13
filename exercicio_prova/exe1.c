#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

typedef struct {
    char nome[50];
    int idade;
    char sexo;
} USER;

USER users[500];  

void cadastrarUsuario(FILE *dadosUsuarios) {
    char nome[50], sexo;
    int idade;

    printf("Digite o nome, idade e sexo (M/F): ");
    scanf("%s %d %c", nome, &idade, &sexo);

    fprintf(dadosUsuarios, "%s ; %d ; %c\n", nome, idade, sexo);
}

void calcularMedias(FILE *dadosUsuarios,FILE *relatorio) {
    int cont = 0;
    rewind(dadosUsuarios);
    while (fscanf(dadosUsuarios, "%s ; %d ; %c\n", users[cont].nome, &users[cont].idade, &users[cont].sexo) != EOF) {
        printf("%s ; %d ; %c\n",users[cont].nome, users[cont].idade, users[cont].sexo);
        cont++;
    }
    
    float somaM = 0, somaF = 0;
    int contM = 0, contF = 0;

    for (int i = 0; i < cont; i++) {
        if (users[i].sexo == 'M') {
            somaM += users[i].idade;
            contM++;
        } else if (users[i].sexo == 'F') {
            somaF += users[i].idade;
            contF++;
        }
    }

    float mediaM = somaM / contM;
    float mediaF = somaF / contF;

    float media_da_media = (mediaM + mediaF) / 2;
    int idadeMaisProxima = users[0].idade;
    char nomeMaisProxima[50];

    float diff = fabs(media_da_media - users[0].idade);

    for(int i = 1; i < cont; i++) {
        if (fabs(media_da_media - users[i].idade) < diff) {
            diff = fabs(media_da_media - users[i].idade);
            idadeMaisProxima = users[i].idade;
            strcpy(nomeMaisProxima, users[i].nome);
        }
    }
    
    relatorio = fopen("relatorio.txt", "w+");
    fprintf(relatorio, "Masculino: %f\nFeminino: %f\n%s: %d", mediaM, mediaF, nomeMaisProxima, idadeMaisProxima);
    fclose(relatorio);
}

int main() {
    FILE *dadosUsuarios;
    FILE *relatorio;

    int op;
    
    dadosUsuarios = fopen("aula.txt", "w+");  

    if (dadosUsuarios == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return 1;
    }

    printf("(1) Cadastrar aluno\n(2) Encerrar\n");
    scanf("%d", &op);

    while (op != 2) {
        if (op == 1) {
            cadastrarUsuario(dadosUsuarios);
        } else {
            printf("Opção inválida. Tente novamente.\n");
        }
        printf("(1) Cadastrar aluno\n(2) Encerrar\n");
        scanf("%d", &op);
    }

    calcularMedias(dadosUsuarios,relatorio);

    fclose(dadosUsuarios);
    return 0;
}
