/* P6.c */
/* Eduardo Carvalho Nascimento de Oliveira */
/* 11811EEL017 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct Ponto{
    double x;
    double y;
}Ponto;


Ponto * gerarcoord(int n) {
    int i;
    Ponto * coord = (Ponto *) calloc(n,sizeof(Ponto));
    for(i=0;i<n;i++)
    {
        coord[i].x = cos(i*2.0*M_PI/(n-1));
        coord[i].y = sin(i*2.0*M_PI/(n-1));
    }
    return coord;
}

void mostrarcoord(Ponto * p_ini, Ponto * p_fim) {
    if(p_ini < p_fim) {
        printf("(%.3lf, %.3lf) ", p_ini->x, p_ini->y);
        mostrarcoord(p_ini+1, p_fim);
    }
}

int main()
{
    int n;
    Ponto * coord;
    printf("Digite o numero de pontos desejados: ");
    scanf("%d", &n);
    getchar();
    coord = gerarcoord(n);
    mostrarcoord(coord, coord + n);
    free(coord);
    return 0;
}
