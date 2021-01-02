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

pivii countPairs(Node* root1, Node* root2, int k){
    // if (!root1 || !root2)
    //     return -1;

    stack<Node*> s1, s2;
    Node *top1, *top2;

    pivii res;
    vpii resVec;

    int count = 0;

    while(1){
        while(root1 != NULL){
            s1.push(root1);
            root1 = root1->left;
        }
        while(root2 != NULL){
            s2.push(root2);
            root2 = root2->right;
        }

        if(s1.empty() || s2.empty())
            break;

        top1 = s1.top();
        top2 = s2.top();

        if((top1->data + top2->data) == k){
            count++;
            s1.pop();
            s2.pop();

            resVec.push_back(make_pair(top1->data, top2->data));

            root1 = top1->right;
            root2 = top2->left;
        }
        else if((top1->data + top2->data) < k){
            s1.pop();
            root1 = top1->right;
        }
        else{
            s2.pop();
            root2 = top2->left;
        }
    }
    res.first = count;
    res.second = resVec;
    return res;
}

// main program 
int main() 
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);  
    Node* root1 = newNode(5); /*             5        */
    root1->left = newNode(3); /*           /   \      */
    root1->right = newNode(7); /*         3     7     */
    root1->left->left = newNode(2); /*    / \   / \    */
    root1->left->right = newNode(4); /*  2  4  6  8    */
    root1->right->left = newNode(6);
    root1->right->right = newNode(8);
 
    // formation of BST 2
    Node* root2 = newNode(10); /*           10         */
    root2->left = newNode(6); /*           /   \        */
    root2->right = newNode(15); /*        6     15      */
    root2->left->left = newNode(3); /*    / \   /  \     */
    root2->left->right = newNode(8); /*  3  8  11  18    */
    root2->right->left = newNode(11);
    root2->right->right = newNode(18);
 
    int x = 16;

    pivii res  = countPairs(root1, root2, x);

    int count = res.first;
    vpii resVec = res.second;

    cout << "Count of Pairs is : " << count << endl;
    cout << "Elements of Pairs are : " << endl;
    for(pii p : resVec)
        cout << p.first << " " << p.second << endl;

    return 0; 
}