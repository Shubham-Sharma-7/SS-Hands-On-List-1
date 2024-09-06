/*
============================================================================
Name : 10.c
Author : Shubham Sharma
Description :  Write a program to open a file with read write mode, write 10 bytes, move the file pointer by 10
bytes (use lseek) and write again 10 bytes.
a. check the return value of lseek
b. open the file with od and check the empty spaces in between the data.
Date: 26th Aug, 2024.
============================================================================
*/
#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>

int main()
{
   int fd = open("readfromhere.txt",O_RDWR|O_CREAT | O_TRUNC, 0666);
   if(fd== -1)
   {
           perror("error in opening file");
           return 1;

   }
   const char d1[]="0123456789";
   ssize_t byt= write(fd,d1,sizeof(d1)-1);

   if(byt ==-1)
   {
           perror("error writting data");
           close(fd);
           return 1;
   }

   off_t offset = lseek(fd, 10, SEEK_CUR);
   if(offset == -1)
   {
           perror("error seeking");
           close(fd);
           return 1;
   }
   const char d2[]="Shubham Sharma";
   byt = write(fd, d2, sizeof(d2) -1);
   if(byt==-1)
   {
        perror("error writing");
        close(fd);
        return 1;
   }
   close(fd);
   printf("lseek returned offset: %ld\n", offset);
   return 0;
}
/*
============================================================================
(base) mohitsharma@MacBook-Pro hands_on_list_1 % gcc 10.c -o 10c
(base) mohitsharma@MacBook-Pro hands_on_list_1 % ./10c
lseek returned offset: 20
(base) mohitsharma@MacBook-Pro hands_on_list_1 % od -c readfromhere.txt
0000000    0   1   2   3   4   5   6   7   8   9  \0  \0  \0  \0  \0  \0
0000020   \0  \0  \0  \0   S   h   u   b   h   a   m       S   h   a   r
0000040    m   a                                                        
0000042
============================================================================
*/