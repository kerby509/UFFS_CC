
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define tam 15

typedef struct Veiculos {
  int ano ;
  char modelo[30];
}veiculo;
  
int getMax(veiculo vet[], int n) {
  int max = vet[0].ano;
  for (int i = 1; i < n; i++)
    if (vet[i].ano > max)
      max = vet[i].ano;
  return max;
}

void countingSort(veiculo vet[], int size, int place) {
  veiculo output[size];

  int count[10];

  for (int i = 0; i < 10; ++i)
    count[i] = 0;

  // faço a contagem dos elementos
  for (int i = 0; i < size; i++)
    count[(vet[i].ano / place) % 10]++;

  //aqui faço  a contagem cumulativa
  for (int i = 1; i < 10; i++)
    count[i] += count[i - 1];

  // coloco os elementos em ordem 
  for (int i = size - 1; i >= 0; i--) {
    output[count[(vet[i].ano / place) % 10] - 1] = vet[i];
    count[(vet[i].ano / place) % 10]--;
  }

  for (int i = 0; i < size; i++)
    vet[i] = output[i];
  }

void radixsort(veiculo vet[], int size) {
  // Obter máximo
  int max = getMax(vet, size);

  // Aplique classificação por contagem para classificar os elementos com base no valor local.
  for (int place = 1; max / place > 0; place *= 10)
    countingSort(vet, size, place);
}


int main (void) {
  veiculo vet[tam]; 

  // Preencher o vetor
  for(int i = 0; i<tam; i++){
      printf("Entre o ano  do veiculo %d:\n", i+1);
      scanf("%d", &vet[i].ano);
      printf("Entre o nome  do veiculo %d:\n", i+1);
      scanf("%s", vet[i].modelo);
  }

  radixsort(vet, tam);


  printf("\n");
  printf("=========================================================\n");
    for(int i = 0; i < tam; i++){
          printf("\t%d - %s\n", vet[i].ano, vet[i].modelo);
    }
  printf("========================================================\n");

  return 0;
}