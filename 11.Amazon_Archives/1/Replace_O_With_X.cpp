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
#define V 6
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
Time Complexity => O(MN) as every element processed at most 3 times.
*/

void floodFill(char mat[][V],int x, int y, char prevChar, char newChar){
    if( x < 0 || y >= V || y < 0 || x >= V ) return;
    if(mat[x][y] != prevChar) return;

    mat[x][y] = newChar;
    floodFill(mat, x+1, y , prevChar, newChar);
    floodFill(mat, x-1, y , prevChar, newChar);
    floodFill(mat, x, y+1 , prevChar, newChar);
    floodFill(mat, x, y-1 , prevChar, newChar);
}

void replaceSurrounded(char mat[][V]){
    for (int i = 0; i < V; i++)
        for (int j = 0; j < V; j++)
            if(mat[i][j] == 'O') 
                mat[i][j] = '-';

    for(int i = 0; i < V; i++)
        if(mat[0][i] == '-')
            floodFill(mat, 0 , i , '-', 'O');
    for(int i = 0; i < V; i++)
        if(mat[i][0] == '-')
            floodFill(mat, i , 0 , '-', 'O');
    for(int i = 0; i < V; i++)
        if(mat[i][V-1] == '-')
            floodFill(mat, i , V-1 , '-', 'O');
    for(int i = 0; i < V; i++)
        if(mat[V-1][i] == '-')
            floodFill(mat, V-1 , i , '-', 'O');
    
    for (int i = 0; i < V; i++) 
        for (int j = 0; j < V; j++) 
            if (mat[i][j] == '-') 
                mat[i][j] = 'X';
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
        
    char mat[][V] =  {{'X', 'O', 'X', 'O', 'X', 'X'}, 
                     {'X', 'O', 'X', 'X', 'O', 'X'}, 
                     {'X', 'X', 'X', 'O', 'X', 'X'}, 
                     {'O', 'X', 'X', 'X', 'X', 'X'}, 
                     {'X', 'X', 'X', 'O', 'X', 'O'}, 
                     {'O', 'O', 'X', 'O', 'O', 'O'}}; 
    replaceSurrounded(mat); 
  
    for (int i=0; i< V; i++){ 
        for (int j=0; j< V; j++) 
            cout << mat[i][j] << " "; 
      cout << endl; 
    } 
    return 0; 
}