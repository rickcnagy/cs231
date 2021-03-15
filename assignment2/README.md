# CS231 Assignment 2

Rick Nagy

## Structure

- `standard_deviation_calculator.cpp` provides a
  `double getStandardDeviation(double[] data)` function that calculates the
  standard deviation for the given data array.
- `standard_deviation_test.cpp` is *test* that should not be run in production.
  It asserts that `getStandardDeviation()` returns the right value for a series
  of provided input arrays.
- `standard_deviation_cli.cpp` provides an interactive program that
  takes in a series of doubles from `stdin` and gets their standard deviation.

## Running tests

```sh
g++ standard_deviation_test.cpp standard_deviation_calculator.cpp -o standard_deviation_test && ./standard_deviation_test
```

## Running CLI

```sh
g++ standard_deviation_cli.cpp standard_deviation_calculator.cpp -o standard_deviation_cli && ./standard_deviation_cli
```

## Styling

```sh
clang-format --style=Google *.cpp *.h
```

