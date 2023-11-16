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
    
    dadosUsuarios = fopen("aula.txt", "r");  

    if (dadosUsuarios == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return 1;
    }

    calcularMedias(dadosUsuarios,relatorio);

    fclose(dadosUsuarios);
    return 0;
}
