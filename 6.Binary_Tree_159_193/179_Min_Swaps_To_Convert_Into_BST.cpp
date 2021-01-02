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

class Node{
    public:
    Node* left , *right;
    char data;
};

void inOrder(vector<int> &v , int a[], int n, int index){ 
    if (index >= n) 
        return; 
    inOrder(v , a , n , 2*index + 1);  
    v.push_back(a[index]); 
    inOrder(v , a , n , 2*index + 2); 
}

int findMinSwaps(vector<int> &v){
    vector<pair<int,int>> t(v.size());

    for(int i = 0 ; i < v.size() ; i++)
        t[i].first = v[i] , t[i].second = i;

    sort(t.begin() , t.end());

    int swaps = 0;
    for(int i = 0 ; i < t.size() ; i++){
        if(i == t[i].second)
            continue;
        else{
            swap(t[i].first , t[t[i].second].first);
            swap(t[i].second , t[t[i].second].second);
        }
        if(i != t[i].second)
            i--;
        swaps++;
    }
    return swaps;
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int a[] = { 5, 6, 7, 8, 9, 10, 11 }; 
    int n = sizeof(a) / sizeof(a[0]); 
    vector<int> v;
    inOrder(v , a , n , 0);
    cout << findMinSwaps(v);
    return 0;
}