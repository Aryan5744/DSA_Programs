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

#define ROW 5 
#define COL 5 

//=======================

/*
Time complexity: O(N.N)
*/

struct Node{
    Node* left;
    Node* right;
    int data;
};

Node* newNode(int value){
    Node* new_Node = new Node();
    new_Node->left = new_Node->right = NULL;
    new_Node->data = value;
    return new_Node;
}

void zizagTraversal(Node* root){
    if(!root) return;
    stack<Node* > currentLevel;
    stack<Node* > nextLevel;

    currentLevel.push(root);
    
    bool leftToRight = true;

    while(!currentLevel.empty()){
        Node* temp = currentLevel.top();
        currentLevel.pop();
        if(temp)
            cout << temp->data << " ";
        if(leftToRight){
            if(temp->left)
                nextLevel.push(temp->left);
            if(temp->right)
                nextLevel.push(temp->right);
        }
        else if(!leftToRight){
            if(temp->right)
                nextLevel.push(temp->right);
            if(temp->left)
                nextLevel.push(temp->left);
        }
        if(currentLevel.empty()){
            leftToRight = !leftToRight;
            swap(currentLevel, nextLevel);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    Node* root = newNode(1); 
    root->left = newNode(2); 
    root->right = newNode(3); 
    root->left->left = newNode(7); 
    root->left->right = newNode(6); 
    root->right->left = newNode(5); 
    root->right->right = newNode(4); 
    cout << "ZigZag Order traversal of binary tree is \n"; 
    zizagTraversal(root); 
    return 0;
}