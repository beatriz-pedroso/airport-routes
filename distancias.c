#include "headers.h"

/*FICHEIRO: distancias.c
  OBJETIVO: Este ficheiro agrupa as funcoes responsaveis pelo calcula das distancias percorridas pelos voos.*/


/*Funcao que calcula a distancia percorrida num voo(Recebe o topo da companhia e o topo dos aeroportos). Esta funcao vai percorrer cada companhia e dentro de cada companhia vai percorrer cada voo. Por cada voo que percorrer vai percorrer todos os aeroportos e vai encontrar as coordenadas correspondentes ao aeroporto de saida e ao de chegada. Aloca memoria do tipo estruturado COORDENADAS* para poder guardar la as coordenadas de partida e de chegada. Envia para a funcao calcula_distanca as coordenadas esta retorna a distancia (sendo esta inserida num campo de dados do voo) e depois o ciclo continua*/
COMPANHIA *distancia_voo(COMPANHIA *topo, AEROPORTO *topo_aero)
{
  VOO *aux;
  AEROPORTO *inic;
  COMPANHIA *topo_topo;
  float distancia;
  COORDENADAS *partida, *chegada;
  topo_topo = topo;

  for (; topo != NULL; topo = topo->prox)
  {
    for (aux = topo->x; aux != NULL; aux = aux->prox)
    {
      partida = chegada = NULL;
      for (inic = topo_aero; inic != NULL; inic = inic->prox)
      {
        if (strcmp(aux->aeroporto_de_partida, inic->cidade) == 0)
        {
          partida = aloca_memoria_coord(partida);
          partida->latitude[0] = inic->posicao.latitude[0];
          partida->latitude[1] = inic->posicao.latitude[1];
          partida->latitude[2] = inic->posicao.latitude[2];
          partida->sentido_latitude = inic->posicao.sentido_latitude;
          partida->longitude[0] = inic->posicao.longitude[0];
          partida->longitude[1] = inic->posicao.longitude[1];
          partida->longitude[2] = inic->posicao.longitude[2];
          partida->sentido_longitude = inic->posicao.sentido_longitude;
        }
        if (strcmp(aux->aeroporto_de_chegada, inic->cidade) == 0)
        {
          chegada = aloca_memoria_coord(chegada);
          chegada->latitude[0] = inic->posicao.latitude[0];
          chegada->latitude[1] = inic->posicao.latitude[1];
          chegada->latitude[2] = inic->posicao.latitude[2];
          chegada->sentido_latitude = inic->posicao.sentido_latitude;
          chegada->longitude[0] = inic->posicao.longitude[0];
          chegada->longitude[1] = inic->posicao.longitude[1];
          chegada->longitude[2] = inic->posicao.longitude[2];
          chegada->sentido_longitude = inic->posicao.sentido_longitude;
        }
      }

      if ((partida == NULL) || (chegada == NULL))/*Prevencao de erros da funcao inic_lista_companhia (caso nao exista aeroporto de partida ou chegada a funcao nao coloca nada no campo da distancia*/
      {
        printf("Aviso: Aeroporto de partida ou de chegada inexistente \n");
      }
      else if ((partida != NULL) && (chegada != NULL))
      {
        distancia = calcula_distancia(*partida, *chegada);
        aux->preco = 0.40 * distancia;/*Calculo do preco do voo tendo por base um preco de 40 centimos por quilometro :).*/
        aux->distancia = distancia;
      }
    }
  }

  return topo_topo;/*Retorno do topo das companhias*/
}
/*Funcao que recebe as coordenadas e retorna um valor em quilometros correspondente a distancia. Esta funcao vai comparar os sentidos das latitudes e longitudes para poder obter o seu sinal. De seguida, calcula a latitude e longitude em graus (convertendo minutos e segundos em graus. Converte os dados para radianos e utiliza as funcoes fornecidas no enunciado para calcular as coordenadas num referencial em R3. Depois, atraves do produto interno calcula-se o angulo entre os vetores formados pelas coordenadas de partida e de chegada e o centro da terra e retorna-se a distancia (que e igual ao raio * o angulo)*/
float calcula_distancia(COORDENADAS partida, COORDENADAS chegada)
{
  VETOR aero_partida, aero_chegada;
  float latitude_aux, longitude_aux, norma_partida, norma_chegada, produto_interno, angulo, sinal_lon, sinal_lat;
  if (partida.sentido_latitude == 'N')
  {
    sinal_lat = 1;
  }
  if (partida.sentido_latitude == 'S')
  {
    sinal_lat = -1;
  }
  if (partida.sentido_longitude == 'E')
  {
    sinal_lon = 1;
  }
  if (partida.sentido_longitude == 'W')
  {
    sinal_lon = -1;
  }
  latitude_aux = (partida.latitude[0] + (partida.latitude[1]) / 60.0 + (partida.latitude[2]) / 3600.0) * sinal_lat;
  longitude_aux = (partida.longitude[0] + (partida.longitude[1]) / 60.0 + (partida.longitude[2]) / 3600.0) * sinal_lon;

  latitude_aux = latitude_aux * PI / 180;
  longitude_aux = longitude_aux * PI / 180;

  aero_partida.x = R * cos(latitude_aux) * cos(longitude_aux);
  aero_partida.y = R * cos(latitude_aux) * sin(longitude_aux);
  aero_partida.z = R * sin(latitude_aux);

  if (chegada.sentido_latitude == 'N')
  {
    sinal_lat = 1;
  }
  if (chegada.sentido_latitude == 'S')
  {
    sinal_lat = -1;
  }
  if (chegada.sentido_longitude == 'E')
  {
    sinal_lon = 1;
  }
  if (chegada.sentido_longitude == 'W')
  {
    sinal_lon = -1;
  }

  latitude_aux = (chegada.latitude[0] + (chegada.latitude[1]) / 60.0 + (chegada.latitude[2]) / 3600.0) * sinal_lat;
  longitude_aux = (chegada.longitude[0] + (chegada.longitude[1]) / 60.0 + (chegada.longitude[2]) / 3600.0) * sinal_lon;
  latitude_aux = latitude_aux * PI / 180;
  longitude_aux = longitude_aux * PI / 180;
  aero_chegada.x = R * cos(latitude_aux) * cos(longitude_aux);
  aero_chegada.y = R * cos(latitude_aux) * sin(longitude_aux);
  aero_chegada.z = R * sin(latitude_aux);
  norma_partida = sqrt((pow(aero_partida.x, 2.0)) + pow(aero_partida.y, 2.0) + pow(aero_partida.z, 2.0));
  norma_chegada = sqrt((pow(aero_chegada.x, 2.0)) + pow(aero_chegada.y, 2.0) + pow(aero_chegada.z, 2.0));
  produto_interno = ((aero_chegada.x * aero_partida.x) + (aero_chegada.y * aero_partida.y) + (aero_partida.z * aero_chegada.z));
  angulo = acos(produto_interno / (norma_partida * norma_chegada));
  return (angulo * R);
}
