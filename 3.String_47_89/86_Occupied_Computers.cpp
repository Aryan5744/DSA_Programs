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
#define MAX_CHAR 26 
// n is number of computers in cafe. 
// 'seq' is given sequence of customer entry, exit events 
int runCustomerSimulation(int n, const char *seq) 
{ 
	// seen[i] = 0, indicates that customer 'i' is not in cafe 
	// seen[1] = 1, indicates that customer 'i' is in cafe but 
	//			 computer is not assigned yet. 
	// seen[2] = 2, indicates that customer 'i' is in cafe and 
	//			 has occupied a computer. 
	char seen[MAX_CHAR] = {0}; 

	// Initialize result which is number of customers who could 
	// not get any computer. 
	int res = 0; 

	int occupied = 0; // To keep track of occupied computers 

	// Traverse the input sequence 
	for (int i=0; seq[i]; i++) 
	{ 
		// Find index of current character in seen[0...25] 
		int ind = seq[i] - 'A'; 

		// If First occurrence of 'seq[i]' 
		if (seen[ind] == 0) 
		{ 
			// set the current character as seen 
			seen[ind] = 1; 

			// If number of occupied computers is less than 
			// n, then assign a computer to new customer 
			if (occupied < n) 
			{ 
				occupied++; 

				// Set the current character as occupying a computer 
				seen[ind] = 2; 
			} 

			// Else this customer cannot get a computer, 
			// increment result 
			else
				res++; 
		} 

		// If this is second occurrence of 'seq[i]' 
		else
		{ 
		// Decrement occupied only if this customer 
		// was using a computer 
		if (seen[ind] == 2) 
			occupied--; 
		seen[ind] = 0; 
		} 
	} 
	return res; 
} 

// Driver program 
int main() 
{ 
	cout << runCustomerSimulation(2, "ABBAJJKZKZ") << endl; 
	cout << runCustomerSimulation(3, "GACCBDDBAGEE") << endl; 
	cout << runCustomerSimulation(3, "GACCBGDDBAEE") << endl; 
	cout << runCustomerSimulation(1, "ABCBCA") << endl; 
	cout << runCustomerSimulation(1, "ABCBCADEED") << endl; 
	return 0; 
} 
