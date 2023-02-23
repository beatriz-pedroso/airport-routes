#include "headers.h"

/*FICHEIRO: cria_pilhas_escalas.c
  OBJETIVO: Este ficheiro agrupa as funcoes que se responsabilizam pela criaçao dos voos com ligacoes.*/

/*Esta funcao vai percorrer todos os voos de cada companhia comparando as suas cidades de partida e de chegada com as pretendidas.
Sempre que encontrar uma vai invocar a funcao de alocacao para que os seus dados sejam copiados para o novo bloco alocado.
De seguida, procura o lugar de insercao do novo bloco e insere-o.No fim retorna um apontador para o topo da nova estrutura de dados ordenada*/
VOO *insere_voos_diretos(COMPANHIA *x, char *argv[])
{
  VOO *aux = NULL, *ap, *inicio = NULL, *atual = NULL, *anterior = NULL;

  for (; x != NULL; x = x->prox)
  { 
    
    for (aux = x->x; aux != NULL; aux = aux->prox)
    {
      if (strcmp(aux->aeroporto_de_partida, argv[1]) == 0)
      {
        if (strcmp(aux->aeroporto_de_chegada, argv[2]) == 0)
        {
          ap = aloca_memoria_voo(ap);
          conteudo_memoria_alocada(aux, ap);
          inicio = insere_ordenado_tc_td(atual, anterior, ap, inicio, argv);
          fflush(stdout);
        }
      }
    }
  }
  return inicio;
}


/*Funcao que recebe uma string com o nome da cidade de partida e um apontador para o topo das companhias.Esta funcao tem o objetivo de percorrer os voos de cada companhia. Sempre que encontra um voo com a cidade de partida igual a pretendida copia os dados deste voo para um novo bloco de memoria (alocado com a funcao "aloca_memoria_voo").Forma uma nova pilha, procura o lugar de insercao e coloca la o novo bloco. Se o aeroporto de partida nao corresponder ao de nenhum voo o programa e terminado e uma mensagem de erro e impressa.*/
VOO *cria_pilha_partida(char partida[], COMPANHIA *topo)
{

  VOO *aux, *topo_novo = NULL, *novo;
  int i = 0;

  for (; topo != NULL; topo = topo->prox)
  {
    aux = topo->x;
    while (aux != NULL)
    {
      i = 0;
      if (strcmp(aux->aeroporto_de_partida, partida) == 0)
      {
        i++;
        novo = aloca_memoria_voo(novo);

        strcpy(novo->aeroporto_de_chegada, aux->aeroporto_de_chegada);
        strcpy(novo->aeroporto_de_partida, aux->aeroporto_de_partida);
        strcpy(novo->codigo, aux->codigo);
        novo->distancia = aux->distancia;
        novo->partida.hora = aux->partida.hora;
        novo->partida.minutos = aux->partida.minutos;
        strcpy(novo->partida.parte_do_dia, aux->partida.parte_do_dia);
        novo->chegada.hora = aux->chegada.hora;
        novo->chegada.minutos = aux->chegada.minutos;
        strcpy(novo->chegada.parte_do_dia, aux->chegada.parte_do_dia);
        novo->prox = NULL;

        aux = aux->prox;
        if (topo_novo == NULL)
        {
          topo_novo = novo;
        }
        else
        {
          novo->prox = topo_novo;
          topo_novo = novo;
        }
      }
      if (i == 0)
      {
        aux = aux->prox;
      }
    }
  }
  if (topo_novo == NULL)
  {
    printf("Aviso: Aeroporto de partida inexistente\n");
    exit(0);
  }
  return topo_novo;
}

/*Funcao que recebe um apontador para uma pilha de voos, uma string com o nome da cidade de chegada e um apontador para o topo das companhias.Esta funcao tem o objetivo de percorrer a pilha dos voos e de procurar uma possivel ligacao para o destino pretendido.Por cada voo(1), a funcao vai percorrer as companhias (e os seus voos) e sempre que encontrar um voo(2) com partida igual à chegada do voo(1) vai testar se a chegada do voo(2) é igual à pretendida. Se a chegada for igual, aloca memoria do tipo VOO_LIG* e copia os dados para o novo bloco. Forma uma nova pilha e coloca la o novo bloco. No fim retorna o topo da nova pilha.*/
VOO_LIG *cria_pilha_conjunta(VOO *x, char chegada[], COMPANHIA *topo_comp)
{
  VOO *aux;
  VOO_LIG *topo = NULL, *novo;
  COMPANHIA *santogral;
  santogral = topo_comp;
  topo = aloca_memoria_voo_lig(topo);
  topo->prox = NULL;
  for (; x != NULL; x = x->prox)
  {
    for (topo_comp = santogral; topo_comp != NULL; topo_comp = topo_comp->prox)
    {
      for (aux = topo_comp->x; aux != NULL; aux = aux->prox)
      {
        if (strcmp(x->aeroporto_de_chegada, aux->aeroporto_de_partida) == 0)
        {
          if (strcmp(chegada, aux->aeroporto_de_chegada) == 0)
          {
            novo = aloca_memoria_voo_lig(novo);
            novo->x = x;
            novo->ligacao = aux;
            novo->prox = NULL;
            novo->preco_total = (x->preco + aux->preco) * 0.80;
            novo->distancia_total = x->distancia + aux->distancia;
            if (topo->prox == NULL)
            {
              topo->prox = novo;
            }
            else
            {
              novo->prox = topo->prox;
              topo->prox = novo;
            }
          }
        }
      }
    }
  }
  return topo;
}

/*A função recebe o apontador de uma lista de voos, uma string com o nome da cidade de chegada e uma pontador do tipo companhia.
É alocada memoria visto que irá ser criada uma nova lista.
A função tem como objetivo percorrer a lista de voos (recebida pela funcao por endereco) e, para cada um, encontrar novos voos de ligação.
É importante salientar que o aeroporto de chegada deste 2º voo não pode ser igual ao à string recebida pela função uma vez que esta função será
utilizada para agrupar voos com 2 escalas. */
VOO_LIG* pilha_lig1(VOO* x, char chegada[], COMPANHIA* topo_comp){

  COMPANHIA* comp=topo_comp;
  VOO* aux;
  VOO_LIG* novo=NULL, *topo=NULL;
  topo = aloca_memoria_voo_lig(topo);
  topo->prox = NULL;

  for(;x!=NULL;x=x->prox){
    for(topo_comp=comp;topo_comp!=NULL;topo_comp=topo_comp->prox){
      for(aux=topo_comp->x; aux!=NULL; aux=aux->prox){
        if(strcmp(aux->aeroporto_de_partida, x->aeroporto_de_chegada)==0){
          if(strcmp(aux->aeroporto_de_chegada, chegada)!=0){
              novo = aloca_memoria_voo_lig(novo);
              novo->x = x;
              novo->ligacao = aux;
              novo->prox = NULL;
              novo->preco_total = (x->preco + aux->preco);
              novo->distancia_total = x->distancia + aux->distancia;
              if (topo->prox == NULL)
              {
                topo->prox = novo;
              }
              else
              {
                novo->prox = topo->prox;
                topo->prox = novo;
              }
          }
        }
      }
    }
  }
  return topo;
}

/*A função recebe o apontador da lista com 2 voos, uma string com o nome da cidade de chegada e uma pontador do tipo companhia.
É alocada memoria visto que irá ser criada uma nova lista.
A função tem como objetivo percorrer a lista de voos (recebida pela funcao por endereco) e, para cada um, encontrar novos voos de ligação.
Claro que o aeroporto de partida deste 3º voo terá de ser igual ao aeroporto de chegada do 2º voo e o seu aeroorto de chegada terá de ser igual
à string recebida pela função de modo a que o bloco de 3 voos esteja completo. */
VOO_LIG2* pilha_lig2(VOO_LIG* x, char chegada[], COMPANHIA* topo_comp){

  COMPANHIA* comp=topo_comp;
  VOO* aux;
  VOO_LIG2* novo=NULL, *topo=NULL;
  topo = aloca_memoria_voo_lig2(topo);
  topo->prox = NULL;

  for(;x!=NULL;x=x->prox){

    for(topo_comp=comp;topo_comp!=NULL;topo_comp=topo_comp->prox){
      for(aux=topo_comp->x; aux!=NULL; aux=aux->prox){

        if(strcmp(aux->aeroporto_de_partida, x->ligacao->aeroporto_de_chegada)==0){
          if(strcmp(aux->aeroporto_de_chegada, chegada)==0){
              novo = aloca_memoria_voo_lig2(novo);
              novo->x = x->x;
              novo->ligacao1 = x->ligacao;
              novo->ligacao2 = aux;
              novo->prox = NULL;
              novo->preco_total = (x->x->preco + x->ligacao->preco + aux->preco)*0.6;
              novo->distancia_total = x->x->distancia + x->ligacao->distancia + aux->distancia;
              if (topo->prox == NULL)
              {
                topo->prox = novo;
              }
              else
              {
                novo->prox = topo->prox;
                topo->prox = novo;
              }
          }
        }
      }
    }
  }
  return topo;
}

