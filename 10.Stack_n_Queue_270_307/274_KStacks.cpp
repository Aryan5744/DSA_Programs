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
*/

class kStacks{
    private:
    int *arr;
    int *top;
    int *next;
    int n, k, free;

    public:
    kStacks(int k, int n); 
  
    // A utility function to check if there is space available 
    bool isFull()   {  return (free == -1);  } 
  
    // To push an item in stack number 'sn' where sn is from 0 to k-1 
    void push(int item, int sn); 
  
    // To pop an from stack number 'sn' where sn is from 0 to k-1 
    int pop(int sn); 
  
    // To check whether stack number 'sn' is empty or not 
    bool isEmpty(int sn)  {  return (top[sn] == -1); } 
};

kStacks :: kStacks(int _k, int _n){
    // Initialize n and k, and allocate memory for all arrays 
    k = _k, n = _n; 
    arr = new int[n]; 
    top = new int[k]; 
    next = new int[n]; 
  
    // Initialize all stacks as empty 
    for (int i = 0; i < k; i++) 
        top[i] = -1; 
  
    // Initialize all spaces as free 
    free = 0; 
    for (int i=0; i<n-1; i++) 
        next[i] = i+1; 
    next[n-1] = -1;  // -1 is used to indicate end of free list 
}

void kStacks :: push(int item, int sn){
    if(isFull()){
        cout << "\nStack Overflow\n"; 
        return;
    }
    int i = free;
    free = next[i];
    next[i] = top[sn];
    top[sn] = i;
    arr[i] = item;
}

int kStacks :: pop(int sn){
    if (isEmpty(sn)){ 
         cout << "\nStack Underflow\n"; 
         return INT_MAX; 
    } 
    int i = top[sn];
    top[sn] = next[i];
    next[i] = free;
    free = i;
    return arr[i]; 
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int k = 3, n = 10; 
    kStacks ks(k, n); 
  
    // Let us put some items in stack number 2 
    ks.push(15, 2); 
    ks.push(45, 2); 
  
    // Let us put some items in stack number 1 
    ks.push(17, 1); 
    ks.push(49, 1); 
    ks.push(39, 1); 
  
    // Let us put some items in stack number 0 
    ks.push(11, 0); 
    ks.push(9, 0); 
    ks.push(7, 0); 
  
    cout << "Popped element from stack 2 is " << ks.pop(2) << endl; 
    cout << "Popped element from stack 1 is " << ks.pop(1) << endl; 
    cout << "Popped element from stack 0 is " << ks.pop(0) << endl;   
    return 0;  
}