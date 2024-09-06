/*
============================================================================
Name : 19.c
Author : Shubham Sharma
Description : Write a program to find out time taken to execute getpid system call. Use time stamp counter.
Date: 27th Aug, 2024.
============================================================================
*/
#include <stdio.h>
#include <unistd.h>
#include <mach/mach_time.h>

int main() {
    uint64_t start, end;
    uint64_t elapsed;
    start = mach_absolute_time();
    getpid();
    end = mach_absolute_time();
    elapsed = end - start;
    mach_timebase_info_data_t timebase;
    mach_timebase_info(&timebase);
    uint64_t elapsed_ns = elapsed * timebase.numer / timebase.denom;
    printf("Time taken to execute getpid: %llu nanoseconds\n", elapsed_ns);

    return 0;
}

/*
============================================================================
(base) mohitsharma@MacBook-Pro ~ % cd hands_on_list_1 
(base) mohitsharma@MacBook-Pro hands_on_list_1 % gcc 19.c -o 19
(base) mohitsharma@MacBook-Pro hands_on_list_1 % ./19
Time taken to execute getpid: 41 nanoseconds
============================================================================
*/