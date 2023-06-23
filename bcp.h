/*
Primeiro entregável - Sistemas Operacionais
Grupo:Heitor Xavier de Abreu
      João Lucas Lima
      Vitor Emanuel Rozeno
*/

#ifndef __BCP
#define __BCP

typedef struct processo Processo;
typedef struct ram RAM;

typedef struct bcp
{
  Processo *dados;
  struct bcp *proximo;
} BCP;

void insereOrdenado(Processo *, BCP **);

void printLista(BCP *, RAM *);

Processo *primProc(BCP *);

#endif