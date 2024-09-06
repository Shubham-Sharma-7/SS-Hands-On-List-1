/*
============================================================================
Name : 8.c
Author : Shubham Sharma
Description : Write a program to open a file in read only mode, read line by line and display each line as it is read.
Close the file when end of file is reached.
Date: 25th Aug, 2024.
============================================================================
*/
#include <stdio.h>
#include <stdlib.h> // For exit()
int main(){
    FILE *f1;
    f1=fopen("abc.txt", "r");
    if(f1==NULL){
        printf("error");
        exit(0);
    }
    do{
        char c=fgetc(f1);
        if(feof(f1)) break;
        printf("%c",c);
    }while(1);
    return 0;
}
/*
============================================================================
(base) mohitsharma@MacBook-Pro ~ % cd hands_on_list_1 
(base) mohitsharma@MacBook-Pro hands_on_list_1 % gcc 8.c -o 8c
(base) mohitsharma@MacBook-Pro hands_on_list_1 % ./8c
you have now entered in program 8 
============================================================================
*/