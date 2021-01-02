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

int solve(int _arr[], int N){
    if(N <= 1)
        return -1;
    int can_reach = 0, jumps = -1 , prev_can_reach = 0;
    pii range = {0,0};
    while (true)
    {
        jumps++;
        for(int i = range.first ; i <= range.second ; i++){
            if(i == N-1)
               return jumps;
            can_reach = max(can_reach , i+_arr[i]);
        }
        range = {range.second+1 , can_reach};

        if(prev_can_reach != can_reach)
            prev_can_reach = can_reach;
        else
            break;
    }
    return -1;
}
int solveUsingDP(int _arr[], int N){
    int jumps[N] = {0};
    for(int i = 1 ; i < N-1 ; i++)
       for(int j = 0 ; j < i ; j++)
          if( j + _arr[j] >= i && jumps[j] != INT_MAX){
              jumps[i] = min(jumps[i],jumps[j]+1);
              break;
          }
    return jumps[N-1];
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while(t--){
        int N;
        cin >> N;
        int _arr[N];
        fo(i,N)
           cin >> _arr[i];
        //cout << solve(_arr,N) << endl;
        cout << solveUsingDP(_arr,N) << endl; 
    }
    return 0;
}