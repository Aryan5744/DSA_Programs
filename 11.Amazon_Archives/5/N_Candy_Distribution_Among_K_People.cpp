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
Time Complexity: O(log N + K)
*/
void distributeCandy(int N, int K){
    int distribute[K];

    memset(distribute, 0, sizeof(distribute));

    int low = 0, high = N, count = 0;
    while(low <= high){
        int mid = (low + high) >> 1;
        int sum = (mid*(mid + 1)) >> 1;

        if(sum <= N){
            count = mid/K;
            low = mid + 1;
        }
        else
            high = mid - 1;
    }
    int last = (count * K);

    N -= (last*(last+1))/2;

    int i = 0;
    int term = last + 1;

    while(N){
        if(term <= N){
            distribute[i++] += term;
            N -= term;
            term++;
        }    
        else{
            distribute[i] += N;
            N = 0;
        }
    }

    int base = K*((count*(count - 1)) / 2);

    for(i = 0; i < K; i++)
        distribute[i] += count*(i + 1) + base;

    for(i = 0; i < K; i++)
        cout << distribute[i] << " ";
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n = 40, k = 5; 
    distributeCandy(n, k); 
    return 0;
}