#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>



int main()  {

  FILE *pont_arq, *pont_arq2; 
  char palavra[20]; 
  char texto_str[20];
  char c, c2, c3;
  
 
  pont_arq = fopen("testearquivo.txt", "r");
  
  //testando se o arquivo foi realmente criado
  if(pont_arq == NULL){
    printf("Erro des abertura do arquivo!");
    exit(1);
  }
  
  pont_arq2 = fopen("testearquivo2.txt", "w");
  
  
  while(!feof(pont_arq)){
    c2 = fgetc(pont_arq);
    c3 = toupper(c2);
    fprintf(pont_arq2, "%c", c3);
    printf("%c", c2);
  }








  //usando fclose para fechar o arquivo
  fclose(pont_arq);
  fclose(pont_arq2);
  
  

  return(0);
}