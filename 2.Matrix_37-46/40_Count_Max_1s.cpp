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
#define Rows 10
#define Columns 10
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

int countOnes(int a[], int l, int r){
    if(l <= r){
        int mid = l + (r-l)/2;
        if( (mid == 0 || a[mid-1] == 0 ) && a[mid] == 1)
           return mid;
        else if(a[mid] == 0)
           return countOnes(a,mid+1,r);
        else
           return countOnes(a,l,mid-1);
    }
    return -1;
}
int solve(int a[Rows][Columns] , int M , int N){
    int max_row_index = INT_MIN , max_1s = INT_MIN;
    for(int i = 0; i < M ; i++){
        int total_1s = countOnes(a[i], 0 , N-1);
        if(total_1s != -1 && (N - total_1s) > max_1s){
            max_1s = N - total_1s;
            max_row_index = i;
        }
    }
    return max_row_index;
}
int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while(t--){
        int M,N;
        cin >> M >> N;
        int a[Rows][Columns];
        fo(i,M)
           fo(j,N)
               cin >> a[i][j];
        solve(a,M,N);
    }
    return 0;
}