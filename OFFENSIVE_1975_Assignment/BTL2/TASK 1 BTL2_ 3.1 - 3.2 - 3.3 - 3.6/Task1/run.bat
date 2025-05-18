@echo off
setlocal enabledelayedexpansion

set BUILD_CMD=g++ -std=c++17 -o main.exe -Iinclude -Itest -Itest\unit_test_Task1 main.cpp ^
test\unit_test_Task1\unit_test_Task1.cpp test\unit_test.cpp ^
src\Position.cpp src\Unit.cpp src\Vehicle.cpp src\Infantry.cpp

for %%f in (test\unit_test_Task1\test_case\*.cpp) do (
    set BUILD_CMD=!BUILD_CMD! %%f
)

echo Building project Task1 with command:
echo %BUILD_CMD%
echo ----------------------------------------

%BUILD_CMD%
if %ERRORLEVEL% EQU 0 (
    echo Build successful!
    echo ----------------------------------------
    echo To run tests, use one of the following commands:
    echo 1. Run all tests: main.exe
    echo 2. Run a specific test: main.exe nameFunctionUnitTest
) else (
    echo Build failed!
    exit /b 1
)
