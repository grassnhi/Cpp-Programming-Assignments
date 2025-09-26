CXX = g++
CXXFLAGS = -std=c++11
TARGET = test_runner
SOURCE = test_runner.cpp

# Thư mục mặc định
TEST_DIR = tests
EXPECTED_DIR = expected

.PHONY: all clean setup test help

all: $(TARGET)

$(TARGET): $(SOURCE)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(SOURCE) -I .

setup: $(TARGET)
	@echo "Tạo cấu trúc thư mục..."
	@mkdir -p $(TEST_DIR) $(EXPECTED_DIR)
	@echo "Tạo test cases mẫu..."
	@$(MAKE) create-samples
	@echo "Setup hoàn tất!"

create-samples:
	@echo '#include <iostream>' > $(TEST_DIR)/test01_hello.cpp
	@echo 'using namespace std;' >> $(TEST_DIR)/test01_hello.cpp
	@echo 'int main() {' >> $(TEST_DIR)/test01_hello.cpp
	@echo '    cout << "Hello, World!" << endl;' >> $(TEST_DIR)/test01_hello.cpp
	@echo '    return 0;' >> $(TEST_DIR)/test01_hello.cpp
	@echo '}' >> $(TEST_DIR)/test01_hello.cpp
	@echo 'Hello, World!' > $(EXPECTED_DIR)/test01_hello.txt
	
	@echo '#include <iostream>' > $(TEST_DIR)/test02_math.cpp
	@echo 'using namespace std;' >> $(TEST_DIR)/test02_math.cpp
	@echo 'int main() {' >> $(TEST_DIR)/test02_math.cpp
	@echo '    int a = 15, b = 7;' >> $(TEST_DIR)/test02_math.cpp
	@echo '    cout << "Addition: " << (a + b) << endl;' >> $(TEST_DIR)/test02_math.cpp
	@echo '    cout << "Subtraction: " << (a - b) << endl;' >> $(TEST_DIR)/test02_math.cpp
	@echo '    cout << "Multiplication: " << (a * b) << endl;' >> $(TEST_DIR)/test02_math.cpp
	@echo '    return 0;' >> $(TEST_DIR)/test02_math.cpp
	@echo '}' >> $(TEST_DIR)/test02_math.cpp
	@echo 'Addition: 22' > $(EXPECTED_DIR)/test02_math.txt
	@echo 'Subtraction: 8' >> $(EXPECTED_DIR)/test02_math.txt
	@echo 'Multiplication: 105' >> $(EXPECTED_DIR)/test02_math.txt

	@echo '#include <iostream>' > $(TEST_DIR)/test03_loop.cpp
	@echo '#include <vector>' >> $(TEST_DIR)/test03_loop.cpp
	@echo 'using namespace std;' >> $(TEST_DIR)/test03_loop.cpp
	@echo 'int main() {' >> $(TEST_DIR)/test03_loop.cpp
	@echo '    vector<int> nums = {2, 4, 6, 8, 10};' >> $(TEST_DIR)/test03_loop.cpp
	@echo '    cout << "Even numbers:" << endl;' >> $(TEST_DIR)/test03_loop.cpp
	@echo '    for (int num : nums) {' >> $(TEST_DIR)/test03_loop.cpp
	@echo '        cout << num << " ";' >> $(TEST_DIR)/test03_loop.cpp
	@echo '    }' >> $(TEST_DIR)/test03_loop.cpp
	@echo '    cout << endl;' >> $(TEST_DIR)/test03_loop.cpp
	@echo '    return 0;' >> $(TEST_DIR)/test03_loop.cpp
	@echo '}' >> $(TEST_DIR)/test03_loop.cpp
	@echo 'Even numbers:' > $(EXPECTED_DIR)/test03_loop.txt
	@echo '2 4 6 8 10' >> $(EXPECTED_DIR)/test03_loop.txt

test: $(TARGET)
	@echo "Chạy tất cả test cases..."
	@./$(TARGET) $(TEST_DIR) $(EXPECTED_DIR)

test-single: $(TARGET)
	@if [ -z "$(name)" ]; then \
		echo "Sử dụng: make test-single name=test01_hello"; \
	else \
		echo "Chạy test: $(name)"; \
		./$(TARGET) $(TEST_DIR) $(EXPECTED_DIR) $(name); \
	fi

add-test:
	@if [ -z "$(name)" ]; then \
		echo "Sử dụng: make add-test name=test04_newtest"; \
		echo "Sau đó chỉnh sửa files:"; \
		echo "  $(TEST_DIR)/$(name).cpp"; \
		echo "  $(EXPECTED_DIR)/$(name).txt"; \
	else \
		echo "Tạo test template: $(name)"; \
		echo '#include "hcmcampaign.h"' > $(TEST_DIR)/$(name).cpp; \
		echo 'using namespace std;' >> $(TEST_DIR)/$(name).cpp; \
		echo '' >> $(TEST_DIR)/$(name).cpp; \
		echo 'int main() {' >> $(TEST_DIR)/$(name).cpp; \
		echo '    // TODO: Write code here' >> $(TEST_DIR)/$(name).cpp; \
		echo '    cout << "Hello from $(name)" << endl;' >> $(TEST_DIR)/$(name).cpp; \
		echo '    return 0;' >> $(TEST_DIR)/$(name).cpp; \
		echo '}' >> $(TEST_DIR)/$(name).cpp; \
		echo 'Hello from $(name)' > $(EXPECTED_DIR)/$(name).txt; \
		echo "Đã tạo:"; \
		echo "  $(TEST_DIR)/$(name).cpp"; \
		echo "  $(EXPECTED_DIR)/$(name).txt"; \
		echo "Hãy chỉnh sửa các file này theo test case của bạn."; \
	fi

list-tests:
	@echo "Danh sách test cases:"
	@ls -1 $(TEST_DIR)/*.cpp 2>/dev/null | sed 's/.*\///' | sed 's/\.cpp$$//' || echo "Chưa có test case nào"

clean:
	rm -f $(TARGET)
	rm -rf $(TEST_DIR) $(EXPECTED_DIR)

clean-temp:
	rm -f /tmp/test_program*

help:
	@echo "Test Runner System - Makefile Commands"
	@echo ""
	@echo "Thiết lập:"
	@echo "  make setup          - Tạo thư mục và test cases mẫu"
	@echo "  make                - Compile test runner"
	@echo ""
	@echo "Chạy test:"
	@echo "  make test           - Chạy tất cả test cases"
	@echo "  make test-single name=testname - Chạy một test cụ thể"
	@echo ""
	@echo "Quản lý test:"
	@echo "  make add-test name=testname    - Tạo test template mới"
	@echo "  make list-tests               - Liệt kê tất cả test cases"
	@echo ""
	@echo "Dọn dẹp:"
	@echo "  make clean          - Xóa executable và test files"
	@echo "  make clean-temp     - Xóa file tạm"
	@echo ""
	@echo "Ví dụ:"
	@echo "  make setup"
	@echo "  make test"
	@echo "  make add-test name=test04_array"
	@echo "  make test-single name=test01_hello"