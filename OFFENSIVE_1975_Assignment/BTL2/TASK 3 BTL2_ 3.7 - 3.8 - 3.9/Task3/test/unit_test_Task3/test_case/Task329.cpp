#include "../unit_test_Task3.hpp"

bool UNIT_TEST_Task3::Task329() {
    string name = "Task329";
    stringstream output;

    // Test: Kiểm tra các chức năng của BattleField, bao gồm hàm getElement và str().
    vector<Position*> arrayForest;          // Mountain
    vector<Position*> arrayRiver;           // River
    vector<Position*> arrayFortification;   // Fortification
    vector<Position*> arrayUrban;           // Urban
    vector<Position*> arraySpecialZone;     // SpecialZone

    arrayForest.push_back(new Position(0, 0));
    arrayRiver.push_back(new Position(0, 1));
    arrayFortification.push_back(new Position(1, 0));
    arrayUrban.push_back(new Position(1, 1));
    arraySpecialZone.push_back(new Position(2, 2));

    int n_rows = 3, n_cols = 3;
    BattleField* bf = new BattleField(n_rows, n_cols, arrayForest, arrayRiver, arrayFortification, arrayUrban, arraySpecialZone);

    // Truy vấn một vài vị trí hợp lệ và không hợp lệ.
    TerrainElement* e00 = bf->getElement(0, 0); // Mong đợi: Mountain
    TerrainElement* e01 = bf->getElement(0, 1); // River
    TerrainElement* e10 = bf->getElement(1, 0); // Fortification
    TerrainElement* e11 = bf->getElement(1, 1); // Urban
    TerrainElement* e22 = bf->getElement(2, 2); // SpecialZone
    TerrainElement* e_invalid = bf->getElement(3, 0); // ngoài phạm vi, mong đợi nullptr

    output << bf->str() << "\n";
    output << "e00 is " << (dynamic_cast<Mountain*>(e00) ? "Mountain" : "Not Mountain") << "\n";
    output << "e01 is " << (dynamic_cast<River*>(e01) ? "River" : "Not River") << "\n";
    output << "e10 is " << (dynamic_cast<Fortification*>(e10) ? "Fortification" : "Not Fortification") << "\n";
    output << "e11 is " << (dynamic_cast<Urban*>(e11) ? "Urban" : "Not Urban") << "\n";
    output << "e22 is " << (dynamic_cast<SpecialZone*>(e22) ? "SpecialZone" : "Not SpecialZone") << "\n";
    output << "Invalid element is " << (e_invalid == nullptr ? "null" : "not null") << "\n";

    string result = output.str();
    // Giá trị mong đợi được xây dựng dựa trên logic trên.
    string expect = "BattleField[n_rows=3,n_cols=3]\n"
                    "e00 is Mountain\n"
                    "e01 is River\n"
                    "e10 is Fortification\n"
                    "e11 is Urban\n"
                    "e22 is SpecialZone\n"
                    "Invalid element is null\n";

    // Cleanup
    delete bf;
    for (auto p : arrayForest) delete p;
    for (auto p : arrayRiver) delete p;
    for (auto p : arrayFortification) delete p;
    for (auto p : arrayUrban) delete p;
    for (auto p : arraySpecialZone) delete p;

    return printResult(result, expect, name);
}