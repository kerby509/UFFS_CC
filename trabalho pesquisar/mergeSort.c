#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <math.h>

#define tam1 10000
#define tam2 50000
#define tam3 100000


void merge(int arr[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;
 
    /* create temp arrays */
    int L[n1], R[n2];
 
    /* Copy data to temp arrays L[] and R[] */
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];
 
    /* Merge the temp arrays back into arr[l..r]*/
    i = 0; // Initial index of first subarray
    j = 0; // Initial index of second subarray
    k = l; // Initial index of merged subarray
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
 
    /* Copy the remaining elements of L[], if there
    are any */
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
 
    /* Copy the remaining elements of R[], if there
    are any */
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}
 
/* l is for left index and r is right index of the
sub-array of arr to be sorted */
void mergeSort(int arr[], int l, int r)
{
    clock_t start, end;
start = clock();
    if (l < r) {
        // Same as (l+r)/2, but avoids overflow for
        // large l and h
        int m = l + (r - l) / 2;
 
        // Sort first and second halves
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
 
        merge(arr, l, m, r);
    }

    end = clock();

  double difTempo = ((double)end - start) / CLOCKS_PER_SEC;

  printf("\n\n\n\t -> Tempo em s: %lf, Tempo em ms: %lf", difTempo, difTempo * 1000);
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

//  Ordenando os 3 vetores de tamanho 10000, com o tempo de execução
  mergeSort(vet1,0, tam1-1);
  mergeSort(vet2, 0,  tam1-1);
  mergeSort(vet3,0, tam1-1);
  printf("\n");

//   Ordenando os 3 vetores de tamanho 50000, com o tempo de execução
  mergeSort(vet4, 0, tam2-1);
  mergeSort(vet5, 0, tam2-1);
  mergeSort(vet6, 0, tam2-1);
  printf("\n");

//    Ordenando os 3 vetores de tamanho 100000, com o tempo de execução
  mergeSort(vet7, 0, tam3-1);
  mergeSort(vet8, 0, tam3-1);
  mergeSort(vet9, 0, tam3-1);
  printf("\n");

  return 0;
}