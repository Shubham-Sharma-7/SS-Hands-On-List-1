 /*
============================================================================
Name : 21.c
Author : Shubham Sharma
Description : Write a program, call fork and print the parent and child process id.
Date: 27th Aug, 2024.
============================================================================
*/
#include <stdio.h>
#include <sys/resource.h>
#include <unistd.h>
int main(){
    pid_t parent= getppid();
    pid_t process= getpid();
    pid_t pid=fork();
    printf("child process: %d\n",process);
    printf("parent process: %d\n",parent);
}
/*
============================================================================
(base) mohitsharma@MacBook-Pro hands_on_list_1 % gcc 21.c -o 21
(base) mohitsharma@MacBook-Pro hands_on_list_1 % ./21
child process: 45824
parent process: 40466
============================================================================
*/