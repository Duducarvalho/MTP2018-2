/* P3.c */
/* Eduardo Carvalho Nascimento de Oliveira */
/* 11811EEL017 */


#include <stdio.h>


int main()
{
    int i, k=0, cum=0;
    char str[256], str1[256];
    printf("Digite sua string: ");
    scanf("%s", str);
    for(i=0;str[i]!='\0';i++)
    {
        if(str[i]>='0' && str[i]<='9')
        {
            str1[k]=str[i];
            k++;
        }
    }
    str1[k]='\0';
    for(i=0;str1[i]!='\0';i++)
    {
			cum = cum*10 + str1[i] - '0';
    }
    printf("Numeros: %d", cum);
    return 0;
}
