#include "headers.h"

/*FICHEIRO: funcoes.c
  OBJETIVO: Este ficheiro tem como objetivo a criacao de varias funcoes que agrupam as funcoes necessárias para a realizacao de uma determinada ordem.
Por exemplo a funcao_1 agrupa as funcoes e os testes necessarios para mostrar todos os aeroportos.*/

/*Esta funcao conjuga varias funcoes anteriores. Ela inicializa os aeroportos e as companhias. 
Testa ambas as novas estruturas de dados e se tudo correr bem utiliza a funcao "mostra" para imprimir todos os aeroportos registados na nova pilha.*/
void funcao_1()
{
  AEROPORTO *topo_aero = NULL;
  topo_aero = inicializar_aeroporto();
  testa_aeroportos(topo_aero);
  if(topo_aero==NULL){
  printf("Aviso: Ficheiro dos aeroportos sem dados válidos\n");
  exit(0);
  }
  printf("Aeroportos mais importantes das capitais europeias:\n");
  mostra(topo_aero);

}
/*Esta funcao conjuga conjuga varias funcoes anteriores. Ela inicializa os aeroportos e as companhias. Testa ambas as novas estruturas de dados e se tudo correr bem utiliza a funcao "mostra_voo" parara imprimir todas as companhias e os seus respetivos voos.*/
void funcao_2()
{
  AEROPORTO *topo_aero = NULL;
  COMPANHIA *topo_companhia = NULL;
  topo_aero = inicializar_aeroporto();
  testa_aeroportos(topo_aero);
  topo_companhia = inicializar_companhia(topo_aero);
  testa_companhia(topo_companhia);
  teste(topo_aero, topo_companhia);
  printf("Voos entre as capitais europeias:\n");
  mostra_voo(topo_companhia);

}
/*A função recebe argumentos passados pela linha de comando.
Esta funcao conjuga conjuga varias funcoes anteriores. Ela inicializa os aeroportos e as companhias.
Testa ambas as novas estruturas de dados e se tudo correr bem utiliza a funcao "mostra_rota_direta" para imprimir todas os voos entre duas cidades, a serem introduzidas pelo utilizador.*/
void funcao_3_ALL(char *argv[])
{
  AEROPORTO *topo_aero = NULL;
  COMPANHIA *topo_companhia = NULL;
  topo_aero = inicializar_aeroporto();
  testa_aeroportos(topo_aero);
  topo_companhia = inicializar_companhia(topo_aero);
  testa_companhia(topo_companhia);
  teste(topo_aero, topo_companhia);
  printf("Rotas diretas entre:%s e %s \n", argv[1], argv[2]);
  mostra_rota_direta(topo_companhia, argv);
}

/*A função recebe argumentos passados pela linha de comando.
Esta funcao conjuga conjuga varias funcoes anteriores. Ela inicializa os aeroportos e as companhias.
Testa ambas as novas estruturas de dados e se tudo correr bem utiliza a funcao "mostra_rota_direta" para imprimir to primeiro voo encontrado entre 2 cidades,
a serem introduzidas pelo utilizador.*/
void funcao_3(char *argv[])
{
  AEROPORTO *topo_aero = NULL;
  COMPANHIA *topo_companhia = NULL;
  topo_aero = inicializar_aeroporto();
  testa_aeroportos(topo_aero);
  topo_companhia = inicializar_companhia(topo_aero);
  testa_companhia(topo_companhia);
  teste(topo_aero, topo_companhia);
  mostra1_rota_direta(topo_companhia, argv);
  printf("\n\n");
}

/*a funnção recebe um argumento passado pela linha de comando e um apontador da lista das companhias.
A função cria um apontador do tipo VOO que está a apontar para o início da lista de voos que têm a rota desejada.
Se a lista estiver fazia, mostra uma mensagem de erro e termina o programa.
Caso contrário, mostra a lista dos voos.*/
void funcao_4_ALL(char *argv[], COMPANHIA *topo_companhia)
{
  VOO *topo_voo = NULL;
  topo_voo = insere_voos_diretos(topo_companhia, argv);
  if (topo_voo == NULL)
  {
    printf("Aviso: Rota pedida nao consta na base de  dados\n");
    exit(0);
  }
  mostra_lista_rota_direta_tc_td(topo_voo);
}

/*a funnção recebe um argumento passado pela linha de comando e um apontador da lista das companhias.
A função cria um apontador do tipo VOO que está a apontar para o início da lista de voos que têm a rota desejada.
Se a lista estiver fazia, mostra uma mensagem de erro e termina o programa.
Caso contrário, mostra o primeiro voo da lista.*/
void funcao_4(char *argv[], COMPANHIA *topo_companhia)
{
  VOO *topo_voo = NULL;
  topo_voo = insere_voos_diretos(topo_companhia, argv);
  if (topo_voo == NULL)
  {
    printf("Aviso: Rota pedida nao consta na base de  dados\n");
    exit(0);
  }
  mostra_1lista_rota_direta_tc_td(topo_voo);
}



/*A função recebe argumentos passados pela linha de comando.
Esta funcao conjuga conjuga varias funcoes anteriores. Ela inicializa os aeroportos e as companhias e os apontadores dos tipos VOO e VOO_LIG.
Cria apontadores tanto para a pilha de partida como para a pilha conjunta que engloba os 2 voos.
É imprimido o primeiro conjunto de voos que verificam a condicao de partida e de chegada, nao importando o horario*/
void funcao_5(char *argv1, char *argv2)
{
  AEROPORTO *topo_aero = NULL;
  COMPANHIA *topo_companhia = NULL;
  VOO *aux_partidas = NULL;
  VOO_LIG *hurray = NULL;

  topo_aero = inicializar_aeroporto();
  testa_aeroportos(topo_aero);
  topo_companhia = inicializar_companhia(topo_aero);
  testa_companhia(topo_companhia);
  teste(topo_aero, topo_companhia);
  printf("Rotas com ligacao(sem preocupacao horario) entre:%s e %s \n", argv1, argv2);

  aux_partidas = cria_pilha_partida(argv1, topo_companhia);
  hurray = cria_pilha_conjunta(aux_partidas, argv2, topo_companhia);
  teste_rota_lig(hurray);

  printf("PRIMEIRO VOO:\n");
  mostra_voovoo(hurray->prox->x);
  printf("SEGUNDO VOO:\n");
  mostra_voovoo(hurray->prox->ligacao);
  printf("\nDISTANCIA TOTAL:%.2f\n", hurray->prox->distancia_total);
  printf("PRECO TOTAL:%.2f EUROS\n", hurray->prox->preco_total);
  printf("\n\n");
  liberta_memoria_voolig(hurray);
  liberta_memoria_aeroporto(topo_aero);
  liberta_memoria_companhia(topo_companhia);

}

/*A função recebe argumentos passados pela linha de comando.
Esta funcao conjuga conjuga varias funcoes anteriores. Ela inicializa os aeroportos e as companhias e os apontadores dos tipo VOO e VOO_LIG.
Cria apontadores tanto para a pilha de partida como para a pilha conjunta que engloba os 2 voos.
É imprimido o primeiro conjunto de voos que verificam a condicao de partida e de chegada e que têm a hora de partida inferior.*/
void funcao_6_crescente(char *argv1, char *argv2)
{
  AEROPORTO *topo_aero = NULL;
  COMPANHIA *topo_companhia = NULL;
  VOO *aux_partidas = NULL;
  VOO_LIG *hurray = NULL;
  topo_aero = inicializar_aeroporto();
  testa_aeroportos(topo_aero);
  topo_companhia = inicializar_companhia(topo_aero);
  testa_companhia(topo_companhia);
  teste(topo_aero, topo_companhia);
  printf("Rotas com ligacao(com preocupacao horario e ordenadas por ordem de partida crescente) entre:%s e %s \n", argv1, argv2);
  aux_partidas = cria_pilha_partida(argv1, topo_companhia);
  hurray = cria_pilha_conjunta(aux_partidas, argv2, topo_companhia);
  teste_rota_lig(hurray);
  hurray = testa_horario(hurray); /*Há preocupação quanto à hora de saída do segundo voo em relação ao primeiro.*/
  hurray = ordena_por_tempo_crescente(hurray);

  printf("PRIMEIRO VOO:\n");
  mostra_voovoo(hurray->prox->x);
  printf("SEGUNDO VOO:\n");
  mostra_voovoo(hurray->prox->ligacao);
  printf("\nDISTANCIA TOTAL:%f\n", hurray->prox->distancia_total);
  printf("PRECO TOTAL:%.2f EUROS\n", hurray->prox->preco_total);
  printf("\n\n");
  liberta_memoria_voolig(hurray);
  liberta_memoria_aeroporto(topo_aero);
  liberta_memoria_companhia(topo_companhia);
}

/*A função recebe argumentos passados pela linha de comando.
Esta funcao conjuga conjuga varias funcoes anteriores. Ela inicializa os aeroportos e as companhias e os apontadores dos tipo VOO e VOO_LIG.
Cria apontadores tanto para a pilha de partida como para a pilha conjunta que engloba os 2 voos.
É imprimido o primeiro conjunto de voos que verificam a condicao de partida e de chegada e que têm a hora de partida superior.*/
void funcao_6_decrescente(char *argv1, char *argv2)
{
  AEROPORTO *topo_aero = NULL;
  COMPANHIA *topo_companhia = NULL;
  VOO *aux_partidas = NULL;
  VOO_LIG *hurray = NULL;
  topo_aero = inicializar_aeroporto();
  testa_aeroportos(topo_aero);
  topo_companhia = inicializar_companhia(topo_aero);
  testa_companhia(topo_companhia);
  teste(topo_aero, topo_companhia);
  printf("Rotas com ligacao(com preocupacao horario e ordenadas por ordem de partida decrescente) entre:%s e %s \n", argv1, argv2);

  aux_partidas = cria_pilha_partida(argv1, topo_companhia);
  hurray = cria_pilha_conjunta(aux_partidas, argv2, topo_companhia);
  teste_rota_lig(hurray);
  hurray = testa_horario(hurray);
  hurray = ordena_por_tempo_decrescente(hurray);

  printf("PRIMEIRO VOO:\n");
  mostra_voovoo(hurray->prox->x);
  printf("SEGUNDO VOO:\n");
  mostra_voovoo(hurray->prox->ligacao);
  printf("\nDISTANCIA TOTAL:%.2f\n", hurray->prox->distancia_total);
  printf("PRECO TOTAL:%.2f EUROS\n", hurray->prox->preco_total);
  printf("\n\n");
  liberta_memoria_voolig(hurray);
  liberta_memoria_aeroporto(topo_aero);
  liberta_memoria_companhia(topo_companhia);
}

/*A função recebe argumentos passados pela linha de comando.
Esta funcao conjuga conjuga varias funcoes anteriores. Ela inicializa os aeroportos e as companhias e os apontadores dos tipo VOO e VOO_LIG.
Cria apontadores tanto para a pilha de partida como para a pilha conjunta que engloba os 2 voos.
No caso de os voos terem a mesma distancia, são ordenados por ordem crescente de partida do primeiro voo.
É imprimido o primeiro conjunto de voos que verificam a condicao de partida e de chegada e que têm a menor distância a ser realizada.*/
void funcao_7_crescente(char *argv1, char *argv2)
{
  AEROPORTO *topo_aero = NULL;
  COMPANHIA *topo_companhia = NULL;
  VOO *aux_partidas = NULL;
  VOO_LIG *hurray = NULL, *hiphip = NULL;
  topo_aero = inicializar_aeroporto();
  testa_aeroportos(topo_aero);
  topo_companhia = inicializar_companhia(topo_aero);
  testa_companhia(topo_companhia);
  teste(topo_aero, topo_companhia);
  printf("Rotas com ligacao(com preocupacao horario e ordenadas predominantemente por distancia crescente e depois por ordem de partida crescente) entre:%s e %s \n", argv1, argv2);
  aux_partidas = cria_pilha_partida(argv1, topo_companhia);
  hurray = cria_pilha_conjunta(aux_partidas, argv2, topo_companhia);
  teste_rota_lig(hurray);
  hurray = testa_horario(hurray);
  hurray = ordena_por_tempo_crescente(hurray);
  hiphip = ordena_por_distancia(hurray);

  printf("PRIMEIRO VOO:\n");
  mostra_voovoo(hiphip->prox->x);
  printf("SEGUNDO VOO:\n");
  mostra_voovoo(hiphip->prox->ligacao);
  printf("\nDISTANCIA TOTAL:%f\n", hiphip->prox->distancia_total);
  printf("PRECO TOTAL:%.2f EUROS\n", hiphip->prox->preco_total);
  printf("\n\n");
  liberta_memoria_voolig(hiphip);
  liberta_memoria_aeroporto(topo_aero);
  liberta_memoria_companhia(topo_companhia);
}

/*A função recebe argumentos passados pela linha de comando.
Esta funcao conjuga conjuga varias funcoes anteriores. Ela inicializa os aeroportos e as companhias e os apontadores dos tipo VOO e VOO_LIG.
Cria apontadores tanto para a pilha de partida como para a pilha conjunta que engloba os 2 voos.
No caso de os voos terem a mesma distancia, são ordenados por ordem decrescente de partida do primeiro voo.
É imprimido o primeiro conjunto de voos que verificam a condicao de partida e de chegada e que têm a menor distância a ser realizada.*/
void funcao_7_decrescente(char *argv1, char *argv2)
{
  AEROPORTO *topo_aero = NULL;
  COMPANHIA *topo_companhia = NULL;
  VOO *aux_partidas = NULL;
  VOO_LIG *hurray = NULL, *hiphip = NULL;
  topo_aero = inicializar_aeroporto();
  testa_aeroportos(topo_aero);
  topo_companhia = inicializar_companhia(topo_aero);
  testa_companhia(topo_companhia);
  teste(topo_aero, topo_companhia);
  printf("Rotas com ligacao(com preocupacao horario e ordenadas predominantemente por distancia crescente e depois por ordem de partida crescente) entre:%s e %s \n", argv1, argv2);
  aux_partidas = cria_pilha_partida(argv1, topo_companhia);
  hurray = cria_pilha_conjunta(aux_partidas, argv2, topo_companhia);
  teste_rota_lig(hurray);
  hurray = testa_horario(hurray);
  hurray = ordena_por_tempo_decrescente(hurray);
  hiphip = ordena_por_distancia(hurray);

  printf("PRIMEIRO VOO:\n");
  mostra_voovoo(hiphip->prox->x);
  printf("SEGUNDO VOO:\n");
  mostra_voovoo(hiphip->prox->ligacao);
  printf("\nDISTANCIA TOTAL:%.2f\n", hiphip->prox->distancia_total);
  printf("PRECO TOTAL:%.2f EUROS\n", hiphip->prox->preco_total);
  printf("\n\n");
  liberta_memoria_voolig(hiphip);
  liberta_memoria_aeroporto(topo_aero);
  liberta_memoria_companhia(topo_companhia);
}


/*A função recebe argumentos passados pela linha de comando.
Esta funcao conjuga conjuga varias funcoes anteriores. Ela inicializa os aeroportos e as companhias e os apontadores dos tipos VOO e VOO_LIG.
Cria apontadores tanto para a pilha de partida como para a pilha conjunta que engloba os 2 voos.
São imprimidos todos os blocos de voos que verificam a condicao de partida e de chegada, nao importando o horario*/
void funcao_5_ALL(char *argv1, char *argv2)
{
  AEROPORTO *topo_aero = NULL;
  COMPANHIA *topo_companhia = NULL;
  VOO *aux_partidas = NULL;
  VOO_LIG *hurray = NULL;

  topo_aero = inicializar_aeroporto();
  testa_aeroportos(topo_aero);
  topo_companhia = inicializar_companhia(topo_aero);
  testa_companhia(topo_companhia);
  teste(topo_aero, topo_companhia);
  printf("Rotas com ligacao(sem preocupacao horario) entre:%s e %s \n", argv1, argv2);

  aux_partidas = cria_pilha_partida(argv1, topo_companhia);
  hurray = cria_pilha_conjunta(aux_partidas, argv2, topo_companhia);
  teste_rota_lig(hurray);
  mostra_voo_lig(hurray->prox);
  liberta_memoria_voolig(hurray);
  liberta_memoria_aeroporto(topo_aero);
  liberta_memoria_companhia(topo_companhia);
}


/*A função recebe argumentos passados pela linha de comando.
Esta funcao conjuga conjuga varias funcoes anteriores. Ela inicializa os aeroportos e as companhias e os apontadores dos tipo VOO e VOO_LIG.
Cria apontadores tanto para a pilha de partida como para a pilha conjunta que engloba os 2 voos.
São imprimidos todos os blocos de voos que verificam a condicao de partida e de chegada, estando ordenados hora de partida inferior.*/
void funcao_6_crescente_ALL(char *argv1, char *argv2)
{
  AEROPORTO *topo_aero = NULL;
  COMPANHIA *topo_companhia = NULL;
  VOO *aux_partidas = NULL;
  VOO_LIG *hurray = NULL;
  topo_aero = inicializar_aeroporto();
  testa_aeroportos(topo_aero);
  topo_companhia = inicializar_companhia(topo_aero);
  testa_companhia(topo_companhia);
  teste(topo_aero, topo_companhia);
  printf("\n\na");
  printf("Rotas com ligacao(com preocupacao horario e ordenadas por ordem de partida crescente) entre:%s e %s \n", argv1, argv2);

  aux_partidas = cria_pilha_partida(argv1, topo_companhia);
  hurray = cria_pilha_conjunta(aux_partidas, argv2, topo_companhia);
  teste_rota_lig(hurray);
  hurray = testa_horario(hurray);
  hurray = ordena_por_tempo_crescente(hurray);
  mostra_voo_lig(hurray->prox);
  liberta_memoria_voolig(hurray);
  liberta_memoria_aeroporto(topo_aero);
  liberta_memoria_companhia(topo_companhia);
}

/*A função recebe argumentos passados pela linha de comando.
Esta funcao conjuga conjuga varias funcoes anteriores. Ela inicializa os aeroportos e as companhias e os apontadores dos tipo VOO e VOO_LIG.
Cria apontadores tanto para a pilha de partida como para a pilha conjunta que engloba os 2 voos.
São imprimidos todos os blocos de voos que verificam a condicao de partida e de chegada, etsando ordenador por hora de partida superior.*/
void funcao_6_decrescente_ALL(char *argv1, char *argv2)
{
  AEROPORTO *topo_aero = NULL;
  COMPANHIA *topo_companhia = NULL;
  VOO *aux_partidas = NULL;
  VOO_LIG *hurray = NULL;
  topo_aero = inicializar_aeroporto();
  testa_aeroportos(topo_aero);
  topo_companhia = inicializar_companhia(topo_aero);
  testa_companhia(topo_companhia);
  teste(topo_aero, topo_companhia);
  printf("Rotas com ligacao(com preocupacao horario e ordenadas por ordem de partida decrescente) entre:%s e %s \n", argv1, argv2);

  aux_partidas = cria_pilha_partida(argv1, topo_companhia);
  hurray = cria_pilha_conjunta(aux_partidas, argv2, topo_companhia);
  teste_rota_lig(hurray);
  hurray = testa_horario(hurray);
  hurray = ordena_por_tempo_decrescente(hurray);
  mostra_voo_lig(hurray->prox);
  liberta_memoria_voolig(hurray);
  liberta_memoria_aeroporto(topo_aero);
  liberta_memoria_companhia(topo_companhia);
}

/*A função recebe argumentos passados pela linha de comando.
Esta funcao conjuga conjuga varias funcoes anteriores. Ela inicializa os aeroportos e as companhias e os apontadores dos tipo VOO e VOO_LIG.
Cria apontadores tanto para a pilha de partida como para a pilha conjunta que engloba os 2 voos.
São imprimidos todos os blocos de voos que verificam a condicao de partida e de chegada , estando ordenados pela menor distância a ser realizada.
No caso de os voos terem a mesma distancia, são ordenados por ordem crescente de partida do primeiro voo.*/
void funcao_7_crescente_ALL(char *argv1, char *argv2)
{
  AEROPORTO *topo_aero = NULL;
  COMPANHIA *topo_companhia = NULL;
  VOO *aux_partidas = NULL;
  VOO_LIG *hurray = NULL, *hiphip = NULL;
  topo_aero = inicializar_aeroporto();
  testa_aeroportos(topo_aero);
  topo_companhia = inicializar_companhia(topo_aero);
  testa_companhia(topo_companhia);
  teste(topo_aero, topo_companhia);
  printf("Rotas com ligacao(com preocupacao horario e ordenadas predominantemente por distancia crescente e depois por ordem de partida crescente) entre:%s e %s \n", argv1, argv2);
  aux_partidas = cria_pilha_partida(argv1, topo_companhia);
  hurray = cria_pilha_conjunta(aux_partidas, argv2, topo_companhia);
  teste_rota_lig(hurray);
  hurray = testa_horario(hurray);
  hurray = ordena_por_tempo_crescente(hurray);
  hiphip = ordena_por_distancia(hurray);
  mostra_voo_lig(hiphip->prox);
  liberta_memoria_voolig(hiphip);
  liberta_memoria_aeroporto(topo_aero);
  liberta_memoria_companhia(topo_companhia);
}

/*A função recebe argumentos passados pela linha de comando.
Esta funcao conjuga conjuga varias funcoes anteriores. Ela inicializa os aeroportos e as companhias e os apontadores dos tipo VOO e VOO_LIG.
Cria apontadores tanto para a pilha de partida como para a pilha conjunta que engloba os 2 voos.
No caso de os voos terem a mesma distancia, são ordenados por ordem decrescente de partida do primeiro voo.
São imprimidos todos os blocos de voos que verificam a condicao de partida e de chegada, etando ordenados pela menor distância a ser realizada.*/
void funcao_7_decrescente_ALL(char *argv1, char *argv2)
{
  AEROPORTO *topo_aero = NULL;
  COMPANHIA *topo_companhia = NULL;
  VOO *aux_partidas = NULL;
  VOO_LIG *hurray = NULL, *hiphip = NULL;
  topo_aero = inicializar_aeroporto();
  testa_aeroportos(topo_aero);
  topo_companhia = inicializar_companhia(topo_aero);
  testa_companhia(topo_companhia);
  teste(topo_aero, topo_companhia);
  printf("Rotas com ligacao(com preocupacao horario e ordenadas predominantemente por distancia decrescente e depois por ordem de partida crescente) entre:%s e %s \n", argv1, argv2);
  aux_partidas = cria_pilha_partida(argv1, topo_companhia);
  hurray = cria_pilha_conjunta(aux_partidas, argv2, topo_companhia);
  teste_rota_lig(hurray);
  hurray = testa_horario(hurray);
  hurray = ordena_por_tempo_decrescente(hurray);
  hiphip = ordena_por_distancia(hurray);
  mostra_voo_lig(hiphip->prox);
  liberta_memoria_voolig(hiphip);
  liberta_memoria_aeroporto(topo_aero);
  liberta_memoria_companhia(topo_companhia);
}



/*A função recebe argumentos passados pela linha de comando.
Esta funcao conjuga conjuga varias funcoes anteriores. Ela inicializa os aeroportos e as companhias e os apontadores dos tipos VOO, VOO_LIG e VOO_LG2.
Cria apontadores tanto para a pilha de partida como as pilhas 1 e 2 que contêm, respetivamente, 2 e 3 voos de ligação.
São imprimidos todos os blocos de voos que verificam a condicao de partida e de chegada, nao importando o horario*/
void funcao_8_sem_restricoes_ALL(char *argv1, char *argv2)
{
  AEROPORTO *topo_aero = NULL;
  COMPANHIA *topo_companhia = NULL;
  VOO *aux_partidas = NULL;
  VOO_LIG *hurray = NULL;
  VOO_LIG2* lig3;

  topo_aero = inicializar_aeroporto();
  testa_aeroportos(topo_aero);
  topo_companhia = inicializar_companhia(topo_aero);
  testa_companhia(topo_companhia);
  teste(topo_aero, topo_companhia);
  printf("Rotas com 2 ligacoes(sem preocupacao horario) entre:%s e %s \n", argv1, argv2);

  aux_partidas = cria_pilha_partida(argv1, topo_companhia);
  hurray = pilha_lig1(aux_partidas, argv2, topo_companhia);
  teste_rota_lig(hurray);
  lig3 = pilha_lig2(hurray->prox, argv2, topo_companhia);
  teste_rota_lig2(lig3);
  mostra_voo_lig2(lig3->prox);
  liberta_memoria_voolig2(lig3);
  liberta_memoria_aeroporto(topo_aero);
  liberta_memoria_companhia(topo_companhia);
}


/*A função recebe argumentos passados pela linha de comando.
Esta funcao conjuga conjuga varias funcoes anteriores. Ela inicializa os aeroportos e as companhias e os apontadores dos tipos VOO, VOO_LIG e VOO_LG2.
Cria apontadores tanto para a pilha de partida como as pilhas 1 e 2 que contêm, respetivamente, 2 e 3 voos de ligação.
É imprimido o primeiro bloco de 3 voos que verifica a condicao de partida e de chegada, nao importando o horario*/
void funcao_8_sem_restricoes(char *argv1, char *argv2)
{
  AEROPORTO *topo_aero = NULL;
  COMPANHIA *topo_companhia = NULL;
  VOO *aux_partidas = NULL;
  VOO_LIG *hurray = NULL;
  VOO_LIG2* lig3;

  topo_aero = inicializar_aeroporto();
  testa_aeroportos(topo_aero);
  topo_companhia = inicializar_companhia(topo_aero);
  testa_companhia(topo_companhia);
  teste(topo_aero, topo_companhia);
  printf("Rotas com 2 ligacoes(sem preocupacao horario) entre:%s e %s \n", argv1, argv2);

  aux_partidas = cria_pilha_partida(argv1, topo_companhia);
  hurray = pilha_lig1(aux_partidas, argv2, topo_companhia);
  teste_rota_lig(hurray);
  lig3 = pilha_lig2(hurray->prox, argv2, topo_companhia);
  teste_rota_lig2(lig3);
  if(strcmp(lig3->prox->x->aeroporto_de_partida, lig3->prox->ligacao1->aeroporto_de_chegada)!=0){
    printf("PRIMEIRO VOO:\n");
    mostra_voovoo(lig3->prox->x);
    printf("SEGUNDO VOO:\n");
    mostra_voovoo(lig3->prox->ligacao1);
    printf("TERCEIRO VOO:\n");
    mostra_voovoo(lig3->prox->ligacao2);
    printf("\nDISTANCIA TOTAL:%.2f\n", lig3->prox->distancia_total);
    printf("PRECO TOTAL:%.2f EUROS\n", lig3->prox->preco_total);
    printf("\n\n");
  }
  liberta_memoria_voolig2(lig3);
  liberta_memoria_aeroporto(topo_aero);
  liberta_memoria_companhia(topo_companhia);
}

/*A função recebe argumentos passados pela linha de comando.
Esta funcao conjuga conjuga varias funcoes anteriores. Ela inicializa os aeroportos e as companhias e os apontadores dos tipo VOO, VOO_LIG e VOO_LIG2.
Cria apontadores tanto para a pilha de partida como as pilhas 1 e 2 que contêm, respetivamente, 2 e 3 voos de ligação.
São imprimidos todos os blocos de voos que verificam a condicao de partida e de chegada, estando ordenados por hora partida inferior.
A memória alocada pelas lista é, no final, libertada.*/
void funcao_8_crescente_ALL(char *argv1, char *argv2)
{
  AEROPORTO *topo_aero = NULL;
  COMPANHIA *topo_companhia = NULL;
  VOO *aux_partidas = NULL;
  VOO_LIG *hurray = NULL;
  VOO_LIG2* lig3;
  topo_aero = inicializar_aeroporto();
  testa_aeroportos(topo_aero);
  topo_companhia = inicializar_companhia(topo_aero);
  testa_companhia(topo_companhia);
  teste(topo_aero, topo_companhia);
  printf("Rota com 2 ligacoes (com preocupacao horario e ordenadas por ordem de partida crescente entre:%s e %s \n", argv1, argv2);
  aux_partidas = cria_pilha_partida(argv1, topo_companhia);
  hurray = pilha_lig1(aux_partidas, argv2, topo_companhia);
  teste_rota_lig(hurray);
  hurray = testa_horario(hurray);
  lig3 = pilha_lig2(hurray->prox, argv2, topo_companhia);
  lig3=testa_horario2(lig3);
  teste_rota_lig2(lig3);
  lig3= ordena_por_tempo_crescente2(lig3);
  if(strcmp(lig3->prox->x->aeroporto_de_partida, lig3->prox->ligacao1->aeroporto_de_chegada)!=0){
    mostra_voo_lig2(lig3->prox);
   }
  liberta_memoria_voolig2(lig3);
  liberta_memoria_aeroporto(topo_aero);
  liberta_memoria_companhia(topo_companhia);
}


/*A função recebe argumentos passados pela linha de comando.
Esta funcao conjuga conjuga varias funcoes anteriores. Ela inicializa os aeroportos e as companhias e os apontadores dos tipo VOO, VOO_LIG e VOO_LIG2.
Cria apontadores tanto para a pilha de partida como as pilhas 1 e 2 que contêm, respetivamente, 2 e 3 voos de ligação.
É imprimido o primeiro bloco de 3 voos que verifica a condicao de partida e de chegada e que tem a hora partida inferior.
A memória alocada pelas lista é, no final, libertada.*/
void funcao_8_crescente(char *argv1, char *argv2)
{
  AEROPORTO *topo_aero = NULL;
  COMPANHIA *topo_companhia = NULL;
  VOO *aux_partidas = NULL;
  VOO_LIG *hurray = NULL;
  VOO_LIG2* lig3;
  topo_aero = inicializar_aeroporto();
  testa_aeroportos(topo_aero);
  topo_companhia = inicializar_companhia(topo_aero);
  testa_companhia(topo_companhia);
  teste(topo_aero, topo_companhia);
  printf("Rota com 2 ligacoes (com preocupacao horario e ordenadas por ordem de partida crescente entre:%s e %s \n", argv1, argv2);
  aux_partidas = cria_pilha_partida(argv1, topo_companhia);
  hurray = pilha_lig1(aux_partidas, argv2, topo_companhia);
  teste_rota_lig(hurray);
  hurray = testa_horario(hurray);
  lig3 = pilha_lig2(hurray->prox, argv2, topo_companhia);
  lig3=testa_horario2(lig3);
  teste_rota_lig2(lig3);
  lig3= ordena_por_tempo_crescente2(lig3);
  if(strcmp(lig3->prox->x->aeroporto_de_partida, lig3->prox->ligacao1->aeroporto_de_chegada)!=0){
    printf("PRIMEIRO VOO:\n");
    mostra_voovoo(lig3->prox->x);
    printf("SEGUNDO VOO:\n");
    mostra_voovoo(lig3->prox->ligacao1);
    printf("TERCEIRO VOO:\n");
    mostra_voovoo(lig3->prox->ligacao2);
    printf("\nDISTANCIA TOTAL:%.2f\n", lig3->prox->distancia_total);
    printf("PRECO TOTAL:%.2f EUROS\n", lig3->prox->preco_total);
    printf("\n\n");
   }
  liberta_memoria_voolig2(lig3);
  liberta_memoria_aeroporto(topo_aero);
  liberta_memoria_companhia(topo_companhia);
}


/*A função recebe argumentos passados pela linha de comando.
Esta funcao conjuga conjuga varias funcoes anteriores. Ela inicializa os aeroportos e as companhias e os apontadores dos tipo VOO, VOO_LIG e VOO_LIG2.
Cria apontadores tanto para a pilha de partida como as pilhas 1 e 2 que contêm, respetivamente, 2 e 3 voos de ligação.
É imprimido o primeiro bloco de 3 voos que verifica a condicao de partida e de chegada e que tem a hora partida superior.
A memória alocada pelas lista é, no final, libertada.*/
void funcao_8_decrescente(char *argv1, char *argv2)
{
  AEROPORTO *topo_aero = NULL;
  COMPANHIA *topo_companhia = NULL;
  VOO *aux_partidas = NULL;
  VOO_LIG *hurray = NULL;
  VOO_LIG2* lig3;
  topo_aero = inicializar_aeroporto();
  testa_aeroportos(topo_aero);
  topo_companhia = inicializar_companhia(topo_aero);
  testa_companhia(topo_companhia);
  teste(topo_aero, topo_companhia);
  printf("Rota com 2 ligacoes (com preocupacao horario) e ordenadas por ordem de partida decrescente entre:%s e %s \n", argv1, argv2);
  aux_partidas = cria_pilha_partida(argv1, topo_companhia);
  hurray = pilha_lig1(aux_partidas, argv2, topo_companhia);
  teste_rota_lig(hurray);
  hurray = testa_horario(hurray);
  lig3 = pilha_lig2(hurray->prox, argv2, topo_companhia);
  lig3=testa_horario2(lig3);
  teste_rota_lig2(lig3);
  lig3= ordena_por_tempo_decrescente2(lig3);
  if(strcmp(lig3->prox->x->aeroporto_de_partida, lig3->prox->ligacao1->aeroporto_de_chegada)!=0){
    printf("PRIMEIRO VOO:\n");
    mostra_voovoo(lig3->prox->x);
    printf("SEGUNDO VOO:\n");
    mostra_voovoo(lig3->prox->ligacao1);
    printf("TERCEIRO VOO:\n");
    mostra_voovoo(lig3->prox->ligacao2);
    printf("\nDISTANCIA TOTAL:%.2f\n", lig3->prox->distancia_total);
    printf("PRECO TOTAL:%.2f EUROS\n", lig3->prox->preco_total);
    printf("\n\n");
   }
  liberta_memoria_voolig2(lig3);
  liberta_memoria_aeroporto(topo_aero);
  liberta_memoria_companhia(topo_companhia);
}


/*A função recebe argumentos passados pela linha de comando.
Esta funcao conjuga conjuga varias funcoes anteriores. Ela inicializa os aeroportos e as companhias e os apontadores dos tipo VOO, VOO_LIG e VOO_LIG2.
Cria apontadores tanto para a pilha de partida como as pilhas 1 e 2 que contêm, respetivamente, 2 e 3 voos de ligação.
São imprimidos todos os blocos de voos que verificam a condicao de partida e de chegada, estando ordenados por hora partida superior.
A memória alocada pelas lista é, no final, libertada.*/
void funcao_8_decrescente_ALL(char *argv1, char *argv2)
{
  AEROPORTO *topo_aero = NULL;
  COMPANHIA *topo_companhia = NULL;
  VOO *aux_partidas = NULL;
  VOO_LIG *hurray = NULL;
  VOO_LIG2* lig3;
  topo_aero = inicializar_aeroporto();
  testa_aeroportos(topo_aero);
  topo_companhia = inicializar_companhia(topo_aero);
  testa_companhia(topo_companhia);
  teste(topo_aero, topo_companhia);
  printf("Rota com 2 ligacoes (com preocupacao horario) e ordenadas por ordem de partida decrescente entre:%s e %s \n", argv1, argv2);
  aux_partidas = cria_pilha_partida(argv1, topo_companhia);
  hurray = pilha_lig1(aux_partidas, argv2, topo_companhia);
  teste_rota_lig(hurray);
  hurray = testa_horario(hurray);
  lig3 = pilha_lig2(hurray->prox, argv2, topo_companhia);
  lig3=testa_horario2(lig3);
  teste_rota_lig2(lig3);
  lig3= ordena_por_tempo_decrescente2(lig3);
  if(strcmp(lig3->prox->x->aeroporto_de_partida, lig3->prox->ligacao1->aeroporto_de_chegada)!=0){
    mostra_voo_lig2(lig3->prox);
   }
  liberta_memoria_voolig2(lig3);
  liberta_memoria_aeroporto(topo_aero);
  liberta_memoria_companhia(topo_companhia);
}

/*A função recebe argumentos passados pela linha de comando.
Esta funcao conjuga conjuga varias funcoes anteriores. Ela inicializa os aeroportos e as companhias e os apontadores dos tipo VOO, VOO_LIG e VOO_LIG2.
Cria apontadores tanto para a pilha de partida como as pilhas 1 e 2 que contêm, respetivamente, 2 e 3 voos de ligação.
São imprimidos todos os blocos de voos que verificam a condicao de partida e de chegada , estando ordenados pela menor distância a ser realizada.
No caso de os voos terem a mesma distancia, são ordenados por ordem crescente de partida do primeiro voo.*/
void funcao_8_crescente_distancia_ALL(char *argv1, char *argv2){
  AEROPORTO *topo_aero = NULL;
  COMPANHIA *topo_companhia = NULL;
  VOO *aux_partidas = NULL;
  VOO_LIG *hurray = NULL;
  VOO_LIG2* lig3;
  topo_aero = inicializar_aeroporto();
  testa_aeroportos(topo_aero);
  topo_companhia = inicializar_companhia(topo_aero);
  testa_companhia(topo_companhia);
  teste(topo_aero, topo_companhia);
  printf("Rota com 2 ligacoes (com preocupacao horario) predominantemente por distancia crescente e ordenadas por ordem de partida crescente entre:%s e %s \n", argv1, argv2);
  aux_partidas = cria_pilha_partida(argv1, topo_companhia);

  hurray = pilha_lig1(aux_partidas, argv2, topo_companhia);

  teste_rota_lig(hurray);


  hurray = testa_horario(hurray);

  lig3 = pilha_lig2(hurray->prox, argv2, topo_companhia);

  lig3=testa_horario2(lig3);\
  teste_rota_lig2(lig3);
  lig3= ordena_por_tempo_crescente2(lig3);
  lig3=ordena_por_distancia2(lig3);

  if(strcmp(lig3->prox->x->aeroporto_de_partida, lig3->prox->ligacao1->aeroporto_de_chegada)!=0){

    mostra_voo_lig2(lig3->prox);
  }
  liberta_memoria_voolig2(lig3);
  liberta_memoria_aeroporto(topo_aero);
  liberta_memoria_companhia(topo_companhia);
}

/*A função recebe argumentos passados pela linha de comando.
Esta funcao conjuga conjuga varias funcoes anteriores. Ela inicializa os aeroportos e as companhias e os apontadores dos tipo VOO, VOO_LIG e VOO_LIG2.
Cria apontadores tanto para a pilha de partida como as pilhas 1 e 2 que contêm, respetivamente, 2 e 3 voos de ligação.
É imprimido o primeiro bloco de 3 voos que verifica a condicao de partida e de chegada , estando ordenados pela menor distância a ser realizada.
No caso de os voos terem a mesma distancia, são ordenados por ordem crescente de partida do primeiro voo.*/
void funcao_8_crescente_distancia(char *argv1, char *argv2){
  AEROPORTO *topo_aero = NULL;
  COMPANHIA *topo_companhia = NULL;
  VOO *aux_partidas = NULL;
  VOO_LIG *hurray = NULL;
  VOO_LIG2* lig3;
  topo_aero = inicializar_aeroporto();
  testa_aeroportos(topo_aero);
  topo_companhia = inicializar_companhia(topo_aero);
  testa_companhia(topo_companhia);
  teste(topo_aero, topo_companhia);
  printf("Rota com 2 ligacoes (com preocupacao horario) predominantemente por distancia crescente e ordenadas por ordem de partida crescente entre:%s e %s \n", argv1, argv2);
  aux_partidas = cria_pilha_partida(argv1, topo_companhia);
  hurray = pilha_lig1(aux_partidas, argv2, topo_companhia);
  teste_rota_lig(hurray);
  hurray = testa_horario(hurray);
  lig3 = pilha_lig2(hurray->prox, argv2, topo_companhia);
  lig3=testa_horario2(lig3);
  teste_rota_lig2(lig3);
  lig3= ordena_por_tempo_crescente2(lig3);
  lig3=ordena_por_distancia2(lig3);
  if(strcmp(lig3->prox->x->aeroporto_de_partida, lig3->prox->ligacao1->aeroporto_de_chegada)!=0){
    printf("PRIMEIRO VOO:\n");
    mostra_voovoo(lig3->prox->x);
    printf("SEGUNDO VOO:\n");
    mostra_voovoo(lig3->prox->ligacao1);
    printf("TERCEIRO VOO:\n");
    mostra_voovoo(lig3->prox->ligacao2);
    printf("\nDISTANCIA TOTAL:%.2f\n", lig3->prox->distancia_total);
    printf("PRECO TOTAL:%.2f EUROS\n", lig3->prox->preco_total);
    printf("\n\n");
  }
  liberta_memoria_voolig2(lig3);
  liberta_memoria_aeroporto(topo_aero);
  liberta_memoria_companhia(topo_companhia);
}

/*A função recebe argumentos passados pela linha de comando.
Esta funcao conjuga conjuga varias funcoes anteriores. Ela inicializa os aeroportos e as companhias e os apontadores dos tipo VOO, VOO_LIG e VOO_LIG2.
Cria apontadores tanto para a pilha de partida como as pilhas 1 e 2 que contêm, respetivamente, 2 e 3 voos de ligação.
É imprimido o primeiro bloco de 3 voos que verifica a condicao de partida e de chegada , estando ordenados pela menor distância a ser realizada.
No caso de os voos terem a mesma distancia, são ordenados por ordem decrescente de partida do primeiro voo.*/
void funcao_8_decrescente_distancia(char *argv1, char *argv2)
{
  AEROPORTO *topo_aero = NULL;
  COMPANHIA *topo_companhia = NULL;
  VOO *aux_partidas = NULL;
  VOO_LIG *hurray = NULL;
  VOO_LIG2* lig3;
  topo_aero = inicializar_aeroporto();
  testa_aeroportos(topo_aero);
  topo_companhia = inicializar_companhia(topo_aero);
  testa_companhia(topo_companhia);
  teste(topo_aero, topo_companhia);
  printf("Rota com 2 ligacoes (com preocupacao horario) predominantemente por distancia crescente e ordenadas por ordem de partida decrescente entre:%s e %s \n", argv1, argv2);
  aux_partidas = cria_pilha_partida(argv1, topo_companhia);
  hurray = pilha_lig1(aux_partidas, argv2, topo_companhia);
  teste_rota_lig(hurray);
  hurray = testa_horario(hurray);
  lig3 = pilha_lig2(hurray->prox, argv2, topo_companhia);
  lig3=testa_horario2(lig3);
  teste_rota_lig2(lig3);
  lig3= ordena_por_tempo_decrescente2(lig3);
  lig3=ordena_por_distancia2(lig3);
  if(strcmp(lig3->prox->x->aeroporto_de_partida, lig3->prox->ligacao1->aeroporto_de_chegada)!=0){
    printf("PRIMEIRO VOO:\n");
    mostra_voovoo(lig3->prox->x);
    printf("SEGUNDO VOO:\n");
    mostra_voovoo(lig3->prox->ligacao1);
    printf("TERCEIRO VOO:\n");
    mostra_voovoo(lig3->prox->ligacao2);
    printf("\nDISTANCIA TOTAL:%.2f\n", lig3->prox->distancia_total);
    printf("PRECO TOTAL:%.2f EUROS\n", lig3->prox->preco_total);
    printf("\n\n");
   }
  liberta_memoria_voolig2(lig3);
  liberta_memoria_aeroporto(topo_aero);
  liberta_memoria_companhia(topo_companhia);
}

/*A função recebe argumentos passados pela linha de comando.
Esta funcao conjuga conjuga varias funcoes anteriores. Ela inicializa os aeroportos e as companhias e os apontadores dos tipo VOO, VOO_LIG e VOO_LIG2.
Cria apontadores tanto para a pilha de partida como as pilhas 1 e 2 que contêm, respetivamente, 2 e 3 voos de ligação.
São imprimidos todos os blocos de voos que verificam a condicao de partida e de chegada , estando ordenados pela menor distância a ser realizada.
No caso de os voos terem a mesma distancia, são ordenados por ordem decrescente de partida do primeiro voo.*/
void funcao_8_decrescente_distancia_ALL(char *argv1, char *argv2)
{
  AEROPORTO *topo_aero = NULL;
  COMPANHIA *topo_companhia = NULL;
  VOO *aux_partidas = NULL;
  VOO_LIG *hurray = NULL;
  VOO_LIG2* lig3;
  topo_aero = inicializar_aeroporto();
  testa_aeroportos(topo_aero);
  topo_companhia = inicializar_companhia(topo_aero);
  testa_companhia(topo_companhia);
  teste(topo_aero, topo_companhia);
  printf("Rota com 2 ligacoes (com preocupacao horario) predominantemente por distancia crescente e ordenadas por ordem de partida decrescente entre:%s e %s \n", argv1, argv2);
  aux_partidas = cria_pilha_partida(argv1, topo_companhia);
  hurray = pilha_lig1(aux_partidas, argv2, topo_companhia);
  teste_rota_lig(hurray);
  hurray = testa_horario(hurray);
  lig3 = pilha_lig2(hurray->prox, argv2, topo_companhia);
  lig3=testa_horario2(lig3);
  teste_rota_lig2(lig3);
  lig3= ordena_por_tempo_decrescente2(lig3);
  lig3=ordena_por_distancia2(lig3);
  if(strcmp(lig3->prox->x->aeroporto_de_partida, lig3->prox->ligacao1->aeroporto_de_chegada)!=0){
    mostra_voo_lig2(lig3->prox);
   }
  liberta_memoria_voolig2(lig3);
  liberta_memoria_aeroporto(topo_aero);
  liberta_memoria_companhia(topo_companhia);
}

/*A função é do tipo char**. Recebe os argumentos da linha de comando e um apontador de um apontador de caracteres.
Esta função é utilizada para o caso de os argumentos a serem introduzidos pelo utilizador estar na ordem errada.
Esta função é utilizada para o caso do número de argumentos ser 5.
Os ciclos irão correr os argumentos introduzidos e quando encontrarem o primeiro elemento que estaria na posicao seguinte na ordem correta
é introduzido na célula correspondente da string 'ordenado'. Só retorna o array caso encontre apenas um argumeno de cada,
evitando assim, possiveis repeticoes introduzidas na linha de comando.*/
char** ordena_5(int argc, char* argv[],char*ordenado[]){

int i=0,contador1=0;
int contador_L=0, contador_numero=0;
ordenado[0]=argv[0];
ordenado[1]=argv[1];
ordenado[2]=argv[2];
contador1=3;
do{
  for(i=1;i<=4;i++){
   if(contador1==3){
    if(strcmp(argv[i],"-L")==0){
    ordenado[3]=argv[i];
    contador_L++;
     }
    }
   if(contador1==4){
    if((strcmp(argv[i],"0")==0)||(strcmp(argv[i],"1")==0)||(strcmp(argv[i],"2")==0)){
    ordenado[4]=argv[i];
    contador_numero++;
    }
    }
  }
  contador1++;
}while(contador1<5);
if((contador_L==1)&&(contador_numero==1)){
  return ordenado;
}
limpa_espaco();
exit(0);
}


/*A função é do tipo char**. Recebe os argumentos da linha de comando e um apontador de um apontador de caracteres.
Esta função é utilizada para o caso de os argumentos a serem introduzidos pelo utilizador estar na ordem errada.
Esta função é utilizada para o caso do número de argumentos ser 6.
Os ciclos irão correr os argumentos introduzidos e quando encontrarem o primeiro elemento que estaria na posicao seguinte na ordem correta
é introduzido na célula correspondente da string 'ordenado'. Só retorna o array caso encontre apenas um argumeno de cada,
evitando assim, possiveis repeticoes introduzidas na linha de comando.*/
char** ordena_6(int argc, char* argv[],char*ordenado[]){
int i=0,contador1=0;
int contador_L=0, contador_numero=0,contador_crescente_ou_all=0;
ordenado[0]=argv[0];
ordenado[1]=argv[1];
ordenado[2]=argv[2];
contador1=3;
do{
  for(i=1;i<=5;i++){
   if(contador1==3){
    if(strcmp(argv[i],"-L")==0){
    ordenado[3]=argv[i];
    contador_L++;

     }
    }
   if(contador1==4){
    if((strcmp(argv[i],"0")==0)||(strcmp(argv[i],"1")==0)||(strcmp(argv[i],"2")==0)){
    ordenado[4]=argv[i];
    contador_numero++;
    }
    }
    if(contador1==5){
    if((strcmp(argv[i],"ALL")==0)||(strcmp(argv[i],"-TC")==0)||(strcmp(argv[i],"-TD")==0)){
    ordenado[5]=argv[i];
    contador_crescente_ou_all++;
    }
    }
  }
  contador1++;
}while(contador1<=5);
if((contador_L==1)&&(contador_numero==1)&&(contador_crescente_ou_all==1)){
return ordenado;
}
limpa_espaco();
exit(0);
}


/*A função é do tipo char**. Recebe os argumentos da linha de comando e um apontador de um apontador de caracteres.
Esta função é utilizada para o caso de os argumentos a serem introduzidos pelo utilizador estar na ordem errada.
Esta função é utilizada para o caso do número de argumentos ser 7.
Os ciclos irão correr os argumentos introduzidos e quando encontrarem o primeiro elemento que estaria na posicao seguinte na ordem correta
é introduzido na célula correspondente da string 'ordenado'. Só retorna o array caso encontre apenas um argumeno de cada,
evitando assim, possiveis repeticoes introduzidas na linha de comando.*/
char** ordena_7(int argc, char* argv[],char*ordenado[]){
int i=0,contador1=0;
int contador_L=0, contador_numero=0,contador_crescente_ou_all=0,contador_distancia_ou_all=0;
ordenado[0]=argv[0];
ordenado[1]=argv[1];
ordenado[2]=argv[2];
contador1=3;
do{
  for(i=1;i<=6;i++){
   if(contador1==3){
    if(strcmp(argv[i],"-L")==0){
    ordenado[3]=argv[i];
    contador_L++;

     }
    }
   if(contador1==4){
    if((strcmp(argv[i],"0")==0)||(strcmp(argv[i],"1")==0)||(strcmp(argv[i],"2")==0)){
    ordenado[4]=argv[i];
    contador_numero++;
    }
    }
    if(contador1==5){
    if((strcmp(argv[i],"-TC")==0)||(strcmp(argv[i],"-TD")==0)){
    ordenado[5]=argv[i];
    contador_crescente_ou_all++;
    }
    }
    if(contador1==6){
    if((strcmp(argv[i],"ALL")==0)||(strcmp(argv[i],"-D")==0)){
    ordenado[6]=argv[i];
    contador_distancia_ou_all++;
    }
    }
  }
  contador1++;
}while(contador1<=6);
if((contador_L==1)&&(contador_numero==1)&&(contador_crescente_ou_all==1)&&(contador_distancia_ou_all==1)){
return ordenado;
}
limpa_espaco();
exit(0);

}


/*A função é do tipo char**. Recebe os argumentos da linha de comando e um apontador de um apontador de caracteres.
Esta função é utilizada para o caso de os argumentos a serem introduzidos pelo utilizador estar na ordem errada.
Esta função é utilizada para o caso do número de argumentos ser 8.
Os ciclos irão correr os argumentos introduzidos e quando encontrarem o primeiro elemento que estaria na posicao seguinte na ordem correta
é introduzido na célula correspondente da string 'ordenado'. Só retorna o array caso encontre apenas um argumeno de cada,
evitando assim, possiveis repeticoes introduzidas na linha de comando.*/
char** ordena_8(int argc, char* argv[],char*ordenado[]){
int i=0,contador1=0;
int contador_L=0, contador_numero=0,contador_crescente_ou_all=0,contador_distancia=0,contador_all=0;
ordenado[0]=argv[0];
ordenado[1]=argv[1];
ordenado[2]=argv[2];
contador1=3;
do{
  for(i=1;i<=7;i++){
   if(contador1==3){
    if(strcmp(argv[i],"-L")==0){
    ordenado[3]=argv[i];
    contador_L++;

     }
    }
   if(contador1==4){
    if((strcmp(argv[i],"1")==0)||(strcmp(argv[i],"2")==0)){
    ordenado[4]=argv[i];
    contador_numero++;
    }
    }
    if(contador1==5){
    if((strcmp(argv[i],"-TC")==0)||(strcmp(argv[i],"-TD")==0)){
    ordenado[5]=argv[i];
    contador_crescente_ou_all++;
    }
    }
    if(contador1==6){
    if((strcmp(argv[i],"-D")==0)){
    ordenado[6]=argv[i];
    contador_distancia++;
    }
    }
    if(contador1==7){
    if(strcmp(argv[i],"ALL")==0){
    ordenado[7]=argv[i];
    contador_all++;
    }
    }
  }
  contador1++;
}while(contador1<=7);
if((contador_L==1)&&(contador_numero==1)&&(contador_crescente_ou_all==1)&&(contador_distancia==1)&&(contador_all==1)){
return ordenado;
}
limpa_espaco();
exit(0);

}

/*

void imprime_entre_horas(char *argv1, char *argv2, char *argv3){

  AEROPORTO *topo_aero = NULL;
  VOO *aux;
  COMPANHIA *topo_companhia = NULL, *x=NULL;
  topo_aero = inicializar_aeroporto();
  testa_aeroportos(topo_aero);
  topo_companhia = inicializar_companhia(topo_aero);
  testa_companhia(topo_companhia);
  teste(topo_aero, topo_companhia);
  int hora1, hora2;
  sscanf(argv2, "%d", &hora1);
  sscanf(argv3, "%d", &hora2);


  for(x=topo_companhia; x!=NULL; x=x->prox){
    aux=x->x;

        for(; aux!=NULL; aux=aux->prox){

      if(strcmp(aux->aeroporto_de_partida, argv1)==0){

        if((aux->partida.hora>=hora1)&&(aux->partida.hora<=hora2)){
          printf("%s %s %02d:%02d %s %s %02d:%02d %s\n", aux->codigo, aux->aeroporto_de_partida, aux->partida.hora,
                 aux->partida.minutos, aux->partida.parte_do_dia, aux->aeroporto_de_chegada,
                 aux->chegada.hora, aux->chegada.minutos, aux->chegada.parte_do_dia);
          printf("Distancia total:%f\nPreco:%.2f\n",aux->distancia,aux->preco);
        }
      }
    }
  }
}

*/




















