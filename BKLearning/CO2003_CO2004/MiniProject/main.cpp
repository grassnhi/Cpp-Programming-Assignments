#include<iostream>

#include "IList.h"
#include "IDeck.h"
#include "SLL.h"

using namespace std;

int main(){
    SLL<int>* test = new SLL<int>();
    test->add(1);
    test->add(2);
    test->add(3);
    test->add(2);
    test->add(1);

    return 0;
}