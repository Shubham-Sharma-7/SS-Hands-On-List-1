/*
============================================================================
Name : 13.c
Author : Shubham Sharma
Description : Write a program to wait for a STDIN for 10 seconds using select. Write a proper print statement to
verify whether the data is available within 10 seconds or not (check in $man 2 select).
Date: 26th Aug, 2024.
============================================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <sys/types.h>
#include <unistd.h>

int main(void)
{
    fd_set rfds;
    struct timeval tv;
    int retval;
    FD_ZERO(&rfds);
    FD_SET(0, &rfds);
    tv.tv_sec = 10;
    tv.tv_usec = 0;

   retval = select(1, &rfds, NULL, NULL, &tv);
    if (retval == -1)
        perror("select()");
    else if (retval)
        printf("Data is available now.\n");
    else
        printf("No data within ten seconds.\n");
   exit(EXIT_SUCCESS);
}
/*
============================================================================
(base) mohitsharma@MacBook-Pro hands_on_list_1 % gcc 13.c -o 13c
(base) mohitsharma@MacBook-Pro hands_on_list_1 % ./13c    
No data within ten seconds.
(base) mohitsharma@MacBook-Pro hands_on_list_1 % ./13c
hello
Data is available now
============================================================================
*/