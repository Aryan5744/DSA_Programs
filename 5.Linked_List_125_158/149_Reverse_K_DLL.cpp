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

Node* getNode(int data){ 
    // allocate space 
    Node* new_node = (Node*)malloc(sizeof(Node)); 
   
    // put in the data 
    new_node->data = data; 
    new_node->next = new_node->prev = NULL; 
    return new_node; 
}

void push(Node** head_ref, Node* new_node){ 
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

Node* revListInGroupOfGivenSize(Node* node, int k){
    if(node == NULL || k == 0)
        return node;
    Node* current = node;
    Node* next = NULL;
    Node* newHead = NULL;

    int count = 0;
    while(current != NULL && count < k){
        next = current->next;
        push(&newHead , current);
        current = next;
        count++;
    }

    if(next != NULL){
        node->next = revListInGroupOfGivenSize(next , k);
        node->next->prev = node;
    }

    return newHead;
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
        push(&head, getNode(2)); 
        push(&head, getNode(12)); 
        push(&head, getNode(10)); 
        push(&head, getNode(4)); 

        head = revListInGroupOfGivenSize(head , 2);
        printList(head); 
    }
    return 0;
}