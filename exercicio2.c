#include <stdio.h>
#include <ctype.h>

int main(void) {
    char entrada[100] = "a6-b15-c1-d1";

    // printf("Informe a entrada que sera descompactada: ");
    // scanf("%99s", entrada);

    //percorrendo a string
    for (int i = 0; entrada[i] != '\0'; i++) {
        //se for uma letra
        if (isalpha(entrada[i])) {
            char letra = entrada[i];
            int numeroRepeticoesLetras = 0;

            //passando para o caractere que contem o numero
            i++;

            //pegando o numero de vezes que se repete
            while (entrada[i] >= '0' && entrada[i] <= '9') {
                numeroRepeticoesLetras = numeroRepeticoesLetras * 10 + (entrada[i] - '0');  // convertendo para inteiro
                i++;
            }

            //printando na tela n vezes a letra
            for (int k = 0; k < numeroRepeticoesLetras; k++) {
                printf("%c", letra);
            }
        }
    }
    printf("\n");
}