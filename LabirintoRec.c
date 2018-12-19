#include <stdio.h>

void print_Lab(char Labirinto[8][8]) {
  int i, j;
  printf("            ----------\n");
  for (i = 0; i < 8; i++){
    printf("            |");
    for (j = 0; j < 8; j++){
      printf("%c", Labirinto[i][j]);
    }
    printf("|\n");
  }
  printf("            ----------\n");
}

int caminho_Lab(char Labirinto[8][8], int i, int j) {

  if (Labirinto[i][j] == '1') {
    return 0;
  }
  else if (i == 8 - 1 && j == 8 - 1) {
    Labirinto[i][j] = 'X';
    return 1;
  }
  else {
    Labirinto[i][j] = '1';
    if      (caminho_Lab(Labirinto, i, j + 1)) {
      Labirinto[i][j] = 'X';
      return 1;
    }
    else if (caminho_Lab(Labirinto, i, j - 1)) {
      Labirinto[i][j] = 'X';
      return 1;
    }
    else if (caminho_Lab(Labirinto, i + 1, j)) {
      Labirinto[i][j] = 'X';
      return 1;
    }
    else if (caminho_Lab(Labirinto, i - 1, j)) {
      Labirinto[i][j] = 'X';
      return 1;
    }
  }
}

int main() {
  int i=0, j=0;
  char Labirinto[8][8] =  {'0','0','1','0','0','0','1','1',
                          '1','0','1','0','1','1','1','1',
                          '1','0','1','0','0','0','0','0',
                          '1','0','1','1','0','1','1','0',
                          '1','0','0','0','0','1','1','0',
                          '1','0','1','1','0','1','1','1',
                          '1','0','1','0','0','0','0','0',
                          '1','1','1','1','1','1','1','0'};
  printf("Labirinho antes de ser resolvido: \n");

  print_Lab(Labirinto);
  printf("OBS: Numeros '1' representam paredes e numeros '0' representam caminhos.\n\n");
  caminho_Lab(Labirinto, i, j);
  printf("\nLabirinho resolvido: \n");

  print_Lab(Labirinto);
  printf("OBS: A letra 'X' indica o caminho feito.\n\n");
  return 0;
}
