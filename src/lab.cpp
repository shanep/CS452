#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <readline/readline.h>
#include <readline/history.h>
#include "lab.h"
#include <labconfig.h>

#define UNUSED(x) (void)(x)

/*Implementations for functions defined in lab.h*/

int myMain(int argc, char **argv)
{
    UNUSED(argc);
    UNUSED(argv);
    using_history();
    char *line = (char *)NULL;
    line = readline("What is your name?");
    printf("Hello %s! This is the starter template version: %d.%d\n", line, lab_VERSION_MAJOR, lab_VERSION_MINOR);
    free(line);
    return 0;
}

char *getVersion(void)
{
    char *version = (char*) malloc(MAX_VERSION_STRING);
    snprintf(version,MAX_VERSION_STRING, "%d.%d", lab_VERSION_MAJOR, lab_VERSION_MINOR);
    return version;
}

int add(int a, int b)
{
    return a + b;
}

int* leak(int a)
{
  //add a leak1
  int* rval = (int*) malloc(sizeof(int));
  rval = (int*)malloc(sizeof(int));
  *rval = a;
  return rval;
}


int segfault(void)
{
  int *foo = nullptr;
  int bar = *foo;
  return bar;
}
