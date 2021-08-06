#include "deposito.h"


void menu(){
    printf("****************************\n");
    printf("        MENU INICIAL\n");
    printf("*****************************\n");
    printf("[1] CADASTRAR PACOTES\n[2] REMOVER PACOTES\n[3] VISUALIZAR PACOTES\n[0] SAIR\n--> ");
}
Lista* push(Lista* l, int ori) {

  Lista* aux = (Lista*)malloc(sizeof(Lista));

  int cod;
  float pesoD;
  printf("DIGITE O CODIGO DO PRODUTO:");
  scanf("%d",&cod);
  printf("DIGITE O PESO DO PRODUTO (KG): ");
  scanf("%f", &pesoD);

  if(ori == 1){
    strcpy(aux->origem, "ESTADO");
  }
  else if(ori == 2){
    strcpy(aux->origem, "FORA DO ESTADO");
  }
  else if(ori == 3){
    strcpy(aux->origem, "FORA DO BRASIL");
  }

    aux->codigo = cod;
    aux->peso = pesoD;
    aux->ant = NULL;
    aux->prox = l;
    
    if (l != NULL)
        l->ant = aux;
    
    system("clear");
    printf("PACOTE CHEGANDO!!\n");
    printf("Aperte uma tecla pra continuar...");
    getchar();
    getchar();
    return aux;
}

void imprimir(Lista* l) {
    Lista* aux = l;
    float precoTotal;
    system("clear");
    printf("\n****************\nEXIBICAO PACOTES\n****************\n");

    if(aux == NULL){
      printf("VAZIO!\n");
    }
   while (aux != NULL) {
        printf("CODIGO PRODUTO: %d\n", aux->codigo);
        printf("PESO: %.2f\n", aux->peso);
        printf("QT REMOVIDO: %d\n", aux->tirado);
        printf("ORIGEM: %s\n", aux->origem);
        printf("----------------------\n");
        aux = aux->prox;
    }
    printf("aperte uma tecla pra continuar...");
    getchar();
    getchar();
}

Lista* pop(Lista *l, int valor){
  Lista *aux = l;

  while (aux!=NULL && aux->codigo!=valor){
    aux->tirado++;
    aux = aux->prox;
  }

  if (aux==NULL){
    printf("Pacote nao encontrado\n");
    printf("Aperta uma tecla pra continuar...");
    getchar();
    getchar();
    return l;
  }
  if (aux == l){//primeiro elemento da lista
    
    l = l->prox;
    if(l != NULL)
      l->ant = NULL;
    
  }else if (aux->prox == NULL){//ultima posicao
 
    aux->ant->prox = NULL;
    
  }else{
    aux->ant->prox = aux->prox;
    aux->prox->ant = aux->ant;

  }

  system("clear");
  printf("Pacote de codigo:%d e Origem:%s Saindo...\n",aux->codigo, aux->origem);
  printf("O pacote ja foi tirado: %d vezes anteriormente!\n", aux->tirado);
  if(strcmp(aux->origem, "ESTADO") == 0){
    printf("Valor a pagar:R$%.2f\n",aux->peso);
  }
  else if(strcmp(aux->origem, "FORA DO ESTADO") == 0){
    printf("Valor a pagar:R$%.2f\n",aux->peso * 3);
  }
  else if(strcmp(aux->origem, "FORA DO BRASIL") == 0){
    printf("Valor a pagar:R$%.2f\n",aux->peso * 6);
  }
  
  printf("Pressione uma tecla pra continuar...\n");
  getchar();
  getchar();
  free(aux);
  return l;

}


