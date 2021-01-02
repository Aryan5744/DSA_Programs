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

void inorder(Node* root){ 
    if(root != NULL){ 
        inorder(root->left); 
        cout << root->data << " "; 
        inorder(root->right); 
    } 
}

void binaryTreeToArray(Node* root, int temp[], int *i){
    if(!root)
       return;
    binaryTreeToArray(root->left, temp, i);
    temp[*i] = root->data;
    (*i)++;
    binaryTreeToArray(root->right, temp , i);
}

Node* buildTreeUtil(int merged[], int low, int high){
    if(low > high) return NULL;

    int mid = (low+high)/2;
    Node* root = newNode(merged[mid]);

    root->left = buildTreeUtil(merged, low, mid-1);
    root->right = buildTreeUtil(merged, mid+1, high);

    return root;
}

void mergeSortedArrays(int v1[], int v2[], int m, int n, int merged[]){
    int i = 0, j = 0, k = 0;
    while(i < m && j < n){
        if(v1[i] < v2[j])
            merged[k++] = v1[i++];
        else if(v1[i] > v2[j])
            merged[k++] = v2[j++];
        else{
            merged[k++] = v1[i++];
            merged[k++] = v2[j++];
        }
    }
    while(i < m)
        merged[k++] = v1[i++];
    while(j < n)
        merged[k++] = v2[j++];
}

Node* mergeTrees(Node* root1, Node* root2, int m, int n){
    if(root1 && !root2) return root1;
    if(!root1 && root2) return root2; 

    int *temp1 = new int[m];
    int *temp2 = new int[n];
    
    int k = 0;
    binaryTreeToArray(root1, temp1, &k);
    k = 0;
    binaryTreeToArray(root2, temp2, &k);

    int *merged = new int[m+n];
    mergeSortedArrays(temp1, temp2, m, n, merged);

    return buildTreeUtil(merged, 0 , (m+n-1));
}

// main program 
int main() 
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);  
     /* Create following tree as first balanced BST  
        100  
        / \  
        50 300  
    / \  
    20 70  
    */
    Node *root1 = newNode(100);  
    root1->left = newNode(50);  
    root1->right = newNode(300);  
    root1->left->left = newNode(20);  
    root1->left->right = newNode(70);  
  
    /* Create following tree as second balanced BST  
            80  
        / \  
        40 120  
    */
    Node *root2 = newNode(80);  
    root2->left = newNode(40);  
    root2->right = newNode(120);  
  
    Node *mergedTree = mergeTrees(root1, root2, 5, 3);  
  
    cout << "Following is Inorder traversal of the merged tree \n";  
    inorder(mergedTree);
  
    return 0; 
}