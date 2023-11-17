#include <stdio.h>
#include <string.h>
#include "imprime.h"


//Validar CPF
int validarCPF(char *cpf)
{
    int i, j, digito1 = 0, digito2 = 0;
    for (i = 0; i < 11; i++)
    {
        if (cpf[i] < 48 || cpf[i] > 57)
            return 2;
    }

    if (strlen(cpf) != 11)
        return 0;
    else if ((strcmp(cpf, "00000000000") == 0) || (strcmp(cpf, "11111111111") == 0) || (strcmp(cpf, "22222222222") == 0) ||
             (strcmp(cpf, "33333333333") == 0) || (strcmp(cpf, "44444444444") == 0) || (strcmp(cpf, "55555555555") == 0) ||
             (strcmp(cpf, "66666666666") == 0) || (strcmp(cpf, "77777777777") == 0) || (strcmp(cpf, "88888888888") == 0) ||
             (strcmp(cpf, "99999999999") == 0))
        return 0;
    else
    {
        for (i = 0, j = 10; i < strlen(cpf) - 2; i++, j--)
            digito1 += (cpf[i] - 48) * j;
        digito1 %= 11;
        if (digito1 < 2)
            digito1 = 0;
        else
            digito1 = 11 - digito1;
        if ((cpf[9] - 48) != digito1)
            return 0;
        else
        {
            for (i = 0, j = 11; i < strlen(cpf) - 1; i++, j--)
                digito2 += (cpf[i] - 48) * j;
            digito2 %= 11;
            if (digito2 < 2)
                digito2 = 0;
            else
                digito2 = 11 - digito2;
            if ((cpf[10] - 48) != digito2)
                return 0;
        }
    }
    return 1;
}



int main()
{
    //Cria ponteiro FILE de dois arquivos
    FILE *arquivoCpf,*arquivoCpfValidado;
    int cont=0; 
    char CPF[12];
    
    //Abre o arquivo arquivoCpf.txt no modo leitura 
    //Abre o arquivo arquivoCpfValidado.txt no modo escrita
    arquivoCpf = fopen("arquivoCpf.txt","r+");
    arquivoCpfValidado = fopen("arquivoCpfValidado.txt","w+");
    
    //verifica se o arquivo arquivoCpf.txt existe, caso não encerra o programa
    if(arquivoCpf == NULL){
        printf("Não foi possivel abrir o arquivo!");
        return 1;
    }
    
    //cria um laço de repetição para ler os CPFs do arquivoCpf como string e já valida
    while(fscanf(arquivoCpf,"%s",CPF)!=EOF){
        if (validarCPF(CPF) == 2){
            //2 - Número Inválido e escreve no arquivoCpfValidado
            fprintf(arquivoCpfValidado,"%s => Numero invalido\n",CPF);
        }
        else if (validarCPF(CPF) == 1){
            //1 - CPF Válido e escreve no arquivoCpfValidado
            fprintf(arquivoCpfValidado,"%s => CPF valido\n",CPF);
        }
        else if (validarCPF(CPF) == 0){
            //0 - CPF Inválido e escreve no arquivoCpfValidado
            fprintf(arquivoCpfValidado,"%s => CPF invalido\n",CPF);
        }
        cont++;
    }
    
    //fecha os arquivos
    fclose(arquivoCpf);
    fclose(arquivoCpfValidado);
	imprime();

    return 0;
}
