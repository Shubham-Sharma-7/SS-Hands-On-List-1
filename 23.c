 /*
============================================================================
Name : 23.c
Author : Shubham Sharma
Description : Write a program to create a Zombie state of the running program.
Date: 27th Aug, 2024.
============================================================================
*/
#include <stdio.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/resource.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
int main(){
    pid_t pid;
    pid=fork();
    int abc;
    if(pid<0){
        printf("forkfailed\n");
        exit(1);
    }
    if(pid==0){
        sleep(10);
        printf("In child\n");
    }else{
        abc=getpid();
        printf("In parent\n");
        exit(0);
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