#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int cpf(char *a)
{
    int i = 0, s1 = 0, s2 = 0, c1 = 0, j, k;
    while (i < 9){
        if (a[i] >= 48 && a[i] <= 57){
            s1 = s1 + (10 - i) * (a[i] - 48);
            s2 = s2 + (11 - i) * (a[i] - 48);
        }else{
            c1++;
        }
        i++;
    }

    if (s1 % 11 > 1){
        j = 11 - (s1 % 11);
    }else{
        j = 0;
    }
    
    if ((s2 + 2 * s1) % 11 > 1){
        k = 11 - ((s2 + 2 * j) % 11);
    }else{
        k = 0;
    }
    
    if (c1 != 0 || strlen(a) != 11){
        return -1;
    }else if (j + 48 == a[9] && k + 48 == a[10]){
        return 0;
    }else if (j != a[9] || k != a[10]){
        return 1;
    }
}

int main()
{
    FILE *arquivoCpf,*arquivoCpfValido;
    int cont=0; 
    char CPF[12];
    
    arquivoCpf = fopen("arquivoCPF.txt","r+");
    arquivoCpfValido = fopen("arquivoCPFVALIDO.txt","w+");
    
    if(arquivoCpf == NULL){
        printf("Não foi possivel abrir o arquivo!");
        return 1;
    }
    
    while(fscanf(arquivoCpf,"%s",CPF)!=EOF){
        if (cpf(CPF) == -1){
            fprintf(arquivoCpfValido,"%s => Numero invalido\n",CPF);
        }
        else if (cpf(CPF) == 0){
            fprintf(arquivoCpfValido,"%s => CPF valido\n",CPF);
        }
        else if (cpf(CPF) == 1){
            fprintf(arquivoCpfValido,"%s => CPF invalido\n",CPF);
        }
        cont++;
    }

    return 0;
}
