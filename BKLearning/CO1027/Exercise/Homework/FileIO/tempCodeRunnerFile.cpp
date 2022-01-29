void calSum(string fileName){
	ifstream myfile;
	myfile.open(fileName);
        string myText;
        getline(myfile, myText);
        myfile.close();
        int a = 0;
        int sum = 0;
        cout << myText << endl;
        for(unsigned int i = 0; i < myText.length(); i++){
            cout << "i: " << i << " "  << "text: " <<myText[i] << endl;
            if(myText[i] >= '0' && myText[i] <= '9') a = a * 10 + (myText[i] % 16);
            else{
                cout << a <<endl;
                sum = sum + a;
                cout << sum << endl;
                a = 0;
            }
        }
        cout << sum;
}