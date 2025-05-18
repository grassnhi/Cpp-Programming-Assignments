#include "../unit_test_Task3.hpp"

bool UNIT_TEST_Task3::Task324() {
    string name = "Task324";
    stringstream output;

    // Tạo một BattleField kích thước 2x2, không có vùng đặc biệt (tất cả sẽ là Road)
    vector<Position*> empty;
    int n_rows = 2, n_cols = 2;
    BattleField* bf = new BattleField(n_rows, n_cols, empty, empty, empty, empty, empty);
    
    // Kiểm tra getElement với các chỉ số nằm ngoài phạm vi
    TerrainElement* e_neg   = bf->getElement(-1, 0);
    TerrainElement* e_neg2  = bf->getElement(0, -1);
    TerrainElement* e_oob1  = bf->getElement(2, 0);
    TerrainElement* e_oob2  = bf->getElement(0, 2);
    
    output << "Out of bounds: " 
           << (e_neg == nullptr ? "null" : "not null") << ", "
           << (e_neg2 == nullptr ? "null" : "not null") << ", "
           << (e_oob1 == nullptr ? "null" : "not null") << ", "
           << (e_oob2 == nullptr ? "null" : "not null") << "\n";
    output << bf->str();
    
    string result = output.str();
    string expect = "Out of bounds: null, null, null, null\nBattleField[n_rows=2,n_cols=2]";
    
    delete bf;
    return printResult(result, expect, name);
}