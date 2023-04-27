#include "main.h"

const int HALFMAX = MAXSIZE / 2;

void simulate(string filename)
{
	ifstream orders(filename);
    string command;
	
    if (orders.is_open()) {
        while (getline(orders, command)) {
			int space = count(command.begin(), command.end(), ' ');

			string request = "";
			string para = "";
			int NUM = 0;

			if(space == 1){
				stringstream ss(command);
				ss >> request >> para;

				if(request == "REG"){
                    bool noDigit = true;
                    for (char c : para){
                        if (isdigit(c)){
                            noDigit = false;
                            break;
                        }
                    }
                    if(noDigit){
                        REG(para);
                    }
				}else if(request == "CLE"){
                    bool isNum = true;
                    for (char c : para){
                        if (!isdigit(c)){
                            isNum = false;
                            break;
                        }
                    }
                    if(isNum){
                        NUM = stoi(para);
					    CLE(NUM);
                    }
				}
			}else if(space == 0){
				stringstream ss(command);
				ss >> request;
				if(request == "PrintHT"){
					PrintHT();
				}else if(request == "PrintAVL"){
					PrintAVL();
				}else if(request == "PrintMH"){
					PrintMH();
				}
			}
		}
        orders.close();
    }
}