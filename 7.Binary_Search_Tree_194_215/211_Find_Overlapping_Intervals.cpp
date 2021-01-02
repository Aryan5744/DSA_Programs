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

struct Interval
{
    int low, high;
};

struct ITNode
{
    Interval *i;
    int max;
    ITNode *left, *right;
};

ITNode* newNode(Interval i){
    ITNode *temp = new ITNode();
    temp->i = new Interval(i);
    temp->max = i.high;
    temp->left = temp->right = NULL;
    return temp;
}

ITNode* insert(ITNode* root, Interval i){
    if(!root) return newNode(i);

    int l = root->i->low;

    if(i.low < l)
       root->left = insert(root->left, i);
    else
       root->right = insert(root->right, i);
    
    if(root->max < i.high)
       root->max = i.high;
    
    return root;
}

bool doOverlap(Interval i1, Interval i2){
    return (i1.low <= i2.high && i2.low <= i1.high) ? true : false;
}

Interval* overlapSearch(ITNode* root, Interval i){
    if(!root) return NULL;

    if(doOverlap(*(root->i), i)) return root->i;

    if(root->left && root->left->max >= i.low)
        return overlapSearch(root->left, i);
    else
        return overlapSearch(root->right, i);
}

void inOrder(ITNode* root){
    if(!root) return;
    
    inOrder(root->left); 
  
    cout << "[" << root->i->low << ", " << root->i->high << "]" << " max = " << root->max << endl; 
  
    inOrder(root->right); 
}

int main(){
    Interval ints[] = {{15, 20}, {10, 30}, {17, 19}, {5, 20}, {12, 15}, {30, 40}}; 
    int n = sizeof(ints)/sizeof(ints[0]); 
    ITNode *root = NULL; 
    for (int i = 0; i < n; i++) 
        root = insert(root, ints[i]); 
  
    cout << "Inorder traversal of constructed Interval Tree is\n"; 
    inOrder(root); 
  
    Interval x = {6, 7}; 
  
    cout << "\nSearching for interval [" << x.low << "," << x.high << "]"; 
    Interval *res = overlapSearch(root, x); 

    (!res) ? cout << "\nNo Overlapping Interval" : cout << "\nOverlaps with [" << res->low << ", " << res->high << "]";   

    return 0;
}