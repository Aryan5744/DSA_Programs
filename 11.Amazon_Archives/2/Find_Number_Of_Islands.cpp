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

#define ROW 5 
#define COL 5 

//=======================

/*
Time complexity: O(ROW x COL)
*/
bool isSafe(int r, int c, int M[][COL], int visited[][COL]){
    return (r>=0 && r < ROW) && (c >= 0 && c < COL) && (!visited[r][c] && M[r][c]);
}

void DFS(int M[][COL], int r, int c, int visited[][COL]){
    static int rowNbr[] = {-1,-1,1,0,1,1,1,0};
    static int colNbr[] = {-1,0,-1,1,1,0,-1,-1};

    visited[r][c] = true;
    
    for(int i = 0 ; i < 8 ; ++i)
        if(isSafe(r + rowNbr[i], c + colNbr[i], M, visited))
            DFS(M, r + rowNbr[i], c + colNbr[i], visited);
}

int countIslands(int M[][COL]){
    int visited[ROW][COL];
    
    memset(visited,false,sizeof(visited));

    int count = 0;

    for(int i = 0 ; i < ROW ; ++i){
        for(int j = 0 ; j < COL ; ++j){
            if(M[i][j] && !visited[i][j]){
                DFS(M, i, j, visited);
                ++count;
            }
        }
    }
    return count;
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int M[][COL]  = {{ 1, 1, 0, 0, 0 }, 
                     { 0, 1, 0, 0, 1 }, 
                     { 1, 0, 0, 1, 1 }, 
                     { 0, 0, 0, 0, 0 }, 
                     { 1, 0, 1, 0, 1 }}; 
  
    cout << "Number of islands is: " << countIslands(M); 
    return 0;
}