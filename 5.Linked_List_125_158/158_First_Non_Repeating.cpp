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
    char data;
    Node* next , *prev;
};

void printList(Node* node){
    while(node != NULL){ 
        cout << node->data << " "; 
        node = node->next; 
    }
}

Node *newNode(int data) { 
    struct Node *new_node = (struct Node *) malloc(sizeof(struct Node)); 
    new_node->data = data; 
    new_node->next = NULL; 
    return new_node; 
} 
void push(struct Node** head_ref, int new_data){ 
    // allocate node  
    struct Node* new_node = newNode(new_data); 
  
    // link the old list off the new node  
    new_node->next = (*head_ref); 
  
    // move the head to point to the new node  
    (*head_ref) = new_node; 
} 

void reverseList(Node** head){
    Node* curr = *head;
    Node* prev = NULL;
    Node* next;
    while(curr != NULL){
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    *head = prev;
}

void appendNode(Node** head , Node** tail , char x){
    Node* temp = new Node;
    temp->data = x;
    temp->prev = temp->next = NULL;

    if(*head == NULL){
        *head = *tail = temp;
        return;
    }
    (*tail)->next = temp;
    temp->prev = *tail;
    *tail = temp;
}

void removeNode(Node** head , Node** tail , Node* temp){
    if(*head == NULL)
        return;
    if(*head == temp)
        *head = (*head)->next;
    if(*tail == temp)
        *tail = (*tail)->prev;
    if(temp->next != NULL)
        temp->next->prev = temp->prev;
    if(temp->prev != NULL)
        temp->prev->next = temp->next;
    delete(temp);
}

void findFirstNonRepeating(){
    Node* inDLL[256];
    bool repeated[256];

    for(int i = 0; i < 256 ; i++) { 
        inDLL[i] = NULL; 
        repeated[i] = false; 
    } 

    Node* head = NULL , *tail = NULL;
    char stream[] = "geeksg";

    for(int i = 0 ; stream[i] ; i++){
        char x = stream[i];

        if(!repeated[x]){
            if(inDLL[x] == NULL){
                appendNode(&head , &tail , x);
                inDLL[x] = tail;
            }else{
                removeNode(&head , &tail , inDLL[x]);
                inDLL[x] = NULL;
                repeated[x] = true;
            }
        }
        if (head != NULL) 
            cout << "First non-repeating character so far is " << head->data << endl;
    } 
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    findFirstNonRepeating();
    return 0;
}