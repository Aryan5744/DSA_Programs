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
void swap(int *a1, int *b1){
    int temp = *a1;
    *a1 =  *b1;
    *b1 = temp;
}
void merge(int ar1[], int ar2[], int m, int n) 
{  
    for (int i=n-1; i>=0; i--){ 
        int j, last = ar1[m-1]; 
        for (j=m-2; j >= 0 && ar1[j] > ar2[i]; j--) 
            ar1[j+1] = ar1[j]; 
        if (j != m-2 || last > ar2[i]){ 
            ar1[j+1] = ar2[i]; 
            ar2[i] = last; 
        } 
    } 
} 
void solve(int a[], int b[] , int M , int N){
    
    for( int i = 0 ; i < M ; i++ ){
        for( int j = 0 ; j < N ; j++ ){
            if(a[i] > b[j]){
                swap(&a[i],&b[j]);
            }
        }
    }
    sort(a,a+M);
    sort(b,b+N);
    fo(i,M)
       cout << a[i] << " ";
       
    fo(i,N)
       cout << b[i] << " ";
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while(t--){

        //int M,N;
        //cin >> M >> N;
        //int _a[M], _b[N];
        // fo(i,M)
        //    cin >> _a[i];
        // fo(i,N)
        //    cin >> _b[i];
    int _a[] = {1, 5, 9, 10, 15, 20}; 
    int _b[] = {2, 3, 8, 13}; 
    int M = sizeof(_a)/sizeof(_a[0]); 
    int N = sizeof(_b)/sizeof(_b[0]);
        solve(_a,_b,M,N);
    }
    return 0;
}