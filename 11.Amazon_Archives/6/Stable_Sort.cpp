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
Let NN be the number of logs in the list and MM be the maximum length of a single log.

Time Complexity: O(M⋅N⋅logN)
First of all, the time complexity of the Arrays.sort() is O(N⋅logN), 
as stated in the API specification, which is to say that the compare() function would be 
invoked O(N⋅logN) times.
For each invocation of the compare() function, it could take up to O(M) time,
since we compare the contents of the logs.
Therefore, the overall time complexity of the algorithm 
is O(M⋅N⋅logN).
*/

bool my_compare(string log1, string log2){
    int p1 = log1.find(' ');
    string id1 = log1.substr(0,p1);
    string rest1 = log1.substr(p1+1,log1.size());
    
    int p2 = log2.find(' ');
    string id2 = log2.substr(0,p2);
    string rest2 = log2.substr(p2+1, log2.size());
    
    if(!isdigit(rest1[0]) && isdigit(rest2[0])){ 
        return true; //returing true means I want to order rest1 before rest2
    }else if(isdigit(rest1[0]) && !isdigit(rest2[0])){
        return false; //returing false means I want to order rest2 before rest1
    }else if(!isdigit(rest1[0]) && !isdigit(rest2[0])){
        if(rest2.compare(rest1) == 0){
           return id1 < id2;
        }else{
           return rest1 <rest2;
        }
    }
    return false;      
}

vector<string> reorderLogFiles(vector<string>& logs) {
    stable_sort(logs.begin(),logs.end(),my_compare);
    return logs;
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    vector<string> logs = {"let1 art can",
                           "dig1 8 1 5 1",
                           "dig2 3 6",
                           "let2 own kit dig",
                           "let3 art zero"};
    vector<string> res = reorderLogFiles(logs);
    for(auto s : res)
        cout << s << endl;
    return 0;
}