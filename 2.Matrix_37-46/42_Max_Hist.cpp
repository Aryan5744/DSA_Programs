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
#define Rows 100
#define Columns 100
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

int maxHist(int a[], int N){
    stack<int> s;
    int i = 0 , max_area = INT_MIN;
    while(i < N){
        if(s.empty() || a[s.top()] <= a[i])
           s.push(i++);
        else{
            int top = s.top();
            s.pop();
            int area = a[top] * (s.empty() ? i : i - s.top() - 1);
            max_area = std :: max(max_area, area); 
        }
    }
    while(!s.empty()){
        int top = s.top();
        s.pop();
        int area = a[top] * (s.empty() ? i : i - s.top() - 1);
        max_area = max(max_area, area);
    }
    return max_area;
}
/*
0 1 2 3
6 5 4 5
st -> 0, 
*/
int getMaxArea(int mat[Rows][Columns], int M, int N){
    int result = maxHist(mat[0],N);
    for(int i = 1; i < M; i++){
        fo(j,N)
            if(mat[i][j])
               mat[i][j] += mat[i-1][j];
        result = max(result,maxHist(mat[i],N));
    } 
    return result;
}
int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while(t--){
        int M,N;
        cin >> M >> N;
        int mat[Rows][Columns];
        fo(i,M)
            fo(j,N)
               cin >> mat[i][j];
        cout << getMaxArea(mat,M,N) << endl;    
/*Using Stack we are pushing if a[i] > a[st.top()] else keep on poping unless you find 
the element smaller than that && we can you Segment Tree approach as well with O(NlogN)*/
    }
    return 0;
}