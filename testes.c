#include "headers.h"

/*FICHEIRO: testes.c
  OBJETIVO: Este ficheiro agrupa todas as funcoes que sao utilizadas para testar dados, ficheiros e variaveis.*/

/*A função é do tipo void. Recebe três argumentos do tipo inteiro.
Imprime uma mensagem de erro para cada valor diferente de zero de cada uma das variáveis.
A função testa se os aeroportos se encontram com a estrutura correta nos ficheiros de texto.*/
void imprime_erros_aero(int a, int b, int c){

  if(a!=0){
    printf("Aviso:Erro, dados insuficientes. %d Aeroportos nao acrescentados.\n",a);
  }
  if(b!=0){
    printf("Aviso:Erro, coordenadas incorretas. %d Aeroportos nao acrescentados.\n",b);
  }
  if(c!=0){
    printf("Aviso:Erro na zona temporal. %d Aeroportos nao acrescentados.\n",c);
  }
}

/*A função é do tipo int e recebe um apontador para a lista dos aeroportos.
A função testa as timezones indicadas no ficheiro dos aeroportos. Se estas foram maiores do que 3 ou inferiores a -1, retorna 1.
Em caso contrário, retorna 0*/
int testa_timezone(AEROPORTO *novo){
if(novo->timezone<(-1) || novo->timezone>(3)){
  return 1;
}
return 0;
}


/*Funcao que testa as coordenadas, se algum parametro falhar retorna 1*/
int testa_coordenadas(AEROPORTO *aero)
{
  float help = 0;
  /*Teste para latitudes negativas*/
  if ((aero->posicao.latitude[0] < 0) || (aero->posicao.latitude[1] < 0) || (aero->posicao.latitude[2] < 0))
  {
    return 1;
  }
  /*Teste para longitudes negativas*/
  else if ((aero->posicao.longitude[0] < 0) || (aero->posicao.longitude[1] < 0) || (aero->posicao.longitude[2] < 0))
  {
    return 1;
  }
 /*Calculo da latitude em graus*/
  help = (aero->posicao.latitude[0] + (aero->posicao.latitude[1]) / 60.0 + (aero->posicao.latitude[2]) / 3600.0);
 /*Teste para longitudes maiores que 90 graus*/
  if (help > 90)
  {
    return 1;
  }
  /*Calculo da longitude em graus*/
  help = (aero->posicao.longitude[0] + (aero->posicao.longitude[1]) / 60.0 + (aero->posicao.longitude[2]) / 3600.0);
  /*Teste para longitudes maiores que 180 graus*/
  if (help > 180)
  {
    return 1;
  }
  /*Teste do sentido de latitude*/
  if ((aero->posicao.sentido_latitude != 'S') && (aero->posicao.sentido_latitude != 'N'))
  {
    return 1;
  }
  /*Teste do sentido de longitude*/
  if ((aero->posicao.sentido_longitude != 'W') && (aero->posicao.sentido_longitude != 'E'))
  {
    return 1;
  }
  return 0;/*Retorna 0 em caso de sucesso*/
}


/*A função é do tipo companhia e recebe um apontador desse mesmo tipo.
Vai percorrer todas as companhias e quando encontrar uma companhia que não tenha voos imprime uma mensagem de erro e apaga a companhia.*/
COMPANHIA* apaga_companhias_sem_voos(COMPANHIA* topo){

COMPANHIA* x=NULL,*prox=NULL,*adeus=NULL;

for(x=topo,prox=topo->prox;prox!=NULL;){
 if(prox->x==NULL){
  x->prox=prox->prox;
  adeus=prox;
  printf("Aviso:COMPANHIA: %s nao tem voos. Vai ser apagada.\n",prox->nome);
  prox=prox->prox;
  free(adeus);
 }
 else{
 x=x->prox;
 prox=prox->prox;
 }
}
if(topo->x==NULL){
  printf("Aviso:COMPANHIA: %s nao tem voos. Vai ser apagada.\n",topo->nome);
  topo=topo->prox;
}
return topo;
}



/*A função é do tipo inteiro e ecebe um apontador do tipo VOO.
Se o utilizador pedir uma rota que tenha a mesma origem e chegada, a função restorna 1.
Em caso contrário, retorna 0.*/
int testa_nomes(VOO* ola){
if(strcmp(ola->aeroporto_de_partida,ola->aeroporto_de_chegada)==0){
  return 1;
}
else {
  return 0;
 }
}


/*A função é do tipo float. Recebe 2 apontadores: um do tipo AEROPORTO e um do tipo VOO.
Vai testar a duração dos voos. Se esta for inferior a 30 min ou 11horas, a rota é eliminada.
Retorna 0 cajo seja válida ou -1, em caso contrário.*/
 float testa_duracao(AEROPORTO *topo, VOO *voo_testar){
  AEROPORTO *aux;
  float contador_partida = 0, contador_chegada = 0;
  int timezone_partida=0, timezone_chegada=0,hora_partida=0,hora_chegada=0,minutos_part=0,minutos_cheg=0;
  for (aux = topo; aux != NULL; aux = aux->prox){/*Ciclo que percorre os aeroportos para encontarar a timezone associada a cada cidade de partida ou chegdaa.*/
    if (strcmp(aux->cidade, voo_testar->aeroporto_de_partida) == 0){/*Comparacao da cidade de partida com a cidade do aeroporto*/
      timezone_partida=aux->timezone;
      contador_partida++;}/*Incremento de um contador no caso de compatibilidade (cidades serem iguais)*/
    if (strcmp(aux->cidade, voo_testar->aeroporto_de_chegada) == 0){/*Comparacao da cidade de chegada com a cidade do aeroporto*/
      timezone_chegada=aux->timezone;
      contador_chegada++;}/*Incremento de um contador no caso de compatibilicade (cidades serem iguais)*/
  }
  if ((contador_partida == 0) || (contador_chegada == 0)){
    return -1;}
  minutos_cheg=voo_testar->chegada.minutos; /*Inicialização das variaveis*/
  minutos_part=voo_testar->partida.minutos;
  if(strcmp(voo_testar->partida.parte_do_dia,"PM")==0){ /*Se as horas de partida ou de chegada estiverem em PM,
  estas são alteradas para um sistema horário de 24horas. Para que a comparação seja mais fácil todas as horas são também convertidas à timezone 0.*/
  hora_partida=voo_testar->partida.hora+12;}
  else{
    hora_partida=voo_testar->partida.hora;    }
  if(timezone_partida==-1){
    hora_partida=hora_partida + 1;}
  if(timezone_partida==1){
  hora_partida=hora_partida - 1;}
  if(timezone_partida==2){
    hora_partida=hora_partida - 2;}
  if(timezone_partida==3){
    hora_partida=hora_partida - 3;}
  if(strcmp(voo_testar->chegada.parte_do_dia,"PM")==0){
    hora_chegada=voo_testar->chegada.hora+12;}
  else{
    hora_chegada=voo_testar->chegada.hora;}
  if(timezone_chegada==-1){
    hora_chegada=hora_chegada + 1;}
  if(timezone_chegada==1){
  hora_chegada=hora_chegada - 1;}
  if(timezone_chegada==2){
    hora_chegada=hora_chegada - 2;}
  if(timezone_chegada==3){
    hora_chegada=hora_chegada  -3;}
  if((hora_chegada-hora_partida)<0){
  return -1;}
  else if((hora_chegada-hora_partida)==0){ /*Se a duração for inferior a 30 min*/
    if((minutos_cheg-minutos_part)<30){
      return -1;}
    else{
    return 0;}
    }
   else if ((hora_chegada-hora_partida)==1){
   minutos_part = 60-minutos_part;
   if((minutos_part+minutos_cheg)<30){/*Se a duração for inferior a 30 min uma vez que há voos a sair num dia e achegar no sguinte*/
   return -1;}
   else {
   return 0;}
  }
  else if ((hora_chegada-hora_partida)>11){/*Se a duração for superior a 11 horas*/
    return -1;}
  else if((hora_chegada-hora_partida)==11)
  	if((minutos_cheg-minutos_part)>0){
  	 return -1;}
  return 0;
}


/*A função é do tipo inteiro. Recebe um apontador do tipo VOO.
Retorna 1 caso o codigo de indentifcação tenha a estrutura correta: 2Letras maiusculas e 3 algarismos.
Caso contrário retorna 1*/
int testa_identificacao(VOO* novo){
  if((novo->codigo[0]<65) || (novo->codigo[0]>90)){
    return 1;
  }
  else if((novo->codigo[1]<65) || (novo->codigo[1]>90)){
    return 1;
  }
  else if((novo->codigo[2]<48) || (novo->codigo[2]>57)){
    return 1;
  }
  else if((novo->codigo[3]<48) || (novo->codigo[3]>57)){
    return 1;
  }
  else if((novo->codigo[4]<48) || (novo->codigo[4]>57)){
    return 1;
  }
  return 0;
}

/*A função é do tipo void. Recebe três argumentos do tipo inteiro. Para cada valor do argumento diferente de zero é imprimida uma mensagem de erro.*/
void imprime_erros(int a, int b, int c, int d, int e){
  if (a!=0){
    printf("Aviso:Dados invalidos. %d Rotas nao acrescentadas\n",a);
  }
  if (b!=0){
    printf("Aviso:Voos partindo de capital inexistente na base de dados,%d Rotas nao acrescentadas.\n",b);
  }
  if (d!=0){
    printf("Aviso:%d Voos sem companhia, nao irao ser adicionado\n",d);
  }
  if (c!=0){
    printf("Aviso:%d Voos com identificao errada\n",c);
  }
  if (e!=0){
    printf("Aviso:%d Voos com duracao errada, nao acrescentados\n",e);
  }
}
/*FUncao que recebe o topo da pilha dos aeroportos e um voo que vai testar. Esta funcao verifica se as cidades dos voos existem na lista dos aeroportos, ou seja se estes voos estao a sair de cidades cujos aeroportos nos conhecamos.Se nao existirem, a funcao vai retornar 1 e o voo nao sera acrescentado*/
int testa_capitais(AEROPORTO *topo, VOO *voo_testar)
{
  AEROPORTO *aux;
  float contador_partida = 0, contador_chegada = 0;

  for (aux = topo; aux != NULL; aux = aux->prox)/*Ciclo que percorre os aeroportos*/
  {
    if (strcmp(aux->cidade, voo_testar->aeroporto_de_partida) == 0)/*Comparacao da cidade de partida com a cidade do aeroporto*/
    {
      contador_partida++;/*Incremento de um contador no caso de compatibilidade (cidades serem iguais)*/
    }
    if (strcmp(aux->cidade, voo_testar->aeroporto_de_chegada) == 0)/*Comparacao da cidade de chegada com a cidade do aeroporto*/
    {
      contador_chegada++;/*Incremento de um contador no caso de compatibilicade (cidades serem iguais)*/
    }
  }
  if ((contador_partida == 0) || (contador_chegada == 0))/*No caso de nao terem sido encontradas cidades retorna 1. Se tudo correr bem retorna 0.*/
  {
    return 1;
  }

  return 0;
}


/*Esta funcao tem como objetivo testar os horarios de cada voo com ligacao e para isso recebe a pilha de voo com ligacao (atraves do apontador para o seu topo).
Esta funcao percorre cada um dos voos. Se o 2º voo partir antes do primeiro chegar, o voo_lig que estava a ser testado é retirado da pilha. 
De salientar que esta funcao utiliza dois apontadores, um que se desloca à frente e outro que se mantem atras de forma a poder retirar elementos da pilha. 
Retorna um apontador para o topo da pilha com os voos testados. */
VOO_LIG *testa_horario(VOO_LIG *hurray)
{
  VOO_LIG *willy, *anterior, *atual;
  int contador;
  for (atual = hurray->prox, anterior = hurray; atual != NULL; atual = anterior->prox)
  {
    contador = 0;
    if (strcmp(atual->x->chegada.parte_do_dia, "AM") == 0 && (strcmp(atual->ligacao->partida.parte_do_dia, "PM") == 0))/*Se o voo chegar em AM e partir em PM esta tudo nos conformes*/
    {
      anterior = anterior->prox;
      contador++;
    }
    else if (strcmp(atual->x->chegada.parte_do_dia, "PM") == 0 && (strcmp(atual->ligacao->partida.parte_do_dia, "AM") == 0))/*Se o voo chegar em PM e partir em AM significa que a ligacao partiu antes do 1º voo chegar e vai ser retirado*/
    {
      willy = atual;
      anterior->prox = atual->prox;
      free(willy);
      contador++;
    }
    else if ((atual->x->chegada.hora) > (atual->ligacao->partida.hora))/*Comparacao das horas no caso de estarem ambos em AM ou ambos em PM*/
    {
      willy = atual;
      anterior->prox = atual->prox;
      free(willy);
      contador++;
    }
    else if (((atual->x->chegada.hora) == (atual->ligacao->partida.hora)) && ((atual->x->chegada.minutos) >= (atual->ligacao->partida.minutos)))/*Comparacao das horas e dos minutos no caso de estarem ambos em AM ou ambos em PM*/
    {
      willy = atual;
      anterior->prox = atual->prox;
      free(willy);
      contador++;
    }
    else if (contador == 0)
    {
      anterior = anterior->prox;
    }
  }
  return hurray;
}


/*Esta funcao testa os horarios de partida e de chegada de cada voo. Se estes forem negativos, tiverem as horas maiores que 12, os minutos maiores que 59 ou se a parte do dia correspondente nao for "PM" ou "AM", a funcao devolverá 1. No caso de tudo estar correto é devolvido 0.*/
int testa_horas(VOO *novo_voo)
{
  if ((novo_voo->partida.hora < 0) || (novo_voo->partida.hora > 12))
  {
    printf("Aviso:Voo nao acrescentado, parametro do tempo de partida ou de chegada errado.\n\n");
    return 1;
  }
  if ((novo_voo->chegada.hora < 0) || (novo_voo->chegada.hora > 12))
  {
    printf("Aviso:Voo nao acrescentado, parametro do tempo de partida ou de chegada errado.\n\n");
    return 1;
  }
  else if ((novo_voo->chegada.minutos < 0) || (novo_voo->chegada.minutos > 59))
  {
    printf("Aviso:Voo nao acrescentado, parametro do tempo de partida ou de chegada errado.\n\n");
    return 1;
  }
  else if ((novo_voo->partida.minutos < 0) || (novo_voo->partida.minutos > 59))
  {
    printf("Aviso:Voo nao acrescentado, parametro do tempo de partida ou de chegada errado.\n\n");
    return 1;
  }
  else if ((strcmp(novo_voo->partida.parte_do_dia, "PM") != 0) && (strcmp(novo_voo->partida.parte_do_dia, "AM") != 0))
  {
    printf("Aviso:Voo nao acrescentado, parametro do tempo de partida ou de chegada errado.\n\n");
    return 1;
  }
  else if ((strcmp(novo_voo->chegada.parte_do_dia, "PM") != 0) && (strcmp(novo_voo->chegada.parte_do_dia, "AM") != 0))
  {
    printf("Aviso:Voo nao acrescentado, parametro do tempo de partida ou de chegada errado.\n\n");
    return 1;
  }

  return 0;
}


/*Esta funcao recebe um apontador do tipo AEROPORTO* um do tipo COMPANHIA*. Se algum destes for nulo imprime uma mensagem de erro e termina o programa. Em caso contrario nao faz nada.*/
void teste(AEROPORTO *X, COMPANHIA *Y)
{
  if (X == NULL)
  {
    printf("Aviso:Não existe nenhum aeroporto com dados corretos… programa a terminar.\n");
    exit(0);
  }

  if (Y == NULL)
  {
    printf("Aviso:Não existe nenhum voo com dados corretos… programa a terminar.\n");
    exit(0);
  }
}
/*Esta funcao tem como ojetivo testar se o proximo elemento de uma pilha apontada pelo elemento que é recebido é nulo. Se for nulo, emite uma mensagem de erro e termina o programa. Em caso contrario, nao faz nada.*/
void teste_rota_lig(VOO_LIG *x)
{
  if ((x->prox) == NULL)
  {
    printf("Aviso:Rota com ligacao inexistente na nossa base de dados\n");
    exit(0);
  }
}


/*Esta funcao tem como ojetivo testar se o proximo elemento de uma pilha apontada pelo elemento que é recebido é nulo.
Se for nulo, emite uma mensagem de erro e termina o programa. Em caso contrario, nao faz nada.*/
void teste_rota_lig2(VOO_LIG2 *x)
{
  if ((x->prox) == NULL)
  {
    printf("Aviso:Rota com ligacao inexistente na nossa base de dados\n");
    exit(0);
  }
}


/*Esta funcao tem como objetivo testar os horarios de cada voo com 2 ligacao e para isso recebe a pilha de voo com 2 ligacoes (atraves do apontador para o seu topo).
Esta funcao percorre cada um dos voos. Se o 3º voo partir antes do 2º chegar, o voo_lig2 que estava a ser testado é retirado da pilha.
De salientar que esta funcao utiliza dois apontadores, um que se desloca à frente e outro que se mantem atras de forma a poder retirar elementos da pilha.
Retorna um apontador para o topo da pilha com os voos testados. */
VOO_LIG2 *testa_horario2(VOO_LIG2 *lig3)
{
  VOO_LIG2 *willy, *anterior, *atual;
  int contador;
  for (atual = lig3->prox, anterior = lig3; atual != NULL; atual = anterior->prox)
  {
    contador = 0;
    if (strcmp(atual->ligacao1->chegada.parte_do_dia, "AM") == 0 && (strcmp(atual->ligacao2->partida.parte_do_dia, "PM") == 0))
    {
      anterior = anterior->prox;
      contador++;
    }
    if (strcmp(atual->ligacao1->chegada.parte_do_dia, "PM") == 0 && (strcmp(atual->ligacao2->partida.parte_do_dia, "AM") == 0))
    {
      willy = atual;
      anterior->prox = atual->prox;
      free(willy);
      contador++;
    }
    else if ((atual->ligacao1->chegada.hora) > (atual->ligacao2->partida.hora))
    {
      willy = atual;
      anterior->prox = atual->prox;
      free(willy);
      contador++;
    }
    else if (((atual->ligacao1->chegada.hora) == (atual->ligacao2->partida.hora)) && ((atual->ligacao1->chegada.minutos) >= (atual->ligacao2->partida.minutos)))
    {
      willy = atual;
      anterior->prox = atual->prox;
      free(willy);
      contador++;
    }
    else if (contador == 0)
    {
      anterior = anterior->prox;
    }
  }
  return lig3;
}

/*A funcao e do tipo companhia. Esta recebe um apontador do tipo COMPANHIA.
A funcao ira percorrer todas as companhia e voos. Se encontrar voos com o mesmo código ; um deles irá ser eliminado.
Retorna o apontador do da loista de companhias.*/
COMPANHIA* testa_companhia(COMPANHIA *topo_companhia){

VOO *aux=NULL, *atual=NULL, *compara=NULL, *temp=NULL, *anterior=NULL;
COMPANHIA *x=NULL;



for (x=topo_companhia; x != NULL; x = x->prox)
  {
    for (aux = x->x; aux != NULL; aux = aux->prox)
    {
      for(compara=aux; compara!=NULL; compara=compara->prox){
        for(anterior=compara;  atual!=NULL; atual=anterior->prox){
          if (strcmp(compara->codigo, atual->codigo)==0) {
            anterior->prox=atual->prox;

            temp=atual;
            atual=atual->prox;
            free(temp);
          }
          else{
            atual=atual->prox;
            anterior=anterior->prox;
          }
        }
      }
}
}
return topo_companhia;
}


/*A funcao recebe um apontador do tipo AEROPORTO e é desse mesmo tipo.
Irá percorrer a lista dos aeroportos e quando encontrar dois aeroportos que tenham a mesma identificacao IATA ou ICAO, um desses aeroportos irá ser
eliminado. Retorna o apontador dessa listas*/
AEROPORTO* testa_aeroportos(AEROPORTO *topo_aero){

AEROPORTO *atual=NULL, *compara=NULL, *temp=NULL, *anterior=NULL;



  for(compara=topo_aero; compara!=NULL; compara=compara->prox){

    for(anterior=compara, atual=anterior->prox; atual!=NULL;){


      if ((strcmp(compara->ident_ICAO, atual->ident_ICAO)==0) || (strcmp(compara->ident_IATA, atual->ident_IATA)==0)) {
        anterior->prox=atual->prox;

        temp=atual;
        atual=atual->prox;
        free(temp);
      }
      else{
        atual=atual->prox;
        anterior=anterior->prox;
      }
    }

}

return topo_aero;

}


/*Esta funcao que recebe dois apontadores de VOO_LIG tem como objetivo comparar qual deles sai mais cedo do seu aeroporto de partida.
Se o primeiro voo sair mais cedo retorna 0,se for o segundo a sair retorna 1 e se sairem ao mesmo tempo retorna 2.*/
int compara_horario(VOO_LIG* atual, VOO_LIG* prox){

  if((strcmp(atual->x->partida.parte_do_dia, "PM") == 0) && (strcmp(prox->x->partida.parte_do_dia, "AM") == 0)){
  return 1;
  }
  else if((strcmp(atual->x->partida.parte_do_dia, "AM") == 0) && (strcmp(prox->x->partida.parte_do_dia, "PM") == 0)){
  return 0;
  }
  else if ((atual->x->partida.hora) < (prox->x->partida.hora))
      {
        return 0;
      }
  else if (((atual->x->partida.hora) == (prox->x->partida.hora)) && ((atual->x->partida.minutos) < (prox->x->partida.minutos)))
      {
        return 0;
      }
  else if (((atual->x->partida.hora) == (prox->x->partida.hora)) && ((atual->x->partida.minutos) == (prox->x->partida.minutos)))
      {
        return 2;
      }
  else if (((atual->x->partida.hora) == (prox->x->partida.hora)) && ((atual->x->partida.minutos) > (prox->x->partida.minutos)))
      {
        return 1;
      }
  else{
    return 1;
    }
}


/*Esta funcao que recebe dois apontadores de VOO_LIG2 tem como objetivo comparar qual deles sai mais cedo do seu aeroporto de partida (1º ligacao).
Se o primeiro voo sair mais cedo retorna 0,se for o segundo a sair retorna 1 e se sairem ao mesmo tempo retorna 2.*/
int compara_horario2(VOO_LIG2* atual, VOO_LIG2* prox){

  if((strcmp(atual->x->partida.parte_do_dia, "PM") == 0) && (strcmp(prox->x->partida.parte_do_dia, "AM") == 0)){
  return 1;
  }
  else if((strcmp(atual->x->partida.parte_do_dia, "AM") == 0) && (strcmp(prox->x->partida.parte_do_dia, "PM") == 0)){
  return 0;
  }
  else if ((atual->x->partida.hora) < (prox->x->partida.hora))
      {
        return 0;
      }
  else if (((atual->x->partida.hora) == (prox->x->partida.hora)) && ((atual->x->partida.minutos) < (prox->x->partida.minutos)))
      {
        return 0;
      }
  else if (((atual->x->partida.hora) == (prox->x->partida.hora)) && ((atual->x->partida.minutos) == (prox->x->partida.minutos)))
      {
        return 2;
      }
  else if (((atual->x->partida.hora) == (prox->x->partida.hora)) && ((atual->x->partida.minutos) > (prox->x->partida.minutos)))
      {
        return 1;
      }
  else{
    return 1;
    }
}

/*A função e do tipo void e recebe dois argumentos do tipo char*. Vai testar se as palavras introduzidas na linha de comandos que corresponderiam
a cidades verificam as condicoes de serem apenas contituidas por letras. Caso nao sejam o programa termina.*/
void testa_input(char *primeiro, char *segundo){
  int i=0, comprimento1=0,comprimento2=0;
  comprimento1=strlen(primeiro);
  comprimento2=strlen(segundo);
  for(i=0;i<comprimento1;i++)
  {
    if(isalpha(primeiro[i])==0){
      printf("Aviso:O nome das cidades apenas pode conter letras");
      exit(0);
    }
  }
  for(i=0;i<comprimento2;i++)
  {
    if(isalpha(segundo[i])==0){
      printf("Aviso:O nome das cidades apenas pode conter letras\n");
      exit(0);
    }
  }
}

