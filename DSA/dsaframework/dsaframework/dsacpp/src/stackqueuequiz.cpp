#include <iostream>
#include <iomanip>
#include "stacknqueue/Stack.h"
#include "stacknqueue/Queue.h"
#include "geom/Vector3D.h"
using namespace std;

void demo_stack(){
    Stack<int> stack;
    for(int i=0; i < 100; i +=10) stack.push(i);
    stack.println();
    
}
void demo_queue
int main(int argc, char** argv){
    demo_stack();
    return 0;
}

