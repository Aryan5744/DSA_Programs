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

bool mySort(pair<int,int> p1,pair<int,int> p2){
    return p1.first < p2.first;
}

void solve(vector<pair<int,int>> a, int N){

    vector<pair<int,int>> intervals;
    sort(a.begin(), a.end(), mySort);

    pair<int,int> limit = {a[0].first,a[0].second};

    for(int i = 1; i < N ; i++){
        if(a[i].first <= limit.second)
            limit = {std::min(limit.first,a[i].first) , std::max(limit.second,a[i].second) };
        else{
            intervals.push_back(make_pair(limit.first,limit.second));
            limit = {a[i].first,a[i].second};
        }
    }
    intervals.push_back(make_pair(limit.first,limit.second));

    for(int i = 0 ; i < intervals.size() ; i++){
        cout << intervals[i].first << " " << intervals[i].second << " ";
    }
}

struct Interval{ 
    int start, end; 
}; 
  
bool compareInterval(Interval i1, Interval i2){ 
    return (i1.start < i2.start); 
}
void mergeIntervals(Interval arr[], int n){ 
    if (n <= 0) 
        return; 
    stack<Interval> s; 
    sort(arr, arr+n, compareInterval); 
    s.push(arr[0]); 

    for (int i = 1 ; i < n; i++){ 
        Interval top = s.top(); 
        if (top.end < arr[i].start) 
            s.push(arr[i]); 
        else if (top.end < arr[i].end) { 
            top.end = arr[i].end; 
            s.pop(); 
            s.push(top); 
        } 
    } 
    while (!s.empty()){ 
        Interval t = s.top(); 
        cout << "[" << t.start << "," << t.end << "] "; 
        s.pop(); 
    } 
    return; 
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while(t--){
        int N;
        cin>>N;
        vector<pair<int,int>> a;
        for(int i = 0 ; i < N ; i++){
            int p,q;
            cin >> p >> q;
            a.push_back(make_pair(p,q));
        }
        solve(a,N);
        cout << endl;
        
        //we can implement the same logic with stack as well
        
        Interval arr[] =  { {6,8}, {1,9}, {2,4}, {4,7} }; 
        int n = sizeof(arr)/sizeof(arr[0]); 
        mergeIntervals(arr, n);
    }
    return 0;
}