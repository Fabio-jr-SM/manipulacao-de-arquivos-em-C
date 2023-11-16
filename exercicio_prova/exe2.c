#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int matricula;
    char nome[50];
    float nota_media;
} ALUNO;


ALUNO dadosAluno[500];
int cont=0;

void cadastrarAluno(FILE *aluno){
    printf("Digite a matricula, nome e media do aluno: ");
    scanf("%d %s %f",&dadosAluno[cont].matricula,dadosAluno[cont].nome,&dadosAluno[cont].nota_media);
    fprintf(aluno,"%d; %s; %f\n",dadosAluno[cont].matricula,dadosAluno[cont].nome,dadosAluno[cont].nota_media);
    cont++;
}


void exibirTodosOsAlunos(){
    printf("=========LISTA DE ALUNOS=========\n");
    for(int i=0;i<cont;i++){
        printf("%d %s %f\n",dadosAluno[i].matricula,dadosAluno[i].nome,dadosAluno[i].nota_media);
    }
    printf("\n");
}


void buscaPorMatricula(){
    
}

int main(){
    FILE *aluno;
    int op;
    aluno = fopen("aluno.txt","w+");
    if(aluno==NULL){
        printf("Erro ao abrir o arquivo!");
        return 1;
    }
    
    
    printf("Escolha uma opção\n(1) Cadastrar aluno\n(2) Exibir alunos\n(3) Buscar aluno por matricula\n(4) Encerrar\n");
    scanf("%d",&op);
    
    while(op!=4){    
        if(op==1){
            cadastrarAluno(aluno);
        }else if(op==2){
            exibirTodosOsAlunos();
        }else if(op==3){
            buscaPorMatricula();
        }
        printf("Escolha uma opção\n(1) Cadastrar aluno\n(2) Exibir alunos\n(3) Buscar aluno por matricula\n(4) Encerrar\n");
        scanf("%d",&op);
    }
    fclose(aluno);
    return 0;
}
