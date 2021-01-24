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

implement a stack with DLL which will support following operations in O(1) time complexity :
1) push() which adds an element to the top of stack.
2) pop() which removes an element from top of stack.
3) findMiddle() which will return middle element of the stack.

*/
class DLLNode{
    public:
    DLLNode *prev, *next;
    int data;
};

class myStack{
    public: 
    DLLNode *mid, *head;
    int count;
};

myStack *createMyStack(){
    myStack *ms = new myStack();
    ms->count = 0;
    return ms;
}

void push(myStack *ms, int new_data){
    DLLNode* new_node = new DLLNode();
    new_node->data = new_data;
    new_node->prev = NULL;
    new_node->next = ms->head;
    ms->count += 1;

    if(ms->count == 1)
        ms->mid = new_node;
    else{
        ms->head->prev = new_node;
        if(!(ms->count & 1))
            ms->mid = ms->mid->prev;
    }
    ms->head = new_node;
}

int pop(myStack* ms){
    if(ms->count == 0)
       return -1;
    
    DLLNode *head = ms->head;
    ms->head = head->next;
    ms->count -= 1;
    
    if(ms->head) ms->head->prev = NULL;

    if((ms->count) & 1) ms->mid = ms->mid->next;

    int item = head->data;

    free(head);

    return item;
}

int findMiddle(myStack *ms){
    return (ms->count > 0) ? ms->mid->data : -1;
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    myStack *ms = createMyStack();
    push(ms, 11);  
    push(ms, 22);  
    push(ms, 33);  
    push(ms, 44);  
    push(ms, 55);  
    push(ms, 66);  
    push(ms, 77);

    cout << "Item popped is " << pop(ms) << endl;  
    cout << "Item popped is " << pop(ms) << endl;  
    cout << "Middle Element is " << findMiddle(ms) << endl;  
    return 0;  
}