/*
Nome:Renan Horochk de Andrade
RA:10438120
-------------------------------
Nome:Ryan Vinicius Ledo
RA:10352727
 */

#include <stdio.h>
#include <string.h>

typedef struct {
    char letra;
    int numero; 
} Compactado;


int main(void) {
    char entrada[100] = "abcabc";
    int tamanho = strlen(entrada);
    char *ptr_inicio = entrada;
    char *ptr_final = entrada;

    int contador = 1;

    while (*ptr_final != '\0') {
        ptr_final++;

        if (*ptr_inicio == *ptr_final)
        {
            contador++;
        }
        else
        {
            Compactado s;

            s.letra = *ptr_inicio;
            s.numero = contador;

            if (*ptr_final == entrada[tamanho]) printf("%c%d", s.letra, s.numero);
            else  printf("%c%d-", s.letra, s.numero);

            contador = 1;
        }
        ptr_inicio = ptr_final;
    }
    printf("\n");
}
