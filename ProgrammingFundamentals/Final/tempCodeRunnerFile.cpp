str[n] = '\0';
    if(n - start < outSize) outSize = n - start;
    for(int i = start; i <= n - start; i++){
        
        out[i-start]= str[i];
        cout << i - start << endl;
    }
    out[n-start] = '\0';
    cout << n - start << endl;