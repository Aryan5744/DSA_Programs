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

int printSolution (int p[], int n, int size);

void findWordWrap(int words[], int size, int width){
    int cost[size][size];
    int sum[size+1] = {0};
    sum[1] = words[0];

    int c[size] ,arrange[size];

    memset(cost, -1 , sizeof(cost));

    for(int i = 0 ; i < size ; i++)
       cost[i][i] =  pow((width - words[i]),2);

    for(int i = 2 ; i <= size ; i++)
       sum[i] = sum[i-1] + words[i-1];

    for(int i = 1 ; i <= size ; i++){
        for(int j = i+1 ; j <= size ; j++){
            if((width - (sum[j]-sum[i-1]) - (j-i)) > 0)
                cost[i-1][j-1] = pow((width - (sum[j]-sum[i-1]) - (j-i)),2);
        }
    }

    int min = INT_MAX, splitIndex;
    int j = size-1;
    for(int i = size-1 ; i >= 0 ; i--){
        if(cost[i][j] != -1){
            c[i] = cost[i][j];
            arrange[i] = j+1;
        }
        else{
            while( j > i ){
                if(cost[i][j-1] != -1){
                    if( min > (c[j] + cost[i][j-1]) ){
                        min = c[j] + cost[i][j-1];
                        splitIndex = j;
                    }
                }
                j--;
            }
            c[i] = min;
            arrange[i] = splitIndex;
            j = size-1;
            min = INT_MAX;
        }
    }
    for(int i = 0  ;  i < size ; i++){
        cout << arrange[i] << " ";
    }
    cout << endl;

    printSolution(arrange,0,size);
} 
int printSolution (int p[], int n,int size) 
{ 
	int k; 
	if (p[n] == size) 
        k = 1;
	cout << n+1 <<" "<<p[n]<< " ";
    if(p[n] != size)
	    k = printSolution (p, p[n] ,size) + 1;  
	return k; 
    
} 

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while(t--){
        int size,width;
        cin >> size;
        int words[size];
        fo(i,size)
           cin >> words[i];
        cin >> width;
        findWordWrap(words, size, width);
        cout << endl;
    }
    return 0;
    int l[] = {3, 2, 2}; 
    // int n = sizeof(l)/sizeof(l[0]); 
    // int M = 4; 
    // findWordWrap(l, n, M); 
    // return 0; 
}