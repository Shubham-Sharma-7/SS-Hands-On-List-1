 /*
============================================================================
Name : 23.c
Author : Shubham Sharma
Description : Write a program to create a Zombie state of the running program.
Date: 27th Aug, 2024.
============================================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    pid_t pid;
    pid = fork();
    if (pid < 0) {
        perror("fork failed");
        exit(1);
    } else if (pid == 0) {
        printf("Child process with PID %d is exiting.\n", getpid());
        exit(0);
    } else {
        printf("Parent process with PID %d created a child process with PID %d.\n", getpid(), pid);
        sleep(10);
        printf("Parent process is now exiting.\n");
    }
    return 0;
}

 /*
============================================================================
(base) mohitsharma@MacBook-Pro hands_on_list_1 % gcc 23.c -o 23
(base) mohitsharma@MacBook-Pro hands_on_list_1 % ./23
In child
In parent
============================================================================
*/
