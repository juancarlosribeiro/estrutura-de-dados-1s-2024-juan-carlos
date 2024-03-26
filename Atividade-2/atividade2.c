#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Erro!\nAdicione um, e apenas um numero inteiro");
        exit(0);
    }
    if (atoi(argv[1]) < 2)
    {
        printf("false");
        return -1;
    }
    for (int i = 2; i < atoi(argv[1]); i++)
    {
        if (atoi(argv[1]) % i == 0)
        {
            printf("false");
            return -1;
        }
    }
    printf("true");
    exit(0);
}