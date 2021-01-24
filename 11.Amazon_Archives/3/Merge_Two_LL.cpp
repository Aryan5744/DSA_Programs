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
Time complexity:O(N).
Only one traversal of the linked lists are needed.
Auxiliary Space:O(N).
If the recursive stack space is taken into consideration.
*/

struct Node{ 
    int data; 
    struct Node* next; 
}; 
  
// Function to create newNode in a linkedlist 
Node* newNode(int key) 
{ 
    struct Node* temp = new Node; 
    temp->data = key; 
    temp->next = NULL; 
    return temp; 
} 
  
// A utility function to print linked list 
void printList(Node* node) 
{ 
    while (node != NULL) { 
        printf("%d  ", node->data); 
        node = node->next; 
    } 
} 

Node* merge(Node* h1, Node* h2){
    if(!h1) return h2;
    if(!h2) return h1;
    if(h1->data < h2->data){
        h1->next = merge(h1->next, h2);
        return h1;
    }
    else{
        h2->next = merge(h1, h2->next);
        return h2;
    }
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    Node* head1 = newNode(1); 
    head1->next = newNode(3); 
    head1->next->next = newNode(5); 
  
    // 1->3->5 LinkedList created 
  
    Node* head2 = newNode(0); 
    head2->next = newNode(2); 
    head2->next->next = newNode(4); 
  
    // 0->2->4 LinkedList created 
  
    Node* mergedhead = merge(head1, head2); 
  
    printList(mergedhead); 
    return 0;
}