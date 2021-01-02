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

const char MARKER = '$';
//=======================

class Node{
    public:
    Node* left , *right;
    char data;
};

Node* newNode(int data){
    Node* new_node = new Node();
    new_node->data = data;
    new_node->left = new_node->right = NULL;
    return new_node;
}

unordered_set<string> st;

string duplicateSubTree(Node *root){
    
    string s = "";
    if(!root)
       return s+MARKER;
    
    string lstr = duplicateSubTree(root->left);
    if(lstr.compare(s) == 0)
        return s;
    
    string rstr = duplicateSubTree(root->right);
    if(rstr.compare(s) == 0)
        return s;
    
    s += lstr + rstr + root->data;

    if(s.length() > 3 && st.find(s) != st.end())
        return "";
    
    st.insert(s);
    
    return s;
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    Node *root = newNode('A'); 
    root->left = newNode('B'); 
    root->right = newNode('C'); 
    root->left->left = newNode('D'); 
    root->left->right = newNode('E'); 
    root->right->right = newNode('B'); 
    root->right->right->right = newNode('E'); 
    root->right->right->left= newNode('D'); 

    string str = duplicateSubTree(root);
    
    (str.compare("") == 0) ? "Yes" : "No";

    return 0;
}