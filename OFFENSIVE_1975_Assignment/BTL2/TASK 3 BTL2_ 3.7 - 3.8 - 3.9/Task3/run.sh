#!/bin/bash

BUILD_CMD="g++ -std=c++17 -o main -Iinclude -Itest -Itest/unit_test_Task3 -g main.cpp \
test/unit_test_Task3/unit_test_Task3.cpp test/unit_test.cpp \
src/Position.cpp src/Unit.cpp src/Vehicle.cpp src/Infantry.cpp \
src/Army.cpp src/UnitList.cpp src/LiberationArmy.cpp src/ARVN.cpp \
src/BattleField.cpp src/Configuration.cpp src/TerrainElement.cpp \
test/unit_test_Task3/test_case/*.cpp"

echo "Building project Task3 VOTIEN with command:"
echo "$BUILD_CMD"
echo "----------------------------------------"
eval $BUILD_CMD
if [ $? -eq 0 ]; then
    echo "Build successful!"
    echo "----------------------------------------"
    echo "To run tests, use one of the following commands:"
    echo "1. Run all tests: ./main "
    echo "2. Run a specific test: ./main nameFunctionUnitTest"
else
    echo "Build failed!"
    exit 1
fi
