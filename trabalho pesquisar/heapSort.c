#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#define tam1 10000
#define tam2 50000
#define tam3 100000



void heapSort(int vet[], int n){
    clock_t start, end;
    start = clock();
  int troca;
  int meio = (n - 1) / 2;

  
  for(int i = meio; i >= 0; i--){
    criaHeap(vet, i, n - 1);
  }


  for(int i = n - 1; i >= 1; i--){
    
  
    troca = vet[0];
    vet[0] = vet[i];
    vet[i] = troca;

    
    criaHeap(vet, 0, i - 1);
  }

    end = clock();

  double difTempo = ((double)end - start) / CLOCKS_PER_SEC;

  printf("\n\n\n\t -> Tempo em s: %lf, Tempo em ms: %lf", difTempo, difTempo * 1000);
} 

void criaHeap(int vet[], int inicio, int fim){
  int valor;
  int pai = vet[inicio];
  int filho = inicio * 2 + 1;
  valor=rand()%1000;


  while(filho <= fim){
    
    if(filho < fim){
      if(vet[filho] < vet[filho + 1]){
        filho = filho + 1;
      }
    }

  
  
    if(pai < vet[filho]){
      vet[inicio] = vet[filho];
      inicio = filho;
      filho = 2 * inicio + 1;
    }else{
      filho = fim + 1;
    }
  }
  

  vet[inicio] = pai;
}





void ordemCrescente(int vet[], int n){
  int i, j, k;

  srand(time(NULL));
  for (k = 0; k < n; k++){
    vet[k] = rand() % 100;
  }

  for (i = 0; i < n; i++){
    for (j = i + 1; j < n; j++){
      if (vet[i] > vet[j]){
        int aux = vet[j];
        vet[j] = vet[i];
        vet[i] = aux;
      }
    }
  }
  
}

void ordemDecrescente(int vet[], int n){
  int i, j, k;

  srand(time(NULL));
  for (k = 0; k < n; k++){
    vet[k] = rand() % 100;
  }

  for (i = 0; i < n; i++){
    for (j = i + 1; j < n; j++){
      if (vet[i] < vet[j]){
        int aux = vet[j];
        vet[j] = vet[i];
        vet[i] = aux;
      }
    }
  }
  
}

void ordemAleatorio(int vet[], int tam){
  int i;
  srand(time(NULL));
  for (i = 0; i < tam; i++)
  {
    vet[i] = rand() % 100;
  }
}

int main(){
  int *vet1, *vet2, *vet3;
  int *vet4, *vet5, *vet6;
  int *vet7, *vet8, *vet9;


  vet1 = malloc(tam1 * sizeof(int));
  vet2 = malloc(tam1 * sizeof(int));
  vet3 = malloc(tam1 * sizeof(int));

  vet4 = malloc(tam2 * sizeof(int));
  vet5 = malloc(tam2 * sizeof(int));
  vet6 = malloc(tam2 * sizeof(int));

  vet7 = malloc(tam3 * sizeof(int));
  vet8 = malloc(tam3 * sizeof(int));
  vet9 = malloc(tam3 * sizeof(int));

  //Gerando 3 vetores de tamanho 10000
  ordemCrescente(vet1, tam1);
  ordemDecrescente(vet2, tam1);
  ordemAleatorio(vet3, tam1);

//   Gerando 3 vetores de tamanho 50000
  ordemCrescente(vet4, tam2);
  ordemDecrescente(vet5, tam2);
  ordemAleatorio(vet6, tam2);

  //Gerando 3 vetores de tamanho 100000
  ordemCrescente(vet7, tam3);
  ordemDecrescente(vet8, tam3);
  ordemAleatorio(vet9, tam3);

  //Ordenando os 3 vetores de tamanho 10000, com o tempo de execução
  heapSort(vet1, tam1);
  heapSort(vet2, tam1);
  heapSort(vet3, tam1);
  printf("\n");

//   Ordenando os 3 vetores de tamanho 50000, com o tempo de execução
  heapSort(vet4, tam2);
  heapSort(vet5, tam2);
  heapSort(vet6, tam2);
  printf("\n");

  //Ordenando os 3 vetores de tamanho 100000, com o tempo de execução
  heapSort(vet7, tam3);
  heapSort(vet8, tam3); 
  heapSort(vet9, tam3);
  printf("\n");

  

  return 0;
}




