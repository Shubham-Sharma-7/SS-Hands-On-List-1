/*
============================================================================
Name : 27c.c
Author : Shubham Sharma
Description : Write a program to execute ls -Rl by the following system calls
a. execl
b. execlp
c. execle
Date: 28th Aug, 2024.
============================================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

extern char **environ;  // Environment variable

int main() {
    char *command = "/bin/ls";
    char *args[] = { "ls", "-Rl", NULL };
    if (execle(command, args[0], args[1], (char *)NULL, environ) == -1) {
        perror("execle failed");
        exit(EXIT_FAILURE);
    }
    // This line will never be reached if execle is successful
    return 0;
}

/*
============================================================================
(base) mohitsharma@MacBook-Pro hands_on_list_1 % gcc 27c.c -o 27c
(base) mohitsharma@MacBook-Pro hands_on_list_1 % ./27c
total 3392
-rwxr-xr-x@ 1 mohitsharma  staff  33600 Aug 30 15:26 1
-rwxr-xr-x@ 1 mohitsharma  staff   2233 Aug 30 15:55 1.c
-rwxr-xr-x@ 1 mohitsharma  staff  33760 Aug 30 16:01 10
-rw-r--r--@ 1 mohitsharma  staff   1926 Aug 30 16:09 10.c
-rwxr-xr-x  1 mohitsharma  staff  33760 Aug 30 16:08 10c
-rwxr-xr-x@ 1 mohitsharma  staff  33536 Aug 30 16:23 11a
-rw-r--r--@ 1 mohitsharma  staff   1251 Aug 30 16:25 11a.c
-rwxr-xr-x  1 mohitsharma  staff  33504 Aug 30 16:07 11b
-rw-r--r--@ 1 mohitsharma  staff    998 Aug 30 16:18 11b.c
-rwxr-xr-x@ 1 mohitsharma  staff  33680 Aug 30 18:18 11c
-rw-r--r--@ 1 mohitsharma  staff   1824 Aug 30 18:18 11c.c
-rwxr-xr-x@ 1 mohitsharma  staff  33552 Aug 30 17:17 12
-rw-r--r--@ 1 mohitsharma  staff    865 Aug 30 16:20 12.c
-rwxr-xr-x  1 mohitsharma  staff  33552 Aug 30 16:20 12c
-rwxr-xr-x@ 1 mohitsharma  staff  33680 Aug 30 16:36 13
-rw-r--r--@ 1 mohitsharma  staff   1319 Aug 30 16:45 13.c
-rwxr-xr-x  1 mohitsharma  staff  33680 Aug 30 16:35 13c
-rwxr-xr-x  1 mohitsharma  staff  33696 Aug 30 18:24 14
-rw-r--r--@ 1 mohitsharma  staff   2065 Aug 30 18:26 14.c
-rwxr-xr-x  1 mohitsharma  staff  33456 Aug 30 17:14 14c
-rwxr-xr-x  1 mohitsharma  staff  33472 Aug 30 17:19 15
-rw-r--r--@ 1 mohitsharma  staff   2176 Aug 30 18:32 15.c
-rwxr-xr-x  1 mohitsharma  staff  33680 Aug 30 17:20 16
-rw-r--r--@ 1 mohitsharma  staff   1324 Aug 30 18:35 16.c
-rwxr-xr-x  1 mohitsharma  staff  33632 Aug 30 18:15 17
-rwxr-xr-x@ 1 mohitsharma  staff  33632 Aug 30 18:17 17a
-rw-r--r--@ 1 mohitsharma  staff   1676 Aug 30 18:28 17a.c
-rwxr-xr-x  1 mohitsharma  staff  33712 Aug 30 18:21 17b
-rw-r--r--@ 1 mohitsharma  staff   1745 Aug 30 18:28 17b.c
-rwxr-xr-x  1 mohitsharma  staff  33792 Aug 30 18:30 18
-rw-r--r--@ 1 mohitsharma  staff   1812 Aug 30 19:18 18.c
-rwxr-xr-x@ 1 mohitsharma  staff  33600 Aug 30 19:38 19
-rw-r--r--@ 1 mohitsharma  staff   1176 Aug 30 19:31 19.c
-rwxr-xr-x  1 mohitsharma  staff  33600 Aug 30 15:55 1c
-rw-r--r--@ 1 mohitsharma  staff    904 Aug 30 14:54 2.c
-rwxr-xr-x  1 mohitsharma  staff  33648 Aug 30 18:37 20
-rw-r--r--@ 1 mohitsharma  staff   1173 Aug 30 18:59 20.c
-rwxr-xr-x  1 mohitsharma  staff  33552 Aug 30 18:40 21
-rw-r--r--@ 1 mohitsharma  staff    868 Aug 30 19:06 21.c
-rwxr-xr-x  1 mohitsharma  staff  33584 Aug 30 18:42 22
-rw-r--r--@ 1 mohitsharma  staff   1306 Aug 30 18:59 22.c
-rwxr-xr-x@ 1 mohitsharma  staff  33584 Aug 30 18:48 23
-rw-r--r--@ 1 mohitsharma  staff   1037 Aug 30 18:59 23.c
-rwxr-xr-x@ 1 mohitsharma  staff  33584 Aug 30 19:32 24
-rw-r--r--@ 1 mohitsharma  staff   1078 Aug 30 19:32 24.c
-rwxr-xr-x  1 mohitsharma  staff  33680 Aug 30 18:58 25
-rw-r--r--@ 1 mohitsharma  staff   2288 Aug 30 19:00 25.c
-rwxr-xr-x  1 mohitsharma  staff  33424 Aug 30 19:50 26
-rwxr-xr-x  1 mohitsharma  staff  33424 Aug 30 19:56 27a
-rw-r--r--@ 1 mohitsharma  staff   5969 Aug 30 19:57 27a.c
-rwxr-xr-x  1 mohitsharma  staff  33424 Aug 30 19:59 27b
-rw-r--r--@ 1 mohitsharma  staff   6004 Aug 30 20:01 27b.c
-rwxr-xr-x  1 mohitsharma  staff  33664 Aug 30 20:11 27c
-rw-r--r--@ 1 mohitsharma  staff    902 Aug 30 20:10 27c.c
-rwxr-xr-x  1 mohitsharma  staff  16832 Aug 30 13:26 2c
-rw-r--r--@ 1 mohitsharma  staff   1027 Aug 30 14:54 3.c
-rwxr-xr-x  1 mohitsharma  staff  33680 Aug 30 19:12 30
-rw-r--r--@ 1 mohitsharma  staff   2132 Aug 30 19:35 30.c
-rwxr-xr-x  1 mohitsharma  staff  33552 Aug 30 13:41 3c
-rwxr-xr-x@ 1 mohitsharma  staff  33600 Aug 30 13:46 4
-rwxr-xr-x@ 1 mohitsharma  staff   1754 Aug 30 15:56 4.c
-rwxr-xr-x@ 1 mohitsharma  staff  33552 Aug 30 15:01 5
-rw-r--r--@ 1 mohitsharma  staff   1746 Aug 30 15:58 5.c
-rwxr-xr-x  1 mohitsharma  staff  33552 Aug 30 15:56 5c
-rwxr-xr-x@ 1 mohitsharma  staff  33632 Aug 30 15:23 6
-rw-r--r--@ 1 mohitsharma  staff   1103 Aug 30 15:27 6.c
-rwxr-xr-x  1 mohitsharma  staff  33632 Aug 30 15:24 6c
-rw-r--r--@ 1 mohitsharma  staff   2066 Aug 30 15:50 7.c
-rwxr-xr-x  1 mohitsharma  staff  33584 Aug 30 15:47 7c
-rwxr-xr-x@ 1 mohitsharma  staff  33584 Aug 30 15:50 8
-rw-r--r--@ 1 mohitsharma  staff   1038 Aug 30 15:52 8.c
-rwxr-xr-x  1 mohitsharma  staff  33584 Aug 30 15:52 8c
-rwxr-xr-x@ 1 mohitsharma  staff  33696 Aug 30 15:38 9
-rw-r--r--@ 1 mohitsharma  staff   2159 Aug 30 15:40 9.c
-rw-r--r--@ 1 mohitsharma  staff      0 Aug 30 15:39 9_file
-rwxr-xr-x  1 mohitsharma  staff  33696 Aug 30 15:36 9c
-rw-r--r--@ 1 mohitsharma  staff     60 Aug 30 15:51 abc.txt
-rw-r--r--  1 mohitsharma  staff      0 Aug 30 13:41 create_file.txt
-rw-r--r--@ 1 mohitsharma  staff     98 Aug 30 16:25 dup.txt
-rw-r--r--@ 1 mohitsharma  staff      0 Aug 30 13:46 existing_file.txt
-rw-r--r--  1 mohitsharma  staff     33 Aug 30 15:48 fil2
-rw-r--r--  1 mohitsharma  staff     48 Aug 30 18:24 file1
-rw-r--r--  1 mohitsharma  staff     42 Aug 30 18:24 file2
-r--------@ 1 mohitsharma  staff      0 Aug 30 15:01 foo.txt
-rw-r--r--@ 2 mohitsharma  staff      0 Aug 30 13:08 hard_link.txt
-rwx------@ 1 mohitsharma  staff      0 Aug 30 18:18 misc.txt
prw-r--r--  1 mohitsharma  staff      0 Aug 30 15:55 named_pipe.fifo
-rw-r--r--@ 1 mohitsharma  staff     34 Aug 30 16:08 readfromhere.txt
-rw-r--r--@ 1 mohitsharma  staff      0 Aug 30 18:53 record.txt
lrwxr-xr-x  1 mohitsharma  staff     15 Aug 30 15:55 soft_link.txt -> target_file.txt
-rw-r--r--@ 2 mohitsharma  staff      0 Aug 30 13:08 target_file.txt
-rw-r--r--  1 mohitsharma  staff      0 Aug 30 13:47 test_file.txt
-rw-r--r--@ 1 mohitsharma  staff      4 Aug 30 18:21 ticket_file.txt
============================================================================
*/