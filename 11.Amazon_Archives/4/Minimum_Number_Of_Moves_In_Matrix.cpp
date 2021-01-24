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

#define ROW 4
#define COL 4
//=======================

/*
Time Complexity: O(N*M).
In BFS traversal every element is traversed only once so time Complexity is O(M*N).
Space Complexity: O(1).
No extra space is required.
*/

pii getCordinatesForValue(int M[ROW][COL], int value){
    F(i,0,ROW)
        F(j,0,COL)
            if(M[i][j] == value)
               return make_pair(i,j);
    return make_pair(-1,-1);
}
bool isSafe(int i, int j, int M[][COL]){ 
    if((i < 0 || i >= ROW) || (j < 0 || j >= COL) || M[i][j] == 0) 
        return false; 
    return true; 
}

int BFS(pii src, pii dest, int M[ROW][COL]){
    int dx[] = {-1, 0, 1, 0};
	int dy[] = {0, 1, 0, -1};
    queue<pii> q;
    q.push(src);
    
    M[src.first][src.second] = 0;

    while(!q.empty()){
        pii currCell = q.front();
        q.pop();
        F(i,0,4){
            int x = currCell.first + dx[i];
            int y = currCell.second + dy[i];
            if(isSafe(x,y,M)){
                if(M[x][y] < 0){
                    M[x][y] = M[currCell.first][currCell.second] + 1;
                    q.push(make_pair(x,y));
                }
            }
        }
    }
    return M[dest.first][dest.second];
}
int MinimumPath(int M[ROW][COL]){
    pii src = getCordinatesForValue(M,1);
    pii dest = getCordinatesForValue(M,2);

    F(i,0,ROW)
        F(j,0,COL)
            M[i][j] = -1;

    return BFS(src,dest,M);
}
int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int M[ROW][COL] = {
        { 3 , 3 , 1 , 0 }, 
        { 3 , 0 , 3 , 3 }, 
        { 2 , 3 , 0 , 3 }, 
        { 0 , 3 , 3 , 3 } 
    }; 
    cout << MinimumPath(M) << endl;
    return 0;
}