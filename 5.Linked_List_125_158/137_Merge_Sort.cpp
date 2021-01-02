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
    int data;
    Node* next;
};

void push(Node** head, int data){
    Node* new_node = new Node;
    new_node->data = data;
    new_node->next = *head;
    *head = new_node;
}

void splitList(Node *h, Node** a, Node** b){
    Node* slow = h;
    Node* fast = h->next;

    while(fast != NULL){
        fast = fast->next;
        if(fast != NULL){
            fast = fast->next;
            slow = slow->next;    
        }
    }
    *a = h;
    *b = slow->next;
    slow->next = NULL;
}

Node* merge(Node* a, Node* b){
    Node* result = NULL;

    if(a == NULL)
       return b;
    if(b == NULL)
       return a;
    
    if(a->data <= b->data){
        result = a;
        result->next = merge(a->next , b);
    }else{
        result = b;
        result->next = merge(a , b->next);
    }
    return result;
}

Node* mergeSort(Node** head){
    Node* h = *head;
    Node* a;
    Node* b;

    if(h == NULL || h->next == NULL)
        return;
    
    splitList(h,&a,&b);
    mergeSort(&a);
    mergeSort(&b);
    *head = merge(a , b);   
}

void printList(Node *node)  {  
    while (node != NULL){  
        cout << node->data<<" ";  
        node = node->next;
    } 
    cout << endl; 
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while(t--){
        Node* head1 = NULL;  
        push(&head1 , 4);
        push(&head1 , 3);
        push(&head1 , 2);
        push(&head1 , 1);

        cout << intersectionAtY(head1 , head2) << endl;
    }
    return 0;
}