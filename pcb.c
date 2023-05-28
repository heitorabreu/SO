#include "pcb.h"
#include <stdlib.h>

void initList(PCB_list* list){
    list->first = NULL;
    list->last = NULL;
}

Process* createProcess(int pid, int priority, int remainingTime, int totalTime){
    Process* newProcess = (Process*)malloc(sizeof(Process));
    newProcess->pid = pid;
    newProcess->priority = priority;
    newProcess->remainingTime = remainingTime;
    newProcess->totalTime = totalTime;
    newProcess->next = NULL;

    return newProcess;
}

// Insere um novo PCB na posição correta da lista (ordenado pelo remainingTime)
void insert(PCB_list* list, Process *newProcess){

    Process* current = list->first;
    Process* prev = NULL;

    // Encontra a posição correta para inserir o novo Process (ordenado pelo remainingTime)
    while (current != NULL && current->remainingTime < newProcess->remainingTime) {
        prev = current;
        current = current->next;
    }

    if (prev == NULL) {
        // Insere o novo Process no início da lista
        newProcess->next = list->first;
        list->first = newProcess;
    } else {
        // Insere o novo Process no meio ou no final da lista
        prev->next = newProcess;
        newProcess->next = current;
        if (current == NULL) {
            // Atualiza o último elemento da lista
            list->last = newProcess;
        }
    }
}

// Percorre e exibe os PCBs da lista
void displayList(PCB_list* list){
    Process* current = list->first;
    while (current != NULL) {
        printf("PID: %d, State: %d, Priority: %d, Remaining Time: %d, Total Time: %d\n",
               current->pid, current->state, current->priority, current->remainingTime, current->totalTime);
        current = current->next;
    }
}

Process* remover(PCB_list* list){
    Process* aux = list->first;
    list->first = list->first->next;
    aux->next = NULL;
    return aux;
}

Process *selectNextProcess(PCB_list* list) {
    Process *current = list->first;
    Process *shortest = current;

    while (current != NULL) {
        if (current->remainingTime < shortest->remainingTime) {
            shortest = current;
        }
        current = current->next;
    }

    return shortest;
}

void SRTF(PCB_list *list){
    Process *current = NULL;
    int time = 0;

    while(list->first != NULL){
        current = selectNextProcess(list);
        current->state = 1;
        remover(list);

        printf("Tempo: %d, Processo em execução: PID %d\n", time, current->pid);

        while (current->remainingTime > 0) {
            current->remainingTime--;
            time++;
        }

        current->state = 0; // Marca o processo como concluído
        free(current);

    }
}

