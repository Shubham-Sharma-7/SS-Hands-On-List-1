 /*
============================================================================
Name : 22.c
Author : Shubham Sharma
Description : Write a program, open a file, call fork, and then write to the file by both the child as well as the
parent processes.Check output of the file.
Date: 27th Aug, 2024.
============================================================================
*/
#include <stdio.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/resource.h>
#include <unistd.h>
int main(){
    int fd;
    fd=open("input.txt",O_WRONLY|O_APPEND);
    int fort=fork();
    if(fort==0){
        char *childwrites="child is writing\n";
        lseek(fd, sizeof(childwrites), SEEK_CUR);
        write(fd, childwrites, sizeof(childwrites));
        printf("child has written\n");
    }else{
        char *parentwrite="parent is writing\n";
        lseek(fd, sizeof(parentwrite), SEEK_CUR);
        write(fd, parentwrite, sizeof(parentwrite));
        printf("parent has written\n");
    }
}
 /*
============================================================================
(base) mohitsharma@MacBook-Pro hands_on_list_1 % gcc 22.c -o 22
(base) mohitsharma@MacBook-Pro hands_on_list_1 % ./22
parent has written
child has written
============================================================================
*/