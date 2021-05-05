#!/bin/bash
case "$1" in
"list")
    clang++ -Wall -Wextra -Werror tests/list_test.cpp;;
"vector")
    clang++ -Wall -Wextra -Werror tests/vector_test.cpp;;
"queue")
    echo "Vector is not exist";;
"stack")
    echo "Vector is not exist";;
"map")
    echo "Vector is not exist";;
"valgrind")
    valgrind --leak-check=full ./a.out;;
*)
    clang++ -Wall -Wextra -Werror tests/*.cpp;;
esac
./a.out
