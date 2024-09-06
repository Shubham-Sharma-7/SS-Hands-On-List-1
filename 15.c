/*
============================================================================
Name : 15.c
Author : Shubham Sharma
Description : Write a program to display the environmental variable of the user(use environ).
Date: 26th Aug, 2024.
============================================================================
*/
#include <stdio.h>
#include <stdlib.h>

extern char **environ;

int main() {
    
    for (int i = 0; environ[i] != NULL; i++) {
        printf("%s\n", environ[i]);
    }

    return 0;
}
/*
============================================================================
(base) mohitsharma@MacBook-Pro ~ % cd hands_on_list_1 
(base) mohitsharma@MacBook-Pro hands_on_list_1 % gcc 15.c -o 15
(base) mohitsharma@MacBook-Pro hands_on_list_1 % ./15
__CFBundleIdentifier=com.apple.Terminal
TMPDIR=/var/folders/ql/c97qv6q50pd9zgt8ylx1gl9m0000gn/T/
XPC_FLAGS=0x0
TERM=xterm-256color
SSH_AUTH_SOCK=/private/tmp/com.apple.launchd.NWzTvaBwkg/Listeners
XPC_SERVICE_NAME=0
TERM_PROGRAM=Apple_Terminal
TERM_PROGRAM_VERSION=453
TERM_SESSION_ID=CBF5C922-AFA2-49B0-82F9-F5879EC6E036
SHELL=/bin/zsh
HOME=/Users/mohitsharma
LOGNAME=mohitsharma
USER=mohitsharma
PATH=/Users/mohitsharma/anaconda3/bin:/Users/mohitsharma/anaconda3/condabin:/opt/homebrew/bin:/opt/homebrew/sbin:/usr/local/bin:/System/Cryptexes/App/usr/bin:/usr/bin:/bin:/usr/sbin:/sbin:/var/run/com.apple.security.cryptexd/codex.system/bootstrap/usr/local/bin:/var/run/com.apple.security.cryptexd/codex.system/bootstrap/usr/bin:/var/run/com.apple.security.cryptexd/codex.system/bootstrap/usr/appleinternal/bin
SHLVL=1
PWD=/Users/mohitsharma/hands_on_list_1
OLDPWD=/Users/mohitsharma
HOMEBREW_PREFIX=/opt/homebrew
HOMEBREW_CELLAR=/opt/homebrew/Cellar
HOMEBREW_REPOSITORY=/opt/homebrew
MANPATH=/opt/homebrew/share/man::
INFOPATH=/opt/homebrew/share/info:
CONDA_EXE=/Users/mohitsharma/anaconda3/bin/conda
_CE_M=
_CE_CONDA=
CONDA_PYTHON_EXE=/Users/mohitsharma/anaconda3/bin/python
CONDA_SHLVL=1
CONDA_PREFIX=/Users/mohitsharma/anaconda3
CONDA_DEFAULT_ENV=base
CONDA_PROMPT_MODIFIER=(base) 
LC_CTYPE=UTF-8
_=/Users/mohitsharma/hands_on_list_1/./15
============================================================================
*/