/*
Given an array of distinct integers, find if there are two pairs (a, b) and (c, d) such that a+b = c+d, and a, b, c and d are distinct elements. If there are multiple answers, you can find any of them.

Some libraries you can use in this question:

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <algorithm>
#include <iostream>
#include <utility>
#include <map>
#include <vector>
#include <set>
Note: The function checkAnswer is used to determine whether your pairs found is true or not in case there are two pairs satistify the condition. You don't need to do anything about this function.



For example:

Test	Result
int arr[] = { 3, 4, 7, 1, 2, 9, 8 };
int n = sizeof arr / sizeof arr[0];
pair<int, int> pair1, pair2;
if (findPairs(arr, n, pair1, pair2)) {
    if (checkAnswer(arr, n, pair1, pair2)) {
        printf("Your answer is correct.\n");
    }
    else printf("Your answer is incorrect.\n");
}
else printf("No pair found.\n");
Your answer is correct.
int arr[] = { 3, 4, 7 };
int n = sizeof arr / sizeof arr[0];
pair<int, int> pair1, pair2;
if (findPairs(arr, n, pair1, pair2)) {
    if (checkAnswer(arr, n, pair1, pair2)) {
        printf("Your answer is correct.\n");
    }
    else printf("Your answer is incorrect.\n");
}
else printf("No pair found.\n");
No pair found.
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <algorithm>
#include <iostream>
#include <utility>
#include <map>
#include <vector>
#include <set>

bool findPairs(int arr[], int n, pair<int, int>& pair1, pair<int, int>& pair2)
{
	map<int, pair<int, int>> Hash;

	for (int i = 0; i < n; ++i)
	{
		for (int j = i + 1; j < n; ++j)
		{
			int sum = arr[i] + arr[j];
			if (Hash.find(sum) == Hash.end())
				Hash[sum] = make_pair(i, j);

			else 
			{
				pair<int,int>temp = Hash[sum];
				pair1.first = arr[temp.first];
				pair1.second = arr[temp.second];
				pair2 = make_pair(arr[i],arr[j]);
				return true;
			}
		}
	}
	return false;
}