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
1. Time Complexity: The solution involves a simple traversal of the given tree. 
So the time complexity is O(n) where n is the number of nodes in the given Binary Tree.

2. Time Complexity: O(n), where n is the number of nodes in the binary tree.
*/

class node{  
    public: 
    int data;  
    node* left;  
    node* right;  
};  
  
/* Helper function that allocates a new node with the  
given data and NULL left and right pointers. */
node* newNode(int data)  
{  
    node* Node = new node(); 
    Node->data = data;  
    Node->left = NULL;  
    Node->right = NULL;  
  
    return(Node);  
}  

void leftViewUtil(node* root, int level , int* max_level){
    if(!root) return;
    if(*max_level < level){
        cout << root->data << " ";
        *max_level = level;
    }
    leftViewUtil(root->left, level + 1 , max_level);
    leftViewUtil(root->right, level + 1 , max_level);
}

void leftView(node* root){
    int max_level = 0;
    leftViewUtil(root, 1, &max_level);
}

void printLeftView(node* root){
    queue<node*> q;
    q.push(root);

    while(!q.empty()){
        int size = q.size();
        for(int i = 1 ; i <= size ; i++){
            
            node* temp = q.front();
            q.pop();

            if(i == 1)
                cout << temp->data << " ";
            
            if(temp->left)
                q.push(temp->left);
            if(temp->right)
                q.push(temp->right);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    node *root1 = newNode(1);  
    node *root2 = newNode(1);  
    root1->left = newNode(2);  
    root1->right = newNode(3);  
    root1->left->left = newNode(4);  
    root1->left->right = newNode(5);  
    //leftView(root1);  //recursive approach
    printLeftView(root1); // using queue

    return 0;
}