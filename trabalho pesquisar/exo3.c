#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>



int main()  {
  int matricula, iaa;
  char nome[70];
  FILE *pont_arq;


  printf("Sua matricula:");
  scanf("%d", &matricula);

  printf("Seu nome:");
  scanf("%s", nome);

  printf("Seu IAA: ");
  scanf("%d", &iaa);


  
  
 
  pont_arq = fopen("aquivoBinary.txt", "wb");
   fprintf(pont_arq, "%d %s %d", matricula, nome, iaa);

   fseek(pont_arq, 0, SEEK_SET);
  
 

  
  fclose(pont_arq);
  
  

  return(0);
}