/*
524324 1234547 9410656 3 7

3414636319 3873433019 4090743227 4107438988
18867643 217048507 965879227 1206969787
1296295355 1458302971 1474291131 1502042059
2329929147 2569795003 3068126651 3130087099

*/

#include <stdio.h>

// unsigned matriz[1750000][16] = { };
unsigned a, c, x = 0;
int n, t;

void random() { x = ((a * x) + c); }

void bubbleSort(unsigned array[][16], int n) {
  int size = 16;
  // iteramos en las filas
  for (int j = 0; j < n; j++) {
    // ciclo para acceder a cada elemento del arreglo
    for (int step = 0; step < size; ++step) {
      // comparamos los elementos del array
      for (int i = 0; i < size - step - 1; ++i) {
        if (array[j][i] > array[j][i + 1]) {
          // intercambio
          unsigned temp = array[j][i];
          array[j][i] = array[j][i + 1];
          array[j][i + 1] = temp;
        }
      }
    }
  }
}

void printVector(unsigned vec[], int size) {
  for (int i = 0; i < size; i++)
    printf("%u ", vec[i]);
}

int main() {
  scanf("%u%u%u%d%d", &a, &c, &x, &n, &t);
  // tenemos una matriz y su transpuesta
  
  /*unsigned mat[n][16] = {};		//por alguna raz�n, estas lineas no compilan bien
  unsigned matT[16][n] = {};*/
  
  //alternativa a inicializar
  unsigned mat[n][16], matT[16][n];
  	for (int f = 0; f < n; f++) 
        for (int c = 0; c < 16; c++) 
          mat[f][c] = 0;
    for (int f = 0; f < 16; f++) 
        for (int c = 0; c < n; c++) 
          matT[f][c] = 0;
         
    
  
  for (int p = 0; p < t; p++) { // este hara la cantidad de recorridos T
    // cuando hacemos un recorrido non, estamos visitando la matriz tal cual
    // por otro lado, los recorridos pares tienen la forma de su transpuesta
    if (p % 2 == 0) {
      for (int f = 0; f < n; f++) {
        for (int c = 0; c < 16; c++) {
          mat[f][c] += x;
          random();
        }
      }
    } else {
      for (int f = 0; f < 16; f++) {
        for (int c = 0; c < n; c++) {
          matT[f][c] += x;
          random();
        }
      }
    }
  }
  // una vez que terminamos de llenarlas, le sumaremos a la matriz original la
  // 'transpuesta de su transpuesta'
  for (int f = 0; f < n; f++) {
    for (int c = 0; c < 16; c++) {
      mat[f][c] += matT[c][f];
    }
  }

  bubbleSort(mat, n);

  // aqui hacemos la suma final
  unsigned sum[16] = {};
  for (int f = 0; f < n; f++) {
    for (int c = 0; c < 16; c++) {
      sum[c] += mat[f][c];
    }
  }

  printVector(sum, 16);
}
