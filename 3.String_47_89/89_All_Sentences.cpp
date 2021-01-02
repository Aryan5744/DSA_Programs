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
#define R 3
#define C 3

void printUtil(string arr[R][C], int m, int n, string output[R])
{
	// Add current word to output array
	output[m] = arr[m][n];

	// If this is last word of current output sentence, then print
	// the output sentence
	if (m==R-1)
	{
		for (int i=0; i<R; i++)
		cout << output[i] << " ";
		cout << endl;
		return;
	}

	// Recur for next row
	for (int i=0; i<C; i++)
	if (arr[m+1][i] != "")
		printUtil(arr, m+1, i, output);
}

// A wrapper over printUtil()
void print(string arr[R][C])
{
// Create an array to store sentence
string output[R];

// Consider all words for first row as starting points and
// print all sentences
for (int i=0; i<C; i++)
	if (arr[0][i] != "")
		printUtil(arr, 0, i, output);
}

// Driver program to test above functions
int main()
{
string arr[R][C] = {{"you", "we"},{"have", "are"},{"sleep", "eat", "drink"}};

print(arr);

return 0;
}
/*

phle "you" fir "have" fir fir "sleep" ab choonki last row h to puri row print kro with "have" go back 
pick "are", again come to "sleep" as its last row again print all with "are"

Input: {{"you", "we"},
        {"have", "are"},
        {"sleep", "eat", "drink"}}

Output:
  you have sleep
  you have eat
  you have drink
  you are sleep
  you are eat
  you are drink
  we have sleep
  we have eate
  we have drink
  we are sleep
  we are eat
  we are drink 
*/