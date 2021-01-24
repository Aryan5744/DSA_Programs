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
/*

Complexity Analysis:

Time Complexity:
Push operation : O(1)
Pop operation : O(1)
Auxiliary Space :O(N).
Use of array to implement stack so it is a space-optimised method.

*/

class twoStack{
    public: 
    int maxSize;
    int *arr;
    int top1, top2;
    
    twoStack(int n){
        maxSize = n;
        arr = new int[maxSize];
        top1 = -1;
        top2 = maxSize;
    }

    
    void push1(int val){
        if(top1 < top2 - 1)
            arr[++top1] = val;
        else 
            cout << "Overflow !!";
    }
    void push2(int val){
        if(top1 < top2 - 1)
            arr[--top2] = val;
        else 
            cout << "Overflow !!";
    }
    int pop1(){
        if(top1 > -1)
            return arr[top1--];
        else{
            cout << "Underflow !!";
            exit(1);
        } 
    }
    int pop2(){
        if(top2 < maxSize)
            return arr[top2++];
        else{
            cout << "Underflow !!";
            exit(1);
        }
    }
};

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    twoStack st(5);

    st.push2(1);
    st.push2(2); 
    st.push2(3);
    st.push2(4);
    st.push1(5);

    cout << st.pop2() << endl;
    cout << st.pop1();

    return 0;
}