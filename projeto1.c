#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include "pcb.c"

// Defina as estruturas de dados necessárias

// Defina as variáveis globais necessárias, como semáforos e mutexes

// Implemente as funções necessárias, como processInterrupt, semaphoreP, semaphoreV, memLoadReq, memLoadFinish, processCreate, processFinish, etc.

void processInterrupt(PCB *process, PCB_list* list){
    PCB* aux;
    aux = remove(list);
    insert(PCB_list*, process);
}

// Função para execução da thread do núcleo do SO
void* coreThread(void* arg) {
    // Implemente a lógica do núcleo do SO aqui

    return NULL;
}

int main() {
    // Inicialize as estruturas de dados e variáveis globais

    // Crie a thread do núcleo do SO
    pthread_t core_tid;
    //pthread_create(&core_tid, NULL, coreThread, NULL);

    // Implemente a lógica da interface de controle aqui

    // Aguarde a finalização da thread do núcleo do SO
    //pthread_join(core_tid, NULL);

    return 0;
}