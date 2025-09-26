#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <vector>
#include <windows.h>
#include <shlwapi.h>
#include <direct.h>
#include <iomanip> // for setw
#include <algorithm>

#pragma comment(lib, "shlwapi.lib")

using namespace std;

// Hàm kiểm tra xem có phải là file thường
bool isRegularFile(const string& path) {
    DWORD attrib = GetFileAttributesA(path.c_str());
    return (attrib != INVALID_FILE_ATTRIBUTES && 
           !(attrib & FILE_ATTRIBUTE_DIRECTORY));
}

// Hàm lấy tất cả file trong thư mục có phần mở rộng cụ thể
vector<string> getFilesWithExtension(const string& directory, const string& extension) {
    vector<string> files;
    WIN32_FIND_DATAA findData;
    HANDLE hFind = FindFirstFileA((directory + "\\*" + extension).c_str(), &findData);

    if (hFind == INVALID_HANDLE_VALUE) {
        cerr << "Không thể mở thư mục: " << directory << endl;
        return files;
    }

    do {
        string filename(findData.cFileName);
        if (filename == "." || filename == "..") continue;
        
        string fullPath = directory + "\\" + filename;
        if (!isRegularFile(fullPath)) continue;
        
        // Trích xuất tên test case (loại bỏ phần mở rộng)
        string baseName = filename.substr(0, filename.size() - extension.size());
        files.push_back(baseName);
    } while (FindNextFileA(hFind, &findData) != 0);

    FindClose(hFind);
    return files;
}

// Hàm so sánh 2 file
bool compareFiles(const string& file1, const string& file2) {
    ifstream f1(file1);
    ifstream f2(file2);
    
    if (!f1.is_open() || !f2.is_open()) 
        return false;
    
    string line1, line2;
    while (getline(f1, line1) && getline(f2, line2)) {
        if (line1 != line2) 
            return false;
    }
    
    return f1.eof() && f2.eof();
}

// Hàm đọc nội dung file theo dòng
vector<string> readFileLines(const string& path) {
    vector<string> lines;
    ifstream file(path);
    if (file.is_open()) {
        string line;
        while (getline(file, line)) {
            lines.push_back(line);
        }
    }
    return lines;
}

// Hàm in kết quả so sánh dạng bảng
void printComparison(const vector<string>& expected, const vector<string>& actual) {
    const int colWidth = 40; // Độ rộng mỗi cột
    const int maxLines = 20; // Giới hạn số dòng hiển thị
    
    // Header
    cout << left << setw(colWidth) << "Expected" << " | Actual Output\n";
    cout << string(colWidth, '-') << "-|-" << string(colWidth, '-') << "\n";
    
    // Tính số dòng cần hiển thị
    size_t numLines = min(max(expected.size(), actual.size()), static_cast<size_t>(maxLines));
    
    for (size_t i = 0; i < numLines; i++) {
        string exp = (i < expected.size()) ? expected[i] : "";
        string act = (i < actual.size()) ? actual[i] : "";
        
        // Giới hạn độ dài nếu quá dài
        if (exp.length() > colWidth) exp = exp.substr(0, colWidth-3) + "...";
        if (act.length() > colWidth) act = act.substr(0, colWidth-3) + "...";
        
        cout << left << setw(colWidth) << exp << " | " << act << "\n";
    }
    
    // Thông báo nếu bị cắt
    if (expected.size() > maxLines || actual.size() > maxLines) {
        cout << "\n[...] Hiển thị " << numLines << "/" << max(expected.size(), actual.size()) << " dòng\n";
    }
}


int main(int argc, char* argv[]) {
    const string testDir = "tests";
    const string expectedDir = "expected";
    const string cppExt = ".cpp";
    const string expectedExt = ".txt";
    
    // Tạo thư mục build nếu chưa tồn tại
    _mkdir("build");

    // Lấy danh sách test cases
    vector<string> testCases = getFilesWithExtension(testDir, cppExt);
    if (testCases.empty()) {
        cout << "Không tìm thấy test cases nào trong thư mục " << testDir << endl;
        return 1;
    }

        // Xử lý tham số dòng lệnh
    string targetTest;
    if (argc > 1) {
        targetTest = argv[1];
        
        // Kiểm tra test case có tồn tại không
        auto it = find(testCases.begin(), testCases.end(), targetTest);
        if (it == testCases.end()) {
            cerr << "Test case '" << targetTest << "' không tồn tại!" << endl;
            cerr << "Các test case có sẵn: ";
            for (const auto& t : testCases) cerr << t << " ";
            cerr << endl;
            return 1;
        }
        
        // Chỉ chạy test case được chỉ định
        testCases = {targetTest};
    }


    for (const auto& testName : testCases) {
        string sourceFile = testDir + "\\" + testName + cppExt;
        string expectedFile = expectedDir + "\\" + testName + expectedExt;
        string outputFile = "build\\" + testName + "_output.txt";
        string executable = "build\\" + testName + ".exe";

        // Kiểm tra file expected tồn tại
        ifstream f(expectedFile);
        if (!f.is_open()) {
            cerr << "⚠️ " << testName << ": Không tìm thấy file expected " << expectedFile << endl;
            continue;
        }

        // Biên dịch (sử dụng Visual C++ hoặc MinGW)
        string compileCmd;
        #ifdef _MSC_VER
            // Visual Studio Compiler
            compileCmd = "cl /EHsc /Fe:" + executable + " " + sourceFile + " > nul";
        #else
            // MinGW/GCC
            compileCmd = "g++ -std=c++11 -o " + executable + " " + sourceFile + " hcmcampaign.cpp -I . > nul";
        #endif
        
        int compileResult = system(compileCmd.c_str());
        
        if (compileResult != 0) {
            cerr << "❌ " << testName << ": Biên dịch thất bại\n";
            continue;
        }

        // Chạy chương trình
        string runCmd = executable + " > " + outputFile + " 2>&1";
        system(runCmd.c_str());

        // Đọc nội dung file
        vector<string> expectedLines = readFileLines(expectedFile);
        vector<string> actualLines = readFileLines(outputFile);

        // So sánh nội dung
        bool passed = (expectedLines == actualLines);
        
        if (passed) {
            cout << "OK " << testName << ": PASSED\n";
        } else {
            cerr << "" << testName << ": FAILED\n";
            cerr << "   Output:   " << outputFile << "\n";
            cerr << "   Expected: " << expectedFile << "\n";
            
            // Hiển thị bảng so sánh
            cout << "\n=============================================\n";
            cout << " COMPARISON FOR TEST: " << testName << "\n";
            cout << "=============================================\n";
            printComparison(expectedLines, actualLines);
            cout << "=============================================\n\n";
        }
    }

    return 0;
}