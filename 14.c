/*
============================================================================
Name : 14.c
Author : Shubham Sharma
Description : Write a program to find the type of a file.
a. Input should be taken from command line.
b. program should be able to identify any type of a file.
Date: 26th Aug, 2024.
============================================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <string.h>

void print_file_type(const char *file_path) {
    struct stat file_stat;

    // Get file status
    if (stat(file_path, &file_stat) != 0) {
        perror("stat");
        exit(EXIT_FAILURE);
    }

    // Identify the file type
    if (S_ISREG(file_stat.st_mode)) {
        printf("%s: Regular file\n", file_path);
    } else if (S_ISDIR(file_stat.st_mode)) {
        printf("%s: Directory\n", file_path);
    } else if (S_ISCHR(file_stat.st_mode)) {
        printf("%s: Character device\n", file_path);
    } else if (S_ISBLK(file_stat.st_mode)) {
        printf("%s: Block device\n", file_path);
    } else if (S_ISFIFO(file_stat.st_mode)) {
        printf("%s: FIFO/pipe\n", file_path);
    } else if (S_ISLNK(file_stat.st_mode)) {
        printf("%s: Symbolic link\n", file_path);
    } else if (S_ISSOCK(file_stat.st_mode)) {
        printf("%s: Socket\n", file_path);
    } else {
        printf("%s: Unknown file type\n", file_path);
    }
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <file_path>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    for (int i = 1; i < argc; i++) {
        print_file_type(argv[i]);
    }

    return 0;
}
/*
============================================================================
(base) mohitsharma@MacBook-Pro hands_on_list_1 % gcc 14.c -o 14
(base) mohitsharma@MacBook-Pro hands_on_list_1 % ./14
Usage: ./14 <file_path>
(base) mohitsharma@MacBook-Pro hands_on_list_1 % ./14 file1 file2
file1: Regular file
file2: Regular file
============================================================================
*/