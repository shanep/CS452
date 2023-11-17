# Overview

Steps to configure, build, run, and test the project, if you are working in the
CS Lab follow the instructions listed in the
[README-KOUNT-LAB.md](README-KOUNT-LAB.md) document instead.

- Configure the project.

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

- There are other build presets available which you can list with `cmake --list-presets`.

## Important Links

- [Course Projects](https://shanepanter.com/cs452/projects/)
- [Google Test Framework](http://google.github.io/googletest/primer.html#simple-tests)

## Project Submission Checklist

- Review the [Grading Rubric](https://shanepanter.com/cs452/projects/grading-rubric.html)
- Make Sure and complete the [Retrospective](Retrospective.md)
- Update the [student.toml](student.toml) file with your information
- Ensure that you have pushed all your code to GitHub
