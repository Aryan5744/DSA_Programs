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
Time complexity: O(N)
*/
class node{  
    public: 
    int data;  
    node* left, *right;  
    node(int data){ 
        this->data = data; 
        this->left = NULL; 
        this->right = NULL; 
    } 
};

void inorder(node* node){  
    if (node == NULL)  
        return;  
    inorder(node->left);  
    cout<<node->data<<" ";  
    inorder(node->right);  
}

int updateTree(node* root){
    if(!root) return 0;
    if(!root->left && !root->right) return root->data;

    int left_sum = updateTree(root->left);
    int right_sum = updateTree(root->right);

    root->data += left_sum;
    return root->data + right_sum;
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    struct node *root = new node(1);  
    root->left  = new node(2);  
    root->right = new node(3);  
    root->left->left = new node(4);  
    root->left->right = new node(5);  
    root->right->right = new node(6);  
  
    updateTree(root);  

    cout << "Inorder traversal of the modified tree is: \n";  
    inorder(root);  
    return 0;  
}