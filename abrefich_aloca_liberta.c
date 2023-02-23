#include "headers.h"

/*FICHEIRO: abrefich_aloca_liberta.c
OBJETIVO: Este ficheiro agrupa funcoes cujo objetivo e libertar memoria, abrir ficheiros e alocar memoria.*/


/*Funcao que recebe um apontador do tipo FILE* e um vetor de caracteres contendo um nome de um ficheiro de texto.
A funcao tenta abrir o ficheiro de texto, testa a sua abertura(em caso de erro termina o programa) e devolve um apontador para o ficheiro.*/
FILE *abre_fich(FILE *fp, char x[])
{
  fp = fopen(x, "r");
  if (fp == NULL)
  {
    printf("AVISO: Erro na abertura do ficheiro\n");
    exit(0);
  }
  return fp;
}

/*Funcao que recebe um apontador do tipo AEROPORTO*.
A funcao vai alocar um bloco de memoria do tamanho do tipo estruturado AEROPORTO, testa a alocaçao de memoria (em caso de erro termina o programa)
e devolve um apontador para o bloco alocado.*/
AEROPORTO *aloca_memoria(AEROPORTO *novo)
{
  novo = (AEROPORTO *)calloc(1, sizeof(AEROPORTO));
  if (novo == NULL)
  {
    printf("AVISO: Erro na alocação de memória\n");
    exit(0);
  };
  return novo;
}

/*Funcao que recebe um apontador do tipo COMPANHIA*. A funcao vai alocar um bloco de memoria do tamanho do tipo estruturado COMPANHIA, testa a alocaçao de memoria (em caso de erro termina o programa) e devolve um apontador para o bloco alocado.*/
COMPANHIA *aloca_memoria_comp(COMPANHIA *novo)
{
  novo = (COMPANHIA *)calloc(1, sizeof(COMPANHIA));
  if (novo == NULL)
  {
    printf("Aviso: Erro na alocação de memória\n");
    exit(0);
  };
  return novo;
}
/*Funcao que recebe um apontador do tipo VOO*. A funcao vai alocar um bloco de memoria do tamanho do tipo estruturado VOO, testa a alocaçao de memoria (em caso de erro termina o programa) e devolve um apontador para o bloco alocado.*/
VOO *aloca_memoria_voo(VOO *novo)
{
  novo = (VOO *)calloc(1, sizeof(VOO));
  if (novo == NULL)
  {
    printf("Aviso: Erro na alocação de memória\n");
    exit(0);
  };
  return novo;
}

/*Funcao que recebe um apontador do tipo COORDENADAS*. A funcao vai alocar um bloco de memoria do tamanho do tipo estruturado COORDENADAS, testa a alocaçao de memoria (em caso de erro termina o programa) e devolve um apontador para o bloco alocado.*/

COORDENADAS *aloca_memoria_coord(COORDENADAS *novo)
{

  novo = (COORDENADAS *)calloc(1, sizeof(COORDENADAS));
  if (novo == NULL)
  {
    printf("Aviso: Erro na alocação de memória\n");
    exit(0);
  };
  return novo;
}


/*Funcao que recebe um apontador do tipo VOO_LIG*. A funcao vai alocar um bloco de memoria do tamanho do tipo estruturado VOO_LIG, testa a alocaçao de memoria (em caso de erro termina o programa) e devolve um apontador para o bloco alocado.*/
VOO_LIG *aloca_memoria_voo_lig(VOO_LIG *novo)
{
  novo = (VOO_LIG *)calloc(1, sizeof(VOO_LIG));
  if (novo == NULL)
  {
    printf("Aviso: Erro na alocação de memória\n");
    exit(0);
  };
  return novo;
}


/*Funcao que recebe um apontador do tipo VOO_LIG2*.
A funcao vai alocar um bloco de memoria do tamanho do tipo estruturado VOO_LIG2, testa a alocaçao de memoria (em caso de erro termina o programa)
e devolve um apontador para o bloco alocado.*/
VOO_LIG2 *aloca_memoria_voo_lig2(VOO_LIG2 *novo)
{
  novo = (VOO_LIG2 *)calloc(1, sizeof(VOO_LIG2));
  if (novo == NULL)
  {
    printf("Aviso: Erro na alocação de memória\n");
    exit(0);
  };
  return novo;
}

/*Funcao que recebe dois apontadores do tipo estruturado VOO* e copia os dados de um deles para o outro*/
void conteudo_memoria_alocada(VOO *aux, VOO *ap)
{
  strcpy(ap->codigo, aux->codigo);
  strcpy(ap->aeroporto_de_partida, aux->aeroporto_de_partida);
  strcpy(ap->aeroporto_de_chegada, aux->aeroporto_de_chegada);
  ap->partida.hora = aux->partida.hora;
  ap->partida.minutos = aux->partida.minutos;
  strcpy(ap->partida.parte_do_dia, aux->partida.parte_do_dia);
  ap->chegada.hora = aux->chegada.hora;
  ap->chegada.minutos = aux->chegada.minutos;
  strcpy(ap->chegada.parte_do_dia, aux->chegada.parte_do_dia);
  ap->distancia = aux->distancia;
}

/*a função recebe um apontador do tipo AEROPORTO. Percorre a lista libertando a mem´ria de cada bloco.*/
void liberta_memoria_aeroporto(AEROPORTO* x){
  AEROPORTO* p=x, *t;
  while(p!=NULL){
    t=p->prox;
    free(p);
    p=t;
  }
}

/*a função recebe um apontador do tipo COMPANHIA. Percorre a lista libertando a mem´ria de cada bloco.*/
void liberta_memoria_companhia(COMPANHIA* x){
  COMPANHIA* p=x, *t;
  while(p!=NULL){
    t=p->prox;
    free(p);
    p=t;
  }
}

/*a função recebe um apontador do tipo VOO. Percorre a lista libertando a mem´ria de cada bloco.*/
void liberta_memoria_voo(VOO* x){
  VOO* p=x, *t;
  while(p!=NULL){
    t=p->prox;
    free(p);
    p=t;
  }
}

/*a função recebe um apontador do tipo VOO_LIG. Percorre a lista libertando a mem´ria de cada bloco.*/
void liberta_memoria_voolig(VOO_LIG* x){
  VOO_LIG* p=x, *t;
  while(p!=NULL){
    t=p->prox;
    free(p);
    p=t;
  }
}

/*a função recebe um apontador do tipo VOO_LIG2. Percorre a lista libertando a mem´ria de cada bloco.*/
void liberta_memoria_voolig2(VOO_LIG2* x){
  VOO_LIG2* p=x, *t;
  while(p!=NULL){
    t=p->prox;
    free(p);
    p=t;
  }
}

/*Esta funcao tem como objetivo imprimir o formato dos comandos que o programa pode realizar*/
void limpa_espaco()
{
  printf("\n\nATENCAO!!!\n\n");
  printf("Por favor introduza comandos válidos...\nConiderando 'rota' o nome do ficheiro executável, se pretender:\n");
  printf("1. Visualizar a informação dos aeroportos: rota -aeroportos\n");
  printf("2. Visualizar a informação dos voos diretos: rota -voos\n");
  printf("3. Pedir uma rota entre um aeroporto A(LISBON) e um aeroporto B(ROME), ligação direta: rota LISBON ROME -L 0\n");
  printf("4. Pedir uma rota idêntica ao ponto anterior com os voos apresentados por ordem crescente(-TC) ou descrescente (-TD): rota LISBON ROME -L 0 -TC\n");
  printf("5. Pedir uma rota com uma ligação mas sem preocupação horária: rota LISBON ROME -L 1\n");
  printf("6. Pedir uma rota com uma ligação com preocupação de ligação horária: rota LISBON ROME -L 1 -TC\n");
  printf("7. Pedir uma rota com uma ligação com preocupação de ligação horária e com a menor distância: rota LISBON ROME -L 1 -TC -D\n");
  printf("8.(ALL) Pedir todas as rotas com uma ligação mas sem preocupação horária: rota LISBON ROME -L 1 ALL\n");
  printf("9.(ALL) Pedir todas as rotas com uma ligação com preocupação de ligação horária: rota LISBON ROME -L 1 -TC ALL\n");
  printf("10.(ALL) Pedir todas as rotas com uma ligação com preocupação de ligação horária e com a menor distância: rota LISBON ROME -L 1 -TC -D ALL\n");
  printf("11. Pedir uma rota com duas ligaçoes mas sem preocupação horária: rota LISBON ROME -L 2\n");
  printf("12. Pedir uma rota com duas ligaçoes com preocupação de ligação horária: rota LISBON ROME -L 2 -TC\n");
  printf("13. Pedir uma rota com duas ligaçoes com preocupação de ligação horária e com a menor distância: rota LISBON ROME -L 2 -TC -D\n");
  printf("14.(ALL) Pedir todas as rotas com duas ligaçoes mas sem preocupação horária: rota LISBON ROME -L 2 ALL\n");
  printf("15.(ALL) Pedir todas as rotas com duas ligaçoes com preocupação de ligação horária: rota LISBON ROME -L 2 -TC ALL\n");
  printf("16.(ALL) Pedir todas as rotas com duas ligaçoes com preocupação de ligação horária e com a menor distância: rota LISBON ROME -L 2 -TC -D ALL\n");
  printf("17. Pedir todas as rotas entre um aeroporto A(LISBON) e um aeroporto B(ROME), ligação direta: rota LISBON ROME -L 0 ALL\n");
  printf("18. Pedir todas as rotas idênticas ao ponto anterior com os voos apresentados por ordem crescente(-TC) ou descrescente (-TD): rota LISBON ROME -L 0 -TC ALL\n");
}








