#include <stdio.h>
#include <string.h>
#include <stdlib.h>


char* substring(const char* str, int comeco, int fim) {
    // verificando se os indices fornecidos sao validos
    if (comeco < 0 || fim <= comeco || fim > strlen(str)) {
        return NULL;
    }

    int tamanho = fim - comeco;
    // alocando memoria para a substring, o + 1 e por causa do '\0'
    char* substring = (char*)malloc(tamanho + 1);

    // validando a alocacao de memoria para a substring
    if (substring == NULL) {
        return NULL;
    }

    // colocando os dados na substring
    for (int i = 0; i < tamanho; i++) {
        substring[i] = str[comeco + i];
    }

    // colocando o caractere de '\0'
    substring[tamanho] = '\0';

    return substring;
}

char* replace(char* str, const char* velhaStr, const char* novaStr) {
    int tamanhoStr = strlen(str);
    int tamanhoStrVelha = strlen(velhaStr);
    int tamanhoStrNova = strlen(novaStr);

    int tamanhoMaximoNovaStr = tamanhoStr;
    // encontrando o tamanho maximo d nova string para alocar memoria
    for (int i = 0; i < tamanhoStr; i++) {
        // encontrando a substring
        if (strncmp(&str[i], velhaStr, tamanhoStrVelha) == 0) {
            tamanhoMaximoNovaStr += tamanhoStrNova - tamanhoStrVelha;
            i += tamanhoStrVelha - 1;
        }
    }

    // alocando o espaco de memoria necessario
    char* resultado = (char*)malloc(tamanhoMaximoNovaStr + 1);
    int posicao = 0;

    for (int i = 0; i < tamanhoStr; i++) {
        // encontrando a substring
        if (strncmp(&str[i], velhaStr, tamanhoStrVelha) == 0) {
            // colocando a nova string
            strcpy(&resultado[posicao], novaStr);

            posicao += tamanhoStrNova;
            i += tamanhoStrVelha - 1;
        } else {
            // copiando o caractere para a nova string
            resultado[posicao++] = str[i];
        }
    }

    // colocando o \0 no final da string
    resultado[posicao] = '\0';
    return resultado;
}

int contains(char* str, char caractere) {
    int tamanhoStr = strlen(str);

    for(int i = 0; i < tamanhoStr; i++) {
        // verificando se o caractere esta na string
        if (str[i] == caractere) {
            return 0; // tem o caractere 
        }
    }
    return 1;
}

int main() {
    // char entrada[100] = "cacocacocaco";

    char* entrada = (char*)malloc(100 * sizeof(char));

    printf("Digite a entrada: ");
    fgets(entrada, 100, stdin); // le somente 99 caracteres e nao preciso fazer verificacao
    
    // alocando espaco suficiente para a string final
    char* strFinal = (char*)malloc(100 * sizeof(char));
    strFinal[0] = '\0';  // colocando o \0

    int count = 0;

    int tamanho = 0;
    char* substr1;
    char* substr2;
    char* substr3;
    char* check;
    char* mudar = (char*)malloc(strlen(entrada)+1);

    for (int i = 0; i < strlen(entrada); i++) {

        for (int j = 0; j < i; j++) {
            substr1 = substring(entrada, j, i);

            tamanho = strlen(substr1);

            if (i + tamanho > strlen(entrada)) {} 
            else {
                substr2 = substring(entrada, i, i + tamanho);
            }

            if (contains(substr1, '_') == 0) {}

            else if (strcmp(substr1, substr2) == 0) {

                for (int k = 0; k < strlen(entrada); k++) {

                    if (k + strlen(substr1) > strlen(entrada)) {} else {
                        substr3 = substring(entrada, k, k + strlen(substr1));

                        if (strcmp(substr2, substr3) == 0) {
                            count++;
                        }
                        free(substr3);
                    }
                }

                for (int l = 0; l < strlen(substr2); l++) {
                    strcat(mudar, "_");
                }


               

                char *newEntrada = replace(entrada, substr2, mudar);
                if (newEntrada == NULL) {
                    printf("Erro na alocaco de memoria :(");
                }


                check = substring(entrada, 0, i);
                if (check != NULL) {
                    char *newCheck = replace(check, "_", "");
                    free(check);
                    check = newCheck;
                }

                if (check != NULL && check[0] == '\0') {
                    strcat(strFinal, check);
                    strcat(strFinal, "1");
                    free(check);
                }

        
                char countStr[100];
                snprintf(countStr, sizeof(countStr), "%d", count);  // convertendo count para string

                strcat(strFinal, substr2);
                strcat(strFinal, countStr);
    
                count = 0;
                mudar[0] = '\0';
                
            }
            
        }   

        }

    printf("%s\n", strFinal);

    free(substr1);
    free(substr2);
    free(strFinal);  // Liberando a memória no final
    free(mudar);

    return 0;
}
