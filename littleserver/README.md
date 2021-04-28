# littleserver
_A little HTTP server_

Rick Nagy

## Building and running

```sh
g++ src/*.cpp -o littleserver && ./littleserver
```

This should output something like: `Listening on http://localhost:64998`. Go to that URL to see `littleserver` in action!

This should work on any platform but it hasn't been tested on Windows.

## Formatting

```sh
clang-format src/*.cpp
```
