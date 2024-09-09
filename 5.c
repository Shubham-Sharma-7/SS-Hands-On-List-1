/*
============================================================================
Name : 5.c
Author : Shubham Sharma
Description : Write a program to create five new files with infinite loop. Execute the program in the background
and check the file descriptor table at /proc/pid/fd.
Date: 25th Aug, 2024.
============================================================================
*/
#include <errno.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
extern int errno;
int main(){
    int fd1=open("foo.txt",O_RDONLY|O_CREAT);
    int fd2=open("foo.txt",O_RDONLY|O_CREAT);
    int fd3=open("foo.txt",O_RDONLY|O_CREAT);
    int fd4=open("foo.txt",O_RDONLY|O_CREAT);
    int fd5=open("foo.txt",O_RDONLY|O_CREAT);

    printf("fd =  %d\n",fd1);
    printf("fd =  %d\n",fd2);
    printf("fd =  %d\n",fd3);
    printf("fd =  %d\n",fd4);
    printf("fd =  %d\n",fd5);

    if(fd1==-1){
        printf("error number %d\n",errno);
        perror("program");
    }
    if(fd2==-1){
        printf("error number %d\n",errno);
        perror("program");
    }
    if(fd3==-1){
        printf("error number %d\n",errno);
        perror("program");
    }
    if(fd4==-1){
        printf("error number %d\n",errno);
        perror("program");
    }
    if(fd5==-1){
        printf("error number %d\n",errno);
        perror("program");
    }

    
    //infinte loop
    while(1){

    }
    return 0;
}
/*
============================================================================
(base) mohitsharma@MacBook-Pro hands_on_list_1 % gcc 5.c -o 5c
(base) mohitsharma@MacBook-Pro hands_on_list_1 % ./5c
fd =  3
fd =  4
fd =  5
fd =  6
fd =  7
then click CTRL + D to stop
(base) mohitsharma@MacBook-Pro copy for hands for list 1 % lsof -p 3334
COMMAND  PID        USER   FD   TYPE DEVICE  SIZE/OFF    NODE NAME
5c      3334 mohitsharma  cwd    DIR   1,13      3520 5205370 /Users/mohitsharma/copy for hands for list 1
5c      3334 mohitsharma  txt    REG   1,13     33552 5420381 /Users/mohitsharma/copy for hands for list 1/5c
5c      3334 mohitsharma    0u   CHR   16,0 0t1856753     699 /dev/ttys000
5c      3334 mohitsharma    1u   CHR   16,0 0t1856753     699 /dev/ttys000
5c      3334 mohitsharma    2u   CHR   16,0 0t1856753     699 /dev/ttys000
5c      3334 mohitsharma    3r   REG   1,13         0 5214227 /Users/mohitsharma/copy for hands for list 1/foo.txt
5c      3334 mohitsharma    4r   REG   1,13         0 5214227 /Users/mohitsharma/copy for hands for list 1/foo.txt
5c      3334 mohitsharma    5r   REG   1,13         0 5214227 /Users/mohitsharma/copy for hands for list 1/foo.txt
5c      3334 mohitsharma    6r   REG   1,13         0 5214227 /Users/mohitsharma/copy for hands for list 1/foo.txt
5c      3334 mohitsharma    7r   REG   1,13         0 5214227 /Users/mohitsharma/copy for hands for list 1/foo.txt
============================================================================
*/
