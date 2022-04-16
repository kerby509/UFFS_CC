#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>



int main()  {

  FILE *pont_arq;
  char nome[20]; 
  int x;
  float  y, totalProd, totCompras = 0;
  
  
 
  pont_arq = fopen("aquivocompras.txt", "r");
  
  //testando se o arquivo criado
  if(pont_arq == NULL){
    printf("Erro de abertura do arquivo!");
    exit(1);
  }

  for(int i = 0; fscanf(pont_arq, "%s %d %f", nome, &x, &y)!= EOF; i++){
      totalProd = x * y;
      printf("Produto %i = %.2f\n", totalProd);
      totCompras += totalProd;

  }
  printf("%.2f\n", totCompras);


  
  fclose(pont_arq);
  
  

  return(0);
}