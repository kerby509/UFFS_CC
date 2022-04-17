
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define tam 4

typedef struct Produtos {
  int numProduto ;
  char nome[30];
}produto;
  
int getMax(produto vet[], int n) {
  int max = vet[0].numProduto;
  for (int i = 1; i < n; i++)
    if (vet[i].numProduto > max)
      max = vet[i].numProduto;
  return max;
}

void countingSort(produto vet[], int size, int place) {
  produto output[size];

  int count[10];

  for (int i = 0; i < 10; ++i)
    count[i] = 0;

  // faço a contagem dos elementos
  for (int i = 0; i < size; i++)
    count[(vet[i].numProduto / place) % 10]++;

  //aqui faço  a contagem cumulativa
  for (int i = 1; i < 10; i++)
    count[i] += count[i - 1];

  // coloquo os elementos em ordem 
  for (int i = size - 1; i >= 0; i--) {
    output[count[(vet[i].numProduto / place) % 10] - 1] = vet[i];
    count[(vet[i].numProduto / place) % 10]--;
  }

  for (int i = 0; i < size; i++)
    vet[i] = output[i];
  }

void radixsort(produto vet[], int size) {
  // Obter máximo
  int max = getMax(vet, size);

  // Aplique classificação por contagem para classificar os elementos com base no valor local.
  for (int place = 1; max / place > 0; place *= 10)
    countingSort(vet, size, place);
}


int main (void) {
  produto vet[tam]; 

  // Preencher o vetor
  for(int i = 0; i<tam; i++){
      printf("Entre o codigo  do produto %d:\n", i+1);
      scanf("%d", &vet[i].numProduto);
      printf("Entre o nome  do produto %d:\n", i+1);
      scanf("%s", vet[i].nome);
  }

  radixsort(vet, tam);


  printf("\n");
  printf("=========================================================\n");
    for(int i = 0; i < tam; i++){
          printf("\t%d - %s\n", vet[i].numProduto, vet[i].nome);
    }
  printf("========================================================\n");

  return 0;
}
