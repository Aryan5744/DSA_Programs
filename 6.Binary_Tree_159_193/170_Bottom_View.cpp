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
    int data , hd;
};

Node* newNode(int data){
    Node* new_node = new Node();
    new_node->data = data;
    new_node->left = new_node->right = NULL;
    return new_node;
}

void bottomView(Node* root){
    queue <Node*> q;
    map<int , int> m;
    int hd = 0;
    root->hd = hd;

    q.push(root);

    while(!q.empty()){
        
        hd = root->hd;

        m[hd] = root->data; // the only line change diff from top view as 
                            //we want to replace values for multiple values of hd.

        if(root->left){
            root->left->hd = hd-1;
            q.push(root->left);
        }
        if(root->right){
            root->right->hd = hd+1;
            q.push(root->right);
        }
        q.pop();
        root = q.front();
    }

    for(auto i = m.begin() ; i != m.end() ; i++)
        cout << i->second << " ";
}
/*
              1
           2      3
        4            5 
           6      7
*/
int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    Node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->left->right = newNode(6);
    root->right->right = newNode(5);
    root->right->right->left = newNode(7);

    bottomView(root);

    return 0;
}