/*
============================================================================
Name : 9.c
Author : Shubham Sharma
Description : Write a program to print the following information about a given file.
a. inode
b. number of hard links
c. uid
d. gid
e. size
f. block size
g. number of blocks
h. time of last access
i. time of last modification
j. time of last change
Date: 26th Aug, 2024.
============================================================================
*/
#include <stdio.h>
#include <sys/stat.h>
#include <time.h>
#include <unistd.h>

void print_file_info(const char *file_path) {
    struct stat file_stat;

    // Get file stats
    if (stat(file_path, &file_stat) == -1) {
        perror("Error getting file stats");
        return;
    }

    // Print required information
    printf("File: %s\n", file_path);
    printf("Inode: %lu\n", (unsigned long)file_stat.st_ino);
    printf("Number of hard links: %lu\n", (unsigned long)file_stat.st_nlink);
    printf("UID: %u\n", (unsigned int)file_stat.st_uid);
    printf("GID: %u\n", (unsigned int)file_stat.st_gid);
    printf("Size: %ld bytes\n", (long)file_stat.st_size);
    printf("Block size: %ld bytes\n", (long)file_stat.st_blksize);
    printf("Number of blocks: %ld\n", (long)file_stat.st_blocks);
    printf("Time of last access: %s", ctime(&file_stat.st_atime));
    printf("Time of last modification: %s", ctime(&file_stat.st_mtime));
    printf("Time of last change: %s", ctime(&file_stat.st_ctime));
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <file_path>\n", argv[0]);
        return 1;
    }

    print_file_info(argv[1]);

    return 0;
}

/*
============================================================================
(base) mohitsharma@MacBook-Pro hands_on_list_1 % ./9c 9_file
File: 9_file
Inode: 5194346
Number of hard links: 1
UID: 501
GID: 20
Size: 0 bytes
Block size: 4096 bytes
Number of blocks: 0
Time of last access: Fri Aug 30 15:39:20 2024
Time of last modification: Fri Aug 30 15:39:20 2024
Time of last change: Fri Aug 30 15:39:20 2024
============================================================================
*/