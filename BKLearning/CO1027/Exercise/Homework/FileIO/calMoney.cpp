/*
Write a function void calMoney(string price, string buy) that reads into 2 files price.txt and buy.txt.

In there:
    The price.txt file contains information about products, including: 
    The first line contains a positive integer N (N <= 20) which is 
    the number of products currently in the store. The next N lines each contain 
    2 positive integers that are the IDs and prices of the respective products.
    
Example:
          3

          1 10

          2 15

          3 12

Meaning: currently there are 3 products for sale in the store,
        product 1 costs 10 products 2 costs 15 and product 3 costs 12.

The buy.txt file contains information about the customer's purchase of goods. 
The first line contains a positive integer M representing the number of purchases made in a day. 
The next M lines each contain the following information: there will be multiple values ​​in a row, 
separated by a space. The first value will be the customer name (in string form), 
the remaining values ​​will come in pairs, respectively: <product ID>_<corresponding quantity>

Example:
          2

          A 1 2 2 3

          B 1 3 3 2

It means that there are 2 customers A and B, 
    A buys 2 products of type 1 and 3 products of type 2; 
    B buys 3 products of type 1 and 2 products of class 3.

Note: Product ID and customer name are unique (no repetition).

Calculate how much each customer needs to pay, then output the results to the screen.

Input:
    2 variables "price" (the name of the file containing product information) 
    and "buy" (the name of the file containing purchase information).

Output:
    Amount each customer needs to pay.
*/
#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

void calMoney(string price, string buy) {
    fstream priceFile;
    priceFile.open(price, ios::in);
    
    fstream buyFile;
    buyFile.open(buy, ios::in);

    int N;

    if (priceFile.is_open()){
        priceFile >> N;
        int arr[N];
        int id_idx;
        for(int i = 0;  i < N; i++){
            priceFile >> id_idx;
            priceFile >> arr[id_idx];
        }
cout << arr[N] << endl;        
        priceFile.close();
    }

    if (buyFile.is_open()){
        buyFile >> N;
        string customer;
        while(!buyFile.eof()){
            getline(buyFile, customer);
            unsigned long int sum = 0;
            string tokens[100];
            int idx = 0;
cout << customer << endl;
            for (auto i = strtok(&customer[0], " "); i; i = strtok(NULL, " ")){
                tokens[idx++] = i;
cout << tokens[idx++] << endl;
            }

            cout << tokens[0];

            int pro, num;
            for(int j = 1; j < idx; j += 2){
                pro = stoi(tokens[j]);
                num = stoi(tokens[j+1]);
                sum += pro*num;
cout << pro << " " << num << " " << sum << endl;
            }
            
            cout << " " << sum << endl;
            sum = 0;

            buyFile.close();
        }
    }
    
}

int main(){
    string price = "price.txt";
    string buy = "buy.txt";

    calMoney(price, buy);

    return 0;
}