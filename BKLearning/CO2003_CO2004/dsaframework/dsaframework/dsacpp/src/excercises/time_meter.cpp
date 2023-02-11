#include <iostream>
#include <fstream>
#include <chrono>
using namespace std;
using namespace std::chrono;

#include "list/XArrayList.h"
#include "list/SLinkedList.h"
#include "list/DLinkedList.h"
#include "list/IList.h"
#include "util/ArrayLib.h"
#include <random>
#include <valarray>

int* randomize(int size, int amin=0, int amax=100){
    std::random_device rd;     // only used once to initialise (seed) engine
    std::mt19937 rng(rd());    // random-number engine used (Mersenne-Twister in this case)
    std::uniform_int_distribution<int> uni(amin, amax); // guaranteed unbiased
    int * ptr = new int[size];
    for(int idx=0; idx < size; idx++){
        ptr[idx] = uni(rng);
    }
    return ptr;
}

double list_addfirst(IList<int>* plist, int size, int nexec){
    //create a list of 'size' items; no timing here
    plist->clear();
    for(int idx=0; idx < size; idx++) plist->add(idx);
    
    //
    double total = 0;
    for(int n=0; n < nexec; n++){
        auto start = high_resolution_clock::now();
        plist->add(0, 999); //add 999 to be the first => (size + 1) items
        auto stop = high_resolution_clock::now();
        duration<double> time_span = duration_cast<microseconds>(stop-start);
        total += time_span.count();
        
        //remove one item => maintan 'size' items
        plist->removeAt(size);
    }

    plist->clear();
    return total/nexec;
}

double list_addlast(IList<int>* plist, int size, int nexec){
    //create a list of 'size' items; no timing here
    plist->clear();
    for(int idx=0; idx < size; idx++) plist->add(idx);
    
    //
    double total = 0;
    for(int n=0; n < nexec; n++){
        auto start = high_resolution_clock::now();
        plist->add(999); //add 999 to be the last => (size + 1) items
        auto stop = high_resolution_clock::now();
        duration<double> time_span = duration_cast<microseconds>(stop-start);
        total += time_span.count();
        
        //remove one item => maintan 'size' items
        plist->removeAt(size);
    }

    plist->clear();
    return total/nexec;
}
double list_addrandpos(IList<int>* plist, int size, int nexec, int nItems=5){
    //create a list of 'size' items; no timing here
    plist->clear();
    for(int idx=0; idx < size; idx++) plist->add(idx);
    int* ptrItems = randomize(nItems, 0, size-1);
    //
    double total = 0;
    for(int itemIdx =0; itemIdx < nItems; itemIdx++){
        for(int n=0; n < nexec; n++){
            auto start = high_resolution_clock::now();
            plist->add(ptrItems[itemIdx], ptrItems[itemIdx]); //add ptrItems[itemIdx] at ptrItems[itemIdx]
            auto stop = high_resolution_clock::now();
            duration<double> time_span = duration_cast<microseconds>(stop-start);
            total += time_span.count();
            
            //remove one item => maintan 'size' items
            plist->removeAt(size);
        }
    }
    
    delete []ptrItems;
    plist->clear();
    return total/(nexec*nItems);
}
/////////////////////////////////////////////////////////////////////
//// REMOVAL
/////////////////////////////////////////////////////////////////////

double list_removefirst(IList<int>* plist, int size, int nexec){
    //create a list of 'size' items; no timing here
    plist->clear();
    for(int idx=0; idx < size; idx++) plist->add(idx);
    
    //
    double total = 0;
    for(int n=0; n < nexec; n++){
        auto start = high_resolution_clock::now();
        plist->removeAt(0); //=> (size - 1) items
        auto stop = high_resolution_clock::now();
        duration<double> time_span = duration_cast<microseconds>(stop-start);
        total += time_span.count();
        
        //add one more again
        plist->add(999); //=> (size - 1) items => add one more => size
    }

    plist->clear();
    return total/nexec;
}

double list_removelast(IList<int>* plist, int size, int nexec){
    //create a list of 'size' items; no timing here
    plist->clear();
    for(int idx=0; idx < size; idx++) plist->add(idx);
    
    //
    double total = 0;
    for(int n=0; n < nexec; n++){
        auto start = high_resolution_clock::now();
        plist->removeAt(size - 1); //=> (size - 1) items
        auto stop = high_resolution_clock::now();
        duration<double> time_span = duration_cast<microseconds>(stop-start);
        total += time_span.count();

        //add one more again
        plist->add(999); //=> (size - 1) items => add one more => size
    }

    plist->clear();
    return total/nexec;
}
double list_removerandpos(IList<int>* plist, int size, int nexec, int nItems=5){
    //create a list of 'size' items; no timing here
    plist->clear();
    for(int idx=0; idx < size; idx++) plist->add(idx);
    
    int* ptrItems = randomize(nItems, 0, size-1);
    //
    double total = 0;
    for(int itemIdx =0; itemIdx < nItems; itemIdx++){
        for(int n=0; n < nexec; n++){
            auto start = high_resolution_clock::now();
            plist->removeAt(ptrItems[itemIdx]); // size => size -1
            auto stop = high_resolution_clock::now();
            duration<double> time_span = duration_cast<microseconds>(stop-start);
            total += time_span.count();
            
            //add one more again
            plist->add(999); //=> (size - 1) items => add one more => size
        }
    }
    
    delete []ptrItems;
    plist->clear();
    return total/(nexec*nItems);
}

/////////////////////////////////////////////////////////////////////
//// REMOVAL
/////////////////////////////////////////////////////////////////////
double list_getrandpos(IList<int>* plist, int size, int nexec, int nItems=5){
    //create a list of 'size' items; no timing here
    plist->clear();
    for(int idx=0; idx < size; idx++) plist->add(idx);
    
    int* ptrItems = randomize(nItems, 0, size-1);
    //
    double total = 0;
    for(int itemIdx =0; itemIdx < nItems; itemIdx++){
        for(int n=0; n < nexec; n++){
            auto start = high_resolution_clock::now();
            plist->get(ptrItems[itemIdx]);
            auto stop = high_resolution_clock::now();
            duration<double> time_span = duration_cast<microseconds>(stop-start);
            total += time_span.count();
        }
    }
    
    delete []ptrItems;
    plist->clear();
    return total/(nexec*nItems);
}



/**
 * 
 * @param csvfile
 * @param nsamples
 * @param nexec
 * @param max_length: max length of lists
 */
void meter(IList<int>* plist, string csvfile, int nsamples, int nexec=10, int max_length=1000){
    std::ofstream csvstream;
    csvstream.open (csvfile, std::ofstream::out | std::ofstream::app);
    csvstream << "size, addfirst(ms), addlast(ms), addrandpos(ms), ";
    csvstream << "removefirst(ms), removelast(ms), removerandpos(ms), ";
    csvstream << "getrandpos(ms)" << endl;
    
    int* ptr = genIntArray(nsamples, 1, max_length);

    cout          << "index/nsamples"  << ":\t" 
                  << "n" << "\t-> "
                  << fixed << setw(12) << setprecision(8) << "add(0,*)" << ", " 
                  << fixed << setw(12) << setprecision(8) << "add(*)" << ", "
                  << fixed << setw(12) << setprecision(8) << "add(k,*)" << ", "
                  << fixed << setw(12) << setprecision(8) << "removeAt(0)" << ", " 
                  << fixed << setw(12) << setprecision(8) << "removeAt(n-1)" << ", "
                  << fixed << setw(12) << setprecision(8) << "removeAt(k)" << ", "
                  << fixed << setw(12) << setprecision(8) << "get(k)" << endl;

    for(int idx=0; idx < nsamples; idx++){
        plist->clear(); 

        double addfirst = list_addfirst(plist, ptr[idx], nexec);
        double addlast = list_addlast(plist, ptr[idx], nexec);
        double addrandpos = list_addrandpos(plist, ptr[idx], nexec, 20);
        double removefirst = list_removefirst(plist, ptr[idx], nexec);
        double removelast = list_removelast(plist, ptr[idx], nexec);
        double removerandpos = list_removerandpos(plist, ptr[idx], nexec, 20);
        double getrandpos = list_getrandpos(plist, ptr[idx], nexec, 20);

        if(idx %10 ==0) 
                  cout << "[" << setw(2) << idx << "/" << setw(3) << nsamples << "]"  << ":\t" 
                  << ptr[idx] << "\t-> "
                  << fixed << setw(12) << setprecision(8) << addfirst << ", " 
                  << fixed << setw(12) << setprecision(8) << addlast << ", "
                  << fixed << setw(12) << setprecision(8) << addrandpos << ", "
                  << fixed << setw(12) << setprecision(8) << removefirst << ", " 
                  << fixed << setw(12) << setprecision(8) << removelast << ", "
                  << fixed << setw(12) << setprecision(8) << removerandpos << ", "
                  << fixed << setw(12) << setprecision(8) << getrandpos << endl;

        csvstream  << ptr[idx] << ", " 
                  << fixed << setw(12) << setprecision(8) << addfirst << ", " 
                  << fixed << setw(12) << setprecision(8) << addlast << ", "
                  << fixed << setw(12) << setprecision(8) << addrandpos << ", "
                  << fixed << setw(12) << setprecision(8) << removefirst << ", " 
                  << fixed << setw(12) << setprecision(8) << removelast << ", "
                  << fixed << setw(12) << setprecision(8) << removerandpos << ", "
                  << fixed << setw(12) << setprecision(8) << getrandpos << endl;
    }
    cout << "Done" << endl;

    delete []ptr;
    csvstream.close();
}


int main(int argc, char** argv){
    XArrayList<int> alist;
    SLinkedList<int> slist;
    DLinkedList<int> dlist;

    //meter(&alist, "dlisttime.csv", 50, 2, 100);
    meter(&slist, "slisttime.csv", 50, 2, 100);
    meter(&dlist, "dlisttime.csv", 50, 2, 100);
    
    return 0;
}