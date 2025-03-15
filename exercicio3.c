#include <stdio.h>
#include <string.h>

int main(void) {
     char str[100];
    char strDoPadrao[20];
    int contador = 0;

    //pegando a entrada do usuario
    printf("Digite a entrada: ");
    scanf("%99s", str);

    //pegando a primeira letra
    char letra = str[0];

    //pegndo o tamanho da string
    int tamanho = strlen(str);

    //percorrendo a string e pegando o numer de rep
    for (int i = 0; i < tamanho; i++) {
        if (str[i] == letra) {
            contador ++;
        }
    }

    // j ser usado para adicionar o padrao
    int j = 1;
    strDoPadrao[0] = letra;

    for (int i = 1; i < tamanho; i++) { 
        if (str[i] != letra) {
            strDoPadrao[j++] = str[i];
        } else {
            break; // Quando encontrar a letra igual a primeira, sai do laco
        }
    }
    strDoPadrao[j] = '\0'; // Finaliza a string

    // printando o padrao e a qtd de vezes que se repetiu
    printf(">'");
    printf("%s%d\n", strDoPadrao, contador);
    printf("'");

    return 0;

}