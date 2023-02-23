/*FICHEIRO: ordenacoes.c
OBJETIVO: agrupa as funcoes que irao ordenar os voos por horas ou distancias*/


#include "headers.h"

/*Esta funcao recebe apontadores do tipo VOO* bem como o vetor de apontadores da linha de comandos. Utilizando o strcmp para comparar os argumentos da linha de comandos com os strings que representam a ordem crescente e a decrescente. Tendo "percebido" qual e a ordem pedida vai retirar os voos de uma pilha e colocando os noutra ja ordenada. Retorna o inicio desta nova pilha*/
VOO *insere_ordenado_tc_td(VOO *atual, VOO *anterior, VOO *ap, VOO *inicio, char *argv[])
{
  int controlo = 0;
  fflush(stdout);
  atual = inicio;
  if (strcmp(argv[5], "-TC") == 0)
  {
    while ((atual != NULL) && (((ap->partida.hora > atual->partida.hora) && (strcmp(ap->partida.parte_do_dia, atual->partida.parte_do_dia) == 0)) || ((strcmp(ap->partida.parte_do_dia, "PM") == 0) && (strcmp(atual->partida.parte_do_dia, "AM") == 0))))
    {
      anterior = atual;
      atual = atual->prox;
      controlo = 1;
    }
  }
  else
  {
    while ((atual != NULL) && (((ap->partida.hora < atual->partida.hora) && (strcmp(ap->partida.parte_do_dia, atual->partida.parte_do_dia) == 0)) || ((strcmp(ap->partida.parte_do_dia, "AM") == 0) && (strcmp(atual->partida.parte_do_dia, "PM") == 0))))
    {
      anterior = atual;
      atual = atual->prox;
      controlo = 1;
    }
  }

  if (anterior == NULL)
  {
    inicio = ap;
    inicio->prox = atual;
    return inicio;
  }
  if (controlo == 1)
  {
    ap->prox = anterior->prox;
    anterior->prox = ap;
  }
  else
  {
    ap->prox = atual;
    inicio = ap;
  }

  return inicio;
}


/*Esta funcao tem como objetivo ordenar os dados de uma pilha de voos com ligacao por distancia crescente. O funcionamento é do tipo de Bubble Sort. A funcao percorre todos os pares de voo (atual e proximo) verifica se deve ser efetuada alguma troca e se sim fa-la. De seguida, repete ate nao serem realizadas trocas. Retorna o topo da pilha agora ordenada.*/
VOO_LIG *ordena_por_distancia(VOO_LIG *topo)

{
  VOO_LIG *atual=NULL, *anterior=NULL, *temp=NULL;
  int trocas = 0;
  
  if(topo->prox->prox==NULL)
  {
  return topo;
  }
  
  do{
  trocas=0;
  atual = topo->prox;
  anterior=topo;	
    do{
      if (atual->distancia_total > atual->prox->distancia_total)
      {
        anterior->prox=atual->prox;
        temp=atual->prox;
        atual->prox=temp->prox;
        temp->prox=atual;
        trocas++;
        anterior=temp;
      }
      else{
      anterior=anterior->prox;
      atual=atual->prox;
      }
    }while(atual->prox!=NULL);
  }while(trocas!=0);
  return topo;
}


/*Esta funcao tem como objetivo ordenar os dados de uma pilha de voos com ligacao por ordem de partida decrescente. 
O funcionamento é do tipo de Bubble Sort. 
A funcao percorre todos os pares de voo (atual e proximo) verifica se deve ser efetuada alguma troca e se sim fa-la. 
De seguida, repete ate nao serem realizadas trocas. Retorna o topo da pilha agora ordenada.*/
VOO_LIG *ordena_por_tempo_decrescente(VOO_LIG *topo_velho)
{
  VOO_LIG *atual=NULL, *anterior=NULL, *temp=NULL;
  int trocas = 0;
  
  if(topo_velho->prox->prox==NULL)
  {
  return topo_velho;
  }
  
  do{
  trocas=0;
  atual = topo_velho->prox;
  anterior=topo_velho;
    do{
      if (compara_horario(atual,atual->prox)==0)
      {
        anterior->prox=atual->prox;
        temp=atual->prox;
        atual->prox=temp->prox;
        temp->prox=atual;
        trocas++;
        anterior=temp;
      }
      else{
      anterior=anterior->prox;
      atual=atual->prox;
      }
    }while(atual->prox!=NULL);
  }while(trocas!=0);
  return topo_velho;
}


/*Esta funcao tem como objetivo ordenar os dados de uma pilha de voos com ligacao por ordem de partida crescente. O funcionamento é do tipo de Bubble Sort. A funcao percorre todos os pares de voo (atual e proximo) verifica se deve ser efetuada alguma troca e se sim fa-la. De seguida, repete ate nao serem realizadas trocas. Retorna o topo da pilha agora ordenada.*/
VOO_LIG *ordena_por_tempo_crescente(VOO_LIG *topo_velho)
{
  VOO_LIG *atual=NULL, *anterior=NULL, *temp=NULL;
  int trocas = 0;
  
  
  if(topo_velho->prox->prox==NULL)
  {
  return topo_velho;
  }
  
  do{
  trocas=0;
  atual = topo_velho->prox;
  anterior=topo_velho;
    do{
      if (compara_horario(atual,atual->prox)==1)
      {
        anterior->prox=atual->prox;
        temp=atual->prox;
        atual->prox=temp->prox;
        temp->prox=atual;
        trocas++;
        anterior=temp;
      }
       else{
      anterior=anterior->prox;
      atual=atual->prox;
      }
    }while(atual->prox!=NULL);
  }while(trocas!=0);
  return topo_velho;
}


/*Esta funcao tem como objetivo ordenar os dados de uma pilha de voos com ligacao por ordem de partida crescente. 
O funcionamento é do tipo de Bubble Sort. A funcao percorre todos os pares de voo (atual e proximo) verifica se deve ser efetuada alguma troca e se sim fa-la. 
De seguida, repete ate nao serem realizadas trocas. Retorna o topo da pilha agora ordenada.*/
VOO_LIG2 *ordena_por_tempo_crescente2(VOO_LIG2 *topo_velho)
{
  VOO_LIG2 *atual=NULL, *anterior=NULL,*temp=NULL;
  int trocas = 0;
  
  
  if(topo_velho->prox->prox==NULL)
  {
  return topo_velho;
  }
  
  do{
  trocas=0;
  atual = topo_velho->prox;
  anterior=topo_velho;
    do{
      if (compara_horario2(atual,atual->prox)==1)
      {
        anterior->prox=atual->prox;
        temp=atual->prox;
        atual->prox=temp->prox;
        temp->prox=atual;
        trocas++;
        anterior=temp;
      }
       else{
      anterior=anterior->prox;
      atual=atual->prox;
      }
    }while(atual->prox!=NULL);
  }while(trocas!=0);
  return topo_velho;
}


/*Esta funcao tem como objetivo ordenar os dados de uma pilha de voos com ligacao por ordem de partida decrescente. 
O funcionamento é do tipo de Bubble Sort. 
A funcao percorre todos os pares de voo (atual e proximo) verifica se deve ser efetuada alguma troca e se sim fa-la. De seguida, repete ate nao serem realizadas trocas. Retorna o topo da pilha agora ordenada.*/
VOO_LIG2 *ordena_por_tempo_decrescente2(VOO_LIG2 *topo_velho)
{
  VOO_LIG2 *atual=NULL, *anterior=NULL, *temp=NULL;
  int trocas = 0;
  
  
  if(topo_velho->prox->prox==NULL)
  {
  return topo_velho;
  }
  
  do{
  trocas=0;
  atual = topo_velho->prox;
  anterior=topo_velho;
    do{
      if (compara_horario2(atual,atual->prox)==0)
      {
        anterior->prox=atual->prox;
        temp=atual->prox;
        atual->prox=temp->prox;
        temp->prox=atual;
        trocas++;
        anterior=temp;
      }
      else{
      anterior=anterior->prox;
      atual=atual->prox;
      }
    }while(atual->prox!=NULL);
  }while(trocas!=0);
  return topo_velho;
}



/*Esta funcao tem como objetivo criar uma lista ordenada por distancia crescente e para isso vai receber a lista de voos com 2 ligacoes. 
O funcionamento é do tipo de Bubble Sort. 
A funcao percorre todos os pares de voo (atual e proximo) verifica se deve ser efetuada alguma troca e se sim fa-la. De seguida, repete ate nao serem realizadas trocas. Retorna o topo da pilha agora ordenada.*/
VOO_LIG2 *ordena_por_distancia2(VOO_LIG2 *topo)

{
  VOO_LIG2 *atual=NULL, *anterior=NULL, *temp=NULL;
  int trocas = 0;
  
  
  if(topo->prox->prox==NULL)
  {
  return topo;
  }
  
  do{
  trocas=0;
  atual = topo->prox;
  anterior=topo;  
    do{
      if (atual->distancia_total > atual->prox->distancia_total)
      {
        anterior->prox=atual->prox;
        temp=atual->prox;
        atual->prox=temp->prox;
        temp->prox=atual;
        trocas++;
        anterior=temp;
      }
      else{
      anterior=anterior->prox;
      atual=atual->prox;
      }
    }while(atual->prox!=NULL);
  }while(trocas!=0);
  return topo;
}


