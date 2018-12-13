/* P7.c */
/* Eduardo Carvalho Nascimento de Oliveira */
/* 11811EEL017 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct Ponto
{
    double x;
    double y;
} Ponto;


Ponto * gerarcoord(int n)
{
    int i;
    Ponto * coord = (Ponto *) calloc(n,sizeof(Ponto));
    for(i=0; i<n; i++)
    {
        coord[i].x = cos(i*2.0*M_PI/(n-1));
        coord[i].y = sin(i*2.0*M_PI/(n-1));
    }
    return coord;
}

void mostrarcoord(Ponto * p_ini, Ponto * p_fim)
{
    if(p_ini < p_fim)
    {
        printf("(%.3lf, %.3lf) ", p_ini->x, p_ini->y);
        mostrarcoord(p_ini+1, p_fim);
    }
}

void gravacoord(Ponto * p_ini, int n)
{
    FILE * arquivo;
    arquivo = fopen ("coord.dat", "wb");
    fwrite(p_ini, n, sizeof(Ponto), arquivo);
    fclose(arquivo);
}

Ponto * lercoord(char * nome_arquivo, unsigned int *pn)
{
    Ponto * coord = (Ponto *) malloc(sizeof(Ponto));
    unsigned int n = 0;
    FILE * arquivo;
    arquivo = fopen(nome_arquivo, "rb");
    while(1)
    {
        fread(coord, 1, sizeof(Ponto), arquivo);
        if(feof(arquivo))
            break;
        n++;
    }
    rewind(arquivo);
    coord = (Ponto *) realloc(coord, n*sizeof(Ponto));
    fread(coord, n, sizeof(Ponto), arquivo);
    fclose(arquivo);
    *pn = n;
    return coord;
}

int main()
{
    unsigned int n, opcao;
    Ponto * coord;
    printf("Digite 1 para gravar um arquivo; Digite 2 para ler arquivo: ");
    scanf("%u", &opcao);
    getchar();
    if(opcao==2)
    {
        coord = lercoord("coord.dat", &n);
        mostrarcoord(coord, coord + n);
    }
    else
    {
        printf("Digite o numero de pontos: ");
        scanf("%u", &n);
        getchar();
        coord = gerarcoord(n);
        gravacoord(coord, n);
        printf("Arquivo gravado");
    }
    free(coord);
    return 0;
}
