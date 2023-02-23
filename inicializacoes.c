  #include "headers.h"

  /*FICHEIRO: inicializacoes.c
    OBJETIVO: Este ficheiro agrupa as funcoes necessarias para o registo de dados (provenientes dos ficheiros de texto)
em pilhas. Ao longo do registo, os dados sao testados.*/



/*Funcao que recebe um apontador para o ficheiro de texto "aeroportos.txt".
Esta funcao vai ler cada linha "medir o seu tamanho" e guarda-la num vetor de caracteres.
Se o tamanho estiver correto vai alocar memoria e tentar ler 12 dados do vetor.
Coloca os dados na estrutura apontada por novo. Se a funcao sscanf tiver convertido 12 dados, o programa ira testar o campo de dados coordenadas.
O programa vai verificar se o sentido da latitude e longitude é o suposto e se e os numeros das coordenadas pertencem a um intervalo que sera evidenciado no comentario da funcao "testa_coordenadas".
Se tudo estiver de acordo com o esperado vai procurar o local de inserção do novo bloco e inseri-lo.
Em caso contrario, imprime a razao que o fez falhar. No fim devolver um apontador para o topo da estrutura onde inseriu os dados. */
AEROPORTO *inic_lista_aero(FILE *fp)
{
  char linha[DIM];
  int aux, contador=0,contador1=0,contador2=0;
  AEROPORTO *novo, *topo = NULL;
  while (fgets(linha, DIM, fp) != NULL)/*Funcao que le uma linha e que a guarda num vetor*/
  {
    if ((strlen(linha) != 0) && (strlen(linha) != 1) && (strlen(linha) != 2))/*Funcao que tenta coverter 12 dados*/
    {
      novo = aloca_memoria(novo);/*Funcao invocada para alocar memoria*/
      aux = sscanf(linha, "%s %s %d %d %d %c %d %d %d %c %s %d", novo->ident_ICAO, novo->ident_IATA, &(novo->posicao.latitude[0]),
                   &(novo->posicao.latitude[1]), &(novo->posicao.latitude[2]), &(novo->posicao.sentido_latitude),
                   &(novo->posicao.longitude[0]), &(novo->posicao.longitude[1]), &(novo->posicao.longitude[2]),
                   &(novo->posicao.sentido_longitude),
                   novo->cidade, &(novo->timezone));/*conversao dos dados*/
      novo->prox = NULL;/*Inicializacao do campo prox a null*/
      if ((aux == 12) && (testa_coordenadas(novo) == 0) && (testa_timezone(novo) == 0))/*Teste dos dados da linha*/
      {
        if (topo == NULL)/*Teste do apontador topo(se este for nulo vai passar a apontar para o bloco de memoria alocado*/
        {
          topo = novo;
        }
        else/*Em caso contrario,o novo bloco passa a apontar para o topo e o topo para o novo bloco*/
        {
          novo->prox = topo;
          topo = novo;
        }
      }
      else if (aux != 12)/*No caso de nao serem convertidos 12 dados*/
      {
        contador++;
        novo=NULL;
      }
      else if (testa_coordenadas(novo) != 0)/*No caso das coordenadas nao serem as corretas*/
      {
       contador1++;
       novo=NULL;
      }
      else if (testa_timezone(novo) != 0)/*No caso das coordenadas nao serem as corretas*/
      {
       contador2++;
       novo=NULL;
      }
    }
  }
  imprime_erros_aero(contador,contador1,contador2);
  return topo;
}



/*Funcao que recebe um apontador para o ficheiro de texto "rotas.txt" e um apontador do tipo AEROPORTO* para o topo da pilha dos aeroportos.
Esta funcao vai ler cada linha "medir o seu tamanho" e guarda-la num vetor de caracteres. Se o tamanho estiver correto vai
comparar os primeiros 8 caracteres do vetor com a string "AIRLINE:", se a funcao strncmp devolver 0,ou seja se as strings forem iguais)
vai alocar memoria do tipo COMPANHIA(atraves da funcao "aloca_memoria_comp" e colocar la a string q estiver a seguir a "AIRLINE:".
De seguida procura o lugar onde deve inserir a nova companhia e insere - la .
Se a comparacao retornar diferente de 0, o programa vai alocar memoria do tipo voo e vai tentar coverter os 9 dados caracteristicos de cada voo.
Se os tiver convertido vai testar as cidades de partida e chegada (vai compara-las com as que recebemos atraves do ficheiro "aeroportos.txt")
e vai testar os horarios(parametros a ser especificados na funcao do teste de horarios), tendo as cidades sido confirmadas e os horarios tambem,
o programa procura o local de insercao e coloca la o novo voo. Em caso contrario, imprime o erro que o levou a nao colocar o voo.
De salientar que esta funcao associa os voos a uma determinada companhia e que se esta nao existir, nao vai colocar nada na pilha de pilhas. */
COMPANHIA *inic_lista_companhia(FILE *fp, AEROPORTO *topo_aero){
  COMPANHIA *novo = NULL, *topo = NULL;
  VOO *novo_voo = NULL;
  char linha[DIM];
  int aux=0,aux1=0,contador=0,contador1=0,contador2=0,contador3=0, contador4=0, contador5=0;
  while (fgets(linha, DIM, fp) != NULL){/*Leitura de uma linha*/
    if ((strlen(linha) != 0) && (strlen(linha) != 1) &&(strlen(linha)!=2)){/*teste do comprimento da linha*/
      if (strncmp(linha, "AIRLINE:", 8) == 0){/*Teste nome do aeroporto*/
        novo = aloca_memoria_comp(novo);
        aux1=sscanf(linha, "AIRLINE: %s", novo->nome);
        if(aux1!=1){
        novo = NULL;}
        else if (topo == NULL){/*Se nenhuma companhia existir coloca a nova companhia no topo*/
          novo->prox = NULL;
          topo = novo;}
        else{/*Se alguma companhia existir coloca esta apontar para o topo e o topo a apontar para ela*/
          novo->prox = topo;
          topo = novo;}
      }
      else{
        novo_voo = aloca_memoria_voo(novo_voo);/*Alocacao de memoria*/
        aux = sscanf(linha, "%s %s %02d:%02d %s %s %02d:%02d %s", novo_voo->codigo,
                     novo_voo->aeroporto_de_partida, &(novo_voo->partida.hora), &(novo_voo->partida.minutos),
                     novo_voo->partida.parte_do_dia, novo_voo->aeroporto_de_chegada, &(novo_voo->chegada.hora),
                     &(novo_voo->chegada.minutos), novo_voo->chegada.parte_do_dia);
        novo_voo->prox = NULL;/*Inicializacao do campo prox*/
        if ((aux == 9) && (testa_capitais(topo_aero, novo_voo) == 0) && (testa_horas(novo_voo) == 0) && (topo !=NULL) &&(novo!=NULL) && (testa_identificacao(novo_voo)==0) && (testa_duracao(topo_aero,novo_voo)==0) &&(testa_nomes(novo_voo)==0))/*Teste dos dados*/{
          if (topo->x == NULL){/*Algoritmo de insercao igual ao anteriormente comentado*/
            topo->x = novo_voo;
            novo_voo->prox = NULL;
          }
          else{
            novo_voo->prox = topo->x;
            topo->x = novo_voo;}
        }
        else if (aux != 9){
          contador++;
          novo_voo=NULL;}
        else if((aux==9) && (novo == NULL)){
          contador3++;
          novo_voo=NULL;}
        else if ((aux == 9) && (testa_capitais(topo_aero, novo_voo) != 0)){
           contador1++;
           novo_voo=NULL;}
          else if ((testa_identificacao(novo_voo) != 0)){
           contador2++;
           novo_voo=NULL;}
          else if((testa_duracao(topo_aero,novo_voo)!=0)){
           contador4++;
           novo_voo=NULL; }
          else if(testa_nomes(novo_voo)!=0){
           contador5++;
           novo_voo=NULL;}
      }
    }
  }
  if(contador5!=0){
    printf("Aviso: %d voos cujo aeroporto de partida e igual ao de chegada (nao foram acrescentados)\n",contador5);}
  imprime_erros(contador, contador1, contador2,contador3,contador4);/*impressao de erros*/
  topo = apaga_companhias_sem_voos(topo);
  return topo;/*Retorno do topo das companhias*/
}

/*Esta funcao conjuga varias funcoes menores e tem como objetivo a inicializacao da pilha dos aeroportos. Nao tem argumentos e retorna um apontador do tipo AEROPORTO* para o topo da pilha dos aeroportos.*/
AEROPORTO *inicializar_aeroporto()
{
  FILE *fp = NULL;
  AEROPORTO *topo_aero = NULL;

  fp = abre_fich(fp, "aeroportos.txt");
  topo_aero = inic_lista_aero(fp);
  fclose(fp);
  return topo_aero;
}
/*Esta funcao conjuga varias funcoes menores e tem como objetivo a inicializacao da pilha das companhias. Nao tem argumentos e retorna um apontador do tipo COMPANHIA* para o topo da pilha das companhias.*/
COMPANHIA *inicializar_companhia(AEROPORTO *topo_aero)
{
  FILE *fp = NULL;
  COMPANHIA *topo_companhia = NULL;

  fp = abre_fich(fp, "rotas.txt");
  topo_companhia = inic_lista_companhia(fp, topo_aero);
  fclose(fp);
  topo_companhia = distancia_voo(topo_companhia, topo_aero);
  return topo_companhia;
}



