# Overview

This project is divided into 5 tasks. Each task will be explained in detail and
you are expected to complete each task in order. This project has been tested on
Linux, Windows, and MacOS using github actions. In _theory_ you could use any
operating system you wish to develop and test your solution. However, the
reality of writing native cross platform code is a quagmire of sadness and
despair. Additionally, supporting 3 operating systems and their respective
development environments is beyond the capacity of your instructor and GA/TA.

Thus, your code will be graded on the departments lab machines, office hours
with your instructor or TA/GA will be conducted in the departments lab machines,
and all questions about the project will be answered in the context of the
departments lab machines. If you choose to use a different operating system you
are on your own to figure out how to get the project to build and run. **ALL**
instructions below assume you are working on the departments lab machines.

## Task 0 - Pre-reading

- [Grading Rubric](https://shanepanter.com/cs452/grading-rubric.html)
- (optional)[Cross Platform Notes](https://shanepanter.com/cs452/cross-platform.html)

## Task 1 - Build

This project has a preset file to help build the project. You can list all the
presets with `cmake --list-presets`. You can get started right away with the
Address Sanitizer build as shown below. The executable will be located in the
out/build/x64-ASan directory.

```bash
cmake --preset x64-ASan
cmake --build --preset x64-ASan
```

## Task 2 - Write Unit tests

In the **tests** directory is a file named `test-lab.cpp`. You will need to
write at least 1 test for each function defined in `lab.h`. Each test will fail
until you implement the function in `lab.cpp`. This approach is called [Test
Driven Development](https://en.wikipedia.org/wiki/Test-driven_development) and
it is a very powerful tool for writing high quality code. You may have to stub
out some functions in `lab.cpp` to get the tests to compile but resist the urge
to implement any code in `lab.cpp` until you have written the tests!

## Task 3 - Write the code

In the **src** directory you will find a file named `lab.h` that is well
documented. Your job is to implement all the functions defined in that file in
`lab.cpp`. You are free to create additional **private** functions in `lab.cpp`
if you wish but you are not allowed to modify `lab.h` in any way. You are also
not allowed to modify the `main.cpp` file in any way. You do not need to have
any unit test for private functions you create in `lab.cpp`.

## Task 4 - Complete the Retrospective

Once you have completed the tests an implementation open the file
**Retrospective.md** and complete each section that has a TODO label. You will
need to add your name and email address to the top of the file or your project
will not be graded.

## Task 5 - Add, Commit, Push your code

Once you are finished you need to make sure that you have pushed all your code
to GitHub for grading! You can do this by running the following commands in the
root of your project directory. You can run `git status` to see what files have
changed since the last commit.

```bash
git add .
git commit -m "My project is finished"
git push
```

## Task 6 - Bonus

As a bonus for those of you who do the work to get everything working on a
different OS you can claim a bonus of up to 5% of your final project grade. For
more details on how to claim this bonus see the appropriate assignment in
Canvas.
