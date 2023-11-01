#include <stdio.h>
#include <stdlib.h>

int main()
{

    void copiar_conteudo(FILE *file1,FILE *file2);

    FILE *file1 ;
    file1 = fopen("arquivo1.txt","r");

    if(file1 == NULL){
        printf("Não foi possivel abrir");
        return 1;
    }

    FILE *file2;
    file2= fopen("arquivo2.txt","w");
    
    copiar_conteudo(file1,file2);
    
    fclose(file1);
    fclose(file2);
    return 0;
}


void copiar_conteudo(FILE *file1,FILE *file2){
    char leitor[1000];

    while (fscanf(file1,"%[^\n]%*c\n",leitor)!=EOF)
    {
        printf("%s",leitor);
        fprintf(file2,"%s\n",leitor);
        //fputs(leitor,file2);
    }
    
}