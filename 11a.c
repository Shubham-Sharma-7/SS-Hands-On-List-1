/*
============================================================================
Name : 11a.c
Author : Shubham Sharma
Description :  Write a program to open a file, duplicate the file descriptor and append the file with both the
descriptors and check whether the file is updated properly or not.
a. use dup
b. use dup2
c. use fcntl
Date: 26th Aug, 2024.
============================================================================
*/
#include<stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main()
{
	int file_desc = open("dup.txt", O_WRONLY | O_APPEND);
	
	if(file_desc < 0) printf("Error opening the file\n");
	int copy_desc = dup(file_desc);
	write(copy_desc,"This will be output to the file named dup.txt\n", 46);
	write(file_desc,"This will also be output to the file named dup.txt\n", 51);
	return 0;
}
/*
============================================================================
(base) mohitsharma@MacBook-Pro hands_on_list_1 % gcc 11a.c -o 11a
(base) mohitsharma@MacBook-Pro hands_on_list_1 % ./11a
(base) mohitsharma@MacBook-Pro hands_on_list_1 % cat dup.txt
This will be output to the file named dup.txt
This will also be output to the file named dup.txt
============================================================================
*/