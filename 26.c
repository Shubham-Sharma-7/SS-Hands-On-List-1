/*
============================================================================
Name : 26.c
Author : Shubham Sharma
Description : Write a program to execute an executable program.
a. use some executable program
b. pass some input to an executable program. (for example execute an executable of $./a.out name)
Date: 28th Aug, 2024.
============================================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

void run_as_a_out(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <name>\n", argv[0]);
        exit(1);
    }
    printf("Hello, %s!\n", argv[1]);
    exit(0);
}
int main(int argc, char *argv[]) {
    if (argc > 1 && strcmp(argv[1], "--run-aout") == 0) {
        run_as_a_out(argc - 1, argv + 1);
    }
    char *path = argv[0];
    char *args[] = { path, "--run-aout", "Shubham", NULL };
    // Execute the program using execv
    if (execv(path, args) == -1) {
        perror("execv failed");
        exit(EXIT_FAILURE);
    }
    // This line will never be reached if execv is successful
    return 0;
}
/*
============================================================================
(base) mohitsharma@MacBook-Pro hands_on_list_1 % gcc 26.c -o 26
(base) mohitsharma@MacBook-Pro hands_on_list_1 % ./26
Hello, Shubham!
============================================================================
*/