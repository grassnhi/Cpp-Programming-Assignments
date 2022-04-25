/*
Given the template for class PrinterQueue and 2 methods:

1. addNewRequest(int priority, string fileName)

Add a file to queue with priority and fileName. The test cases have maximum of 100 file.
2. print()
Print the highest priority file's fileName. If there is no file in the queue, print "No file to print";
The files that have the same priority will be printed in FIFO (First In First Out) order
You can implement any additional method.

For example:

Test	Result
PrinterQueue* myPrinterQueue = new PrinterQueue();
myPrinterQueue->addNewRequest(1, "hello.pdf");
myPrinterQueue->addNewRequest(2, "goodbye.pdf");
myPrinterQueue->addNewRequest(2, "goodnight.pdf");
myPrinterQueue->print();
myPrinterQueue->print();
myPrinterQueue->print();
goodbye.pdf
goodnight.pdf
hello.pdf
PrinterQueue* myPrinterQueue = new PrinterQueue();
myPrinterQueue->addNewRequest(1, "hello.pdf");
myPrinterQueue->print();
myPrinterQueue->print();
myPrinterQueue->print();
*/
class PrinterQueue
{
    // your attributes
    
public:
    // your methods
    int priority[100];
    string fileName[100];
    int size = 0;
    
    void addNewRequest(int priority, string fileName)
    {
        // your code here
        this->priority[size] = priority;
        this->fileName[size] = fileName;
        size++;
    }
    
    int findMax(){
        int idx = 0;
        for(int i = 0; i < size; i++){
            if(this->priority[i] > this->priority[idx]){
                idx = i;
            }
        }
        return idx;
    }

    void print()
    {
        // your code here
        // After some logic code, you have to print fileName with endline 
        if(size > 0){
            int max_idx = findMax();
            cout << this->fileName[max_idx] << endl;
            for(int i = max_idx; i < size - 1; i++){
                this-> fileName[i] = this->fileName[i+1];
                this-> priority[i] = this->priority[i+1];
            }
            size--;
        }else
            cout << "No file to print" << endl;
        
    }
};




