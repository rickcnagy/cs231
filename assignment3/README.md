# CS231 Assignment 2

Rick Nagy

`vehicle_test.cpp` is *test* that should not be run in production. It constructs
several vehicle types and tests that each of them perform as expected. It also
serves as the main entrypoint for the submission.

## Running tests

```sh
g++ *.cpp -o vehicle_test && ./vehicle_test
```

To recompile on change:

```sh
fswatch -0 . | while read -d "" event; do g++ *.cpp; done
```

## Styling

```sh
clang-format --style=Google *.cpp *.h
```

