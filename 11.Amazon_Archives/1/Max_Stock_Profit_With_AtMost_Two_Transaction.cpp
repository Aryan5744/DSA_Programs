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
Time Complexity => O(N)
*/

int maxProfit(int prices[], int n){
    int profit[n];
    memset(profit, 0 , sizeof(profit));

    int max_price = prices[n-1];

    for(int i = n-2 ; i > 0 ; i--){
        max_price = max(max_price, prices[i]);
        profit[i] = max(profit[i+1], max_price - prices[i]);
    }

    int min_price = prices[0];

    for(int i = 1 ; i < n ; i++){
        min_price = min(min_price, prices[i]);
        profit[i] = max(profit[i-1], profit[i] + (prices[i] - min_price));
    }
    return profit[n-1];
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);      
        int prices[] = {2, 30, 15, 10, 8, 25, 80};
        int n = sizeof(prices)/sizeof(prices[0]);
        cout << maxProfit(prices,n);
    return 0;
}