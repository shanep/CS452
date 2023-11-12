# Overview

Steps to configure, build, run, and test the project, if you are working in the
CS Lab follow the instructions listed in the [README-KOUNT-LAB.md](README-KOUNT-LAB.md)
document instead.

- Configure the project. You can list all the presets with `cmake
   --list-presets`. We will use the Address Sanitizer build as shown below.

```bash
cmake --preset x64-ASan
```

- Build the project.

```bash
cmake --build --preset x64-ASan
```

- Assuming that the project successfully built you can run the executable like this:

```bash
./out/build/x64-ASan/myprogram
```

- Assuming that the project successfully built you can run your tests like this:

```bash
ctest --preset x64-ASan
```

## Important Links

- [Project Details](https://shanepanter.com/cs452/)
- [Grading Rubric](https://shanepanter.com/cs452/grading-rubric.html)
- [Google Test Framework](http://google.github.io/googletest/primer.html#simple-tests)

## Project Tasks

TODO: Add a description of the project tasks here.

## Final Task Preparing your project for grading

Read the [grading rubric](https://shanepanter.com/cs452/grading-rubric.html)
and make sure you meet all the requirements.

### Complete the Retrospective

Once you have completed everything open the file **Retrospective.md** and
complete each section that has a TODO label. You will need to add your name and
email address to the top of the file or your project will not be graded.

### Update student.toml

Update update the `student.toml` file with your name and Boise State email
address.

### Add, Commit, Push your code

Once you are finished you need to make sure that you have pushed all your code
to GitHub for grading! You can do this by running the following commands in the
root of your project directory. You can run `git status` to see what files have
changed since the last commit.

```bash
git add .
git commit -m "My project is finished"
git push
```

### Bonus

As a bonus for those of you who do the work to get everything working on at
least one other operating system other than Linux.  You can claim a bonus of up
to 5% of your final project grade. Your code must configure, build, and run
(without errors) on either Windows or MacOS.

### Extra super bonus

You did the lab in [rust](https://www.rust-lang.org/)! You can claim a bonus of up to 10% of your final
project grade. You can claim both the bonus tasks if you wish.
