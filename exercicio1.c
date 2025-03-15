#include <stdio.h>
#include <ctype.h>


int main(void) {
    char entrada[100] = "aaaaaaabbbbbaaaaaaaaaa";
    // saida: "a7-b5-a10"
    int contador = 1;

    for (int i = 0; entrada[i] != '\0'; i++) {
        // se for uma letra
        if (isalpha(entrada[i])) {
            //pegando a letra
            char letra = entrada[i];

            //enquanto a letra for a mesma
            while (entrada[i+1] == entrada[i]) {
                contador++;
                i++;
            }
            printf("%c%d", letra, contador);

            // se nao tiver chegado ao final entrada, acrescente um hifen
            if (entrada[i+1] != '\0') {
                printf("-");
            }

            //reiniciando o contador
            contador = 1;
        }
    }
    printf("\n");
}
