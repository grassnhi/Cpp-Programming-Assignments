#include "../unit_test_Task3.hpp"

bool UNIT_TEST_Task3::Task316() {
    string name = "Task316";
    stringstream output;

    // Tạo các vector lưu vị trí cho từng loại Terrain Element
    vector<Position*> arrayForest;          // Dùng để khởi tạo Mountain (rừng núi)
    vector<Position*> arrayRiver;           // Dùng để khởi tạo River
    vector<Position*> arrayFortification;   // Dùng để khởi tạo Fortification
    vector<Position*> arrayUrban;           // Dùng để khởi tạo Urban
    vector<Position*> arraySpecialZone;     // Dùng để khởi tạo SpecialZone

    // Thiết lập vị trí cho từng đối tượng:
    // Giả sử: rừng núi (Mountain) được biểu diễn bởi arrayForest
    arrayForest.push_back(new Position(0, 0));   // Phần tử (0,0)
    arrayForest.push_back(new Position(1, 1));   // Phần tử (1,1)
    // Sông (River)
    arrayRiver.push_back(new Position(0, 1));      // Phần tử (0,1)
    // Chiến hào (Fortification)
    arrayFortification.push_back(new Position(1, 0)); // Phần tử (1,0)
    // Khu dân cư (Urban)
    arrayUrban.push_back(new Position(2, 2));      // Phần tử (2,2)
    // Khu phi quân sự (SpecialZone)
    arraySpecialZone.push_back(new Position(2, 1));  // Phần tử (2,1)

    // Tạo BattleField với kích thước 3x3. Các ô không nằm trong vector trên sẽ mặc định là Road.
    int n_rows = 3;
    int n_cols = 3;
    BattleField* bf = new BattleField(n_rows, n_cols, arrayForest, arrayRiver, arrayFortification, arrayUrban, arraySpecialZone);

    output << bf->str() << "\n";

    // Lấy các TerrainElement ở các vị trí cụ thể và kiểm tra kiểu đối tượng bằng dynamic_cast
    TerrainElement* e00 = bf->getElement(0, 0); // mong đợi: Mountain (do nằm trong arrayForest)
    TerrainElement* e01 = bf->getElement(0, 1); // mong đợi: River
    TerrainElement* e10 = bf->getElement(1, 0); // mong đợi: Fortification
    TerrainElement* e11 = bf->getElement(1, 1); // mong đợi: Mountain (arrayForest)
    TerrainElement* e21 = bf->getElement(2, 1); // mong đợi: SpecialZone
    TerrainElement* e22 = bf->getElement(2, 2); // mong đợi: Urban
    TerrainElement* e02 = bf->getElement(0, 2); // không thuộc vector nào → mặc định Road

    output << "Element (0,0) is " 
           << (dynamic_cast<Mountain*>(e00) ? "Mountain" : "Not Mountain") << "\n";
    output << "Element (0,1) is " 
           << (dynamic_cast<River*>(e01) ? "River" : "Not River") << "\n";
    output << "Element (1,0) is " 
           << (dynamic_cast<Fortification*>(e10) ? "Fortification" : "Not Fortification") << "\n";
    output << "Element (1,1) is " 
           << (dynamic_cast<Mountain*>(e11) ? "Mountain" : "Not Mountain") << "\n";
    output << "Element (2,1) is " 
           << (dynamic_cast<SpecialZone*>(e21) ? "SpecialZone" : "Not SpecialZone") << "\n";
    output << "Element (2,2) is " 
           << (dynamic_cast<Urban*>(e22) ? "Urban" : "Not Urban") << "\n";
    output << "Element (0,2) is " 
           << (dynamic_cast<Road*>(e02) ? "Road" : "Not Road") << "\n";

    // Lấy kết quả output dưới dạng string
    string result = output.str();

    // Chuỗi kết quả mong đợi tương ứng
    string expect = "BattleField[n_rows=3,n_cols=3]\n"
                    "Element (0,0) is Mountain\n"
                    "Element (0,1) is River\n"
                    "Element (1,0) is Fortification\n"
                    "Element (1,1) is Mountain\n"
                    "Element (2,1) is SpecialZone\n"
                    "Element (2,2) is Urban\n"
                    "Element (0,2) is Road\n";

    // Cleanup: giải phóng các đối tượng Position được cấp phát trong vector
    for (auto p : arrayForest) delete p;
    for (auto p : arrayRiver) delete p;
    for (auto p : arrayFortification) delete p;
    for (auto p : arrayUrban) delete p;
    for (auto p : arraySpecialZone) delete p;
    delete bf;

    return printResult(result, expect, name);
}