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
//=======================

struct Pair{
    ll min;
    ll max;
};

struct Pair solve(ll _arr[], ll start, ll end){
    struct Pair MinMax, MinMax_L, MinMax_R;
    ll mid;
    if(start == end){
        MinMax.min = _arr[start];
        MinMax.max = _arr[start];
        R(MinMax);
    }
    else if(end == start+1){
        if(_arr[start] < _arr[end]){
            MinMax.min = _arr[start];
            MinMax.max = _arr[end];
        }else{
            MinMax.min = _arr[end];
            MinMax.max = _arr[start];
        }
        R(MinMax);
    }
    mid = (start+end)/2;
    MinMax_L = solve(_arr,start,mid);
    MinMax_R = solve(_arr,mid+1,end);

    if(MinMax_L.min < MinMax_R.min)
        MinMax.min = MinMax_L.min;
    else
        MinMax.min = MinMax_R.min;
    
    if(MinMax_L.max > MinMax_R.max)
        MinMax.max = MinMax_L.max;
    else
        MinMax.max = MinMax_R.max;

    R(MinMax);
}

struct Pair solve1(ll _arr[], ll _size){
    struct Pair MinMax;
    ll i;
    if (_size % 2 == 0) { 
        if (_arr[0] > _arr[1]){ 
            MinMax.max = _arr[0]; 
            MinMax.min = _arr[1]; 
        } 
        else{ 
            MinMax.min = _arr[0]; 
            MinMax.max = _arr[1]; 
        } 
        i = 2; 
    } 
    else{ 
        MinMax.min = _arr[0]; 
        MinMax.max = _arr[0]; 
        i = 1; 
    }

    while(i < _size-1){

        if(_arr[i] < _arr[i+1])
            if(_arr[i] < MinMax.min)
                MinMax.min = _arr[i];
            if(_arr[i+1] > MinMax.max)
                MinMax.max = _arr[i+1];
        else
            if(_arr[i] > MinMax.max)
                MinMax.max = _arr[i];
            if(_arr[i+1] < MinMax.min)
                MinMax.min = _arr[i+1];    
        i+=2;
    }
    R(MinMax);
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
        //struct Pair MinMax = solve(_arr,0,_size-1);
        struct Pair MinMax = solve1(_arr,_size);
        cout << "Max is : " << MinMax.max << " Min is : " << MinMax.min;
        END();
    }
    return 0;
}