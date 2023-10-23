# Overview

This project is divided into several tasks. Each task will be explained in
detail and you are expected to complete each task in order. This project has
been tested on Linux, Windows, and MacOS using github actions. In _theory_ you
could use any operating system you wish to develop and test your solution.
However, the reality of writing native cross platform code is a quagmire of
sadness and despair. Additionally, supporting 3 operating systems and their
respective development environments is beyond the capacity of your instructor
and GA/TA.

Thus, your code will be graded on the departments lab machines, office hours
with your instructor or TA/GA will be conducted in the departments lab machines,
and all questions about the project will be answered in the context of the
departments lab machines. If you choose to use a different operating system you
are on your own to figure out how to get the project to build and run. **ALL**
instructions below assume you are working on the departments lab machines.

This project can be completed in C/C++ or [Rust](https://www.rust-lang.org/).
You are in no way required to use C++ or Rust if you do not wish to do so. The
textbook, examples, and starter code are all written in C. The only C++
dependency is the Google Test Framework. However, we are only going to write
simple tests and you can easily write those in C. Using the advanced features of
the Google Test Framework is optional.

## Task 0 - Pre-reading

- [Grading Rubric](https://shanepanter.com/cs452/grading-rubric.html)
- [Google Test Framework](http://google.github.io/googletest/primer.html#simple-tests)
- (optional)[Cross Platform Notes](https://shanepanter.com/cs452/cross-platform.html)

## Task 1 - Understand Starter Code

This project is setup with a sample `lab.h`, `lab.cpp`, and `test-lab.cpp` file
to demonstrate how to structure your code and tests. This project template
includes intentional errors in the code and tests to demonstrate how address
sanitizer can help you find bugs in your code. Run the following commands to see
everything in action!

```bash
cmake --preset x64-ASan
cmake --build --preset x64-ASan
```

You should see a bunch of warnings in the output (which is bad), your code
should have no warnings.

```bash
/home/shanep/repos/cpp-project-template/src/lab.cpp:14:16: warning: unused parameter ‘argc’ [-Wunused-parameter]
   14 | int myMain(int argc, char **argv)
      |            ~~~~^~~~
/home/shanep/repos/cpp-project-template/src/lab.cpp:14:29: warning: unused parameter ‘argv’ [-Wunused-parameter]
   14 | int myMain(int argc, char **argv)
```

You can run the executable like this:

```bash
$ ./out/build/x64-ASan/myprogram
What is your name?shane
Hello shane! This is the starter template version: 0.1
```

You can see the tests in action like this:

```bash
$ ctest --preset x64-ASan
Test project /home/shanep/repos/cpp-project-template/out/build/x64-ASan
    Start 1: VersionTest.PositiveNos
1/5 Test #1: VersionTest.PositiveNos ..........   Passed    0.01 sec
    Start 2: AddTest.PositiveNos
2/5 Test #2: AddTest.PositiveNos ..............   Passed    0.01 sec
    Start 3: SegFaultTest.asan
3/5 Test #3: SegFaultTest.asan ................   Passed    0.04 sec
    Start 4: OutOfBoundsTest.fail
4/5 Test #4: OutOfBoundsTest.fail .............***Not Run (Disabled)   0.00 sec
    Start 5: LeakTest.fail
5/5 Test #5: LeakTest.fail ....................***Not Run (Disabled)   0.00 sec

100% tests passed, 0 tests failed out of 3

Total Test time (real) =   0.06 sec

The following tests did not run:
          4 - OutOfBoundsTest.fail (Disabled)
          5 - LeakTest.fail (Disabled)
```

You can see there are two disabled tests. They are disabled because they fail,
lets run them anyway!

```bash
$ ./out/build/x64-ASan/test-lab --gtest_filter=DISABLED_OutOfBoundsTest.fail --gtest_also_run_disabled_tests
Running main() from /builddir/build/BUILD/googletest-1.13.0/googletest/src/gtest_main.cc
Note: Google Test filter = DISABLED_OutOfBoundsTest.fail
[==========] Running 1 test from 1 test suite.
[----------] Global test environment set-up.
[----------] 1 test from DISABLED_OutOfBoundsTest
[ RUN      ] DISABLED_OutOfBoundsTest.fail
=================================================================
==171560==ERROR: AddressSanitizer: stack-buffer-overflow on address 0x7f4241500034 at pc 0x7f424425955a bp 0x7ffd10d43490 sp 0x7ffd10d43488
WRITE of size 4 at 0x7f4241500034 thread T0
...
...
Address 0x7f4241500034 is located in stack of thread T0 at offset 52 in frame
    #0 0x7f4244259359 in outOfBounds /home/shanep/repos/cpp-project-template/src/lab.cpp:61

  This frame has 1 object(s):
    [32, 52) 'arr' (line 62) <== Memory access at offset 52 overflows this variable
HINT: this may be a false positive if your program uses some custom stack unwind mechanism, swapcontext or vfork
      (longjmp and C++ exceptions *are* supported)
SUMMARY: AddressSanitizer: stack-buffer-overflow /home/shanep/repos/cpp-project-template/src/lab.cpp:66 in outOfBounds
Shadow bytes around the buggy address:
  0x7f42414ffd80: 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
  0x7f42414ffe00: 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
  0x7f42414ffe80: 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
  0x7f42414fff00: 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
  0x7f42414fff80: 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
=>0x7f4241500000: f1 f1 f1 f1 00 00[04]f3 f3 f3 f3 f3 00 00 00 00
  0x7f4241500080: 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
  0x7f4241500100: 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
  0x7f4241500180: 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
  0x7f4241500200: 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
  0x7f4241500280: 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
Shadow byte legend (one shadow byte represents 8 application bytes):
  Addressable:           00
  Partially addressable: 01 02 03 04 05 06 07
  Heap left redzone:       fa
  Freed heap region:       fd
  Stack left redzone:      f1
  Stack mid redzone:       f2
  Stack right redzone:     f3
  Stack after return:      f5
  Stack use after scope:   f8
  Global redzone:          f9
  Global init order:       f6
  Poisoned by user:        f7
  Container overflow:      fc
  Array cookie:            ac
  Intra object redzone:    bb
  ASan internal:           fe
  Left alloca redzone:     ca
  Right alloca redzone:    cb
==171560==ABORTING
```

Play around with the project, see if you can get both of the disabled tests to
pass before you move on to the next task. NOTE: Fixing the failing tests is not
part of you grade, it is just for fun. If you are against having fun you can
skip ahead to Task 2, but be warned skipping fun may make you sad 😢.

## Task 2 - Prepare project

The first thing you need to do is download the header file `lab.h` that was
provided for you in the project description. Replace the entire contents of
`src/lab.h` with the contents of the file you downloaded. Then delete the example
code that is in `src/lab.cpp` and `tests/test-lab.cpp`. You will then have to
stub out the functions in `lab.cpp` so everything will compile, even though nothing
is implemented yet. Move to Task 3 once you have everything compiling.

This project has a preset file to help build the project. You can list all the
presets with `cmake --list-presets`. You can get started right away with the
Address Sanitizer build as shown below. The executable will be located in the
out/build/x64-ASan directory.

```bash
cmake --preset x64-ASan
cmake --build --preset x64-ASan
```

## Task 3 - Write Unit tests

In the **tests** directory is a file named `test-lab.cpp`. Make sure and delete
all the example tests before you start to add your own. You will need to
write at least 1 test for each function defined in `lab.h`. Each test will fail
until you implement the function in `lab.cpp`. This approach is called [Test
Driven Development](https://en.wikipedia.org/wiki/Test-driven_development) and
it is a very powerful tool for writing high quality code. You may have to stub
out some functions in `lab.cpp` to get the tests to compile but resist the urge
to implement any code in `lab.cpp` until you have written the tests!

You can run your tests like this:

```bash
cmake --preset x64-ASan
cmake --build --preset x64-ASan
ctest --preset x64-ASan
```

## Task 4 - Write the code

The `lab.h` file that you downloaded is well documented, your job is to
implement all the functions defined in that file in `lab.cpp`. You are free to
create additional **private** functions in `lab.cpp` if you wish but you are not
allowed to add any additional data to `lab.h`. You are also not allowed to
modify the `main.cpp` file in any way. You do not need to have any unit test for
private functions you create in `lab.cpp`.

## Task 5 - Complete the Retrospective

Once you have completed everything open the file **Retrospective.md** and
complete each section that has a TODO label. You will need to add your name and
email address to the top of the file or your project will not be graded.

## Task 6 - Add, Commit, Push your code

Once you are finished you need to make sure that you have pushed all your code
to GitHub for grading! You can do this by running the following commands in the
root of your project directory. You can run `git status` to see what files have
changed since the last commit.

```bash
git add .
git commit -m "My project is finished"
git push
```

## Task 7 - Bonus

As a bonus for those of you who do the work to get everything working on a
different OS you can claim a bonus of up to 5% of your final project grade. Your
code must configure, build, and run (without errors) on either Windows or MacOS.

## Task 8 - Extra super bonus

You did the lab in rust! You can claim a bonus of up to 10% of your final
project grade. You can claim both the bonus tasks if you wish.
