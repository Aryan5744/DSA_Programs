#include <bits/stdc++.h> 
using namespace std; 
bool subArrayExists(int arr[], int n) 
{ 
	unordered_set <int> sumSet;
    int sum = 0 ;
    for(int i = 0; i < n; i++){
        sum += arr[i];                                                           
        if(sum == 0 || sumSet.find(sum) != sumSet.end())  //prefix sum exists 4 ,(3,4,-7), 5,6
           return true;
    }
    return false;
} 
// Driver code 
int main() 
{ 
	int arr[] = {-3, 2, 3, 1, 6}; 
	int n = sizeof(arr)/sizeof(arr[0]); 
	if (subArrayExists(arr, n)) 
		cout << "Found a subarray with 0 sum"; 
	else
		cout << "No Such Sub Array Exists!"; 
	return 0; 
} 