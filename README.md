# Overview

Steps to configure, build, run, and test the project, if you are working in the
CS Lab follow the instructions listed in the
[README-KOUNT-LAB.md](README-KOUNT-LAB.md) document instead.

## Important Links

- [Course Projects](https://shanepanter.com/cs452/projects/)
- [Google Test Framework](http://google.github.io/googletest/primer.html#simple-tests)

## Building

Configure the project.

```bash
cmake --preset x64-ASan
```

Build the project.

```bash
cmake --build --preset x64-ASan
```
Assuming that the project successfully built you can run the executable like
this:

```bash
./out/build/x64-ASan/myprogram
```

There are other build presets available which you can list with `cmake
--list-presets`.

## Testing

Assuming that the project successfully built you can run your tests like this:

```bash
ctest --preset x64-ASan
```

## Code coverage

Generate the code coverage reports with the following:

```bash
cmake --preset x64-Coverage
```

```bash
cmake --build --preset x64-Coverage
```

The coverage report is located in file
`out/build/x64-Coverage/coverage/index.html`. You can use the
[Live Preview](https://marketplace.visualstudio.com/items?itemName=ms-vscode.live-server)
plugin to view the report.

## Project Submission Checklist

- Review the [Grading Rubric](https://shanepanter.com/cs452/projects/grading-rubric.html)
- Make Sure and complete the [Retrospective](Retrospective.md)
- Update the [student.toml](student.toml) file with your information
- Ensure that you have pushed all your code to GitHub
