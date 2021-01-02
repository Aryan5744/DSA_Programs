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

int minOps(string& A, string& B) 
{ 
	int m = A.length(), n = B.length(); 

	// This parts checks whether conversion is 
	// possible or not 
	if (n != m) 
	return -1; 

	int count[256]; 
	memset(count, 0, sizeof(count)); 
	
    for (int i=0; i<n; i++) // count characters in A 
	    count[B[i]]++; 
        
	for (int i=0; i<n; i++) // subtract count for 
	    count[A[i]]--;		 // every character in B

	for (int i=0; i<256; i++) // Check if all counts become 0 
     	if (count[i]) 
	    	return -1; 

	// This part calculates the number of operations required 
	int res = 0; 
	for (int i=n-1, j=n-1; i>=0; ) 
	{ 
		// If there is a mismatch, then keep incrementing 
		// result 'res' until B[j] is not found in A[0..i] 
		while (i>=0 && A[i] != B[j]) 
		{ 
			i--; 
			res++; 
		} 

		// If A[i] and B[j] match 
		if (i >= 0) 
		{ 
			i--; 
			j--; 
		} 
	} 
	return res; 
} 

// Driver program 
int main() 
{ 
	string A = "EACBD"; 
	string B = "EABCD"; 
	cout << "Minimum number of operations required is " << minOps(A, B); 
	return 0; 
} 