/*
============================================================================
Name : 2.c
Author : Shubham Sharma
Description : Write a simple program to execute in an infinite loop at the background.Go to /proc directory and
identify all the process related information in the corresponding proc directory.
Date: 24th Aug, 2024.
============================================================================
*/
#include <stdio.h>
#include <unistd.h>
int main() {
    while (1) {
    }
    return 0;
}
/*
============================================================================
(base) mohitsharma@MacBook-Pro hands_on_list_1 % ps aux | grep 1338
mohitsharma       1338  99.7  0.0 410592880    448 s002  RN    1:13PM  16:28.42 ./2c
mohitsharma       2002   0.0  0.0 410063264    144 s002  U+    1:30PM   0:00.00 grep 1338
============================================================================
*/