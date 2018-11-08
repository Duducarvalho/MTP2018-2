/* P5.c */
/* Eduardo Carvalho Nascimento de Oliveira */
/* 11811EEL017 */

#include <stdio.h>
#include <time.h>

typedef
unsigned long long int
Bytes8;
typedef
struct LCG
{
    Bytes8 a, c, m, rand_max, atual;
}
LCG;

void semente(LCG * r, Bytes8 seed)
{
// constantes do POSIX [de]rand48, glibc [de]rand48[_r]
// ULL transforma a constante ’int’ em ’unsigned long long int’
    r->a = 0x5DEECE66DULL;
    r->c = 11ULL;
    r->m = (1ULL << 48);
    r->rand_max = r->m - 1;
    r->atual = seed;
}
Bytes8 lcg_rand(LCG * r)
{
    r->atual = (r->a * r->atual + r->c) % r->m;
    return r->atual;
}
double lcg_rand_01(LCG * r)
{
    return ((double) lcg_rand(r))/(r->rand_max);
}

void gera_numeros(float * vetor, int tam, float min, float max, LCG * r)
{
    int i;
    for(i = 0; i < tam; i++)
        vetor[i] = (max-min)*lcg_rand_01(r) + min;
}

float soma(float *inicio_vetor, float *fim_vetor)
{
	while (inicio_vetor != fim_vetor + 1)
    {
        return (*inicio_vetor + soma(inicio_vetor + 1, fim_vetor));
    }
	return 0;
}

float produto(float *inicio_vetor, float *fim_vetor)
{
	while (inicio_vetor != fim_vetor + 1)
    {
        return (*inicio_vetor * produto(inicio_vetor + 1, fim_vetor));
    }
	return 1;
}

int main()
{
    LCG random;
    semente(&random, 123456);
    int opcao;
    float vetor[50];
    gera_numeros(vetor, 50, 0.5, 1.5, &random);

    do
    {
        printf("Digite 1 para realizar a soma de 50 numeros aleatorios.\n");
        printf("Digite 2 para realizar a multiplicacao de 50 numeros aleatorios.\n");
        printf("Digite 3 para sair do programa.\n");
        printf("Digite a opcao: ");
        scanf("%d", &opcao);
        getchar();
        switch(opcao)
        {
        case 1:
            printf ("\nSomatorio: %f.\n", soma (&vetor[0], &vetor[49]));
            break;
        case 2:
            printf ("\nProdutorio: %f.\n", produto (&vetor[0], &vetor[49]));
            break;
        }
    }
    while(opcao!=3);
    return 0;
}
