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

ll int solve(ll int a[], ll int n1, ll int b[], ll int n2){

    int suma = 0, sumb = 0, i = 0, j = 0, res = 0;
    while(i < n1 && j < n2){
        
        if(a[i] < b[j]) 
            suma += a[i++];
        else if(b[j] < a[i])
            sumb += b[j++];
        else if(a[i] == b[j]){
            res += std::max(suma + a[i++] , sumb + b[j++]);
            suma = sumb = 0;
        }

        //cout << suma << " " << i << " " << sumb << " " << j << endl;
    }
    while(i < n1)
        suma += a[i++];
    while(j < n2)
        sumb += b[j++];
    
    res += std::max(suma , sumb);

    return res;
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    //int t;
    //cin >> t;
    //while(t--){
        ll int n1,n2,z;
        
        cin >> n1;
        ll int a[n1];
        fo(i , n1)
            cin >> a[i];

        cin >> n2;
        ll int b[n2];
        fo(i , n2)
            cin >> b[i];
        
        cout << solve(a,n1,b,n2) << endl;
        cin >> z;

        
    //}
    return 0;
}