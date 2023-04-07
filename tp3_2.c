#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define A 5
#define M 12

void ganancia (int a[A][M]);
void maxYmin (int a[A][M]);

int main () {

    int simulacro[A][M];

    srand(time(NULL));

    for (int i = 0; i < A; i++)
    {
        for (int j = 0; j < M; j++)
        {
            simulacro[i][j] = rand() % 40001 + 10000;
            printf("%7d", simulacro[i][j]);
        }
        printf("\n");
    }

    ganancia(simulacro);
    maxYmin(simulacro);

    return 0;
}

void ganancia (int a[A][M])
{
    float resultado;
    int aux=0;

    for (int i = 0; i < A; i++)
    {
        for (int j = 0; j < M; j++)
        {
            aux = aux + a[i][j];
        }
        resultado = (float)aux/12;

        printf("\n\n---- PROMEDIO GANANCIA ANIO %d: %.2f ----\n\n", i+1, resultado); 
    }
}

void maxYmin (int a[A][M])
{
    int max=50000, min=10000, amin, mmin, amax, mmax; //los aux son para guardar el año y mes de los max y min

    for (int i = 0; i < A; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (a[i][j]< max)
            {
                max = a[i][j];
                amin = i +1;
                mmin = j +1;
            }

            if (a[i][j]>min)
            {
                min = a[i][j];
                amax = i +1;
                mmax = j +1;
            }
        }
    }

    printf("\nEl valor minimo es %d, se obtiene en el anio %d en el mes %d\n", max, amin, mmin);
    printf("El valor maximo es %d, se obtiene en el anio %d en el mes %d\n", min, amax, mmax);
    
}