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
void printCommonElements(int mat[Rows][Columns], int M, int N){ 
    unordered_map<int, int> mp; 
    // initalize 1st row elements with value 1 
    for (int j = 0; j < N; j++) 
        mp[mat[0][j]] = 1; 
  
    // traverse the matrix 
    for (int i = 1; i < M; i++){ 
        for (int j = 0; j < N; j++){ 
            // If element is present in the map and 
            // is not duplicated in current row. 
            if (mp[mat[i][j]] == i){ 
               // we increment count of the element 
               // in map by 1 
                mp[mat[i][j]] = i + 1; 
                // If this is last row 
                if (i==M-1) 
                  cout << mat[i][j] << " "; 
            } 
        } 
    } 
} 
int findCommonUtil(int mat[Rows][Columns], int M, int N){
    int minArr[M];
    fo(i,M)
       minArr[i] = N-1;
    /* minArr [4] = {4,4,4,4} */
    int minIndex = 0;
    vector<int> res; 
    while(N-- >= 0){
        for(int i = 0 ; i<M ; i++)
            if(mat[i][minArr[i]] < mat[minIndex][minArr[minIndex]])
                minIndex = i;
        
        int eq_count = 0;
        fo(i,M){
            if(mat[i][minArr[i]] > mat[minIndex][minArr[minIndex]]){
                if(minArr[minIndex] == 0)
                    return -1;
                minArr[i] -= 1;
            }else
                eq_count++;
        }
        if(eq_count == M)
            return mat[minIndex][minArr[minIndex]];
    }
    return -1;
}
vector<int> findCommon(int mat[Rows][Columns], int M, int N){
    vector<int> result;
    for(int i = N ; i > 0 ; i--){
        int res = findCommonUtil(mat,M,i);
        if(res != -1)
            result.push_back(res);
    }
    return result;
}
int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int M = 4, N = 5;
    int mat[Rows][Columns] = { 
        { 1, 2, 3, 4, 5 }, 
        { 1, 4, 5, 8, 10 }, 
        { 1, 4, 5, 9, 11 }, 
        { 1, 4, 5, 7, 9 }, 
    }; 
    vector<int> result = findCommon(mat,M,N); 
    if (result.size() == 0) 
        cout << "No common element"; 
    else
        fo(i,result.size())
            cout << result[i] << " ";
    cout << endl; 

    /* maintain an array of size M to contain min value from last column and keep on comparing unless you find
    same element but this has more time complexity O(M*N*N) */

    /* we can use hashing also which has O(MNlogN) */
    return 0;
}