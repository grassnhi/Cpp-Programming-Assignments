#!/bin/bash

# Hàm hiển thị hướng dẫn sử dụng
usage() {
    echo "Usage: $0 [options] [test_name]"
    echo "Options:"
    echo "  -h, --help      Show this help message"
    echo "  -l, --list      List all available test cases"
    echo "Arguments:"
    echo "  test_name       Name of the test case to run (optional)"
    echo "                  Use wildcard (*) to run multiple tests (e.g., math_*)"
    exit 1
}

# Hàm liệt kê test cases
list_tests() {
    echo "Available test cases:"
    find tests -type d -mindepth 1 -maxdepth 1 -exec basename {} \;
    exit 0
}

# Xử lý tham số
while [[ $# -gt 0 ]]; do
    case "$1" in
        -h|--help)
            usage
            ;;
        -l|--list)
            list_tests
            ;;
        *)
            test_name="$1"
            shift
            break
            ;;
    esac
    shift
done

# Biên dịch test runner nếu chưa có
if [ ! -f "test_runner.exe" ]; then
    echo "Compiling test runner..."
    g++ -std=c++11 test_runner.cpp hcmcampaign.cpp -o test_runner.exe -I.
    if [ $? -ne 0 ]; then
        echo "Compilation failed!"
        exit 1
    fi
fi

# Chạy test runner
if [ -z "$test_name" ]; then
    ./test_runner.exe
else
    ./test_runner.exe "$test_name"
fi