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
int maxProfit(int price[], int start, int end){       //when multiple transactions are allowed 

    int best_without_stock = 0, best_with_stock = INT_MIN , prev = INT_MIN , count = 0; 
    for (int i = start; i <= end; i++){
        best_with_stock = max(best_with_stock, best_without_stock - price[i]);
        best_without_stock = max(best_without_stock , best_with_stock + price[i]);

        if(prev != best_with_stock){
            prev = best_with_stock;
            count++;
        }

        if(count == 3)
           return best_without_stock; 
    }
    return best_without_stock;
} 
int maxProfit1(int price[], int start, int end){       //when at-most 1 transactions is allowed 

    int best_without_stock = 0, best_with_stock = INT_MAX; 
    for (int i = start; i <= end; i++){
        best_with_stock = min(best_with_stock, price[i]);
        best_without_stock = max(best_without_stock , price[i] - best_with_stock);
    }
    return best_without_stock;
}
int maxProfit2(int price[], int N){       //when at-most 2 transactions is allowed 
    
    int profit[N];
    fo(i,N)
       profit[i] = 0;

    int maxPrice = price[N-1];
    for(int i = N-2 ; i>= 0 ; i--){
        if(price[i] > maxPrice)
           maxPrice = price[i];
        
        profit[i] = max(profit[i+1] , maxPrice - price[i]);

    fo(i,N)
       cout << profit[i] << " ";
    END();
    }

    int minPrice = price[0];
    for(int i = 1 ; i < N ; i++){
        if(price[i] < minPrice)
           minPrice = price[i];
        
        profit[i] = max(profit[i-1] ,profit[i] + (price[i] - minPrice));

    fo(i,N)
        cout << profit[i] << " ";
    END();
    }
    return profit[N-1];
}  
int main() 
{ 
	int price[] = { 1,2,3,4,5,1,2,3,4,1,2,3}; 
	int n = sizeof(price) / sizeof(price[0]); 
	cout << maxProfit2(price, n); 
	return 0; 
}