#include "headers.h"

/*FICHEIRO: func_main.c
  OBJETIVO: Este ficheiro possui uma serie de if's cujo objetivo é testar as strings provenientes da linha de comandos e
  se preciso ordena las*/

/*Funcao para o caso do utilizador escrever 5 argumentos. Se estiverem corretos efetua devida funcao.*/
  void arg_5(char** ordena, int argc){
    if (((argc == 5) && strcmp(ordena[3], "-L") == 0) && (strcmp(ordena[4], "0") == 0))
    {
      funcao_3(ordena);
    }
    else if ((argc == 5) && (strcmp(ordena[3], "-L") == 0) && (strcmp(ordena[4], "1") == 0))
    {
      funcao_5(ordena[1], ordena[2]);
    }
    else if ((argc == 5) && (strcmp(ordena[3], "-L") == 0) && (strcmp(ordena[4], "2") == 0))
	{
      funcao_8_sem_restricoes(ordena[1], ordena[2]);
    }
  }
/*Funcao para o caso do utilizador escrever 6 argumentos. Se estiverem corretos efetua devida funcao.*/
  void arg_6(char** ordena, int argc){

  AEROPORTO *topo_aero = NULL;
  COMPANHIA *topo_companhia = NULL;
  if (((argc == 6) && strcmp(ordena[3], "-L") == 0) && (strcmp(ordena[4], "0") == 0) && (strcmp(ordena[5], "ALL") == 0))
  {
    funcao_3_ALL(ordena);
  }
  else if ((argc == 6) && (strcmp(ordena[3], "-L") == 0) && (strcmp(ordena[4], "0") == 0) && ((strcmp(ordena[5], "-TC") == 0) || (strcmp(ordena[5], "-TD") == 0)))
  {
    topo_aero = inicializar_aeroporto();
    topo_companhia = inicializar_companhia(topo_aero);
    teste(topo_aero, topo_companhia);
    if (strcmp(ordena[5], "-TC")==0)
    {
      printf("Rotas entre diretas(ordem crescente de hora de partida):%s e %s \n", ordena[1], ordena[2]);
    }
    else
    {
        printf("Rotas entre diretas(ordem decrescente de hora de partida):%s e %s \n", ordena[1], ordena[2]);
    }
        funcao_4(ordena, topo_companhia);
    }
    else if ((argc == 6) && (strcmp(ordena[3], "-L") == 0) && (strcmp(ordena[4], "1") == 0) && (strcmp(ordena[5], "-TC") == 0))
    {
        funcao_6_crescente(ordena[1], ordena[2]);
    }
    else if ((argc == 6) && (strcmp(ordena[3], "-L") == 0) && (strcmp(ordena[4], "1") == 0) && (strcmp(ordena[5], "-TD") == 0))
    {
        funcao_6_decrescente(ordena[1], ordena[2]);
    }
    else if ((argc == 6) && (strcmp(ordena[3], "-L") == 0) && (strcmp(ordena[4], "1") == 0) && (strcmp(ordena[5], "ALL") == 0))
    {
        funcao_5_ALL(ordena[1], ordena[2]);
    }
    else if ((argc == 6) && (strcmp(ordena[3], "-L") == 0) && (strcmp(ordena[4], "2") == 0) && (strcmp(ordena[5], "-TC") == 0))
    {
        funcao_8_crescente(ordena[1], ordena[2]);
    }
    else if ((argc == 6) && (strcmp(ordena[3], "-L") == 0) && (strcmp(ordena[4], "2") == 0) && (strcmp(ordena[5], "-TD") == 0))
    {
        funcao_8_decrescente(ordena[1], ordena[2]);
    }
    else if ((argc == 6) && (strcmp(ordena[3], "-L") == 0) && (strcmp(ordena[4], "2") == 0) && (strcmp(ordena[5], "ALL") == 0))
    {
        funcao_8_sem_restricoes_ALL(ordena[1], ordena[2]);
    }
  }


/*Funcao para o caso do utilizador escrever 7 argumentos. Se estiverem corretos efetua devida funcao.*/
  void arg_7(char** ordena, int argc){

  AEROPORTO *topo_aero = NULL;
  COMPANHIA *topo_companhia = NULL;
  if ((argc == 7) && (strcmp(ordena[3], "-L") == 0) && (strcmp(ordena[4], "1") == 0) && (strcmp(ordena[5], "-TC") == 0) && (strcmp(ordena[6], "-D") == 0))
  {
    funcao_7_crescente(ordena[1], ordena[2]);
  }
  else if ((argc == 7) && (strcmp(ordena[3], "-L") == 0) && (strcmp(ordena[4], "1") == 0) && (strcmp(ordena[5], "-TD") == 0) && (strcmp(ordena[6], "-D") == 0))
  {
    funcao_7_decrescente(ordena[1], ordena[2]);
  }
  else if ((argc == 7) && (strcmp(ordena[3], "-L") == 0) && (strcmp(ordena[4], "1") == 0) && (strcmp(ordena[5], "-TC") == 0) && (strcmp(ordena[6], "ALL") == 0))
  {
    funcao_6_crescente_ALL(ordena[1], ordena[2]);
  }
  else if ((argc == 7) && (strcmp(ordena[3], "-L") == 0) && (strcmp(ordena[4], "1") == 0) && (strcmp(ordena[5], "-TD") == 0) && (strcmp(ordena[6], "ALL") == 0))
  {
    funcao_6_decrescente_ALL(ordena[1], ordena[2]);
  }
  else if ((argc == 7) && (strcmp(ordena[3], "-L") == 0) && (strcmp(ordena[4], "2") == 0) && (strcmp(ordena[5], "-TC") == 0) && (strcmp(ordena[6], "-D") == 0))
  {
    funcao_8_crescente_distancia(ordena[1], ordena[2]);
  }
  else if ((argc == 7) && (strcmp(ordena[3], "-L") == 0) && (strcmp(ordena[4], "2") == 0) && (strcmp(ordena[5], "-TD") == 0) && (strcmp(ordena[6], "-D") == 0))
  {
    funcao_8_decrescente_distancia(ordena[1], ordena[2]);
  }
  else if ((argc == 7) && (strcmp(ordena[3], "-L") == 0) && (strcmp(ordena[4], "2") == 0) && (strcmp(ordena[5], "-TC") == 0) && (strcmp(ordena[6], "ALL") == 0))
  {
    funcao_8_crescente_ALL(ordena[1], ordena[2]);
  }
  else if ((argc == 7) && (strcmp(ordena[3], "-L") == 0) && (strcmp(ordena[4], "2") == 0) && (strcmp(ordena[5], "-TD") == 0) && (strcmp(ordena[6], "ALL") == 0))
  {
    funcao_8_decrescente_ALL(ordena[1], ordena[2]);
  }
  else if ((argc == 7) && (strcmp(ordena[3], "-L") == 0) && (strcmp(ordena[4], "0") == 0) && ((strcmp(ordena[5], "-TC") == 0) || (strcmp(ordena[5], "-TD") == 0)) && (strcmp(ordena[6], "ALL") == 0))
  {
    topo_aero = inicializar_aeroporto();
    topo_companhia = inicializar_companhia(topo_aero);
    teste(topo_aero, topo_companhia);
    if (strcmp(ordena[5], "-TC")==0)
    {
      printf("Rotas entre diretas(ordem crescente de hora de partida):%s e %s \n", ordena[1], ordena[2]);
    }
    else
    {
      printf("Rotas entre diretas(ordem decrescente de hora de partida):%s e %s \n", ordena[1], ordena[2]);
    }
      funcao_4_ALL(ordena, topo_companhia);
    }
  }

/*Funcao para o caso do utilizador escrever 8 argumentos. Se estiverem corretos efetua devida funcao.*/
  void arg_8(char** ordena, int argc){

	  if ((argc == 8) && (strcmp(ordena[3], "-L") == 0) && (strcmp(ordena[4], "1") == 0) && (strcmp(ordena[5], "-TC") == 0) && (strcmp(ordena[6], "-D") == 0) && (strcmp(ordena[7], "ALL") == 0))
	  {
	    funcao_7_crescente_ALL(ordena[1], ordena[2]);
	  }
	  else if ((argc == 8) && (strcmp(ordena[3], "-L") == 0) && (strcmp(ordena[4], "1") == 0) && (strcmp(ordena[5], "-TD") == 0) && (strcmp(ordena[6], "-D") == 0) && (strcmp(ordena[7], "ALL") == 0))
	  {
	    funcao_7_decrescente_ALL(ordena[1], ordena[2]);
	  }
	  else if ((argc == 8) && (strcmp(ordena[3], "-L") == 0) && (strcmp(ordena[4], "2") == 0) && (strcmp(ordena[5], "-TC") == 0) && (strcmp(ordena[6], "-D") == 0) && (strcmp(ordena[7], "ALL") == 0))
	  {
	    funcao_8_crescente_distancia_ALL(ordena[1], ordena[2]);
	  }
	  else if ((argc == 8) && (strcmp(ordena[3], "-L") == 0) && (strcmp(ordena[4], "2") == 0) && (strcmp(ordena[5], "-TD") == 0) && (strcmp(ordena[6], "-D") == 0) && (strcmp(ordena[7], "ALL") == 0))
	  {
	    funcao_8_decrescente_distancia_ALL(ordena[1], ordena[2]);
	  }
  }







