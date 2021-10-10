#!/bin/sh

gcc -Wall -Wextra -Werror -o a $(find . -name "*.c" -type f | head -1 | xargs) && ./a && rm a