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

struct Node 
{ 
int data; 
struct Node *left, *right; 
}; 
  
// create a new BST node 
Node* newNode(int key) 
{ 
struct Node *temp =  new struct Node(); 
temp->data = key; 
temp->left = temp->right = NULL; 
return temp; 
} 

Node* insert(Node* root, int key){
    if(!root)
        return newNode(key); 
    if(key < root->data)
        root->left = insert(root->left , key);
    else
        root->right = insert(root->right , key);
    return root;
}
void inorder(struct Node* root){ 
    if(root != NULL){ 
        inorder(root->left); 
        cout << root->data << " "; 
        inorder(root->right); 
    } 
}
int minValueNode(Node* root){
    Node* curr = root;
    if(curr->left){
        while(curr->left != NULL)
           curr = curr->left;
        return curr->data;
    }
    else
        return root->data;
}
int maxValueNode(Node* root){
    Node* curr = root;
    if(curr->right){
        while(curr->right != NULL)
           curr = curr->right;
        return curr->data;
    }
    else
        return root->data;
}
// main program
int main() 
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
 
    /* Let us create following BST 
              40 
             /  \ 
           30   60 
                    \ 
                   65 
                      \
                     70*/
struct Node *root = NULL; 
root = insert(root, 40); 
insert(root, 30);
insert(root, 20);
insert(root, 10); 
insert(root, 60); 
insert(root, 65); 
insert(root, 70); 

//inorder(root);

cout << minValueNode(root);
END();
cout << maxValueNode(root);
}