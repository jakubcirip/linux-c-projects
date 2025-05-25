# Some notes for threads.c program

- pthread_create - spawns new threads
- pthread_join - waits for threads to finish
- sleep - simulates delay - I/O sensor
- rand() - simulated sensor data

## void* function(void* arg);
- It allows to pass any type of data to the thread function. It must look like this.
- void* is a generic pointer type in C - it can point to any data type (e.g., int, struct*, etc.).
- Inside the thread function we can cast it back to the real type:

```c
void* new_thread(void* arg) {
    int* int_arg = (int*) arg;
    printf("Received: %d\n", *int_arg);
    return NULL;
}

int x = 42;
pthread_create(&tid, NULL, new_thread, &x);
```

## pthread_t
pthread_t is the type used to indetify a thread in POSIX systems.

It is an **opaque data type** - meaning we don't care what is inside. We just use it to reference a thread.

## Internally:
- It may be implemented as an integer, a stuct, or even a pointer.
- We can't assume it's an unsigned char or int.
- We only used it with pthread function like pthread_create, pthread_join, etc.

Example:
```c
pthread_t thread_id;
pthread_create(&thread_id, NULL, my_function, NULL);
pthread_join(thread_id, NULL);
```
- Create a thread and store its ID in thread_id so we can wait on it later.