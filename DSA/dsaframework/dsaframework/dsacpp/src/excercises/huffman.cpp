#include <iostream>
#include <iomanip>
#include <sstream>
#include "heap/Heap.h"
#include "hash/XHashMap.h"
#include "util/FuncLib.h"

using namespace std;

typedef unsigned char uint8;
typedef unsigned int  uint32;
typedef unsigned long long  uint64;


template <class T>
struct Node{
    T symbol;
    float freq;
    Node<T> *left, *right;
    Node(float freq, Node<T> *left, Node<T>* right, T symbol){
        this->freq = freq;
        this->left = left;
        this->right = right;
        this->symbol = symbol;
    }
};
template<class T>
int node_comparator(Node<T>*& a, Node<T>*& b){
    if(a->freq < b->freq) return -1;
    else if(a->freq > b->freq) return +1;
    else return 0;
}

template <class T>
Node<T>* build_huffman_tree(T* symbols, float* freqs, int size){
    Heap<Node<T>*> heap(&node_comparator, Heap<Node<T>*>::free);
    
    //Initialize heap with symbols + freq
    for(int idx=0; idx < size; idx++){
        T symbol = symbols[idx];
        float freq = freqs[idx];
        heap.push(new Node<T>(freq, NULL, NULL, symbol));
    }
    
    //Reduce minimum frequencies
    while(heap.size() > 1){
        Node<T>* left = heap.pop();
        Node<T>* right = heap.pop();
        heap.push(new Node<T>(left->freq + right->freq, left, right, left->symbol)); //left->symbol: not used
    }
    
    return heap.pop();
}

template<class T>
void gen_huffman_table(Node<T>* root, string bits, XHashMap<T, string>& map){
    if((root->left == NULL) && (root->right == NULL))
        map.put(root->symbol, bits);
    else{
        string left_path = bits; left_path.push_back('0');
        string right_path = bits; right_path.push_back('1');
        gen_huffman_table(root->left, left_path, map);
        gen_huffman_table(root->right, right_path, map);
    }
}


void gen_table(Node<uint8>* root, string bits, string* map){
    if((root->left == NULL) && (root->right == NULL))
        map[root->symbol] = bits;
    else{
        string left_path = bits; left_path.push_back('0');
        string right_path = bits; right_path.push_back('1');
        gen_table(root->left, left_path, map);
        gen_table(root->right, right_path, map);
    }
}

void unit8_symbols(){
    int size = 8;
    uint8 symbols[] = {0, 1, 2, 3, 4, 5, 6, 7};
    float freqs[]   = {3, 3, 4, 1, 0, 1, 2, 6}; //20 items
    string huffman_table[size];
    
    Heap<Node<uint8>*> heap(&node_comparator, Heap<Node<uint8>*>::free);
    
    //Initialize heap with symbols + freq
    for(uint8 symbol=0; symbol < size; symbol++){
        float freq = freqs[symbol];
        heap.push(new Node<uint8>(freq, NULL, NULL, symbol));
    }
    
    //Reduce minimum frequencies
    while(heap.size() > 1){
        Node<uint8>* left = heap.pop();
        Node<uint8>* right = heap.pop();
        heap.push(new Node<uint8>(left->freq + right->freq, left, right, 0)); //0: any OK
    }
    Node<uint8>* root = heap.pop();
    
    //Generate maps symbol->bits
    gen_table(root, "", huffman_table);
    
    for(uint8 symbol=0; symbol < size; symbol++){
        cout << (int)symbol << ":" << huffman_table[symbol] << endl;
    }
    
    //averaged length
    int total =0;
    for(int idx=0; idx < size; idx++) total += freqs[idx];
    float avg_nbits = 0;
    for(int idx=0; idx < size; idx++) avg_nbits += (freqs[idx]/total)*huffman_table[idx].length();
    cout << "averaged nbits: " << avg_nbits << endl;
}

int hash_code(uint8& key, int size){
    return key % size;
}
string key2str(uint8& key){
    string out = "";
    out.push_back('0' + key);
    return out;
}
void unit8_symbols_map(){
    int size = 8;
    uint8 symbols[] = {0, 1, 2, 3, 4, 5, 6, 7};
    float freqs[]   = {3, 3, 4, 1, 0, 1, 2, 6}; //20 items
    XHashMap<uint8, string> huffman_table(&hash_code);
    
    
    Node<uint8>* root = build_huffman_tree(symbols, freqs, size);
    gen_huffman_table(root, "", huffman_table);
    
    huffman_table.println(&key2str);
    //averaged length
    int total =0;
    for(int idx=0; idx < size; idx++) total += freqs[idx];
    float avg_nbits = 0;
    for(int idx=0; idx < size; idx++) avg_nbits += 
            (freqs[idx]/total)*huffman_table.get(symbols[idx]).length();
    cout << "averaged nbits: " << avg_nbits << endl;
}

void string_symbols(){
    int size = 8;
    string symbols[] = {"This", "These", "That", "Those", "Hello", "Morning", "Afternoon", "Evening"};
    float freqs[]   = {3, 3, 5, 1, 0, 0, 2, 6}; //20 items
    //string huffman_table[size];
    XHashMap<string, string> huffman_table(&hash_polynomial_rolling);
    
    Node<string>* root = build_huffman_tree(symbols, freqs, size);
    gen_huffman_table(root, "", huffman_table);
    
    huffman_table.println();
    //averaged length
    int total =0;
    for(int idx=0; idx < size; idx++) total += freqs[idx];
    float avg_nbits = 0;
    for(int idx=0; idx < size; idx++) avg_nbits += 
            (freqs[idx]/total)*huffman_table.get(symbols[idx]).length();
    cout << "averaged nbits: " << avg_nbits << endl;
}


void bincount(uint8* data, int size, uint32* const freq, int min, int max){
    //init count => 0
    int nbins = max - min + 1;
    for(int idx=0; idx < nbins; idx++) freq[idx] = 0;
    
    //count
    for(int idx=0; idx < size; idx++){
        uint8 item = data[idx];
        if(item < min) item = min;
        else if(item > max) item = max;
        freq[item-min] += 1;
    }
}
void show_freqs(uint32* const freqs, int min, int max){
    for(int bin=min; bin <=max; bin++)
        cout << fixed << setw(3) << bin << ": " << freqs[bin - min] << endl;
}
int main(int arc, char** argv){
    uint8 data[] = {3, 5, 2, 2, 4, 5, 3, 5}; 
    uint32 freqs[4]; //[2, 5]
    bincount(data, 8, freqs, 2, 5);
    show_freqs(freqs, 2, 5);
    return 0;
}