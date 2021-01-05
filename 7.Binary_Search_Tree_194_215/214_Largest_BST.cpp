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
with top to bottom approach the time complexity will be O(n^2) in worst case
and with bottom to up approach the time complexity will be O(n) as we are passing info
to the parent node from each left and right child.
*/

struct Node{
    int data;
    struct Node *left, *right;
};
 
// A utility function to create a new node
Node *newNode(int data){
    Node *temp = new Node;
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}
 
/* A utility function to insert a new Node
  with given key in BST */
struct Node* insert(struct Node* node, int key){
    /* If the tree is empty, return a new Node */
    if (node == NULL) return newNode(key);

    /* Otherwise, recur down the tree */
    if (key < node->data)
        node->left = insert(node->left, key);
    else if (key > node->data)
        node->right = insert(node->right, key);
 
    /* return the (unchanged) Node pointer */
    return node;
}

struct  Info
{
    int size;
    int min;
    int max;
    int ans;
    bool isBST;
};


Info largestBSTBT(Node* root){
    if(!root){
        return {0,INT_MAX,INT_MIN,0,true};
    }
    if(!root->left || !root->right){
        return {1,root->data,root->data,1,true};
    }

    Info l = largestBSTBT(root->left);
    Info r = largestBSTBT(root->right);

    Info res;
    res.size = 1 + l.size + r.size;

    if(l.isBST && r.isBST && l.max < root->data && r.min > root->data){
        res.min = min(l.min , min(root->data, r.min));
        res.max = max(l.max , max(root->data, r.max));

        res.ans = res.size;
        res.isBST = true;

        return res;
    }
    res.ans = max(l.ans , r.ans);
    res.isBST = false;

    return res;
}


// main program 
int main() 
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);  
    /* Let us construct the following Tree 
       50
     /    \
    30     60
   /  \   /  \ 
  5   20 45   70
              / \
            65   80
*/
  
    struct Node *root = newNode(50); 
    root->left = newNode(30); 
    root->right = newNode(60); 
    root->left->left = newNode(5);
    root->left->right = newNode(20);
    root->right->left = newNode(45);
    root->right->right = newNode(70);
    root->right->right->left = newNode(65);
    root->right->right->right = newNode(80);

    printf(" Size of the largest BST is %d\n", largestBSTBT(root).ans); 
    return 0; 
} 