@echo off
setlocal enabledelayedexpansion

set BUILD_CMD=g++ -std=c++17 -o main -Iinclude -Itest -Itest\unit_test_Task4 main.cpp ^
test\unit_test_Task4\unit_test_Task4.cpp test\unit_test.cpp ^
src\hcmcampaign.cpp

for %%f in (test\unit_test_Task4\test_case\*.cpp) do (
    set BUILD_CMD=!BUILD_CMD! %%f
)

echo Building project Task2 with command:
echo !BUILD_CMD!
echo ----------------------------------------

call !BUILD_CMD!
if %ERRORLEVEL% equ 0 (
    echo Build successful!
    echo ----------------------------------------
    echo To run tests, use one of the following commands:
    echo 1. Run all tests: .\main
    echo 2. Run a specific test: .\main nameFunctionUnitTest
) else (
    echo Build failed!
    exit /b 1
)