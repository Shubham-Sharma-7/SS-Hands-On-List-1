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

int main() {
    char *executable = "./greeting";  
    char *arg1 = "Shubham";              
    char *args[] = {executable, arg1, NULL};

    printf("Executing %s with argument %s...\n", executable, arg1);

    // Execute the program
    if (execvp(executable, args) == -1) {
        perror("execvp failed");
        exit(EXIT_FAILURE);
    }

    // This line will not be executed if execvp is successful
    printf("This won't be printed if execvp is successful.\n");

    return 0;
}

/*
============================================================================
(base) mohitsharma@MacBook-Pro hands_on_list_1 % gcc 26.c -o 26
(base) mohitsharma@MacBook-Pro hands_on_list_1 % ./26
Hello, Shubham!
============================================================================
*/
