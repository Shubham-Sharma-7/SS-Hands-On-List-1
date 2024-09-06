 /*
============================================================================
Name : 20.c
Author : Shubham Sharma
Description : Find out the priority of your running program. Modify the priority with nice command.
Date: 27th Aug, 2024.
============================================================================
*/
#include <stdio.h>
#include <unistd.h>
#include <sys/resource.h>

int main() {
    int priority = 10;
    int old_priority = getpriority(PRIO_PROCESS, 0);
    printf("Old priority: %d\n", old_priority);
    if (setpriority(PRIO_PROCESS, 0, priority) == -1) {
        perror("setpriority");
        return 1;
    }
    int new_priority = nice(5);
    printf("New priority: %d\n", new_priority);
    sleep(5);
    return 0;
}
/*
============================================================================
(base) mohitsharma@MacBook-Pro hands_on_list_1 % gcc 20.c -o 20
(base) mohitsharma@MacBook-Pro hands_on_list_1 % ./20
Old priority: 0
New priority: 15
============================================================================
*/