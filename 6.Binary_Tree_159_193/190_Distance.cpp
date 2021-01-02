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
    int data;
};

Node* getNode(int data){
    Node* new_node = new Node();
    new_node->data = data;
    new_node->left = new_node->right = NULL;
    return new_node;
}

Node* findLCAUtil(Node* root, int n1, int n2, bool &v1, bool &v2){
    if(!root)  return NULL;
    
    if(root->data == n1){
        v1 = true;
        return root;
    }
    if(root->data == n2){
        v2 = true;
        return root;
    }
    Node* left_lca = findLCAUtil(root->left , n1 , n2 , v1 , v2);
    Node* right_lca = findLCAUtil(root->right , n1 , n2 , v1 , v2);

    if(left_lca && right_lca) return root;

    return (left_lca != NULL) ? left_lca : right_lca;
}

bool find(Node* root, int key){
    if(!root)  return false;
 
    if(root->data == key || find(root->left , key) || find(root->right , key))  return true;

    return false;
}

Node* findLCA(Node* root, int n1, int n2){
    if(!root)  return NULL;
    
    bool v1 = false , v2 = false;
    Node* lca = findLCAUtil(root , n1 , n2 , v1 , v2);

    if(v1 && v2 || v1 && find(lca , n2) || v2 && find(lca , n1))  return lca;

    return NULL;
}

int findDistanceUtil(Node* root, int n1, int d1){
    if(!root) return -1;
    if(root->data == n1) return d1;

    int dist = findDistanceUtil(root->left, n1, d1+1);

    if(dist == -1)
        dist = findDistanceUtil(root->right, n1, d1+1);
    
    return dist;
}

int findDistance(Node* root, int n1 , int n2){
    Node* lca = findLCA(root , n1 , n2);

    int d1 = findDistanceUtil(lca , n1 , 0);
    int d2 = findDistanceUtil(lca , n2 , 0);    

    return d1+d2;
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    Node * root = getNode(1);
    root->left = getNode(2);
    root->right = getNode(3);
    root->left->left = getNode(4);
    root->left->right = getNode(5);
    root->right->left = getNode(6);
    root->right->right = getNode(7);
    
    cout << findDistance(root , 4 , 5);   
    
    return 0;
}
