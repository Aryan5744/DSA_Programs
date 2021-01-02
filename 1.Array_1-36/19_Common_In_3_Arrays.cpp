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

void solve(int _a1[], int _a2[], int _a3[], int _size1, int _size2, int _size3){
    int i = 0, j = 0, k = 0;

    while(i < _size1 && j < _size2 && k < _size3){
        if( _a1[i] == _a2[j] && _a2[j] == _a3[k]){
            cout << _a1[i] << " ";                 //use vector in case of need distinct
            i++;j++;k++;
        }
        else if(_a1[i] < _a2[j])
            i++;
        else if(_a2[j] < _a3[k])
            j++;
        else
            k++;
    }
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    
    int _size1, _size2, _size3;
    cin >> _size1 >> _size2 >> _size3;
    int _a1[_size1], _a2[_size2], _a3[_size3];

    fo(i,_size1)
       cin >> _a1[i];
    
    fo(i,_size2)
       cin >> _a2[i];
    
    fo(i,_size3)
       cin >> _a3[i];
    
    solve(_a1,_a2,_a3,_size1,_size2,_size3);
    cout << endl;
    return 0;
}