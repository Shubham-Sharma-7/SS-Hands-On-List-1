/*
============================================================================
Name : 1.c
Author : Shubham Sharma
Description : Create the following types of a files using (i) shell command (ii) system call
a. soft link (symlink system call)
b. hard link (link system call)
c. FIFO (mkfifo Library Function or mknod system call)
Date: 24th Aug, 2024.
============================================================================
*/
#include <unistd.h>  
#include <stdio.h> 
#include <sys/types.h>  
#include <sys/stat.h> 

int main() {
    //for doing it using shell commands visit the terminal

    //For Soft Link (Symbolic Link)
    //ln -s target_file symlink_name
    //For Hard Link
    //ln target_file hardlink_name
    //FIFO (Named Pipe)
    //mkfifo fifo_name

    //for doing it using system call 

    //using system call symlink() to create a soft link

    const char *target_file = "target_file.txt";
    const char *symlink_name = "soft_link.txt";   
    //Create a symbolic link
    if (symlink(target_file, symlink_name) == -1) {
        perror("Error creating symbolic link");
        return 1;
    }
    printf("Symbolic link created: %s -> %s\n", symlink_name, target_file);

    //using system call link() to create a hard link

    const char *hardlink_name = "hard_link.txt";
    //Create a hard link
    if (link(target_file, hardlink_name) == -1) {
        perror("Error creating hard link");
        return 1;
    }

    printf("Hard link created: %s -> %s\n", hardlink_name, target_file);

    //using system call myfifo() to create a FIFO

    const char *fifo_name = "named_pipe.fifo"; 
    //Create a FIFO (named pipe)
    if (mkfifo(fifo_name, 0666) == -1) {
        perror("Error creating FIFO");
        return 1;
    }
    printf("FIFO created: %s\n", fifo_name);
    return 0;
}
/*
============================================================================
(base) mohitsharma@MacBook-Pro hands_on_list_1 % gcc 1.c -o 1c
(base) mohitsharma@MacBook-Pro hands_on_list_1 % ./1c
Symbolic link created: soft_link.txt -> target_file.txt
Hard link created: hard_link.txt -> target_file.txt
FIFO created: named_pipe.fifo
============================================================================
*/
