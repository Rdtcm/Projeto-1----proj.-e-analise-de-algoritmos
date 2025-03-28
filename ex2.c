#include <stdio.h>
#include <stdlib.h>

int main(void) {
    char entrada[100] = "a7-b5-a10";
    char *ptr_inicio = entrada;
    char *ptr_final = entrada + 1;

    while (*ptr_final != '\0') 
    {
        int valor_ptr_final = atoi(ptr_final);

        for (int i = 0; i < valor_ptr_final; i++) printf("%c", *ptr_inicio);
        
        ptr_inicio += 3;
        ptr_final += 3;
    }
    printf("\n");
}
