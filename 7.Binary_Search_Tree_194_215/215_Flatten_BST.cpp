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
typedef pair<int, vpii> pivii;
//=======================

/*
with inOrderTraversal space complexity will become O(N) whereas
with *prev node approach space complexity will become O(H)
*/

struct Node{
    int data;
    struct Node *left, *right;
};
 
// A utility function to create a newNode
Node *newNode(int data){
    Node *temp = new Node();
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}
 
/* A utility function to insert a newNode
  with given key in BST */
struct Node* insert(struct Node* node, int key){
    /* If the tree is empty, return a newNode */
    if (node == NULL) return newNode(key);

    /* Otherwise, recur down the tree */
    if (key < node->data)
        node->left = insert(node->left, key);
    else if (key > node->data)
        node->right = insert(node->right, key);
 
    /* return the (unchanged) Node pointer */
    return node;
}

void inOrder(Node* root, Node* &prev){
    if(!root) return;
    inOrder(root->left, prev);
    prev->left = NULL;
    prev->right = root;
    prev = root;
    inOrder(root->right, prev);
}

void print(Node* root){
    while(root) cout << root->data << " " , root = root->right;
}

Node* flatten(Node* root){
    Node* dummy = newNode(-1);
    Node* prev = dummy;

    inOrder(root, prev);

    prev->left = prev->right = NULL;

    Node* res = dummy->right;

    delete dummy;
    return res;
}

// main program 
int main() 
{   
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);  
    /* Let us construct the following Tree 
          5 
        /   \ 
       3     7 
      / \   / \ 
     2   4 6   8
*/
  
    Node* root = newNode(5); 
    root->left = newNode(3); 
    root->right = newNode(7); 
    root->left->left = newNode(2); 
    root->left->right = newNode(4); 
    root->right->left = newNode(6); 
    root->right->right = newNode(8); 

    print(flatten(root)); 
    return 0; 
} 