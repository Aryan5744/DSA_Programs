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
const int MOD = 1'000'000'007;
const int N = 2e6+13, M = N;
const int IMax = INT_MAX;
const int IMin = INT_MIN; 
const int K = 101;
//=======================
vi g[N];
int a[N];
ll n, m, k;
bool checkIfGreater(ll a, ll b){
    return a>b;
}
//=======================

/*
"https://www.geeksforgeeks.org/write-a-program-to-reverse-an-array-or-string/"
1. we will start from left = 0 and right = n-1
and keep on swapping arr[left] and arr[right] while left < right 
and increase left by 1 and decrease right by 1 for each iteration. 
time complexity = O(n)
space complexity = O(1)

2. recursive approach is not efficient in terms of space complexity as it will have 
space complexity = O(n)
*/

void solve(ll _arr[], ll _size){
    
    ll start = 0, end = _size -1;
    while(start < end){
        ll temp = _arr[end];
        _arr[end] = _arr[start];
        _arr[start] = temp;
        start++;
        end--;
    }
}

void solve1(ll _arr[], ll start, ll end){
    if(start >= end)
        return;
    
    ll temp = _arr[end];
    _arr[end] = _arr[start];
    _arr[start] = temp;
    solve1(_arr,start+1,end-1);
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while(t--){
        ll _size;
        cin >> _size;
        ll _arr[_size];
        fo(i,_size)
           cin >> _arr[i];
        
        solve(_arr,_size);     //method-1
        //solve1(_arr,0,_size-1);    //method-2
        Pa(i,_size,_arr);
    }
    return 0;
}