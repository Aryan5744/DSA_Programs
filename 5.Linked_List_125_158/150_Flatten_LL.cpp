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
    Node* right;
    Node* down;
};

void push (Node** head_ref, int new_data){ 
    /* allocate node */
    Node* new_node = (Node *) malloc(sizeof(Node)); 
    new_node->right = NULL; 
  
    /* put in the data  */
    new_node->data  = new_data; 
  
    /* link the old list off the new node */
    new_node->down = (*head_ref); 
  
    /* move the head to point to the new node */
    (*head_ref) = new_node; 
}

void printList(Node* node){
    while(node != NULL){ 
        cout << node->data << " "; 
        node = node->down; 
    }
}

Node* merge(Node* a, Node* b){
    if(a == NULL)
        return b;
    if(b == NULL)
        return a;
    
    Node* result;
    if(a->data < b->data){
        result = a;
        result->down = merge( a->down , b );
    }
    else{
        result = b;
        result->down = merge( a , b->down );
    }
    result->right = NULL;
    return result;
}

Node* flatten(Node* root){
    if(root == NULL || root->right == NULL)
        return root;
    return merge(root , flatten(root->right));
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while(t--){
        Node* root = NULL; 
        push( &root, 30 ); 
        push( &root, 8 ); 
        push( &root, 7 ); 
        push( &root, 5 ); 
    
        push( &( root->right ), 20 ); 
        push( &( root->right ), 10 ); 
    
        push( &( root->right->right ), 50 ); 
        push( &( root->right->right ), 22 ); 
        push( &( root->right->right ), 19 ); 
    
        push( &( root->right->right->right ), 45 ); 
        push( &( root->right->right->right ), 40 ); 
        push( &( root->right->right->right ), 35 ); 
        push( &( root->right->right->right ), 20 ); 

        flatten(root);
        printList(root); 
    }
    return 0;
}