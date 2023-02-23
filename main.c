/*
Programação - Projeto Final

Alunos:
Beatriz Duarte - 95773
João Tiago Diz - 95810

O programa tem como objetivo facultar a informação de voos ao utilizador. Este terá que introduzir a origem e o destino da rota desejada, assim como
a sua preferência pelo número de escalas, a ordenação horária ou por distância.

Adicionalmente, foram acrescentados alguns comandos não pedidos pelo enunciado deste projeto final. Agora o utilizador poderá escolher se pretende 
uma rota que inclua 2 escalas. Por outro lado, também é possível escolher se todos os voos possíveis aparecem no ecrâ ou apenas um.
Todos os voos têm um preço. E, para finalizar, o utilizador poderá inserir os comandos de forma aleatória. Importante salientar apenas que as cidades
devem estar pela ordem: partida chegada. :))

Este jogo foi desenvolvido segundo a norma ansi.
*/

/*
Ficheiro main.c
Este ficheiro é aquele em que todas as operações são efetuadas no decorrer do jogo. Agrupa todas as funções presentes no ficheiro func.c.
Este está organizado em função do número de arhumentos da linha de comando.
*/


#include <stdio.h>
#include <stdlib.h>
#include "headers.h"

  int main(int argc, char *argv[])
  {
    char *ordenado[MAX],**ordena=NULL;
    

    /*printf("\n\nSTOR\n\n");
printf("aux-> %s", argv[1]);
    fflush(stdout);
    imprime_entre_horas(argv[1], argv[2], argv[3]);

    */
    if(argc==5){
    ordena = ordena_5(argc,argv,ordenado);
    testa_input(ordenado[1],ordenado[2]);
    }
    if(argc==6){
      ordena = ordena_6(argc,argv,ordenado);
      testa_input(ordenado[1],ordenado[2]);
    }
    if(argc==7){
      ordena = ordena_7(argc,argv,ordenado);
      testa_input(ordenado[1],ordenado[2]);
    }
    if(argc==8){
      ordena = ordena_8(argc,argv,ordenado);
      testa_input(ordenado[1],ordenado[2]);
    }
    if (argc < 2)
    {
      limpa_espaco();
      exit(0);
    }
    else if ((argc == 2)&&(strcmp(argv[1], "-aeroportos") == 0))
    {
      funcao_1();
    }
    else if ((argc == 2)&&(strcmp(argv[1], "-voos") == 0))
    {
      funcao_2();
    }
    else if (argc == 5)
      arg_5(ordena, argc);
    else if (argc == 6)
      arg_6(ordena, argc);
    else if (argc == 7)
      arg_7(ordena, argc);
    else if (argc == 8)
      arg_8(ordena, argc);
    else
      limpa_espaco();

    return 0;
  }
