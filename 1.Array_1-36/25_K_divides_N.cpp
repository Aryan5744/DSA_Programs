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

struct ele{
    int e;
    int c;
};
void solve2(int a[], int N, int K){
    if(K < 2)
       return;
    struct ele obj[K-1];
    for(int j = 0 ; j < K-1 ; j++)
       obj[j].c = 0;
    for(int i = 0 ; i < N ; i++){
        int element = a[i];
        int j;
        for(j = 0 ; j < K-1 ; j++)
           if(obj[j].e == element){
               obj[j].c++;
               break;
           }
        if(j == K-1){
            int l;
            for(l = 0 ; l < K-1 ; l++){
                if(obj[l].c == 0){
                    obj[l].e = element;
                    obj[l].c++;
                    break;
                }
            }
            if(l == K-1)
               for(int o = 0; o < K ; o++)
                   obj[o].c--;
        }
    }
    vi v;
    for(int i = 0 ; i < K-1 ; i++){
        int ec = 0;
        for(int j = 0 ; j < N ; j++)
            if(obj[i].e == a[j])
               ec++;
        if(ec > N/K)
           v.push_back(obj[i].e);
    }
    for(int i = 0 ; i < v.size() ; i++)
       cout << v[i] << " ";
    cout << endl;
}

void solve(int a[], int N, int K){
    map<int,int> m;
    fo(i,N)
       m[a[i]]++;
    int res = N/K;
    vi v;
    map<int,int> :: iterator itr = m.begin();
    for(itr = m.begin() ; itr != m.end() ; itr++)
        if(itr->second > res)
           v.push_back(itr->first);
    
    for(int i = 0 ; i < v.size() ; i++)
        cout << v[i] << " ";
    END(); 
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int N, K;
    cin >> N >> K;
    int a[N];
    fo(i,N)
       cin >> a[i];
    solve(a,N,K); //hash map approach
    solve2(a,N,K); //temp array n store K-1 & their frequency  
                   //because output will never have elements more than K-1
    return 0;
}