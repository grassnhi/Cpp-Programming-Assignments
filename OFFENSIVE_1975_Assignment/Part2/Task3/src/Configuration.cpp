#include "Configuration.h"

// * Hint: Bạn có thể thêm hoặc thay thế các phương thức khác để truy cập các thành viên riêng tư nếu cần thiết.
void Configuration::extractPosition(const string& data, vector<Position*>& target) {
    stringstream ss(data);
    string pos;
    while (getline(ss, pos, ')')) {
        if (!pos.empty()) {
            pos += ")"; // restore the closing parenthesis
            target.push_back(new Position(pos));
            ss.ignore(); // skip comma
            // cout << "read: " << pos << endl;
        }
    }
    // for(int i = 0; i < (int)target.size(); i++){
    //     cout << "Check: " << target[i]->str() << " ";
    // }
    // cout << endl;
}

Configuration::Configuration(const string& filepath){
    ifstream file(filepath.c_str());
    string line;
    while (getline(file, line)){
        if(line.find("NUM_ROWS=") == 0){
            this->num_rows = stoi(line.substr(9));
        }else if(line.find("NUM_COLS=") == 0){
            this->num_cols = stoi(line.substr(9));
        }else if(line.find("ARRAY_FOREST=") == 0){
            // cout << "ARRAY_FOREST: ";
            extractPosition(line.substr(14), this->arrayForest);
            // for(int i = 0; i < (int)arrayForest.size(); i++){
            //     cout << "Check: " << arrayForest[i]->str() << " ";
            // }
        }else if(line.find("ARRAY_RIVER=") == 0){
            extractPosition(line.substr(13), this->arrayRiver);
        }else if(line.find("ARRAY_FORTIFICATION=") == 0){
            extractPosition(line.substr(21), this->arrayFortification);
        }else if(line.find("ARRAY_URBAN=") == 0){
            extractPosition(line.substr(13), this->arrayUrban);
        }else if(line.find("ARRAY_SPECIAL_ZONE=") == 0){
            extractPosition(line.substr(20), this->arraySpecialZone);
        }else if(line.find("UNIT_LIST=") == 0){
            string unitsStr = line.substr(10); // after UNIT_LIST=
            unitsStr = unitsStr.substr(1, unitsStr.length() - 2); // remove [ ]

            // cout << "hey: " << unitsStr << endl;
            
            vector<string> unitEntries;
            string current = "";
            int parenCount = 0;
            bool tp = false;

            for(int i = 0; i < (int)unitsStr.length(); i++){
                char ch = unitsStr[i];
                
                current += ch;

                if(ch == '('){
                    parenCount++;
                    tp = true;
                }else if(ch == ')'){
                    parenCount--;
                }

                // cout << ch << " pa:" << parenCount << " cur:" << current << " tp:" << tp << endl;

                if(parenCount == 0 && !current.empty() && tp){
                    tp = false;
                    unitEntries.push_back(current);
                    // cout << current << ":";
                    current = "";
                    if(i+1 < unitsStr.length() && unitsStr[i+1] == ','){
                        i++;
                    }
                }
            }

            for(int i = 0; i < (int)unitEntries.size(); i++){
                string entry = unitEntries[i];
                int pa1 = entry.find('(');
                int pa2 = entry.find_last_of(')');

                // cout << " halo: " << entry << ": " << pa1 << " - " << pa2;

                if(pa1 == string::npos || pa2 == string::npos){
                    continue;
                }

                // cout << "\nhalo: " << entry << ": " << pa1 << " - " << pa2;

                string type = entry.substr(0, pa1);
                string args = entry.substr(pa1 + 1, pa2 - pa1 - 1);

                // cout << " type: " << type;

                stringstream ss(args);
                string qua, wei, pos, own;
                char com;

                getline(ss, qua, ',');
                getline(ss, wei, ',');
                getline(ss, pos, ')');
                pos += ")";
                ss.ignore(); // skip comma
                getline(ss, own);

                // cout << " own: " << own;

                int quantity = stoi(qua);
                int weight = stoi(wei);
                Position position(pos);
                int owner = stoi(own);

                // cout << " - " << owner;

                Unit* unit = nullptr;

                if(type == "SNIPER"){
                    unit = new Infantry(quantity, weight, position, SNIPER);
                }else if(type == "ANTIAIRCRAFTSQUAD"){
                    unit = new Infantry(quantity, weight, position, ANTIAIRCRAFTSQUAD);
                }else if(type == "MORTARSQUAD"){
                    unit = new Infantry(quantity, weight, position, MORTARSQUAD);
                }else if(type == "ENGINEER"){
                    unit = new Infantry(quantity, weight, position, ENGINEER);
                }else if(type == "SPECIALFORCES"){
                    unit = new Infantry(quantity, weight, position, SPECIALFORCES);
                }else if(type == "REGULARINFANTRY"){
                    unit = new Infantry(quantity, weight, position, REGULARINFANTRY);
                }else if(type == "TRUCK"){
                    unit = new Vehicle(quantity, weight, position, TRUCK);
                }else if(type == "MORTAR"){
                    unit = new Vehicle(quantity, weight, position, MORTAR);
                }else if(type == "ANTIAIRCRAFT"){
                    unit = new Vehicle(quantity, weight, position, ANTIAIRCRAFT);
                }else if(type == "ARMOREDCAR"){
                    unit = new Vehicle(quantity, weight, position, ARMOREDCAR);
                }else if(type == "APC"){
                    unit = new Vehicle(quantity, weight, position, APC);
                }else if(type == "ARTILLERY"){
                    unit = new Vehicle(quantity, weight, position, ARTILLERY);
                }else if(type == "TANK"){
                    unit = new Vehicle(quantity, weight, position, TANK);
                }

                if(unit){
                    // cout << "Owner: " << owner;
                    if(owner){
                        ARVNUnits.push_back(unit);
                        // cout << " -> ARV okila ";
                    }else{
                        liberationUnits.push_back(unit);
                        // cout << " -> LBR okila ";
                    }
                    // cout << endl;
                }
            }
        }else if(line.find("EVENT_CODE=") == 0){
            this->eventCode = stoi(line.substr(11));
            // cout << this->eventCode << endl;
            if(this->eventCode <= 0){
                this->eventCode = 0;
            }else if(this->eventCode > 100){
                this->eventCode = this->eventCode % 100;
            }
            // cout << this->eventCode << endl;
        }
    }
    file.close();
}

Configuration::~Configuration(){
    for(int i = 0; i < (int)arrayForest.size(); i++){
        delete arrayForest[i];
    }
    for(int i = 0; i < (int)arrayFortification.size(); i++){
        delete arrayFortification[i];
    }
    for(int i = 0; i < (int)arrayRiver.size(); i++){
        delete arrayRiver[i];
    }
    for(int i = 0; i < (int)arraySpecialZone.size(); i++){
        delete arraySpecialZone[i];
    }
    for(int i = 0; i < (int)arrayUrban.size(); i++){
        delete arrayUrban[i];
    }

    for(int i = 0; i < (int)liberationUnits.size(); i++){
        delete liberationUnits[i];
    }
    for(int i = 0; i < (int)ARVNUnits.size(); i++){
        delete ARVNUnits[i];
    }
}


int Configuration::getNumRows() const {
    return num_rows;
}

int Configuration::getNumCols() const {
    return num_cols;
}

const vector<Position*>& Configuration::getArrayForest() const {
    return arrayForest;
}

const vector<Position*>& Configuration::getArrayRiver() const {
    return arrayRiver;
}

const vector<Position*>& Configuration::getArrayFortification() const {
    return arrayFortification;
}

const vector<Position*>& Configuration::getArrayUrban() const {
    return arrayUrban;
}

const vector<Position*>& Configuration::getArraySpecialZone() const {
    return arraySpecialZone;
}

const vector<Unit*>& Configuration::getLiberationUnits() const {
    return liberationUnits;
}

const vector<Unit*>& Configuration::getARVNUnits() const {
    return ARVNUnits;
}

int Configuration::getEventCode() const {
    return eventCode;
}

string Configuration::printPositions(const string& label, const vector<Position*>& positions) const {
    stringstream ss;
    ss << "," << label << "=[";
    for (size_t i = 0; i < positions.size(); ++i) {
        ss << "(" << positions[i]->getRow() << "," << positions[i]->getCol() << ")";
        // cout << "(" << positions[i]->getRow() << "," << positions[i]->getCol() << ")\n";
        if (i < positions.size() - 1) {
            ss << ",";
        }
    }
    ss << "]";
    return ss.str();
}

string Configuration::str() const {
    stringstream ss;
    ss << "[";
    ss << "num_rows=" << num_rows;
    ss << ",num_cols=" << num_cols;

    // cout << "arrayForest: ";
    ss << printPositions("arrayForest", arrayForest);
    ss << printPositions("arrayRiver", arrayRiver);
    ss << printPositions("arrayFortification", arrayFortification);
    ss << printPositions("arrayUrban", arrayUrban);
    ss << printPositions("arraySpecialZone", arraySpecialZone);

    ss << ",liberationUnits=[";
    for (size_t i = 0; i < liberationUnits.size(); ++i) {
        ss << liberationUnits[i]->str();
        if (i < liberationUnits.size() - 1) ss << ",";
    }
    ss << "],ARVNUnits=[";
    for (size_t i = 0; i < ARVNUnits.size(); ++i) {
        ss << ARVNUnits[i]->str();
        if (i < ARVNUnits.size() - 1) ss << ",";
    }
    ss << "]";

    ss << ",eventCode=" << eventCode;
    ss << "]";

    return ss.str();
}
