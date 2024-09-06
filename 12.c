/*
============================================================================
Name : 12.c
Author : Shubham Sharma
Description : Write a program to find out the opening mode of a file.Use fcntl.
Date: 26th Aug, 2024.
============================================================================
*/
#include<stdlib.h>
#include<unistd.h>
#include<stdio.h>
#include<fcntl.h>
int main(){
    FILE *file = fopen("abc.txt", "r");
    int fd = fileno(file);
    int mode = fcntl(fd, F_GETFL);
    printf("mode of file descriptor is: %d\n",mode);
    return 0;
}
/*
============================================================================
(base) mohitsharma@MacBook-Pro hands_on_list_1 % gcc 12.c -o 12c
(base) mohitsharma@MacBook-Pro hands_on_list_1 % ./12c
mode of file descriptor is: 0
============================================================================
*/