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

struct Node{
    public:
    int data;
    Node* next;
    Node* prev;
};
//                            nth         c
// NULL <-> 1 <-> 2 <-> 3 <-> 4 <-> 5 <-> 6 <-> NULL
// NULL <-> 5 <-> 6 <-> 1 <-> 2 <-> 3 <-> 4 <-> NULL

void rotateWithK(Node** node, int k){
    if(node == NULL || k == 0)
        return;

    Node* current = *node , *last;
    int count = 1;
    for(count = 1 ; count < k && current != NULL ; count++)
        current = current->next;
    
    if(current == NULL) 
        return;

    Node* nthNode = current;

    while(current->next != NULL)
        current = current->next;

    current->next = *node;
    (*node)->prev = current;
    *node = nthNode->next;
    (*node)->prev = NULL;
    nthNode->next = NULL;
}

void push(Node** head_ref, int new_data){
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node)); 
  
    // put in the data 
    new_node->data = new_data; 
  
    // since we are adding at the beginning, 
    // prev is always NULL 
    new_node->prev = NULL; 
  
    // link the old list off the new node 
    new_node->next = (*head_ref); 
  
    // change prev of head node to new node 
    if ((*head_ref) != NULL) 
        (*head_ref)->prev = new_node; 
  
    // move the head to point to the new node 
    (*head_ref) = new_node; 
}

void printList(Node* node){
    while(node != NULL){ 
        cout << node->data << " "; 
        node = node->next; 
    }
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while(t--){
        Node* head = NULL; 
        push(&head, 2); 
        push(&head, 12); 
        push(&head, 10); 
        push(&head, 4); 

        rotateWithK(&head , 2);
        printList(head); 
    }
    return 0;
}