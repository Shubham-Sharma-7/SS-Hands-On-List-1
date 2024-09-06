 /*
============================================================================
Name : 30.c
Author : Shubham Sharma
Description : Write a program to run a script at a specific time using a Daemon process.
Date: 28th Aug, 2024.
============================================================================
*/
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
int main(){
    pid_t pid=fork();
    if(pid==-1){
        printf("fork failed\n");
    }
    if(pid==0){
        //child process
        sleep(10);
        printf("creating a new session with setsid()\n");
        pid_t newsession=setsid();
        if(newsession==-1){
            printf("creating a new session failed\n");
        }else{
            printf("A new session created\n");
        }
        int changedir=chdir("/");
        if(changedir==-1){
            printf("changeing directory failed\n");
        }else{
            printf("changed the directory to '/'\n");
            while(1){
               sleep(2);
                printf("PID of process is %d\n",getpid());
                printf("the deamon process is running\n");
            }
        }
    }
    else{
        //parent process
        printf("parent process this will exit..\n"); 
        exit(0);      
    }
}
/*
============================================================================
(base) mohitsharma@MacBook-Pro hands_on_list_1 % gcc 30.c -o 30
(base) mohitsharma@MacBook-Pro hands_on_list_1 % ./30
parent process this will exit..
(base) mohitsharma@MacBook-Pro hands_on_list_1 % creating a new session with setsid()
A new session created
changed the directory to '/'
PID of process is 58302
the deamon process is running
PID of process is 58302
the deamon process is running
PID of process is 58302
the deamon process is running
PID of process is 58302
the deamon process is running
PID of process is 58302
the deamon process is running

Saving session...
...copying shared history...
...saving history...truncating history files...
...completed.

[Process completed]
============================================================================
*/