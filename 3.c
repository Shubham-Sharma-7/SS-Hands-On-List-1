/*
============================================================================
Name : 3.c
Author : Shubham Sharma
Description : Write a program to create a file and print the file descriptor value.Use creat() system call
Date: 24th Aug, 2024.
============================================================================
*/
#include <stdio.h>
#include <fcntl.h>  
#include <unistd.h>   

int main(){
    //Using creat() system call
    const char *filename = "create_file.txt";
    mode_t mode = S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH;  
    int fd = creat(filename, mode); 
    if (fd < 0) {
        perror("creat");
        return 1;
    }
    printf("File descriptor: %d\n", fd);
    if (close(fd) < 0) {
        perror("close");
        return 1;  
    }
}
/*
============================================================================
(base) mohitsharma@MacBook-Pro hands_on_list_1 % gcc 3.c -o 3c
(base) mohitsharma@MacBook-Pro hands_on_list_1 % ./3c
File descriptor: 3
============================================================================
*/
