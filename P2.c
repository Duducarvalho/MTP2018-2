/* P2.c */
/* Eduardo Carvalho Nascimento de Oliveira */
/* 11811EEL017 */

#include <stdio.h>

int binariopdecimal(char bits[256])
{
    int cont, cont1=0,cont2=1, soma=0, vet[256], i, contt;
    char bits1[256];
    for (cont = 1; bits[cont] != '\0'; cont++);
    contt=cont-1;
    for (i=0; i<cont; i++)
    {
        bits1[i]=bits[contt];
        contt--;
    }
    for(i=0; i<cont; i++)
    {
        if(bits1[i]== '0')
        {
            vet[i]=0;
        }
        if(bits1[i]== '1')
        {
            vet[i]=1;
        }
    }
    while(cont1<cont)
    {
        soma = soma+(vet[cont1]*cont2);
        cont2=cont2*2;
        cont1++;
    }
    return soma;
}
void binariophexadecimal(char bits[256])
{
    int cont, cont1=0,cont2=1, soma=0, vet[256], i, contt, conversao;
    char bits1[256];
    for (cont = 1; bits[cont] != '\0'; cont++);
    contt=cont-1;
    for (i=0; i<cont; i++)
    {
        bits1[i]=bits[contt];
        contt--;
    }
    for(i=0; i<cont; i++)
    {
        if(bits1[i]== '0')
        {
            vet[i]=0;
        }
        if(bits1[i]== '1')
        {
            vet[i]=1;
        }
    }
    while(cont1<cont)
    {
        soma = soma+(vet[cont1]*cont2);
        cont2=cont2*2;
        cont1++;
    }
    conversao=soma;
    printf("Coversao: %x", conversao);
}

int mudarParaNumero(char c)
{
    if(c>='0'&& c<='9')
    {
        c=c-'0';
    }
    else
    {
        if(c>='A'&& c<='F')
        {
            c=c-'A'+10;
        }
        else if(c>='a'&& c<='f')
        {
            c=c-'a'+10;
        }
    }
    return c;
}
int hexadecimalpdecimal(char str[])
{
    int i=0,cont,expoente=0, elevar=1;
    for(; str[i]; i++);
    int soma=0;
    for(cont=i-1; cont>=0; cont--)
    {
        int valorDaletra=mudarParaNumero(str[cont]);
        soma=soma+valorDaletra*elevar;
        elevar=elevar*16;

    }
    return soma;
}

int mudarParaNumerob(char c)
{
    if(c>='0'&& c<='9')
    {
        c=c-'0';
    }
    else
    {
        if(c>='A'&& c<='F')
        {
            c=c-'A'+10;
        }
        else if(c>='a'&& c<='f')
        {
            c=c-'a'+10;
        }
    }
    return c;
}

void decimalpbinario(int dec,char str[],int bits)
{
    int index=0,i=bits-1;
    str[bits]=0;
    for(; index<bits; index++)
    {
        if(dec%2==1)
        {
            str[i]='1';
        }
        else
        {
            str[i]='0';
        }
        dec=dec/2;
        i--;
    }

}
int hexadecimalpbinario(char str[])
{
    int i=0,cont,expoente=0, elevar=1;
    for(; str[i]; i++);
    int soma=0;
    for(cont=i-1; cont>=0; cont--)
    {
        int valorDaletra=mudarParaNumerob(str[cont]);
        soma=soma+valorDaletra*elevar;
        elevar=elevar*16;
    }
    return soma;
}

void decimalpbinariof(int dec,char str[],int bits){
	int index=0,i=bits-1;
str[bits]=0;
	for(;index<bits;index++){
		if(dec%2==1){
			str[i]='1';
		}else{
			str[i]='0';
		}
		dec=dec/2;
i--;
	}

}

void decimalphexadecimal(int numero)
{
    printf("O valor da conversao, de decimal para hexadecimal eh: %x", numero);
}
void decimalpoctal(int numero)
{
    printf("O valor da conversao, de decimal para octal eh: %o", numero);
}
void octalpdecimal(int numero)
{
    printf("O valor da conversao, de octal para decimal eh: %d", numero);
}



int main ()
{
    int opcao, c1, c2, c3, n1, numero;
    char bits[256];
    do
    {
        printf("\n\nDigite a opcao para realizar conversoes: ");
        printf("\n1-Binario para decimal.");
        printf("\n2-Binario para hexadecimal.");
        printf("\n3-Hexadecimal para decimal.");
        printf("\n4-Hexadecimal para binario.");
        printf("\n5-Decimal para binario.");
        printf("\n6-Decimal para hexadecimal.");
        printf("\n7-Octal para decimal.");
        printf("\n8-Decimal para octal.");
        printf("\n9-Para sair do programa.");
        printf("\nSua opcao eh: ");
        scanf("%d", &opcao);


        switch(opcao)
        {
        case 1:
            printf("\nDigite o valor desejado para conversao: ");
            scanf("%s", bits);
            getchar();
            c1=binariopdecimal(bits);
            printf("O valor da conversao, de binario para decimal eh: %d", c1);
            break;
        case 2:
            printf("\nDigite o valor desejado para conversao: ");
            scanf("%s", bits);
            getchar();
            binariophexadecimal(bits);
            break;
        case 3:
            printf("\nDigite o valor desejado para conversao: ");
            scanf("%s", bits);
            getchar();
            c2=hexadecimalpdecimal(bits);
            printf("O valor da conversao, de binario para decimal eh: %d", c2);
            break;
        case 4:
            printf("\nDigite o valor desejado para conversao: ");
            scanf("%s", bits);
            getchar();
            decimalpbinario(hexadecimalpbinario(bits),bits,15);
            printf("O valor da conversao, de hexadecimal para binario eh: %s", bits);
            break;
        case 5:
            printf("\nDigite o valor desejado para conversao: ");
            scanf("%d", &numero);
            decimalpbinariof(numero,bits,10);
            printf("O valor da conversao, de decimal para binario eh: %s", bits);
            break;
        case 6:
            printf("\nDigite o valor desejado para conversao: ");
            scanf("%d", &numero);
            decimalphexadecimal(numero);
            break;
        case 7:
            printf("\nDigite o valor desejado para conversao: ");
            scanf("%o", &numero);
            octalpdecimal(numero);
            getchar();
            break;
        case 8:
            printf("\nDigite o valor desejado para conversao: ");
            scanf("%d", &numero);
            decimalpoctal(numero);
            break;
        case 9:
            break;
        default:
            break;
        }
    }
    while(opcao != 9);
    return 0;
}
