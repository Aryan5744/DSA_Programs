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

bool solve(int a[], int N, int K){
    fo(i,N-2){
        int start = i+1 ,end = N-1;
        while(start < end){
            if(a[i] + a[start] + a[end] == K)
               return true;
            else if(a[i] + a[start] + a[end] < K)
               start++;
            else
               end--;
        }
    }
    return false;
}
bool solve1(int a[], int N, int K){
    unordered_set<int> s;
    fo(i,N-2){
        int curr_sum = K - a[i];
        for(int j = i+1 ; j < N ; j++){
            if(s.find(curr_sum - a[j]) != s.end())
               return true;
            s.insert(a[j]);
        }
    }
}
int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int N = 20;
    int K = 10;
    int a[N] = {6, 6, 2, 3, 1, 4, 1, 5, 6, 2, 8, 7, 4 ,2, 1, 3, 4, 5, 9, 6};
    solve(a,N,K);                 //two - pointer approach  O(n^2)
    solve1(a,N,K);                //hashing approach O(n^2)
    return 0;
}