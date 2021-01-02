#include<bits/stdc++.h>
using namespace std;
#define gc getchar_unlocked
#define fo(i,n) for(long long int i=0;i<n;i++)
#define fr(i,n) for(i = n-1 ; i>0 ; i--)
#define Pa(i,n,a) for(long long int i=0;i<n;i++){cout << a[i] << " ";}
#define Ia(i,n,a) for(long long int i=0;i<n;i++){cin >> a[i];}
#define Fo(i,k,n) for(i=k;k<n?i<n:i>n;k<n?i+=1:i-=1)
#define Fs(itr,s) for(itr = s.begin(); itr != s.end(); ++itr)
#define Cs(s1,s2) set<int>s2(s1.begin(), s1.end());
#define F(i,a,n) for(long long int i=a;i<n;i++)
#define ll long long
#define deb(x) cout << #x << "=" << x << endl
#define deb2(x, y) cout << #x << "=" << x << "," << #y << "=" << y << endl
#define all(x) x.begin(), x.end()
#define clr(x) memset(x, 0, sizeof(x))
#define sortall(x) sort(all(x))
#define PI 3.1415926535897932384626
#define END() cout << endl
#define R(X) return X
#define I(X) cin>>X
#define O(X) cout<<X
#define V 10
//=======================
typedef stack<int> si;
typedef pair<int, int>	pii;
typedef vector<int>		vi;
typedef vector<pii>		vpii;
typedef vector<vi>		vvi;
typedef set <int, greater <int>> sii;
typedef multiset <int, greater <int> > msii;
typedef map<int, int> mapii;
typedef multimap <int, int> mmapii; 
typedef unordered_set <int> uosi;
typedef unordered_multiset <int> uomsi;
typedef unordered_map<int, int> uomapii;
typedef unordered_multimap<int, int> uommapii;
typedef priority_queue<pii,vpii,greater<pii>> pqpv;

//=======================

#include <iostream> 
#include <assert.h> 
using namespace std; 

void rightrotate(int arr[], int n, int outofplace, int cur) { 
	char tmp = arr[cur]; 
	for (int i = cur; i > outofplace; i--) 
		arr[i] = arr[i-1]; 
	arr[outofplace] = tmp; 
} 

void rearrange2(int a[], int n){
    int atwrongplace = -1;
    fo(index , n){
        if(atwrongplace >= 0){
            if( (a[index] >= 0 && a[atwrongplace] < 0) || (a[index] < 0 && a[atwrongplace] >= 0) ){
                rightrotate(a,n,atwrongplace,index);
                if(index - atwrongplace >= 2)
                   atwrongplace += 2;
                else
                   atwrongplace = -1;
            }
        }
        if(atwrongplace == -1)
            if( ((a[index] >= 0) && (!(index & 0X01))) || ((a[index] < 0) && (index & 0X01)) )
               atwrongplace = index;
    }
}

void rearrange(int arr[], int n) 
{ 
	int outofplace = -1; 
	for (int index = 0; index < n; index ++) { 
		if (outofplace >= 0) { 
			if (((arr[index] >= 0) && (arr[outofplace] < 0)) 
				|| ((arr[index] < 0) && (arr[outofplace] >= 0))){ 
				rightrotate(arr, n, outofplace, index); 
                
				if (index - outofplace >= 2) 
					outofplace = outofplace + 2; 
				else
					outofplace = -1; 
			} 
		} 
        if (outofplace == -1) {
			if (((arr[index] >= 0) && (!(index & 0x01))) 
				|| ((arr[index] < 0) && (index & 0x01))){ 
				outofplace = index; 
			} 
		} 
	} 
} 

// A utility function to print an array 'arr[]' of size 'n' 
void printArray(int arr[], int n) 
{ 
	for (int i = 0; i < n; i++) 
	cout << arr[i] << " "; 
	cout << endl; 
} 

// Driver program to test abive function 
int main() 
{  
	//int arr[n] = {-5, 3, 4, 5, -6, -2, 8, 9, -1, -4}; 
	//int arr[] = {-5, -3, -4, -5, -6, 2 , 8, 9, 1 , 4}; 
	//int arr[] = {5, 3, 4, 2, 1, -2 , -8, -9, -1 , -4}; 
	//int arr[] = {-5, 3, -4, -7, -1, -2 , -8, -9, 1 , -4}; 
	int arr[] = {-1,-2,-3,4,5,6}; 
	int n = sizeof(arr)/sizeof(arr[0]); 

	cout << "Given array is \n"; 
	printArray(arr, n); 

	rearrange(arr, n); 

	cout << "Rearranged array is \n"; 
	printArray(arr, n); 

	return 0; 
} 
