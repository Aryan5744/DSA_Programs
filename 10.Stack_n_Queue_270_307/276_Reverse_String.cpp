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

class Stack{
    public: 
    int maxSize;
    char *stackArr;
    int top;

    Stack(int n){
        maxSize = n;
        stackArr = new char[maxSize];
        top = -1;
    }
    int peek(){
        return stackArr[top];
    }
    bool isEmpty(){
        return (top == -1) ? true : false;
    }
    bool isFull(){
        return (top == maxSize-1) ? true : false;
    }
    void push(char val){
        stackArr[++top] = val;
    }
    int pop(){
        return stackArr[top--];
    }
};
void reverse(char str[]){
    int n = strlen(str);  
    Stack st(n);  

    for(int i = 0; i < n; i++)  
        st.push(str[i]);    
    for(int i = 0; i < n; i++)  
        str[i] = st.pop();  
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    char str[] = "abcd";
    reverse(str);
    cout << "Reversed string is : " << str;
    return 0;
}