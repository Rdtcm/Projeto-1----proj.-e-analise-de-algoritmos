#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX 10000

int main(void) {
    char entrada[MAX];
    
    printf("Informe a string a ser descompactada: ");
    scanf("%199s", entrada);

    char *ptr_inicio = entrada;
    char *ptr_final = entrada;
    char num_rep_concatenado[50];
    int i = 0;
    int cont = 0;

    while (*ptr_final != '\0') {
        if (isalpha(*ptr_final)) 
        {
            char letra = *ptr_final;
            ptr_final++; 
            i = 0;  

            while (*ptr_final != '-' && *ptr_final != '\0') 
            {
                num_rep_concatenado[i] = *ptr_final;
                ptr_final++;
                i++;
            }

            num_rep_concatenado[i] = '\0';

            int valor_rep = atoi(num_rep_concatenado);

            for (int j = 0; j < valor_rep; j++) printf("%c", letra);

            if (*ptr_final == '-') {
                ptr_final++;  
            }
        } 
        else 
        {
            ptr_final++;
        }
    }
    printf("\n");
    return 0;
}
