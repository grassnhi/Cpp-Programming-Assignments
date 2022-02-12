void printFirstRepeatedWord(char str[]) {
	int arr[100];
	int n = strlen(str);
	for(int i = 0 ; i < n; i++){
		arr[i] = strtok(str, ' ');
	}
	for(int i = 0 ; i < 100; i++){
		for(int j = 0 ; j < 100; j++){
			if(arr[i]==arr[j]){
				return arr[i];
			}
	}
	}
}