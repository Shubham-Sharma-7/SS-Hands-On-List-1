/*
============================================================================
Name : 11b.c
Author : Shubham Sharma
Description :  Write a program to open a file, duplicate the file descriptor and append the file with both the
descriptors and check whether the file is updated properly or not.
a. use dup
b. use dup2
c. use fcntl
Date: 26th Aug, 2024.
============================================================================
*/
#include<stdlib.h>
#include<unistd.h>
#include<stdio.h>
#include<fcntl.h>
  
int main()
{
    int file_desc = open("test.txt",O_WRONLY | O_APPEND);
    dup2(file_desc, 1) ; 
    printf("I will be printed in the file test.txt\n");
    return 0;
}
/*
============================================================================
(base) mohitsharma@MacBook-Pro hands_on_list_1 % gcc 11b.c -o 11b
(base) mohitsharma@MacBook-Pro hands_on_list_1 % ./11b
I will be printed in the file test.txt
============================================================================
*/