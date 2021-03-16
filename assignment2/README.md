# CS231 Assignment 2

Rick Nagy

## Structure

- `calculator.cpp` provides a
  `Calculator` class that takes in a data array and its length and can calculate
  standard deviation and mean.
- `calculator_test.cpp` is *test* that should not be run in production.
  It asserts that `Calculator.getMean()` and `Calculator.getStandardDeviation()`
  returns the right value for a series of provided input arrays.
- `calculator_cli.cpp` provides an interactive program that
  takes in a series of doubles from `stdin` and calculates their mean and
  standard deviation.

## Running tests

```sh
g++ calculator_test.cpp calculator.cpp -o calculator_test && ./calculator_test
```

## Running CLI

```sh
g++ calculator_cli.cpp calculator.cpp -o calculator_cli && ./calculator_cli
```

## Styling

```sh
clang-format --style=Google *.cpp *.h
```

