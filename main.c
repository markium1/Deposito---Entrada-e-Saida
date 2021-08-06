#include <stdio.h>
#include<stdlib.h>
#include "deposito.h"
int main(void) {

  Lista *estado = NULL;
  Lista *outroEstado = NULL;
  Lista *foraDoBrasil = NULL;
  int galpao;
  int op = 1;
  int codigoRemover;

  while(op != 0){
    system("clear");
    menu();
    scanf("%d",&op);

    switch(op){

      case 1:
        system("clear");
        printf("************\n  CADASTRO\n************\n\n");
        printf("EM QUAL GALPAO:\n");
        printf("[1] Estado\n[2] Outro Estado\n[3] Fora do BR\n---> ");
        scanf("%d",&galpao);
        if(galpao == 1){

          if(estado == NULL){
            estado = push(estado,galpao);
            if(estado->prox != NULL){
              estado->tam = estado->prox->tam + 1;
            }else{
              estado->tam++;
            }
          }
          else if(estado->tam < 10){
    
            estado = push(estado,galpao);
            if(estado->prox != NULL){
              estado->tam = estado->prox->tam + 1;
            }else{
              estado->tam++;
            }
          }else{
            system("clear");
            printf("Galpao cheio!\n");
            printf("aperte uma tecla pra continuar...\n");
            getchar();
            getchar();
          }
        }
        else if(galpao == 2){
          if(outroEstado == NULL){
            outroEstado = push(outroEstado,galpao);
            if(outroEstado->prox != NULL){
              outroEstado->tam = outroEstado->prox->tam + 1;
            }else{
              outroEstado->tam++;
            }
          }
          else if(outroEstado->tam < 10){
    
            outroEstado = push(outroEstado,galpao);
            if(outroEstado->prox != NULL){
              outroEstado->tam = outroEstado->prox->tam + 1;
            }else{
              outroEstado->tam++;
            }
          }else{
            system("clear");
            printf("Galpao cheio!\n");
            printf("aperte uma tecla pra continuar...\n");
            getchar();
            getchar();
          }
        }
        else if(galpao == 3){
          if(foraDoBrasil == NULL){
            foraDoBrasil = push(foraDoBrasil,galpao);
            if(foraDoBrasil->prox != NULL){
              foraDoBrasil->tam = foraDoBrasil->prox->tam + 1;
            }else{
              foraDoBrasil->tam++;
            }
          }
          else if(foraDoBrasil->tam < 10){
    
            foraDoBrasil = push(foraDoBrasil,galpao);
            if(foraDoBrasil->prox != NULL){
              foraDoBrasil->tam = foraDoBrasil->prox->tam + 1;
            }else{
              foraDoBrasil->tam++;
            }
          }else{
            system("clear");
            printf("Galpao cheio!\n");
            printf("aperte uma tecla pra continuar...\n");
            getchar();
            getchar();
          }
        }
        
        break;

      case 2:
        system("clear");
        printf("\n**********\n EXCLUSAO\n**********\n\n");
        printf("EM QUAL GALPAO:\n");
        printf("[1] Estado\n[2] Outro Estado\n[3] Fora do BR\n---> ");
        scanf("%d",&galpao);

        if(galpao == 1){

          if(estado != NULL){
            printf("Digite o codigo: ");
            scanf("%d", &codigoRemover);
            estado = pop(estado,codigoRemover);
            if(estado != NULL)
              estado->tam--;
          }
          else{
            printf("Galpao Vazio!\n");
            printf("pressione uma tecla pra continuar...");
            getchar();
            getchar();
          }
        }
        else if(galpao == 2){
          if(outroEstado != NULL){
            printf("Digite o codigo: ");
            scanf("%d", &codigoRemover);
            outroEstado = pop(outroEstado,codigoRemover);
            if(outroEstado != NULL)
              outroEstado->tam--;
          }
          else{
            printf("Galpao Vazio!\n");
            printf("pressione uma tecla pra continuar...");
            getchar();
            getchar();
          }
        }
        else if(galpao == 3){
          if(foraDoBrasil != NULL){
            printf("Digite o codigo: ");
            scanf("%d", &codigoRemover);
            foraDoBrasil = pop(foraDoBrasil,codigoRemover);
            if(foraDoBrasil != NULL)
              foraDoBrasil->tam--;
          }
          else{
            printf("Galpao Vazio!\n");
            printf("pressione uma tecla pra continuar...");
            getchar();
            getchar();
          }
        }
        break;
      case 3:
        system("clear");
        printf("\n**********\n  EXIBIR\n**********\n\n");
        printf("QUAL GALPAO:\n");
        printf("[1] Estado\n[2] Outro Estado\n[3] Fora do BR\n---> ");
        scanf("%d",&galpao);

        if(galpao == 1){
          imprimir(estado);
        }
        else if(galpao == 2){
          imprimir(outroEstado);
        }
        else if(galpao == 3){
          imprimir(foraDoBrasil);
        }
        break;
      case 0:
        printf("saindo...\n");
        break;
      default:
        printf("opcao invalida!\n");
        getchar();
        getchar();
        system("clear");
        break;
      
    }
  }

}
