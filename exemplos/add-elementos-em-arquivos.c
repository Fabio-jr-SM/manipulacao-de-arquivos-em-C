#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *file;
    file = fopen("string.txt","a");

    if (file == NULL){
        printf("Não foi possivel abrir!");
        getchar();
        exit(0);
    }


    fprintf(file,"\nprimeira linha");

    char frase[] = "\nSegunda line\n";
    fputs(frase,file);

    char caractere ='1';
    fputc(caractere,file);

    fclose(file);
    return 0;
}

