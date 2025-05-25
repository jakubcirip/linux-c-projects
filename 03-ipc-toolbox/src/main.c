#include <stdio.h>
#include <string.h>
#include "ipc_toolbox.h"

int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("Usage:\n");
        printf("  %s fifo listen\n", argv[0]);
        printf("  %s fifo send \"message\"\n", argv[0]);
        return 1;
    }

    if (strcmp(argv[1], "fifo") == 0) {
        if (strcmp(argv[2], "listen") == 0) {
            fifo_listen();
        } else if (strcmp(argv[2], "send") == 0 && argc == 4) {
            fifo_send(argv[3]);
        } else {
            fprintf(stderr, "Invalid FIFO usage\n");
        }
    }

    return 0;
}

