 /*
============================================================================
Name : 24.c
Author : Shubham Sharma
Description : Write a program to create an orphan process.
Date: 28th Aug, 2024.
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
        sleep(5);
        printf("In child\n");
    }
    else{
        abc=getpid();
        printf("In parent\n");
        printf("Parent ID - %d",abc);
        exit(0);
    }
    return 0;
}
 /*
============================================================================
(base) mohitsharma@MacBook-Pro hands_on_list_1 % gcc 24.c -o 24
(base) mohitsharma@MacBook-Pro hands_on_list_1 % ./24
In parent
Parent ID - 50116 
In child
============================================================================
*/