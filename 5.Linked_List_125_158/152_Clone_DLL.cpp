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
    Node *next, *random;
    int data;
    Node(int data){
        this->data = data;
        this->next = this->random = NULL;
    } 
};
class LL{
    public:
    Node* head;

    LL(Node* head){
        this->head = head;
    }

    void push(int data){
        Node* new_node = new Node(data);
        new_node->next = head;
        head = new_node; 
    }
    void print(){
        Node *temp = head;
        while(temp != NULL){
            Node* random = temp->random;
            int randomData = (random != NULL) ? random->data : -1;
            cout << temp->data << " " << randomData << endl;
            temp = temp->next;
        }
        cout << endl;
    }

    LL* clone(){
        Node *origCurr = head;
        Node *cloneCurr = NULL;

        unordered_map<Node* , Node*> mp;

        while(origCurr != NULL){
            cloneCurr = new Node(origCurr->data);
            mp[origCurr] = cloneCurr;
            origCurr = origCurr->next;
        }

        origCurr = head;

        while(origCurr != NULL){
            cloneCurr = mp[origCurr];
            cloneCurr->next = mp[origCurr->next];
            cloneCurr->random = mp[origCurr->random];
            origCurr = origCurr->next;
        }

        return new LL(mp[head]);
    }
};

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while(t--){
        LL *mylist = new LL(new Node(5)); 
        mylist->push(4); 
        mylist->push(3); 
        mylist->push(2); 
        mylist->push(1); 
    
        // Setting up random references. 
        mylist->head->random = mylist->head->next->next; 
    
        mylist->head->next->random = 
            mylist->head->next->next->next; 
    
        mylist->head->next->next->random = 
            mylist->head->next->next->next->next; 
    
        mylist->head->next->next->next->random = 
            mylist->head->next->next->next->next->next; 
    
        mylist->head->next->next->next->next->random = 
            mylist->head->next; 
    
        // Making a clone of the original 
        // linked list. 
        LL *clone = mylist->clone(); 
    
        // Print the original and cloned  
        // linked list. 
        cout << "Original linked list\n"; 
        mylist->print(); 
        cout << "\nCloned linked list\n"; 
        clone->print(); 
        }
    return 0;
}