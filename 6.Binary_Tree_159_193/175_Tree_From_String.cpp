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

Node* newNode(int data){
    Node* new_node = new Node();
    new_node->data = data;
    new_node->left = new_node->right = NULL;
    return new_node;
}

int findIndex(string s, int si , int ei){
    if(si > ei)
        return -1;

    stack<char> st;
    for(int i = si ; i <= ei ; i++){
        if(s[i] == '(')
            st.push(s[i]);
        else if(s[i] == ')'){ 
            if(st.top() == '('){
                st.pop();
                if(st.empty())
                    return i;
            }
        }
    }
    return -1;
}
void preOrder(Node* root){
    if(!root)
        return;
    cout << root->data << " ";
    preOrder(root->left);
    preOrder(root->right);
}
Node* treeFromString(string s, int si , int ei){
    if(si > ei)
        return NULL;
    
    Node* root = newNode(s[si]-'0');
    int index = -1;

    if(si + 1 <= ei && s[si+1] == '(')
        index = findIndex(s , si+1 , ei);
    
    if(index != -1){
        root->left = treeFromString(s , si + 2 , index-1);
        root->right = treeFromString(s , index + 2 , ei - 1);
    }
    return root;
}
int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    // Node *root = newNode(1);
    // root->left = newNode(2);
    // root->right = newNode(3);
    // root->left->left = newNode(4);
    // root->right->right = newNode(5);
    string s = "4(2(3)(1))(6(5))";
    Node* root = treeFromString(s, 0 , s.length()-1);
    preOrder(root);
    return 0;
}