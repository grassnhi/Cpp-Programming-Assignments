#include<bits/stdc++.h> 
#include<string>

using namespace std;

int main(){
    queue<int>* FIFO = new queue<int>(); 
    FIFO->push(12579);
    FIFO->push(20876);
    FIFO->push(22216);
    FIFO->push(56743);
    FIFO->push(12);
    cout << FIFO->front() << " " << FIFO->back() << endl;
    FIFO->pop();
    cout << FIFO->front() << " " << FIFO->back() << endl;

    deque<int>* LRCO = new deque<int>(); 
    stack<int>* pushLRCO = new stack<int>();
    LRCO->push_back(12579);
    LRCO->push_back(20876);
    LRCO->push_back(22216);
    LRCO->push_back(56743);
    LRCO->push_back(12);
    while (LRCO->back() != 12579)
    {
        pushLRCO->push(LRCO->back());
        cout << LRCO->back() << " ";
        LRCO->pop_back();
    }
    LRCO->pop_back();
    while (!pushLRCO->empty())
    {
        LRCO->push_back(pushLRCO->top());
        cout << pushLRCO->top() << " ";
        pushLRCO->pop();
    }
    LRCO->push_back(2);
    cout << endl << LRCO->front() << " - " << LRCO->back() << endl;
    LRCO->pop_back();
    cout << LRCO->front() << " - " << LRCO->back() << endl;
}