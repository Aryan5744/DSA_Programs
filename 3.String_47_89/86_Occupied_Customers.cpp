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
char* solve2(char* str, char* last_removed){
    if(str[0] == '\0' || str[1] == '\0')
        return str;
    
    // Remove leftmost same characters and recur for remaining string
    if (str[0] == str[1])
    {
        *last_removed = str[0];
        while (str[1] && str[0] == str[1])
            str++;
        str++;
        return solve2(str, last_removed);
    }
    // At this point, the first character is definiotely different from its adjacent. Ignore first 
    // character and recursively remove characters from remaining string

    char *rem_str = solve2(str+1,last_removed);
    
    // Check if the first character of the rem_string matches with the first character of the original string

    cout << rem_str << " " << str  << " " << *last_removed << " " << endl;

    if (rem_str[0] && rem_str[0] == str[0]){
        *last_removed = str[0];
        // Remove first character
        return (rem_str+1); 
    }

    // If remaining string becomes empty and last removed character is same as first character of 
    // original string. This is needed for a string like "acbbcddc"

    if (rem_str[0] == '\0' && *last_removed == str[0])
        return rem_str;
    
    // If the two first characters of str and rem_str don't match, append first character of str 
    // before the first character of rem_str. 

    rem_str--;
    rem_str[0] = str[0];
    return rem_str;
}
int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while(t--){
        char s[] = "aaaaxxzy"; 
        char last_removed = '\0';
        cout << (solve2(s,&last_removed));
    }
    return 0;
}