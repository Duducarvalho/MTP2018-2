#include <stdio.h>

int main()
{
    int estado = 0, estado1, i;
    char bits[256], bits1[256];
    printf("\nDigite a sua sequencia: ");
    scanf("%s", bits);

    for(i=0 ;bits[i] != '\0'; i ++)
    {
        if(estado == 0 && bits[i] == '0')
        {
            estado=0;
        }
        else if(estado == 0 && bits[i] == '1')
        {
            estado=1;
        }
        else if(estado == 1 && bits[i] == '1')
        {
            estado=0;
            bits1[i]=bits[i];
        }
        else if(estado == 1 && bits[i] == '0')
        {
            estado=2;
        }
        else if(estado == 2 && bits[i] == '0')
        {
            estado=1;
        }
        else if(estado == 2 && bits[i] == '1')
        {
            estado=2;
        }
        estado1=estado;
    }
    printf ("\nValor da variavel que representa o estado: %d", estado1);
    printf ("\nSequencia original digitada: %s", bits);
    if (estado == 0)
    {
        printf("\nEh multiplo de 3.");
    }
    else
    {
        printf("\nNao eh");
    }
    return 0;
}
