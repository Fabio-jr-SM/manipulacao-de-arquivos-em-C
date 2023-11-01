#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *file;
    
    file = fopen("numeros.txt", "r");
    
    if (file == NULL) {
        printf("Arquivo não foi aberto!");  
        exit(0);
    }
    
    int x, y, z;
    
    fscanf(file, "%d %d %d", &x, &y, &z);
    
    printf("%d %d %d\n", x, y, z);
    
    fclose(file);
    return 0; 
}
