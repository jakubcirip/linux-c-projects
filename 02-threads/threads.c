// threads basic 

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

void* sensor_thread(void* arg) {
    for (int i=0; i<5; i++) {
        int sensor_data = rand() % 100;
        printf("[Sensor] Reading: %d\n", sensor_data);
        sleep(1);
    }
    return NULL;
}

void* logger_thread(void* arg) {
    for (int i=0; i<5; i++) {
        printf("[Logger] Logging data...\n");
        sleep(1);
    }
    return NULL;
}

int main() {
    pthread_t thread1, thread2;

    // Create 2 threads
    pthread_create(&thread1, NULL, sensor_thread, NULL);
    pthread_create(&thread2, NULL, logger_thread, NULL);

    // Wait for both to finish
    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    printf("Main thread done.\n");
    return 0;
}