#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    double x;
    double y;
} Ponto;

int main(int argc, char *argv[])
{
    double somatorio1 = 0;
    double somatorio2 = 0;
    double media_x = 0;
    double media_y = 0;
    double x;
    double y;
    int size = 0;
    char c;

    double inclinacao = 0;
    double intercepcao = 0;

    FILE *arq;
    FILE *arq2;

    arq = fopen(argv[1], "r");
    if (arq == NULL)
    {
        printf("Arquivo nao encontrado");
        return 0;
    }

    while (fscanf(arq, "%lf%c%lf", &x, &c, &y) != EOF)
    {
        size++;
    }
    fclose(arq);

    double *arrX = (double *)malloc(size * sizeof(double));
    double *arrY = (double *)malloc(size * sizeof(double));
    int index = 0;
    arq = fopen(argv[1], "r");
    while (fscanf(arq, "%lf%c%lf", &x, &c, &y) != EOF)
    {
        arrX[index] = x;
        arrY[index] = y;
        media_x += x;
        media_y += y;
        index++;
    }
    fclose(arq);
    media_x /= size;
    media_y /= size;
    // printf("media x = %lf, media y = %lf\n", media_x, media_y);

    for (int i = 0; i < size; i++)
    {
        somatorio1 += ((arrX[i] - media_x) * (arrY[i] - media_y));
        somatorio2 += ((arrX[i] - media_x) * (arrX[i] - media_x));
    }

    inclinacao = somatorio1 / somatorio2;

    intercepcao = media_y - (inclinacao * media_x);

    printf("y = %.1lfx + %.0lf", inclinacao, intercepcao);
}
