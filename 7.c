/*
============================================================================
Name : 7.c
Author : Shubham Sharma
Description : Write a program to copy file1 into file2 ($cp file1 file2).
Date: 25th Aug, 2024.
============================================================================
*/
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<stdio.h>
#include<unistd.h>
int main(int argc,char* argv[])
{
	if(argc!=3)
	{
		printf("incorrect number of argument");
		return 0;
	}
    int fd_read=open(argv[1],O_RDONLY);
	int fd_write=open(argv[2],O_WRONLY|O_CREAT,0644);
	if(fd_write==-1||fd_read==-1)
		printf("hey");
	while(1)
	{
	    char buf;
	    int char_read=read(fd_read,&buf,1);
	    if(char_read==0)
		break;
	    int char_written=write(fd_write,&buf,1);
	}
	int fd_read_close=close(fd_read);
    int fd_write_close=close(fd_write);

	if(fd_read_close==-1||fd_write_close==-1){
		printf("wrong");
    }
    return 0;
}

/*
============================================================================
base) mohitsharma@MacBook-Pro hands_on_list_1 % gcc 7.c -o 7c
(base) mohitsharma@MacBook-Pro hands_on_list_1 % nano file1      
(base) mohitsharma@MacBook-Pro hands_on_list_1 % touch file2
(base) mohitsharma@MacBook-Pro hands_on_list_1 % ./7c file1 fil2
(base) mohitsharma@MacBook-Pro hands_on_list_1 % ls
1			1c			4			6.c			8c			abc.txt			file2			soft_link.txt
1.c			2.c			4.c			6c			9			create_file.txt		foo.txt			target_file.txt
10			2c			5			7.c			9.c			existing_file.txt	hard_link.txt		test_file.txt
10.c			3.c			5.c			7c			9_file			fil2			named_pipe.fifo
10c			3c			6			8.c			9c			file1			readfromhere.txt
(base) mohitsharma@MacBook-Pro hands_on_list_1 % cat fil2
yrdcgrhdfytctynjkfytdfiuyzatepoo
(base) mohitsharma@MacBook-Pro hands_on_list_1 % ./7c file1 file2
(base) mohitsharma@MacBook-Pro hands_on_list_1 % cat file1
yrdcgrhdfytctynjkfytdfiuyzatepoo
(base) mohitsharma@MacBook-Pro hands_on_list_1 % cat file2
yrdcgrhdfytctynjkfytdfiuyzatepoo
       
============================================================================
*/