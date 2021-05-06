#!/bin/bash
case "$1" in
"list")
    rm -rf a.out
    clang++ -Wall -Wextra -Werror tests/list_test.cpp
    ./a.out;;
"vector")
    rm -rf a.out
    clang++ -Wall -Wextra -Werror tests/vector_test.cpp
    ./a.out;;
"queue")
    rm -rf a.out
    clang++ -Wall -Wextra -Werror tests/queue_test.cpp
    ./a.out;;
"stack")
    rm -rf a.out
    clang++ -Wall -Wextra -Werror tests/stack_test.cpp
    ./a.out;;
"map")
    rm -rf a.out
    clang++ -Wall -Wextra -Werror tests/map_test.cpp
    ./a.out;;
"valgrind")
    valgrind --leak-check=full ./a.out;;
*)
    echo "Enter the name of container";;
esac
# ./a.out
