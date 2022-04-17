#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// pode alterar o vetor com os valor que quiser
#define MAX 100000


void swap(int *xp, int *yp) 
{ 
    int temp = *xp; 
    *xp = *yp; 
    *yp = temp; 
} 
// funcao selection Sort
void selectionSort(int arr[]) 
{ 
    int i, j, min_idx; 
  

    for (i = 0; i < MAX-1; i++) 
    { 
       
        min_idx = i; 
        for (j = i+1; j < MAX; j++) 
          if (arr[j] < arr[min_idx]) 
            min_idx = j; 
  
        swap(&arr[min_idx], &arr[i]); 
    } 
} 
// funcao decrescente
void Decrescente(int vetor[])
{
    for (int i = 0; i < MAX - 1; i++)
    {
        for (int j = i; j < MAX - 1; j++)
        {
            if (vetor[i] < vetor[j])
            {
                int temp = vetor[i];
                vetor[i] = vetor[j];
                vetor[j] = temp;
            }
        }
    }
   
    
}
//funcao crescente
void Crescente(int vetor[]){
    for (int i=0;i<MAX; i++)
        for(int j=i+1;j<MAX;j++)
        {
            if (vetor[i]>vetor[j])
            {
                int temp = vetor[i];
                vetor[i]=vetor[j];
                vetor[j]=temp;
            }
        }
}
// mostra vetor
void mostrarVetor(int vetor[])
{
    for (int i = 0; i < MAX - 1; i++)
    {
        printf("%d ", vetor[i]);
    }
    printf("\n");
}




int main(){
    srand(time(NULL));
    int vectorSelect[MAX];
    clock_t start, finish;
    double tempo[3];

    int vectorDecrescente[MAX], vectorCrescente[MAX];
    

    printf("Valores desordenados:\n"); 
    for(int i = 0; i < MAX; i++){
        int random = rand() % 5000;
        vectorSelect[i] = random;

        i == MAX - 1 ? printf("%d.\n\n\n", random): printf("%d, ", random);
    }


    printf("Valores Decrescente:\n");
    for(int j = 0; j < MAX; j++){
        int random = rand() % 5000;
        vectorDecrescente[j] = random;
    }
    // adicionando numa função para deixar decrescente
    Decrescente(vectorDecrescente); 
    //mostra valores aleatorio em decrescente
    
    mostrarVetor(vectorDecrescente); 

    printf("\nValores Crescente:\n");
    for(int n = 0; n < MAX; n++){
        int random = rand() % 5000;
        vectorCrescente[n] = random;
    }
      // adicionando numa função para deixar crescente
    Crescente(vectorCrescente); 
    //mostra valores aleatorio em crescente
    mostrarVetor(vectorCrescente); 
    

    
    
    printf("\n\n=============================================");
    printf("\n\t\t\t ***MetodoMetodo Select Sort*** \n");
    
    start = clock();
    selectionSort(vectorCrescente);
    finish = clock();

  
    tempo[0] = (finish - start) * 1000.0 / CLOCKS_PER_SEC;

    start = clock();
    selectionSort(vectorDecrescente);
    finish = clock();

    tempo[1] = (finish - start) * 1000.0 / CLOCKS_PER_SEC;

    start = clock();
    selectionSort(vectorSelect);
    finish = clock();
    
    tempo[2] = (finish - start) * 1000.0 / CLOCKS_PER_SEC;


    printf("\n");
    printf("\nTempo gasto por cada função :\n");
    printf("Select Sort Crescente:    %.5lf ms\n", tempo[0]);
    printf("Select Sort Decrescente:    %.5lf ms\n", tempo[1]);
    printf("Select Sort Aleatorio:    %.5lf ms\n", tempo[2]);
    printf("\n");
}

