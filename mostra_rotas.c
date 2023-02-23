#include "headers.h"

/*FICHEIRO: mostra_rotas.c
  OBJETIVO: Este é o ficheiro que possui todas as funcoes necessarias para imprimir quaisquer rotas ou aeroportos*/

/*Funcao que recebe um apontador(do tipo AEROPORTO*) para o topo de uma pilha.
Através de um ciclo for, a funcao vai percorrer a pilha e por cada bloco que passa imprime a informacao contida(cidade do aeroporto, coordenadas,etc...).*/
void mostra(AEROPORTO *topo)
{
  for (; topo != NULL; topo = topo->prox)
  {
    printf("%s %s %d %d %d %c %d %d %d %c %s %d\n", topo->ident_ICAO, topo->ident_IATA, topo->posicao.latitude[0],
           topo->posicao.latitude[1], topo->posicao.latitude[2], topo->posicao.sentido_latitude,
           topo->posicao.longitude[0], topo->posicao.longitude[1], topo->posicao.longitude[2], topo->posicao.sentido_longitude,
           topo->cidade, topo->timezone);
    printf("\n");
  }
}

/*Funcao que recebe o topo da companhia e o vetor de apontadores (do texto inserido atraves da linha de comandos).
Esta funcao percorre todos os voos de cada companhia e sempre que encontrar algum com a cidade de partida e a de chegada
correspondentes as cidades indicadas na linha de comandos imprime os.*/
void mostra_rota_direta(COMPANHIA *x, char *argv[])
{
  VOO *aux;
  int i = 0;

  for (; x != NULL; x = x->prox)
  {
    for (aux = x->x; aux != NULL; aux = aux->prox)
    {
      if (strcmp(aux->aeroporto_de_partida, argv[1]) == 0)/*Funcao strcmp utilizada para comparar as cidades*/
      {
        if (strcmp(aux->aeroporto_de_chegada, argv[2]) == 0)
        {
          i++;/*Teste para saber se existe alguma rota*/
          printf("%s %s %02d:%02d %s %s %02d:%02d %s\n", aux->codigo, aux->aeroporto_de_partida, aux->partida.hora,
                 aux->partida.minutos, aux->partida.parte_do_dia, aux->aeroporto_de_chegada,
                 aux->chegada.hora, aux->chegada.minutos, aux->chegada.parte_do_dia);
          printf("Distancia total:%f\nPreco:%.2f\n\n",aux->distancia,aux->preco);
        }
      }
    }
  }
  if (i == 0)/*No caso de nao ter sido impresso nenhum voo e impresso um aviso de que tal rota nao existe nos nossos dados.*/
  {
    printf("AVISO:Nao existe nenhuma rota que corresponda ao seu pedido\n");
  }
}

/*Funcao que recebe o topo da companhia e o vetor de apontadores (do texto inserido atraves da linha de comandos).
Esta funcao percorre todos os voos de cada companhia e quando encontrar algum com a cidade de partida e a de chegada
correspondentes as cidades indicadas na linha de comandos imprime o e sai da funcao retornando 0.*/
int mostra1_rota_direta(COMPANHIA *x, char *argv[])
{
  VOO *aux;
  int i = 0;

  for (; x != NULL; x = x->prox)
  {
    for (aux = x->x; aux != NULL; aux = aux->prox)
    {
      if (strcmp(aux->aeroporto_de_partida, argv[1]) == 0)/*Funcao strcmp utilizada para comparar as cidades*/
      {
        if (strcmp(aux->aeroporto_de_chegada, argv[2]) == 0)
        {
          i++;/*Teste para saber se existe alguma rota*/
          printf("%s %s %02d:%02d %s %s %02d:%02d %s\n", aux->codigo, aux->aeroporto_de_partida, aux->partida.hora,
                 aux->partida.minutos, aux->partida.parte_do_dia, aux->aeroporto_de_chegada,
                 aux->chegada.hora, aux->chegada.minutos, aux->chegada.parte_do_dia);
          printf("Distancia total:%f\nPreco:%.2f\n",aux->distancia,aux->preco);
          return 0;
        }
      }
    }
  }
  if (i == 0)/*No caso de nao ter sido impresso nenhum voo e impresso um aviso de que tal rota nao existe nos nossos dados.*/
  {
    printf("AVISO:Nao existe nenhuma rota que corresponda ao seu pedido\n");
  }
  return 0;
}


/*Funcao que percorre a lista ordenada por horas de partida e imprime os dados de cada um dos voos.
Esta funcao recebe um apontador para o topo da lista e nao devolve nada.*/
void mostra_lista_rota_direta_tc_td(VOO *topo)
{
  VOO *aux = NULL;
  aux = topo;
  while (aux != NULL)
  {
    printf("%s %s %02d:%02d %s %s %02d:%02d %s\n", aux->codigo, aux->aeroporto_de_partida, aux->partida.hora,
           aux->partida.minutos, aux->partida.parte_do_dia, aux->aeroporto_de_chegada,
           aux->chegada.hora, aux->chegada.minutos, aux->chegada.parte_do_dia);
    printf("Distancia:%.2f\nPreco:%.2f\n\n",aux->distancia,aux->distancia*0.4);
    aux = aux->prox;
  }
}

/*Funcao que percorre a lista ordenada por horas de partida e imprime os dados do primeiro voo da lista.
Esta funcao recebe um apontador para o topo da lista e nao devolve nada.*/
void mostra_1lista_rota_direta_tc_td(VOO *topo)
{
  VOO *aux = NULL;
  aux = topo;
  printf("\n%s %s %02d:%02d %s %s %02d:%02d %s\n", aux->codigo, aux->aeroporto_de_partida, aux->partida.hora,
          aux->partida.minutos, aux->partida.parte_do_dia, aux->aeroporto_de_chegada,
          aux->chegada.hora, aux->chegada.minutos, aux->chegada.parte_do_dia);
  printf("Distancia:%.2f\nPreco:%.2f\n\n",aux->distancia,aux->distancia*0.4);
  aux = aux->prox;
}

/*Funcao que imprime todos os dados de cada companhia e de cada voo. Percorre as companhias e dentro de cada companhia percorre os voos. Esta funcao recebe um apontador para o topo da pilha das companhias e nao devolve nada*/
void mostra_voo(COMPANHIA *x)
{
  VOO *aux;

  for (; x != NULL; x = x->prox)
  {
    printf("COMPANHIA:%s\n\n", x->nome);
    for (aux = x->x; aux != NULL; aux = aux->prox)
    {

      printf("%s %s %02d:%02d %s %s %02d:%02d %s\ndistancia a percorrer:%f\n\n", aux->codigo,
             aux->aeroporto_de_partida, aux->partida.hora, aux->partida.minutos,
             aux->partida.parte_do_dia, aux->aeroporto_de_chegada, aux->chegada.hora,
             aux->chegada.minutos, aux->chegada.parte_do_dia, aux->distancia);
      printf("Preco do voo:%.2f euros\n\n", aux->preco);
    }
    printf("\n");
  }
}


/*Funcao que recebe um apontador do tipo VOO_LIG*. Esta funcao percorre a pilha e imprime os dados de cada voo utilizando a funcao "mostra_voovoo".*/
void mostra_voo_lig(VOO_LIG *topo)
{
  printf("\n\n");
  printf("Voos com ligacao tem 20 por cento de desconto!\n");
  for (; topo != NULL; topo = topo->prox)
  {
    printf("PRIMEIRO VOO:\n");
    mostra_voovoo(topo->x);
    printf("SEGUNDO VOO:\n");
    mostra_voovoo(topo->ligacao);
    printf("\nDISTANCIA TOTAL:%.2f\n", topo->distancia_total);
    printf("PRECO TOTAL:%.2f EUROS\n", topo->preco_total);
    printf("\n\n");
  }
}

/*Funcao que recebe um apontador do tipo VOO*. Esta funcao vai imprimir os campos de dados do voo que recebeu. Nao retorna nada.*/
void mostra_voovoo(VOO *x)
{
  VOO *aux;
  aux = x;
  printf("%s %s %02d:%02d %s %s %02d:%02d %s\n", aux->codigo,
         aux->aeroporto_de_partida, aux->partida.hora, aux->partida.minutos,
         aux->partida.parte_do_dia, aux->aeroporto_de_chegada, aux->chegada.hora,
         aux->chegada.minutos, aux->chegada.parte_do_dia);
}


/*Funcao que recebe um apontador do tipo VOO_LIG2*.
Esta funcao percorre a pilha e imprime os dados de cada voo utilizando a funcao "mostra_voovoo".*/
void mostra_voo_lig2(VOO_LIG2 *topo)
{
  printf("\n\n");
  printf("Voos com 2 ligacoes têm desconto de 40%%!\n");
  for (; topo != NULL; topo = topo->prox)
  {
    if(strcmp(topo->x->aeroporto_de_partida, topo->ligacao1->aeroporto_de_chegada)!=0){
    printf("PRIMEIRO VOO:\n");
    mostra_voovoo(topo->x);
    printf("SEGUNDO VOO:\n");
    mostra_voovoo(topo->ligacao1);
    printf("TERCEIRO VOO:\n");
    mostra_voovoo(topo->ligacao2);
    printf("\nDISTANCIA TOTAL:%f\n", topo->distancia_total);
    printf("PRECO TOTAL:%.2f EUROS\n", topo->preco_total);
    printf("\n\n");
   }
  }
}
