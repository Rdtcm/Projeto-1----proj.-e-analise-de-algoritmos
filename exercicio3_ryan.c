#include <stdio.h>
#include <string.h>
#include <stdlib.h>


// estrutura para a substring
typedef struct {
    char substring[100];
    char* pos_inicial;
    int lenght;
    int ocorrencias_substr;
} Substring;

Substring substring(const char* str, char *ptr_inicio, char *ptr_fim) {
    int tamanho = ptr_fim - ptr_inicio + 1;

    // alocando memoria para a substring
    char *substr = (char*)malloc(tamanho + 1);

    if (substr == NULL) {
        printf("Erro: alocacao dinamica de memoria para substr\n");
        Substring invalida = {"", NULL, 0, 0};
        return invalida;
    }

    // colocando os dados na substring
    for (int i = 0; i < tamanho; i++) {
        substr[i] = ptr_inicio[i];
    }

    // colocando o caractere de '\0'
    substr[tamanho] = '\0';

    // retornando a estrutura substring
    Substring resultado = {"", ptr_inicio, tamanho, 0};
    strncpy(resultado.substring, substr, tamanho);

    // liberando o espaco alocado
    free(substr);

    return resultado;
}

void comprimir_substring(char *string) {
    char *ptr_inicio = string;
    char *ptr_final = string;
    int dif_ptr;

    Substring substr1;
    Substring substr2;

    Substring resultado;

    int contador = 0;

    while (*ptr_final != '\0') {
        ptr_final++;

        if (*ptr_final == *ptr_inicio) {
            dif_ptr = ptr_final - ptr_inicio;
            printf("%d\n", dif_ptr);

            substr1 = substring(string, ptr_inicio, ptr_final-1);
            substr2 = substring(string, ptr_final, ptr_final + dif_ptr - 1);

            printf("ponteiro inicio: %c\n", *ptr_inicio);
            printf("ponteiro final: %c\n", *ptr_final);
            printf("substr1: %s\n", substr1.substring);
            printf("substr2: %s\n", substr2.substring);
            printf("\n");
            
            if (strcmp(substr1.substring, substr2.substring) == 0) { contador++; }
            else { ptr_final++; }
        
        }
    printf("Contador: %d\n", contador);
    }
}



int main() {
    char string_teste[] = "cacocacocaco";
    char *ptr_inicio = string_teste;
    char *ptr_fim = string_teste + 2;

    Substring substr = substring(string_teste, (char*)ptr_inicio, (char*)ptr_fim);

    printf("Substring: %s\n\n", substr.substring);

    comprimir_substring(string_teste);


    return 0;
}