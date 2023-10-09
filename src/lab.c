#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <readline/readline.h>
#include <readline/history.h>
#include "lab.h"
#include <labconfig.h>


/*Implementations for functions defined in lab.h*/

int myMain(int argc, char **argv)
{
    using_history();
    char *line = (char *)NULL;
    line = readline("What is your name?");
    printf("Hello %s! This is the starter template version: %d.%d\n", line, lab_VERSION_MAJOR, lab_VERSION_MINOR);
    return 0;
}

char *getVersion()
{
    char *version = malloc(MAX_VERSION_STRING);
    snprintf(version,MAX_VERSION_STRING, "%d.%d", lab_VERSION_MAJOR, lab_VERSION_MINOR);
    return version;
}

int add(int a, int b)
{
    return a + b;
}