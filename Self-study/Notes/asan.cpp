$ g++ --std=c++11 -Wall -Werror -pedantic -g -fsanitize=address -fsanitize=undefined asan.cpp -o asan.exe
$ ./asan.exe