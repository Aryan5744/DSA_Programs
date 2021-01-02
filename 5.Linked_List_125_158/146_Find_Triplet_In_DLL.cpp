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
    int data;
    Node* next;
    Node* prev;
};

void findTripletWithSum(Node** node, int x){

    Node* s = *node;
    bool found = false;
    unordered_map<int, Node*> mp;
    while(s != NULL){
        mp[s->data] = s;
        s = s->next;
    }

    for(Node* ptr1 = *node ; ptr1 != NULL ; ptr1 = ptr1->next){
        for(Node* ptr2 = ptr1->next ; ptr2 != NULL ; ptr2 = ptr2->next){
            int sum = (ptr1->data + ptr2->data);
            if( mp.find(x - sum) != mp.end() && mp[x - sum] != ptr1 && mp[x - sum] != ptr2){
                found = true;
                cout << ptr1->data << " " << ptr2->data << " " << (x - sum) << endl;
            }
        }
    }
    (!found) ? cout << "Not Found" :  cout << "Found";
}

void push(Node** node, int data){
    Node* new_node = new Node();
    new_node->data = data;
    new_node->prev = NULL;
    new_node->next = (*node);

    if((*node) != NULL)
        (*node)->prev = new_node;

    (*node) = new_node;
}

void printList(Node* node){
    while(node != NULL){ 
        cout << node->data << " "; 
        node = node->next; 
    }
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while(t--){
        Node* head = NULL; 
        push(&head, 2); 
        push(&head, 4); 
        push(&head, 8); 
        push(&head, 10); 
         
        cout << "Original Linked list" << endl; 
        // printList(head); 

        findTripletWithSum(&head , 22);
    }
    return 0;
}