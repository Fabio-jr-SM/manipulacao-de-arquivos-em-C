//https://www.cprogressivo.net/2013/11/Como-ler-arquivos-em-C-As-funcoes-fgetc-fscanf-fgets.html
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#define INFINITY (1<<20)

//Struct para armazenar as informações do arquivo
typedef struct p
{
    int IDPessoa;
    char nome[31];
    char cpf[12];
    char dataNascimento[11];
} PESSOA;

void carregaArquivo();
void imprimeArquivo();
void editaArquivo();
void excluiArquivo();
void cadastraArquivo();
int ultimoID();

//Cria o vetor de structs Estáticamente alocado
PESSOA lista[100];
//Cria o vetor de structs Dinamicamente alocado
//PESSOA *lista = (PESSOA*)malloc(100*sizeof(PESSOA));
//Variável responsável por definir a posição do vetor onde os dados serão guardados
int cont;
//Cria um ponteiro de FILE para alocar o espaço em memória
FILE *arquivo;

void carregaArquivo()
{
    cont = 0;
    arquivo = fopen("pessoa.txt", "r+");
    //Percorre o arquivo até que encontre o fim do arquivo (EOF)
    //Utiliza a função fscanf para realizar a leitura formatada
    //Guarda os dados lidos no vetor de structs criado anteriormente
    while(fscanf(arquivo,"%d ; %s ; %s ; %s", &lista[cont].IDPessoa, lista[cont].nome, lista[cont].cpf, lista[cont].dataNascimento)!= EOF)
    {
        //Imprime os dados que foram lidos no vetor de structs, separados por #
        //printf("%d # %s # %s # %s\n", lista[cont].IDPessoa, lista[cont].nome, lista[cont].cpf, lista[cont].dataNascimento);
        //imprimeArquivo();
        //Incrementa o valor de cont para guardar os valores nas próximas posições do vetor
        cont++;
    }
    fclose(arquivo);
}

void imprimeArquivo()
{
    int i;
    for(i = 0; i<cont; i++)
    {
        printf("%d ; %s ; %s ; %s\n", lista[i].IDPessoa, lista[i].nome, lista[i].cpf, lista[i].dataNascimento);
    }
}

void editaArquivo()
{
    //Alterar o registro na memória
    
    int i;
    int IDPessoaAlteracao;
    printf("Digite o ID para alteracao\n");
    scanf("%d", &IDPessoaAlteracao);
    for(i = 0; i<cont; i++)
    {
        if(lista[i].IDPessoa == IDPessoaAlteracao)
        {
            printf("Digite o nome\n");
            scanf("%s", lista[i].nome);
            break;
        }
    }
    
    arquivo = fopen("pessoa.txt", "w+");
    //Laço de repetição responsável por percorrer o vetor
    for(i = 0; i<cont; i++)
    {
        //Escreve no arquivoNovo.txt seguindo um novo formato
        fprintf(arquivo, "%d ; %s ; %s ; %s\n", lista[i].IDPessoa, lista[i].nome, lista[i].cpf, lista[i].dataNascimento);
    }
    //Fecha os dois arquivos que foram abertos com a função fopen
    fclose(arquivo);
}

void excluiArquivo()
{
    //Excluir o registro na memória
    arquivo = fopen("pessoa.txt", "w+");
    int IDPessoaExclusao;
    printf("Digite o ID para exclusao\n");
    scanf("%d", &IDPessoaExclusao);
    int i;
    for(i = 0; i<cont; i++)
    {
        if(lista[i].IDPessoa != IDPessoaExclusao)
        {
            fprintf(arquivo, "%d ; %s ; %s ; %s\n", lista[i].IDPessoa, lista[i].nome, lista[i].cpf, lista[i].dataNascimento);
        }
    }
    fclose(arquivo);
}

void cadastraArquivo()
{
    PESSOA novaPessoa;
    //Cadastrar o registro na memória
    printf("Digite o nome\n");
    scanf("%s", novaPessoa.nome);
    printf("Digite o CPF\n");
    scanf("%s", novaPessoa.cpf);
    printf("Digite a data de nascimento\n");
    scanf("%s", novaPessoa.dataNascimento);
    
    arquivo = fopen("pessoa.txt", "a+");
    //Escreve no arquivoNovo.txt seguindo um novo formato
    fprintf(arquivo, "%d ; %s ; %s ; %s\n", ultimoID()+1, novaPessoa.nome, novaPessoa.cpf, novaPessoa.dataNascimento);
    //Fecha os dois arquivos que foram abertos com a função fopen
    fclose(arquivo);
    
}

int ultimoID()
{
    int maiorID = -INFINITY;
    int i;
    for(i = 0; i<cont; i++)
    {
        if(lista[i].IDPessoa > maiorID)
        {
            maiorID = lista[i].IDPessoa;
        }
    }
}

void menu()
{
    int menu;
    do{
        printf("1 - Cadastrar\n");
        printf("2 - Editar\n");
        printf("3 - Excluir\n");
        printf("4 - Consultar\n");
        printf("5 - Sair\n");
        
        carregaArquivo();
        scanf("%d", &menu);
        switch(menu)
        {
            case 1:
                printf("CADASTRA\n");
                cadastraArquivo();
                break;
            case 2:
                printf("EDITA\n");
                editaArquivo();
                break;
            case 3:
                printf("EXCLUI\n");
                excluiArquivo();
                break;
            case 4:
                printf("IMPRIME\n");
                imprimeArquivo();
                break;
            case 5:
                printf("SAINDO!!!");
                break;
            default:
                printf("Menu invalido\n");
        }
    }while(menu != 5);
}

int main()
{
    menu();

    return 0;
}
