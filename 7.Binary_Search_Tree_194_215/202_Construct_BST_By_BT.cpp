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
struct Node *left, *right, *next; 
}; 
  
// create a new BST node 
Node* newNode(int key) 
{ 
struct Node *temp =  new struct Node(); 
temp->data = key; 
temp->left = temp->right = temp->next = NULL; 
return temp; 
} 

void inorder(struct Node* root){ 
    if(root != NULL){ 
        inorder(root->left); 
        cout << root->data << " "; 
        inorder(root->right); 
    } 
}

int totalNodes(Node* root){
    if(!root)
        return 0;
    return totalNodes(root->left) + totalNodes(root->right) + 1;
}

void binaryTreeToArray(Node* root, int temp[], int *i){
    if(!root)
       return;
    binaryTreeToArray(root->left, temp, i);
    temp[*i] = root->data;
    (*i)++;
    binaryTreeToArray(root->right, temp, i);
}

int compare(const void* a, const void* b){ 
    return (*(int*)a - *(int*)b); 
} 

void arrayToBinarySearchTree(Node* root, int temp[], int *i){
    if(!root)
       return;
    arrayToBinarySearchTree(root->left, temp, i);
    root->data = temp[*i];
    (*i)++;
    arrayToBinarySearchTree(root->right, temp, i);
}

void binaryTreeToBST(Node* root){

    if(!root)
        return;
    
    int n = totalNodes(root);
    int *temp = new int[n];

    int i = 0;
    binaryTreeToArray(root, temp, &i); 
 
    qsort(temp, n, sizeof(temp[0]), compare);

    i = 0;
    arrayToBinarySearchTree(root, temp, &i);

    delete[] temp;
}

/*
 index :     0   1  2  3  4   5
 values :    10, 5, 1, 7, 40, 50 
*/

// main program 
int main() 
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);  
    /* Constructing tree given in the above figure 
          10 
         /  \ 
        30   15 
       /      \ 
      20       5   */
    struct Node* root = NULL;
    root = newNode(10); 
    root->left = newNode(30); 
    root->right = newNode(15); 
    root->left->left = newNode(20); 
    root->right->right = newNode(5); 
  
    // convert Binary Tree to BST 
    binaryTreeToBST(root); 
  
    printf("Following is Inorder Traversal of the converted BST: \n"); 

    inorder(root); 
  
    return 0; 
}