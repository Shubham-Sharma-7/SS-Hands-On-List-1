/*
============================================================================
Name : 28.c
Author : Shubham Sharma
Description : Write a program to get maximum and minimum real time priority
Date: 28th Aug, 2024.
============================================================================
*/
#include <stdio.h>
#include <sched.h>
int main()
{
    printf("Maximum priority and Minimum priority of SCHED_FIFO scheduling is %d and %d respectively\n", sched_get_priority_max(SCHED_FIFO), sched_get_priority_min(SCHED_FIFO));
    printf("Maximum priority and Minimum priority of SCHED_RR scheduling is %d and %d respectively\n", sched_get_priority_max(SCHED_RR), sched_get_priority_min(SCHED_RR));
    printf("Maximum priority and Minimum priority of SCHED_OTHER scheduling is %d and %d respectively\n", sched_get_priority_max(SCHED_OTHER), sched_get_priority_min(SCHED_OTHER));
    return 0;
}
/*
============================================================================
(base) mohitsharma@MacBook-Pro hands_on_list_1 % gcc 28.c -o 28
(base) mohitsharma@MacBook-Pro hands_on_list_1 % ./28
Maximum priority and Minimum priority of SCHED_FIFO scheduling is 47 and 15 respectively
Maximum priority and Minimum priority of SCHED_RR scheduling is 47 and 15 respectively
Maximum priority and Minimum priority of SCHED_OTHER scheduling is 47 and 15 respectively
============================================================================
*/