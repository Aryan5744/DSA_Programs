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
Time Complexity: O(n). 
As only one traversal of the array is needed.
Auxiliary Space: O(1). 
As no extra space is required.
*/
bool isSafe(int x, int y, int N){
    if((x < 0 || x > N) || (y < 0 || y > N)) 
        return false;
    return true; 
}

int minStepToReachTarget(pii knightPos, pii targetPos, int N){
    int dx[] = {1,2,-2,-1,-2,-1,1,2};
    int dy[] = {2,1,1,2,-1,-2,-2,-1};

    int dist[N+1][N+1];

    F(i,0,N+1)
        F(j,0,N+1)
            dist[i][j] = 0;

    dist[knightPos.first][knightPos.second] = 1;

    queue<pii> q;
    q.push(knightPos);

    while(!q.empty()){
        pii currCell = q.front();
        q.pop();

        for(int i = 0; i < 8; i++){
            int _x = currCell.first + dx[i];
            int _y = currCell.second + dy[i];

            if(isSafe(_x, _y, N) && dist[_x][_y] < 1){
                dist[_x][_y] = dist[currCell.first][currCell.second] + 1;
                q.push(make_pair(_x,_y));
            }
        }
    }
    return dist[targetPos.first][targetPos.second] - 1;    
}
int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int N = 30; 
    pii knightPos = make_pair(1, 1); 
    pii targetPos = make_pair(30, 30); 
    cout << minStepToReachTarget(knightPos, targetPos, N);
    return 0;
}