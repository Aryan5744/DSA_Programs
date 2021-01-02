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
int getMid(int s,int e){
    return s+(e-s)/2;
}
int constructSTUtil(int a[], int ss, int se, int *st, int si){
    if(ss  == se){
        st[si] = a[ss];
        return a[ss];
    }
    int mid = getMid(ss,se);
    st[si] = constructSTUtil(a,ss,mid,st,si*2+1)+constructSTUtil(a,mid+1,se,st,si*2+2);
    return st[si];
}
int* constructST(int a[], int N){
    int height = int(ceil(log2(N)-1));
    int size = 2*(int)pow(2,N) - 1;
    int *st = new int [size];
    constructSTUtil(a,0,N-1,st,0);
    return st;
}
int getSumUtil(int* st, int ss, int se, int qs, int qe, int si){
    if(qs <= ss && qe >= se)
       return st[si];
    if(qs > se || qe < ss)
       return 0;
    int mid = getMid(ss,se);
    return getSumUtil(st,ss,mid,qs,qe,si*2+1)+getSumUtil(st,mid+1,se,qs,qe,si*2+2);
}
int getSum(int* st, int N, int qs, int qe){
    if(qs < 0 || qe > N-1 || qs > qe)
       return -1;
    return getSumUtil(st,0,N-1,qs,qe,0);
}
void updateValueUtil(int* st, int ss, int se, int i, int diff, int si){
    if(i < ss || i > se)
       return;
    st[si] = st[si] + diff;
    if(ss != se){
        int mid = getMid(ss,se);
        updateValueUtil(st,ss,mid,i,diff,si*2+1);
        updateValueUtil(st,mid+1,se,i,diff,si*2+2);
    }
}
void updateValue(int a[], int *st, int N, int i, int new_val){
    if(i < 0 || i > N-1)
       return;
    int diff = new_val - a[i];
    a[i] = new_val;
    updateValueUtil(st,0,N-1,i,diff,0);
}
int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while(t--){
        int N = 6;
        int a[N] = {1,2,3,4,5,6};
        // cin >> N;
        // int a[N];
        // fo(i,N)
        //    cin >> a[i];
        int *st = constructST(a, N);
        int sum = getSum(st, N, 1, 3);
        cout << sum << endl;
        updateValue(a, st, N, 1, 10);        
        sum = getSum(st, N, 1, 3);
        cout << sum << endl;
    }
    return 0;
}