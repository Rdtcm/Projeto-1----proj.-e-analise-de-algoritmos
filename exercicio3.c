#include <stdio.h>

int main(void) {
    char str[100] = "ababababababababababab";
    char strDoPadrao[20];
    int contador = 1;

    //pegando a entrada do usuario
    //printf("Digite um numero: ");
    //scanf("%99s", str);

    //pegando a primeira palavra
    char letra = str[1];

    //percorrendo a string e pegando o numer de rep
    for (int i = 0; i < strlen(str); i++) {
        if (str[i] == letra) {
            contador ++;
        }
    }

    //pegando o padrao
    for (int i = 0; i < strlen(str); i++) {
        if (letra != str[i]) {
            strDoPadrao += str[i];
        } else {
            break;
        }
    }

    // printando o padrao e a qtd de vezes que se repetiu
    printf("%s%d", strDoPadrao, contador);   
}