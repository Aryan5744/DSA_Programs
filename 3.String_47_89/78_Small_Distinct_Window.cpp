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
void solve2(string str){
    int n = str.length(); 
    int dist_count = 0; 
    bool visited[256] = { false }; 
    for (int i = 0; i < n; i++) { 
        if (visited[str[i]] == false) { 
            visited[str[i]] = true; 
            dist_count++; 
        } 
    } 
    int count = 0, start = 0, min_len = INT_MAX, start_index;
    int curr_count[256] = {0};
    for(int i = 0 ; i < n ; i++){
        curr_count[str[i]]++;
        if(curr_count[str[i]] == 1)
           count++;
        if(count == dist_count){
            while (curr_count[str[start]] > 1){
                if(curr_count[str[start]] > 1)
                   curr_count[str[start]]--;  
                start++; 
            }
            int len_window = i - start + 1;
            if(len_window < min_len){
                min_len = len_window;
                start_index = start;
            }
        }
    }
    cout << str.substr(start,min_len);
}
void solve(string s){
    int n = s.length();
    unordered_map <int,int> mp;
    for(int i = 0 ; i < n ; i++)
        mp[s[i]]++;
    
    int dist_count = mp.size();
    string res;
    int size = INT_MAX; 
    for(int j = 0 ; j < n ; j++){
        int count = 0;
        int visited[256] = {0};
        string sub_str = "";
        for(int k = j ; k < n ; k++){
            if(visited[s[k]] == 0){
                count++;
                visited[s[k]] = 1;
            }
            sub_str += s[k];
            if(count == dist_count)
               break;
        } 
        if(sub_str.length() < size && count == dist_count)
            res = sub_str;
    }
    cout << res << endl;
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        solve(s);  //brute-force method - use has_map and store all the elements n their frequency n then
                   //generate sub-strings and check if all the map elements are present and update min_len.

        solve2(s); //sliding-window method - use ] hash array to mark the index visited then start counting
                   //frequencies and store them in another curr_count array unless it has all the elements
                   //and then update window size based on start index. 
    }
    return 0;
}