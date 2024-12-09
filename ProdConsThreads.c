#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include </usr/include/semaphore.h>    
#define BUFF_SIZE 10

char buffer[BUFF_SIZE];
int producerIndex = 0, consumerIndex = 0, Times;
sem_t EmptyPostions, FullPositions, BufferLock;

void Insert(char item) {
    printf("Producing %c ...\n", item);
    sem_wait(&EmptyPostions);
    sem_wait(&BufferLock);
    buffer[producerIndex] = item;
    producerIndex = (producerIndex + 1) % BUFF_SIZE;
    sem_post(&BufferLock);
    sem_post(&FullPositions);
}

void *Prod() {
    for (int i = 0; i < Times; i++) Insert((char)('A' + i % 26));
    pthread_exit(NULL);
}

void Delete() {
    sem_wait(&FullPositions);
    sem_wait(&BufferLock);
    char item = buffer[consumerIndex];
    consumerIndex = (consumerIndex + 1) % BUFF_SIZE;
    sem_post(&BufferLock);
    sem_post(&EmptyPostions);
    printf("consuming letter %c ...\n", item);
}

void *Consume() {
    for (int i = 0; i < Times; i++) Delete();
    pthread_exit(NULL);
}

int main(int argc, char **argv) {
    if (argc != 2 || (Times = atoi(argv[1])) <= 0) {
        printf("Usage: %s <positive_number_of_times>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    pthread_t idP, idC;
    sem_init(&EmptyPostions, 0, BUFF_SIZE);
    sem_init(&FullPositions, 0, 0);
    sem_init(&BufferLock, 0, 1);

    pthread_create(&idP, NULL, Prod, NULL);
    pthread_create(&idC, NULL, Consume, NULL);
    pthread_join(idP, NULL);
    pthread_join(idC, NULL);

    sem_destroy(&FullPositions);
    sem_destroy(&EmptyPostions);
    sem_destroy(&BufferLock);

    printf("exiting program\n");
    return 0;
}
