/* P4.c */
/* Eduardo Carvalho Nascimento de Oliveira */
/* 11811EEL017 */

#include <stdio.h>

int recursao(int m, int n)
{
    if(m==0)
    {
        return (n+1);
    }
    if(m>0 && n == 0)
    {
        recursao(m-1,1);
    }
    if(m>0 && n>0)
    {
        recursao(m-1,recursao(m,n-1));
    }
}

int main()
{
    int m, n;
    printf("Digite os valores de m e n: \n");
    scanf("%d %d", &m, &n);
    printf("Resultado: %d\n", recursao(m,n));
    return 0;
}
