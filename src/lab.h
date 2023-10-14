/*Do NOT modify this file! */
#ifndef LAB_H
#define LAB_H
#include <stdlib.h>
#include <stdbool.h>
#include <libshared_and_static_export.h>

#define MAX_VERSION_STRING 10

#ifdef __cplusplus
extern "C"
{
#endif

  /**
   * @brief Entry point for the main function. If your project requires a main
   * then you will write your code in the myMain function. If your project
   * does NOT require a main (i.e. you are writing a library) then this
   * function will be empty.
   *
   * @param argc The argument count
   * @param argv The argument array
   * @return The exit code
   */
  LIBSHARED_AND_STATIC_EXPORT int myMain(int argc, char **argv);

  /**
   * @brief Returns a string containing the version of the library. This string
   * has been allocated using malloc and must be freed by the caller. The
   * version of the library is generated using the cmake version.
   *
   * @return char* The version string
   */
  LIBSHARED_AND_STATIC_EXPORT char* getVersion(void);

  /**
   * @brief Example function that adds two numbers together.
   *
   * @param a The first number
   * @param b The second number
   * @return The sum of the two numbers
   */
  LIBSHARED_AND_STATIC_EXPORT int add(int a, int b);

  /**
   * @brief Function that leaks some data!
   *
   * @param a some number
   * @return a pointer to some memory
   */
  LIBSHARED_AND_STATIC_EXPORT int* leak(int a);

#ifdef __cplusplus
} //extern "C"
#endif

#endif
