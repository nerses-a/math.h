# S21 Math Library

Welcome to the S21 Math Library repository. This library provides custom implementations of various mathematical functions, closely mimicking the behavior of the standard math library in C.

## Features

- Implements functions like `abs`, `sin`, `cos`, `sqrt`, `log`, and more.
- Includes a suite of unit tests to verify each function's correctness.
- Supports code coverage analysis and reporting.
- Provides tools for memory leak detection and static code analysis.

## Prerequisites

To use this library, you will need:

- GCC compiler
- GNU Make
- Check (for unit testing)
- Valgrind (for memory leak detection)
- Cppcheck (for static analysis)
- clang-format (for code styling)
- lcov (for generating coverage reports)
- Appropriate tools for opening HTML files depending on your OS (`xdg-open` on Linux, `open` on MacOS)

### Installing Dependencies

#### For Debian/Ubuntu-based Linux:

```bash
sudo apt-get install gcc make valgrind cppcheck clang-format lcov check libsubunit-dev libcheck-dev
