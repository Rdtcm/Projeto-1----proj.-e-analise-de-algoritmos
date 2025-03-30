/*
Nome:Renan Horochk de Andrade
RA:10438120
-------------------------------
Nome:Ryan Vinicius Ledo
RA:10352727
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>


#define MAX 256


typedef struct {
    char *str;
    int tamanho;
} String;


String criarString(const char *str) {
    String s;
    s.tamanho = strlen(str);
    s.str = (char*)malloc((s.tamanho + 1) * sizeof(char));
    strcpy(s.str, str);
    return s;
}

// liberando a memória alocada para uma string
void liberarString(String *s) {
    free(s->str);
}

// função para substituir todas as ocorrências da substring em s->str por '_' (mantendo o mesmo comprimento)
void substituirSubstring(String *s, const char *candidato) {
    int len = strlen(candidato);
    // cria uma nova string para armazenar o resultado da substituição
    char novaStr[MAX] = "";
    int i = 0;
    while(i < s->tamanho) {

        if(i <= s->tamanho - len && strncmp(s->str + i, candidato, len) == 0) {

            for (int j = 0; j < len; j++) {
                strncat(novaStr, "_", 1);
            }
            i += len;
        } else {

            int lenNova = strlen(novaStr);
            novaStr[lenNova] = s->str[i];
            novaStr[lenNova+1] = '\0';
            i++;
        }
    }

    strcpy(s->str, novaStr);
    s->tamanho = strlen(novaStr);
}

// função para contar quantas vezes a substring candidato aparece em s->str
int contarOcorrencias(String *s, const char *candidato) {
    int count = 0;
    int len = strlen(candidato);
    for (int i = 0; i <= s->tamanho - len; i++) {
        char trecho[MAX] = "";
        strncpy(trecho, s->str + i, len);
        trecho[len] = '\0';
        if(strcmp(candidato, trecho) == 0) {
            count++;
        }
    }
    return count;
}

void removerUnderscores(const char *orig, char *dest) {
    int j = 0;
    for (int i = 0; orig[i] != '\0'; i++) {
        if(orig[i] != '_') {
            dest[j++] = orig[i];
        }
    }
    dest[j] = '\0';
}

void comprimirString(String *s) {
    char resultado[MAX] = "";

    for (int i = 1; i < s->tamanho; i++) {
        for (int k = 0; k < i; k++) {

            int tamanhoSubstr = i - k;
            char candidato[MAX] = "";
            strncpy(candidato, s->str + k, tamanhoSubstr);
            candidato[tamanhoSubstr] = '\0';
            
            // se o candidato contém "_" entao pula
            if (strchr(candidato, '_') != NULL)
                continue;
            
            if(i + tamanhoSubstr <= s->tamanho) {
                char test2[MAX] = "";
                strncpy(test2, s->str + i, tamanhoSubstr);
                test2[tamanhoSubstr] = '\0';
                
                if(strcmp(candidato, test2) == 0) {
                    // Conta quantas vezes o candidato aparece em s->str
                    int cont = contarOcorrencias(s, candidato);
                    
                    substituirSubstring(s, candidato);
                    
                    char prefixo[MAX] = "";
                    strncpy(prefixo, s->str, i);
                    prefixo[i] = '\0';
                    char prefixoLimpo[MAX] = "";
                    removerUnderscores(prefixo, prefixoLimpo);
                    
                    if(strlen(prefixoLimpo) > 0) {
                        strcat(resultado, prefixoLimpo);
                        strcat(resultado, "1");
                    }
                    
                    // aadiciona a substring e sua contagem
                    char buffer[MAX] = "";
                    snprintf(buffer, MAX, "%s%d", candidato, cont);
                    strcat(resultado, buffer);
                }
            }
        }
    }
    printf("String compactada: %s\n", resultado);
}

int main() {
    String input[100];
    printf("Informe a entrada: ");
    scanf("%s", input);
    String entrada = criarString(input);
    comprimirString(&entrada);
    liberarString(&entrada);
    return 0;
}



