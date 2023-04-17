#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main (){
    
       char arre[5][100];
       char *nombres[5], *buff=&arre[0][0];

       for (int i = 0; i < 5; i++)
       {
            printf("Ingrese un nombre: ");
            gets(buff);

            nombres[i] = malloc((strlen(buff)+1) * sizeof(char));
            strcpy(nombres[i],buff);

            //free(buff);
            //free(nombres[i]);
       }

        printf("\n\n-----LISTADO DE NOMBRES-----\n");
       for (int j = 0; j < 5; j++)
       {
            puts(nombres[j]);
       }

    
    return 0;
}