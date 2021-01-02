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

const char MARKER = '$';
//=======================

bool checkIfMirror(vector<stack<int>> &t1 , vector<queue<int>> &t2){
    for(int i = 1 ; i < t1.size() ; ++i){
        stack<int> &s = t1[i];
        queue<int> &q = t2[i];

        while(!s.empty() && !q.empty()){
            if(s.top() != q.front())
                return false;
            s.pop();
            q.pop();
        } 

        if(!s.empty() || !q.empty())
            return false;
    }
    return true;
}

string areMirrors(int M, int N, int u1[], int v1[], int u2[], int v2[]){
    vector<stack<int>> t1(M+1);
    vector<queue<int>> t2(M+1);

    for(int i = 0 ; i < N ; i++)
        t1[u1[i]].push(v1[i]);
    
    for(int i = 0 ; i < N ; i++)
        t2[u2[i]].push(v2[i]);
    
    return checkIfMirror(t1, t2) ? "Yes" : "No";
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int M = 3, N = 2;
 
    int u1[] = { 1, 1 };
    int v1[] = { 2, 3 };
 
    int u2[] = { 1, 1 };
    int v2[] = { 3, 2 };
 
    cout << areMirrors(M, N, u1, v1, u2, v2);
    return 0;
}