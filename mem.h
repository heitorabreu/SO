/*
Primeiro entregável - Sistemas Operacionais
Grupo:Heitor Xavier de Abreu
      João Lucas Lima
      Vitor Emanuel Rozeno
*/

#ifndef __MEM
#define __MEM

extern const int qtBlocos;

// Estrutura para representar a memória RAM
typedef struct ram
{
  int blocosDisp; // Quantos blocos de memória estão disponíveis
  int blocosOcu;  // Quantos blocos de memória estão ocupados
} RAM;

// Alocar uma quantidade de blocos (do segmento) do programa.

int memAloc(RAM *mem, int qBlocos);

// Função para liberar memória do segmento do programa.

void memDesaloc(RAM *mem, int qBlocos);

// Função para exibir a ocupação da memória RAM.
void memSatus(RAM *mem);

#endif
