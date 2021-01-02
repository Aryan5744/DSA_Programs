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

class Node{
    public:
    Node* left , *right;
    char data;
};

Node* getNode(int data){
    Node* new_node = new Node();
    new_node->data = data;
    new_node->left = new_node->right = NULL;
    return new_node;
}

int getMaxSum();
int getMaxSumUtil(Node* root, map<Node* , int> &mp);
int getGrandChildSum(Node* root, map<Node* , int> &mp);

int getGrandChildSum(Node* root, map<Node* , int> &mp){
    int sum = 0;

    if(root->left)
        sum += getMaxSumUtil(root->left->left, mp) + getMaxSumUtil(root->left->right, mp); 
    if(root->right)
        sum += getMaxSumUtil(root->right->left, mp) + getMaxSumUtil(root->right->right, mp);

    return sum;
}

int getMaxSumUtil(Node* root, map<Node* , int> &mp){
    if(!root)
        return 0;
    if(mp.find(root) != mp.end())
        return mp[root];
    
    int incl = root->data + getGrandChildSum(root , mp);

    int excl = getMaxSumUtil(root->left , mp) + getMaxSumUtil(root->right , mp);

    mp[root] = max(incl , excl);

    return mp[root]; 
}

int getMaxSum(Node* root){
    if(!root)
        return 0;
    map<Node* , int> mp;
    return getMaxSumUtil(root , mp);
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    //binary tree formation 
    Node* root = getNode(4);         /*        4        */
    root->left = getNode(2);         /*       / \       */
    root->right = getNode(5);        /*      2   5      */
    root->left->left = getNode(7);   /*     / \ / \     */
    root->left->right = getNode(1);  /*    7  1 2  3    */
    root->right->left = getNode(2);  /*                 */
    root->right->right = getNode(3); 

    cout << "Sum = "<< getMaxSum(root); 
    return 0;
}