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
string solve2(string str, string pattern){
    if(str.length() < pattern.length())
        return "";

    int hash_str[256] = {0};
    int hash_pat[256] = {0};
    int count = 0, start = 0 , start_index = -1, min_len = INT_MAX;

    for(int i = 0 ; i < pattern.length() ; i++)
       hash_pat[pattern[i]]++;
    
    for(int j = 0 ; j < str.length() ; j++){
        hash_str[str[j]]++;

        if(hash_str[str[j]] != 0 && hash_str[str[j]] <= hash_pat[str[j]])
            count++;
        if( count == pattern.length() ){
            while(hash_str[str[start]] > hash_pat[str[start]] || hash_pat[str[start]] == 0){
                if(hash_str[str[start]] > hash_pat[str[start]])
                    hash_str[str[start]]--;
                start++;
            }
            cout << j << " " << start << endl;  
            int len_window = j - start + 1;
            if(min_len > len_window){
                min_len = len_window;
                start_index = start;
            }
        }
    }
    if(start_index == -1)
        return "";
    return str.substr(start_index,min_len);   
}
int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while(t--){
        string s,p;
        cin >> s >> p; 
        cout << solve2(s,p); //sliding-window method - phle frequency nikalo str aur pat dono ki fir
        // check kro ki str k kis index pe pat k sare char mil rhe h using frequencies and then reduce the 
        // frequencies jab tak pat k kisi b char ka eklauta match str me ni mil jata and then calculate 
        // start index using start n end index using j n then calculate. 
    }
    return 0;
}