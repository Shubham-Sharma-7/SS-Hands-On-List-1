/*
============================================================================
Name : 4.c
Author : Shubham Sharma
Description : Write a program to open an existing file with read write mode. Try O_EXCL flag also.
Date: 24th Aug, 2024.
============================================================================
*/
#include <fcntl.h>
#include <unistd.h>  
#include <stdio.h> 
#include <errno.h>  

int main() {

    //Program to Open an Existing File with Read-Write Mode (O_RDWR)

    // Specify the existing file name
    const char *filename = "existing_file.txt";
    int fd = open(filename, O_RDWR);
    if (fd == -1) {
        perror("Error opening file in read-write mode");
        return 1;
    }
    printf("File opened in read-write mode, file descriptor: %d\n", fd);
    close(fd);

    //Program to Open a File with O_RDWR | O_EXCL | O_CREAT

    const char *filenamee = "test_file.txt";
    // Attempt to open the file with O_RDWR | O_EXCL | O_CREAT
    int fdd = open(filenamee, O_RDWR | O_EXCL | O_CREAT, 0644);
    if (fdd == -1) {
        if (errno == EEXIST) {
            perror("Error: File already exists");
        }
        else {
            perror("Error opening or creating file");
        }
        return 1;
    }
    printf("File created and opened in read-write mode, file descriptor: %d\n", fdd);
    close(fdd);

    return 0;

}
/*
============================================================================
(base) mohitsharma@MacBook-Pro hands_on_list_1 % gcc 4.c -o 4c
(base) mohitsharma@MacBook-Pro hands_on_list_1 % ./4c
File opened in read-write mode, file descriptor: 3
File created and opened in read-write mode, file descriptor: 3
============================================================================
*/