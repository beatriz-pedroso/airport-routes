#ifndef HEADERS_H_INCLUDED
#define HEADERS_H_INCLUDED

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <ctype.h>

#define DIM 1000
#define COORD 3
#define tempo 3
#define R 6381
#define PI 3.14159265359
#define MAX 100

/*FICHEIRO: headers.h
  OBJETIVO: header que serve de apoio aos ficheiros.c*/


/*Estrutura de nome HORA. Esta contém as informações úteis relativas às horas de cada voo de partida ou chegada.*/
typedef struct
{
    int hora;
    int minutos;
    char parte_do_dia[tempo];
} HORA;

/*Estrutura de nome voo. Esta contém as informações úteis relativas aos voos, contendo, assim tudo o que os caracteriza.
Inclui o tipo estruturado HORA*/
typedef struct voo
{
    char codigo[DIM];
    char aeroporto_de_partida[DIM];
    char aeroporto_de_chegada[DIM];
    HORA partida, chegada;
    float distancia;
    float preco;
    struct voo *prox;
} VOO;

/*Estrutura de nome COORDENADAS. Esta contém as informações úteis relativas às coordenadas de cada aeroporto.*/
typedef struct
{
    int latitude[COORD];
    char sentido_latitude;
    int longitude[COORD];
    char sentido_longitude;
} COORDENADAS;


/*Estrutura de nome AEROPORTO. Esta contém as informações úteis relativos aos aeroportos. Inclui o tipo estruturado COORDENADAS e o
apontador que permite ler percorrer a lista*/
typedef struct aero
{

    char ident_ICAO[DIM];
    char ident_IATA[DIM];
    COORDENADAS posicao;
    char cidade[DIM];
    int timezone;
    struct aero *prox;
} AEROPORTO;

/*Estrutura de nome COMPANHIA. É definida com o seu nome e inclui uma lista a ela ligada do tipo estruturado VOO. 
Contém ainda um pontador que permite percorrer a lista*/
typedef struct companhia
{
    VOO *x;
    char nome[DIM];
    struct companhia *prox;
} COMPANHIA;

/*Estrutura de nome VOO_LIG. Esta contém as informacoes uteis relativas aos voos com apenas uma escala. Inclui duas listas que estao ligadas a si,
do tipo VOO.*/
typedef struct voo_lig
{
    VOO *x, *ligacao;
    struct voo_lig *prox;
    float distancia_total;
    float preco_total;
} VOO_LIG;

/*Estrutura de nome VOO_LIG2. Esta contém as informacoes uteis relativas aos voos com duas escalas. Inclui tres listas que estao ligadas a si,
do tipo VOO.*/
typedef struct voo_lig2
{
    VOO *x, *ligacao1, *ligacao2;
    struct voo_lig2 *prox;
    float distancia_total;
    float preco_total;
} VOO_LIG2;

/*Tipo estruturado de nome VETOR que contém informaçoes sobre as coordenadas dos aerportos tendo em conta o referencial Oxyz.*/
typedef struct
{
    float x, y, z;
} VETOR;

AEROPORTO *inic_lista_aero(FILE *fp);
AEROPORTO *aloca_memoria(AEROPORTO *);
FILE *abre_fich(FILE *fp, char x[]);
void mostra(AEROPORTO *);
COMPANHIA *inic_lista_companhia(FILE *fp, AEROPORTO *topo_aero);
int testa_coordenadas(AEROPORTO *aero);
int testa_capitais(AEROPORTO *topo, VOO *voo_testar);
COMPANHIA *distancia_voo(COMPANHIA *topo, AEROPORTO *topo_aero);
COMPANHIA *aloca_memoria_comp(COMPANHIA *novo);
VOO *aloca_memoria_voo(VOO *novo);
void mostra_voo(COMPANHIA *x);
void mostra_voovoo(VOO *x);
VOO *cria_pilha_partida(char partida[], COMPANHIA *topo);
VOO_LIG *cria_pilha_conjunta(VOO *x, char chegada[], COMPANHIA *topo_comp);
VOO_LIG *aloca_memoria_voo_lig(VOO_LIG *novo);
void mostra_voo_lig(VOO_LIG *topo);
VOO_LIG *testa_horario(VOO_LIG *hurray);
float calcula_distancia(COORDENADAS partida, COORDENADAS chegada);
COORDENADAS *aloca_memoria_coord(COORDENADAS *novo);
VOO_LIG *ordena_por_distancia(VOO_LIG *topo);
void mostra_rota_direta(COMPANHIA *topo, char *argv[]);
int mostra1_rota_direta(COMPANHIA *topo, char *argv[]);
VOO *insere_voos_diretos(COMPANHIA *x, char *argv[]);
void mostra_lista_rota_direta_tc_td(VOO *topo);
void mostra_1lista_rota_direta_tc_td(VOO *topo);
void conteudo_memoria_alocada(VOO *aux, VOO *ap);
VOO *insere_ordenado_tc_td(VOO *atual, VOO *anterior, VOO *ap, VOO *inicio, char *argv[]);
VOO_LIG *ordena_por_tempo_decrescente(VOO_LIG *topo_velho);
VOO_LIG *ordena_por_tempo_crescente(VOO_LIG *topo_velho);
void limpa_espaco();
int testa_horas(VOO *novo_voo);
AEROPORTO *inicializar_aeroporto();
COMPANHIA *inicializar_companhia(AEROPORTO *topo_aero);
void teste(AEROPORTO *X, COMPANHIA *Y);
void teste_rota_lig(VOO_LIG *x);
void funcao_1();
void funcao_2();
void funcao_3_ALL(char *argv[]);
void funcao_3(char *argv[]);
void funcao_4_ALL(char *argv[], COMPANHIA *topo_companhia);
void funcao_4(char *argv[], COMPANHIA *topo_companhia);
void funcao_5(char *argv1, char *argv2);
void funcao_6_crescente(char *argv1, char *argv2);
void funcao_6_decrescente(char *argv1, char *argv2);
void funcao_7_crescente(char *argv1, char *argv2);
void funcao_7_decrescente(char *argv1, char *argv2);
void funcao_5_ALL(char *argv1, char *argv2);
void funcao_6_crescente_ALL(char *argv1, char *argv2);
void funcao_6_decrescente_ALL(char *argv1, char *argv2);
void funcao_7_crescente_ALL(char *argv1, char *argv2);
void funcao_7_decrescente_ALL(char *argv1, char *argv2);
VOO_LIG* pilha_lig1(VOO* x, char chegada[], COMPANHIA* topo_comp);
VOO_LIG2* pilha_lig2(VOO_LIG* x, char chegada[], COMPANHIA* topo_comp);
VOO_LIG2 *aloca_memoria_voo_lig2(VOO_LIG2 *novo);
void mostra_voo_lig2(VOO_LIG2 *topo);
void teste_rota_lig2(VOO_LIG2 *x);
VOO_LIG2 *testa_horario2(VOO_LIG2 *lig3);
VOO_LIG2 *ordena_por_tempo_crescente2(VOO_LIG2 *topo_velho);
VOO_LIG2 *ordena_por_tempo_decrescente2(VOO_LIG2 *topo_velho);
VOO_LIG2 *ordena_por_distancia2(VOO_LIG2 *topo);
void funcao_8_sem_restricoes_ALL(char *argv1, char *argv2);
void funcao_8_crescente_ALL(char *argv1, char *argv2);
void funcao_8_decrescente_ALL(char *argv1, char *argv2);
void funcao_8_crescente_distancia_ALL(char *argv1, char *argv2);
void funcao_8_decrescente_distancia_ALL(char *argv1, char *argv2);
void funcao_8_sem_restricoes(char *argv1, char *argv2);
void funcao_8_crescente(char *argv1, char *argv2);
void funcao_8_decrescente(char *argv1, char *argv2);
void funcao_8_crescente_distancia(char *argv1, char *argv2);
void funcao_8_decrescente_distancia(char *argv1, char *argv2);
void liberta_memoria_aeroporto(AEROPORTO* x);
void liberta_memoria_companhia(COMPANHIA* x);
void liberta_memoria_voo(VOO* x);
void liberta_memoria_voolig(VOO_LIG* x);
void liberta_memoria_voolig2(VOO_LIG2* x);
int compara_horario(VOO_LIG* atual, VOO_LIG* prox);
int compara_horario2(VOO_LIG2* atual, VOO_LIG2* prox);
void imprime_erros(int a, int b, int c, int d, int e);
int testa_timezone(AEROPORTO *novo);
int testa_identificacao(VOO* novo);
void imprime_erros_aero(int a, int b, int c);
float testa_duracao(AEROPORTO *topo, VOO *voo_testar);
int testa_nomes(VOO* ola);
COMPANHIA* apaga_companhias_sem_voos(COMPANHIA* topo);
char** ordena_5(int argc, char* argv[],char* ordenado[]);
char** ordena_6(int argc, char* argv[],char*ordenado[]);
char** ordena_7(int argc, char* argv[],char*ordenado[]);
char** ordena_8(int argc, char* argv[],char*ordenado[]);
void testa_input(char *primeiro, char *segundo);
AEROPORTO* testa_aeroportos(AEROPORTO *topo_aero);
COMPANHIA* testa_companhia(COMPANHIA *topo_companhia);
void arg_5(char** ordena, int argc);
void arg_6(char** ordena, int argc);
void arg_7(char** ordena, int argc);
void arg_8(char** ordena, int argc);
/*void imprime_entre_horas(char *argv1, char *argv2, char *argv3);*/


#endif
