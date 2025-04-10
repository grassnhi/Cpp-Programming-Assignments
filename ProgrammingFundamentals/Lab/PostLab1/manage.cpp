#include <iostream>
#include <fstream>
#include <unordered_map>
#include <unordered_set>
#include <sstream>

using namespace std;

#include <unordered_map>
#include <unordered_set>
#include <sstream>

#include <unordered_map>
#include <unordered_set>
#include <sstream>

void manage(string library, string book, string author){
    // TODO
    ifstream libFile(library);
    ifstream bookFile(book);
    ifstream authFile(author);
    
    if((!libFile.is_open()) || (!authFile.is_open())){
        return;
    }
    
    int N, M, P;
    
    libFile >> N;
    unordered_map <string, unordered_set<int>> libMap;
    for(int i = 0; i < N; i++){
        string name;
        libFile >> name;
        for(int j = 0; j < 5; j++){
            int idx;
            libFile >> idx;
            libMap[name].insert(idx);
        }
    }
    libFile.close();
    
    authFile >> P;
    unordered_map <string, unordered_set<int>> authMap;
    string name, line;
    getline(authFile, line);
    for(int i = 0; i < P; i++){
        getline(authFile, line);
        stringstream ss(line);
        ss >> name;
        int idx;
        while(ss >> idx){
            authMap[name].insert(idx);
        }
    }
    authFile.close();
    
    string L, A;
    cin >> L >> A;
    if(libMap.find(L) == libMap.end() || authMap.find(A) == authMap.end()){
        cout << "False" << endl;
        return;
    }
    for(int bookId: authMap[A]){
        if(libMap[L].find(bookId) != libMap[L].end()){
            cout << "True" << endl;
            return;
        }
    }
    cout << "False" << endl;
}

#include <sstream>

void manage(string library, string book, string author){
    // TODO
    string line;
    bool foundFlag = false;
    
    ifstream fL(library);
    int nLib;
    string libName[100];
    int bookInLib[100][5];
    
    fL >> nLib;
    for (int i = 0; i < nLib; i++) {
        fL >> libName[i];
        for (int j = 0; j< 5; j++) {
            fL >> bookInLib[i][j];
        }
    }
    
    ifstream fA(author);
    int nAuth;
    string authName[100];
    int bookOfAuth[100][10];
    int bookCountOfAuth[100] = {0};
    
    fA >> nAuth;
    getline(fA, line);
    for (int i = 0; i < nAuth; i++) {
        getline(fA, line);
        stringstream ss(line);
        ss >> authName[i];
        int id;
        int index = 0;
        while (ss >> id) {
            bookOfAuth[i][index++] = id;
        }
        bookCountOfAuth[i] = index;
    }
    
    string libInput;
    string authInput;
    cin >> libInput >> authInput;
    int libIndex = -1;
    int authIndex = -1;
    
    for (int i = 0; i < nLib; i++) {
        if (libName[i] == libInput) {
            libIndex = i;
            break;
        }
    }
    
    for (int i = 0; i < nAuth; i++) {
        if (authName[i] == authInput) {
            authIndex = i;
            break;
        }
    }
    
    if (libIndex != -1 && authIndex != -1) {
        for (int i = 0; i < 5; i++) {
            int id = bookInLib[libIndex][i];
            for (int j = 0; j < bookCountOfAuth[authIndex]; j++) {
                if (bookOfAuth[authIndex][j] == id) {
                    foundFlag = true;
                    break;
                }
            }
            if (foundFlag) break;
        }
    }
    cout << (foundFlag ? "True" : "False");
}

int main() {
    string libraryFile = "library.txt";
    string bookFile = "book.txt";
    string authorFile = "author.txt";

    manage(libraryFile, bookFile, authorFile);
    return 0;
}