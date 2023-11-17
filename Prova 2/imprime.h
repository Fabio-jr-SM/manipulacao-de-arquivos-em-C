#include<stdio.h>

void imprime()
{
    char linha[40];

	FILE *arquivo;
    arquivo = fopen("arquivoCpfValidado.txt", "r");
    while(fgets(linha, 41, arquivo) != NULL)
    {
        printf("%s", linha);
    }
    fclose(arquivo);
}
