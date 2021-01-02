#include<bits/stdc++.h> 
using namespace std; 
 
int min(int A, int B){return A > B ? B : A;}
int max(int A, int B){return A > B ? A : B;}
int middle(int A, int B, int C){
    return max(min(A,B),min(B,C));
}
// Driver program 
int main() 
{ 
	int A,B,C; 
    cin >> A >> B >> C;
	cout << middle(A,B,C) << endl; 
	return 0; 
} 
