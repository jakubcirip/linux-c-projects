#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <sys/stat.h>
#include <errno.h>

#define FIFO_PATH "/tmp/my_fifo"

void fifo_listen(void) {
    char buf[128];

    // Create the FIFO if it doesn't exist
    if (mkfifo(FIFO_PATH, 0666) == -1 && errno != EEXIST) {
        perror("mkfifo");
        exit(EXIT_FAILURE);
    }

    printf("[FIFO] Waiting for message...\n");

    int fd = open(FIFO_PATH, O_RDONLY);
    if (fd < 0) {
        perror("open");
        exit(EXIT_FAILURE);
    }

    ssize_t n = read(fd, buf, sizeof(buf));
    if (n > 0) {
        printf("[FIFO] Received: %s\n", buf);
    } else {
        perror("read");
    }

    close(fd);
    unlink(FIFO_PATH);  // cleanup
}

void fifo_send(const char *message) {
    int fd = open(FIFO_PATH, O_WRONLY);
    if (fd < 0) {
        perror("open");
        exit(EXIT_FAILURE);
    }

    if (write(fd, message, strlen(message) + 1) == -1) {
        perror("write");
    } else {
        printf("[FIFO] Sent: %s\n", message);
    }

    close(fd);
}

