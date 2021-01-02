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
/*
    g x t x a y b
  0 0 0 0 0 0 0 0
a 0 0 0 0 0 1 1 1
g 0 1 1 1 1 1 1 1
g 0 1 1 1 1 1 1 1
t 0 1 1 2 2 2 2 2
a 0 1 1 2 2 3 3 3
b 0 1 1 2 2 3 3 4

*/
int findLCS(string s1, string s2){
    int l1 = s1.length();
    int l2 = s2.length();
    int LCS[l1+1][l2+1];

    for(int i = 0 ; i <= l1 ; i++){
        for(int j = 0 ; j <= l2 ; j++){
            if( i == 0 || j == 0 )
               LCS[i][j] = 0;
            else if(s1[i-1] == s2[j-1] && i != j)
               LCS[i][j] = LCS[i-1][j-1] + 1;
            else
               LCS[i][j] = max(LCS[i-1][j] , LCS[i][j-1]);
        }
    }
    return LCS[l1][l2];
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while(t--){
        string s1, s2;
        cin >> s1 >> s2;
        cout << findLCS(s1,s2) << endl;
    }
    return 0;
}