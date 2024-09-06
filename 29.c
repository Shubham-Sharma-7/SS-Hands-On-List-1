/*
============================================================================
Name : 29.c
Author : Shubham Sharma
Description : Write a program to get scheduling policy and modify the scheduling policy (SCHED_FIFO,
SCHED_RR).
Date: 28th Aug, 2024.
============================================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/resource.h>
#include <errno.h>
/*
On macOS, the real-time scheduling policies SCHED_FIFO and SCHED_RR are not directly 
available as they are in Linux. macOS does not fully support the POSIX real-time 
scheduling API. Instead, macOS uses a priority-based scheduling system, which can be 
indirectly controlled using the setpriority and getpriority functions to adjust the
"nice" value of a process.
*/
void print_current_priority(pid_t pid) {
    int priority = getpriority(PRIO_PROCESS, pid);
    if (priority == -1 && errno != 0) {
        perror("getpriority");
        exit(EXIT_FAILURE);
    }
    printf("Current nice value for PID %d: %d\n", pid, priority);
}
void set_priority(pid_t pid, int priority) {
    if (setpriority(PRIO_PROCESS, pid, priority) == -1) {
        perror("setpriority");
        exit(EXIT_FAILURE);
    }
    printf("Priority (nice value) set to: %d\n", priority);
}
int main() {
    pid_t pid = getpid(); 
    print_current_priority(pid);
    printf("\nIncreasing the nice value to 10...\n");
    set_priority(pid, 10);
    print_current_priority(pid);
    printf("\nDecreasing the nice value to -10...\n");
    set_priority(pid, -10);  
    print_current_priority(pid);

    return 0;
}

/*
============================================================================
(base) mohitsharma@MacBook-Pro hands_on_list_1 % gcc 29.c -o 29
(base) mohitsharma@MacBook-Pro hands_on_list_1 % ./29
Current nice value for PID 90621: 0

Increasing the nice value to 10...
Priority (nice value) set to: 10
Current nice value for PID 90621: 10

Decreasing the nice value to -10...
setpriority: Permission denied
============================================================================
*/