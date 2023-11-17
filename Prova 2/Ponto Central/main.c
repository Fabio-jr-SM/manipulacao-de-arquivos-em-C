#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define tamanho 10

float calcularDistancia();

typedef struct c
{
	int x, y;
	float distancia;
} COORD;

int main()
{
    COORD coord[100];
    int cont=0;
    FILE *arquivoTeste;
    arquivoTeste = fopen("teste.txt","r+");
    
    if(arquivoTeste==NULL){
        printf("Arquivo não existe!");
        return 1;
    }
    
    while(fscanf(arquivoTeste,"%d %d",&coord[cont].x,&coord[cont].y)==2){
        cont++;
    }
    
    int pontoMaisProximo = 0;
    float menorDistancia = 0;
    
    
    for (int i = 0; i < 10; i++) {
        float distanciaTotal = 0;
        
        for (int j = 0; j < 10; j++) {
            if (i != j) {
                distanciaTotal += calcularDistancia(coord[i], coord[j]);
            }
        }
        
        if (i == 0 || distanciaTotal < menorDistancia) {
            menorDistancia = distanciaTotal;
            pontoMaisProximo = i;
        }
    }
    
    printf("%d %d\n", coord[pontoMaisProximo].x, coord[pontoMaisProximo].y);
	return 0;
}

float calcularDistancia(COORD p1, COORD p2) {
    return sqrt(pow(p2.x - p1.x, 2) + pow(p2.y - p1.y, 2));
}
