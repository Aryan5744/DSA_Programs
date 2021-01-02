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
#define RT(X) return X
#define I(X) cin>>X
#define O(X) cout<<X
#define V 10
#define R 100
#define C 100

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
Similar to Code - 69 just the number of directions is diff.
har word ko ek ek kar k search karna h in all the directions and these x n y arrays are (x,y) co-ordinates
of all the 4 directions.
*/
int x[] = {-1,0,0,1};
int y[] = {0,-1,1,0};

bool findWord(char grid[R][C], int row, int column, string word, int M, int N){
    
    if(grid[row][column] != word[0])
        return false;
    int len = word.length();
    for(int dir = 0 ; dir < 8 ; dir++){    
        int rd = row + x[dir] , cd = column + y[dir] , k;
        for(k = 1 ; k < len ; k++){
            if(rd < 0 || rd >= M || cd < 0 || cd >= N)
               break;
            if(grid[rd][cd] != word[k])
               break;
            rd += x[dir] , cd += y[dir];
        }
        if(k == len)
           return true;
    }    
    return false;
}

int solve(char grid[R][C], int rows, int columns, string X){
    int counter = 0;
    for(int i = 0  ; i < rows ; i++)
        for(int j = 0 ; j < columns ; j++)
            if(findWord(grid,i,j,X,rows,columns))
                counter++; 
    return counter;
}
int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while(t--){
        // char mat[R][C];
        // int M,N;
        // cin >> M >> N;
        // fo(i,M)
        //    fo(j,N)
        //       cin >> mat[i][j];
        // string X;
        // cin >> X;
        char grid[R][C] = { "BBABBM",  
                            "CBMBBA",  
                            "IBABBG",  
                            "GOZBBI",  
                            "ABBBBC",  
                            "MCIGAM"
                          };  
        cout << solve(grid,6,6,"MAGIC") << endl;
    }
    return 0;
}