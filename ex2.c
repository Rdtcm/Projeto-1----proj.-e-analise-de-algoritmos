/*
Nome:Renan Horochk de Andrade
RA:10438120
-------------------------------
Nome:Ryan Vinicius Ledo
RA:10352727
 */
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX 10000

int main(void) {
    char entrada[MAX];
    
    printf("Informe a string a ser descompactada: ");
    scanf("%199s", entrada);

    char *ptr_inicio, *ptr_final = entrada;
    char num_rep_concatenado[50];
    int i, cont = 0;

    while (*ptr_final != '\0') {
        if (isalpha(*ptr_final)) 
        {
            char letra = *ptr_final;
            ptr_final++; 
            int repeticoes = 0; 

            while (isdigit(*ptr_final)) {
                repeticoes = repeticoes * 10 + (*ptr_final - '0');
                ptr_final++;
            }

            for (int j = 0; j < repeticoes; j++) printf("%c", letra);

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
