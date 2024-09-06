/*
============================================================================
Name : 11c.c
Author : Shubham Sharma
Description :  Write a program to open a file, duplicate the file descriptor and append the file with both the
descriptors and check whether the file is updated properly or not.
a. use dup
b. use dup2
c. use fcntl
Date: 26th Aug, 2024.
============================================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>

int main(void){
    int fdOne, fdTwo;
    fdOne = open("misc.txt", O_CREAT | O_TRUNC, S_IRWXU, O_APPEND);
    if(fdOne < 0){
        printf("Error opening / creating test.txt. ");
        if(errno==EACCES){
            printf("Error #%d (EACCES): Permission denied.\n", EACCES);
            exit(EXIT_FAILURE);
        }
    } 
    else {
        printf("test.txt created / opened ");
        printf("with file descriptor %d.\n", fdOne);
    }
    //lets use the fcntl() function to copy the 
    //file descriptor
    if((fdTwo = fcntl(fdOne, F_DUPFD, 0))<0){
       printf("Error duplicating file descriptor.\n");
       exit(EXIT_FAILURE);
    } 
    else {
       printf("File descriptor duplicated. ");
       printf("New file descriptor is %d.\n", fdTwo);
       write(fdTwo,"This will also be output to the file named dup.txt\n", 51);
    }
    close(fdOne);
    close(fdTwo);    
    return 0;
    
}
/*
============================================================================
(base) mohitsharma@MacBook-Pro hands_on_list_1 % gcc 11c.c -o 11c
(base) mohitsharma@MacBook-Pro hands_on_list_1 % ./11c
test.txt created / opened with file descriptor 3.
File descriptor duplicated. New file descriptor is 4.
============================================================================
*/