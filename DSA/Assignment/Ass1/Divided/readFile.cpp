#include <iostream>
#include <fstream>
#include <string>

using namespace std;

string request;

void REG(int ID, string name, int age){
    cout << request << " " << ID << " " << name << " " << age << endl;
}

void REGM(string name, int age, int NUM){
    cout << request <<  " " << name << " " << age << " " << NUM << endl;
}

void CLE(int ID){
    cout << request << " " << ID << endl;
}

void PS(int NUM = 0){
    cout << request << " " << NUM << endl;
}

void PQ(int NUM = 0){
    cout << request << " " << NUM << endl;
}

void SQ(int NUM){
    cout << request << " " << NUM << endl;
}

int main() {
    ifstream orders("test.txt");
    string command;

    if (orders.is_open()) {
        while (getline(orders, command)){
            int space = 0;
            for(char c: command){
                if (c == ' '){
                    space++;
                }
            }

            string request = "";
            int ID = 0;
            string name = ""; 
            int age = 0;
            int NUM = 0;

            if(space == 3){
                int pos1 = command.find_first_of(" ");
                int pos2 = command.find_first_of(" ", pos1+1);
                int pos3 = command.find_first_of(" ", pos2+1);

                request = command.substr(0, pos1);
                if(request == "REG"){
                    ID = stoi(command.substr(pos1+1, pos2-pos1-1));
                    name = command.substr(pos2+1, pos3-pos2-1);
                    age = stoi(command.substr(pos3+1));

                    REG(ID, name, age);
                }else{
                    name = command.substr(pos1+1, pos2-pos1-1);
                    age = stoi(command.substr(pos2+1, pos3-pos2-1));
                    NUM = stoi(command.substr(pos3+1));

                    REGM(name, age, NUM);
                }
                
            }else if(space == 2){
                int pos1 = command.find_first_of(" ");
                int pos2 = command.find_first_of(" ", pos1+1);

                request = command.substr(0, pos1);
                name = command.substr(pos1+1, pos2-pos1-1);
                age = stoi(command.substr(pos2+1));

                REG(ID, name, age);
            }else if(space == 1){
                int pos1 = command.find_first_of(" ");

                request = command.substr(0, pos1);
                if(request == "CLE"){
                    ID = stoi(command.substr(pos1+1));
                    CLE(ID);
                }else if(request == "PS"){
                    NUM = stoi(command.substr(pos1+1));
                    PS(NUM);
                }else if(request == "PQ"){
                    NUM = stoi(command.substr(pos1+1));
                    PQ(NUM);
                }else{
                    NUM = stoi(command.substr(pos1+1));
                    SQ(NUM);
                }  
            }else{
                if(request == "PQ"){
                    PQ(NUM);
                }else{
                    SQ(NUM);
                }  
            }
            
            
        }
        orders.close();
    }
    cout << "E";
    return 0;
}

