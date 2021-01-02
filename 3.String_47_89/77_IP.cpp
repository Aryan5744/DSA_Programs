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
bool isValid(string part){
    if((part.length() > 3) || (part[0] == '0' && part.length() > 1))
       return false; 
    stringstream obj(part);  
    int x = 0; 
    obj >> x;
    return (x >= 0 && x <= 255);
}
void findIPAddress(string s1,int n){
    vector<string> l1;
    for(int i = 1 ; i < n && i < 4; i++){
        string first = s1.substr(0,i);
     //   cout <<"first : "<< first << ".";
        if(!isValid(first))
           continue;
        for(int j = 1 ; i+j < n && j < 4 ; j++){
            string second = s1.substr(i,j);
       //     cout <<"second : "<< second << ".";
            if(!isValid(second))
               continue;
            for(int k = 1 ; i+j+k < n && k < 4; k++){
                string third = s1.substr(i+j,k);
                string fourth = s1.substr(i+j+k,n-k);
         //       cout<<"third : " << third << ".";
           //     cout<<"fourth : " << fourth << endl;
                if(!isValid(third) || !isValid(fourth))
                   continue;
                l1.push_back(first+"."+second+"."+third+"."+fourth);
            }   
        }
    }
    cout << endl;
    for(int i = 0 ; i < l1.size() ; i++)
       cout << l1[i] << endl;
}
int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while(t--){
        string s1 = "25525511135";
        //cin >> s1;
        //cout << s1 << endl;
        findIPAddress(s1,s1.length());
    }
    return 0;
}