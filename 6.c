/*
============================================================================
Name : 6.c
Author : Shubham Sharma
Description : Write a program to take input from STDIN and display on STDOUT. Use only read/write system calls.
Date: 25th Aug, 2024.
============================================================================
*/
#include<stdio.h>
#include<unistd.h>

int main() {
    char buffer[1024];
    size_t bytesRead;
    while ((bytesRead = read(STDIN_FILENO, buffer, sizeof(buffer))) > 1) {
            write(STDOUT_FILENO, buffer, bytesRead);
    }
    if (bytesRead == -1) {
        perror("Error reading from STDIN");
        return 1;
    }
    return 0;
}
/*
============================================================================
(base) mohitsharma@MacBook-Pro hands_on_list_1 % gcc 6.c -o 6c
(base) mohitsharma@MacBook-Pro hands_on_list_1 % ./6c
you can write whatever you want
you can write whatever you want
hdfuygd
hdfuygd
kfhuigfiuefue8yf
kfhuigfiuefue8yf
dhfh
dhfh

then click CTRL + D to stop
============================================================================
*/