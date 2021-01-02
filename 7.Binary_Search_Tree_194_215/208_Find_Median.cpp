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

struct Node* insert(struct Node* node, int key){ 
    if (node == NULL) return newNode(key); 
    if (key < node->data) 
        node->left  = insert(node->left, key); 
    else if (key > node->data) 
        node->right = insert(node->right, key); 
    return node; 
} 

int countNodes(Node* root){
    Node* current, *pre;
    int count = 0;
    
    if(!root) return count;

    current = root;
    while(current){
        if(!current->left){
            count++;
            current = current->right;
        }
        else{
            pre = current->left;

            while(pre->right && pre->right != current)
               pre = pre->right;
            
            if(!pre->right){
                pre->right = current;
                current = current->left;
            }
            else{
                pre->right = NULL;
                count++;
                current = current->right;
            }
        }
    }
    return count;
}

int findMedian(Node* root){
    if(!root) return 0;

    int count = countNodes(root);
    int currCount = 0;

    Node* current = root, *pre, *prev;

    while(current){
        if(!current->left){
            
            currCount++;
            
            if(count%2 != 0 && currCount == (count+1)/2)
                return prev->data;
            else if(count%2 == 0 && currCount == (count/2)+1)
                return (prev->data + current->data)/2;

            prev = current;
            current = current->right;
        }   
        else{
            pre = current->left;
            
            while(pre->right && pre->right != current)
                pre = pre->right;
            
            if(pre->right == NULL){
                pre->right = current;
                current = current->left;
            }
            else{
                pre->right = NULL;
                
                prev = pre;

                currCount++;

                if(count%2 != 0 && currCount == (count+1)/2)
                    return current->data;
                else if(count%2 == 0 && currCount == (count/2)+1)
                    return (prev->data + current->data)/2;

                prev = current;
                current = current->right;
            }
        }
    } 
}

// main program 
int main() 
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);  
     /* Let us create following BST 
                  50 
               /     \ 
              30      70 
             /  \    /  \ 
           20   40  60   80 */
    struct Node *root = NULL; 
    root = insert(root, 50); 
    insert(root, 30); 
    insert(root, 20); 
    insert(root, 40); 
    insert(root, 70); 
    insert(root, 60); 
    insert(root, 80); 
  
    cout << "\nMedian of BST is " << findMedian(root); 
    return 0; 
}