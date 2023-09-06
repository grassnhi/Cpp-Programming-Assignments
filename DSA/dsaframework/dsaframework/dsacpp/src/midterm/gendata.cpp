#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include <vector>
using namespace std;

#include "list/XArrayList.h"
#include "util/FileIOLib.h"
#include "util/ArrayLib.h"

void gen_student_data(string folder="./dsacpp/src/midterm/", string file="students.csv"){
    DataFrame df(folder + file);
    vector<string> students = df["student"];
    int seed = 2021;
    int nitems = 10;
    for(auto it= students.begin(); it != students.end(); it++){
        string student_id = *it;
        string filename = folder + student_id + "/input.csv";
        int* ptr = permutation(100, true, seed++);
        
        vector<string> data_vec;
        XArrayList<int> list;
        
        string data ="";
        for(int idx=0; idx < nitems; idx++){
            list.add(ptr[idx]);
            data += std::to_string(ptr[idx]) + ", ";
        }
        data = data.substr(0, data.rfind(","));
        data_vec.push_back(data);
        DataFrame sdf;
        sdf.add("input", data_vec);
        sdf.write(filename, ';');
        
        cout << setw(30) << student_id << ":" << list.toString() << endl;
    }
    
}
int main_(int argc, char **argv){
    gen_student_data();
    
    return 0;
}