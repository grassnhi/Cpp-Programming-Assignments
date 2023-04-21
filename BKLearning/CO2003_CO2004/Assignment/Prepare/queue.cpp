#include <iostream>
#include <queue>

using namespace std;

int main() {
  // Creating a queue
  queue<int>* myQueue = new queue<int>();

  // Adding elements to the queue
  myQueue->push(10);
  myQueue->push(20);
  myQueue->push(30);

  // Accessing elements of the queue
  cout << "Front element: " << myQueue->front() << endl;
  cout << "Back element: " << myQueue->back() << endl;

  // Removing elements from the queue
  myQueue->pop();

  // Checking if the queue is empty
  if (myQueue->empty()) {
    cout << "Queue is empty" << endl;
  } else {
    cout << "Queue is not empty." << endl;
  }
    delete myQueue;
  return 0;
}
