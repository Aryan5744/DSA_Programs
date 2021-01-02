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

#define MAX_CHARS 256 

bool areIsomorphic(string str1, string str2) 
{ 
	int m = str1.length(), n = str2.length(); 
	if (m != n) 
	return false; 

	// To mark visited characters in str2 
	bool marked[MAX_CHARS] = {false}; 

	// To store mapping of every character from str1 to 
	// that of str2. Initialize all entries of map as -1. 
	int map[MAX_CHARS]; 
	memset(map, -1, sizeof(map)); 

	// Process all characters one by on 
	for (int i = 0; i < n; i++) 
	{ 
		// If current character of str1 is seen first 
		// time in it. 
		if (map[str1[i]] == -1) 
		{ 
			// If current character of str2 is already 
			// seen, one to one mapping not possible 
			if (marked[str2[i]] == true) 
				return false; 

			// Mark current character of str2 as visited 
			marked[str2[i]] = true; 

			// Store mapping of current characters 
			map[str1[i]] = str2[i]; 
		} 

		// If this is not first appearance of current 
		// character in str1, then check if previous 
		// appearance mapped to same character of str2 
		else if (map[str1[i]] != str2[i]) 
			return false; 
	} 

	return true; 
} 
int main() 
{ 
cout << areIsomorphic("aab", "xxy") << endl; 
cout << areIsomorphic("aab", "xyz") << endl; 
return 0; 
} 
