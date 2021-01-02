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

bool isIsomorphic(Node* n1, Node* n2){
    if(!n1 && !n2)  return true;
    if(!n1 || !n2)  return false;

    return (isIsomorphic(n1->left,n2->right) && isIsomorphic(n1->right,n2->left)) || (isIsomorphic(n1->right,n2->right) && isIsomorphic(n1->left,n2->left));
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    struct Node *n1 = getNode(1); 
    n1->left        = getNode(2); 
    n1->right       = getNode(3); 
    n1->left->left  = getNode(4); 
    n1->left->right = getNode(5); 
    n1->right->left  = getNode(6); 
    n1->left->right->left = getNode(7); 
    n1->left->right->right = getNode(8); 
  
    struct Node *n2 = getNode(1); 
    n2->left         = getNode(3); 
    n2->right        = getNode(2); 
    n2->right->left   = getNode(4); 
    n2->right->right   = getNode(5); 
    n2->left->right   = getNode(6); 
    n2->right->right->left = getNode(8); 
    n2->right->right->right = getNode(7); 
  
    if (isIsomorphic(n1, n2)) 
       cout << "Yes"; 
    else
      cout << "No"; 
  
    return 0; 
}