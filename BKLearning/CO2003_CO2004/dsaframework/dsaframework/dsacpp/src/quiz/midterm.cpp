#include <iostream>
#include <iomanip>
#include <string>
#include "geom/Vector3D.h"
#include "graph/IGraph.h"
#include "graph/UGraphModel.h"
#include "graph/DGraphModel.h"
#include "list/DLinkedList.h"
#include "stacknqueue/Stack.h"
#include "stacknqueue/Queue.h"
#include "stacknqueue/PriorityQueue.h"
#include "hash/XHashMap.h"
#include "sorting/DLinkedListSE.h"
#include "util/FuncLib.h"
#include "util/ArrayLib.h"


#include "midterm/solution.h"
#include "midterm/student_code.h"

#include "midterm/list_answers.h"
#include "midterm/list_solutions.h"
using namespace std;




IMap<string, char (*)()>* student_1(){
    XHashMap<string, char (*)()> *map = new XHashMap<string, char (*)()>(&hash_murmur);
    Pair<string, char (*)()> answers[] = {
        Pair<string, char (*)()>("question_1", &question_1),
        Pair<string, char (*)()>("question_2", &question_2),
        Pair<string, char (*)()>("question_3", &question_3),
        Pair<string, char (*)()>("question_4", &question_4),
        Pair<string, char (*)()>("question_5", &question_5),
        Pair<string, char (*)()>("question_6", &question_6),
        Pair<string, char (*)()>("question_7", &question_7),
        Pair<string, char (*)()>("question_8", &question_8),
        Pair<string, char (*)()>("question_9", &question_9),
        Pair<string, char (*)()>("question_10", &question_10)
    };
    for(Pair<string, char (*)()> pair: answers) map->put(pair.key, pair.value);
    return map;
}

IMap<string, char (*)()>* solution_1(){
    XHashMap<string, char (*)()> *map = new XHashMap<string, char (*)()>(&hash_murmur);
    Pair<string, char (*)()> solutions[] = {
        Pair<string, char (*)()>("question_1", &question_1_sol),
        Pair<string, char (*)()>("question_2", &question_2_sol),
        Pair<string, char (*)()>("question_3", &question_3_sol),
        Pair<string, char (*)()>("question_4", &question_4_sol),
        Pair<string, char (*)()>("question_5", &question_5_sol),
        Pair<string, char (*)()>("question_6", &question_6_sol),
        Pair<string, char (*)()>("question_7", &question_7_sol),
        Pair<string, char (*)()>("question_8", &question_8_sol),
        Pair<string, char (*)()>("question_9", &question_9_sol),
        Pair<string, char (*)()>("question_10", &question_10_sol)
    };
    for(Pair<string, char (*)()> pair: solutions) map->put(pair.key, pair.value);
    
    return map;
}

void match_1(){
    IMap<string, char (*)()>* answers = student_1();
    IMap<string, char (*)()>* solutions = solution_1();
    
    DLinkedList<string> keys = answers->keys();
    DLinkedList<string>::Iterator it;
    char (*studentF)();
    char (*solutionF)();
    for(it = keys.begin(); it != keys.end(); it++){
        string key = *it;
        studentF = answers->get(key);
        solutionF = answers->get(key);
        cout << key << ":\t" << studentF() << " : " << solutionF() << endl;
    }
    
    
    delete answers;
    delete solutions;
}



IMap<string, int (*)(IList<int>*)>* student_2(){
    Pair<string, int (*)(IList<int>*)> answers[] = {
        Pair<string, int (*)(IList<int>*)>("list_question_1", &list_question_1),
        Pair<string, int (*)(IList<int>*)>("list_question_2", &list_question_2)
    };
    
    XHashMap<string, int (*)(IList<int>*)> *map = new XHashMap<string, int (*)(IList<int>*)>(&hash_murmur);
    for(Pair<string, int (*)(IList<int>*)> pair: answers) map->put(pair.key, pair.value);
    return map;
}

IMap<string, int (*)(IList<int>*)>* solution_2(){
    Pair<string, int (*)(IList<int>*)> solutions[] = {
        Pair<string, int (*)(IList<int>*)>("list_question_1", &list_question_1_sol),
        Pair<string, int (*)(IList<int>*)>("list_question_2", &list_question_2_sol)
    };
    
    XHashMap<string, int (*)(IList<int>*)> *map = new XHashMap<string, int (*)(IList<int>*)>(&hash_murmur);
    for(Pair<string, int (*)(IList<int>*)> pair: solutions) map->put(pair.key, pair.value);
    
    return map;
}
void match_2(){
    IMap<string, int (*)(IList<int>*)>* answers = student_2();
    IMap<string, int (*)(IList<int>*)>* solutions = solution_2();
    
    DLinkedList<string> keys = answers->keys();
    DLinkedList<string>::Iterator it;
    int (*studentF)(IList<int>*);
    int (*solutionF)(IList<int>*);
    XArrayList<int> input;
    for(int v=0; v<5; v++) input.add(v);
    
    for(it = keys.begin(); it != keys.end(); it++){
        string key = *it;
        studentF = answers->get(key);
        solutionF = answers->get(key);
        cout << key << ":\t" << studentF(&input) << " : " << solutionF(&input) << endl;
    }
    
    
    delete answers;
    delete solutions;
}
int main(int arc, char** argv){
    match_2();
    return 0;
}
