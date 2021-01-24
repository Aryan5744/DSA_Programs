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

/*
Time Complexity: O(n)
Auxiliary Space: O(1)
*/

struct Node{ 
    int data; 
    struct Node* next; 
    struct Node* random;
}; 
  
// Function to create newNode in a linkedlist 
Node* newNode(int key){ 
    struct Node* temp = new Node; 
    temp->data = key; 
    temp->next = temp->random = NULL;
    return temp; 
} 
  
// A utility function to print linked list 
void printList(Node* node){ 
    while (node != NULL) { 
        printf("%d  ", node->data); 
        node = node->next; 
    } 
} 

Node* clone(Node* start){
    Node* curr = start, *temp;
    
    while(curr){
        temp = curr->next;
        curr->next = newNode(curr->data);
        curr->next->next = temp;
        curr = temp;
    }

    curr = start;

    while(curr){
        if(curr->next)
            curr->next->random = curr->random ? curr->random->next : curr->random;
        
        curr = curr->next ? curr->next->next : curr->next;
    }

    Node* original = start, *copy = start->next;
    temp = copy;

    while(original && copy){
        original->next = original->next ? original->next->next : original->next;
        copy->next = copy->next ? copy->next->next : copy->next;
        
        original = original->next;
        copy = copy->next;
    }
    return temp;
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    Node* start = newNode(1); 
    start->next = newNode(2); 
    start->next->next = newNode(3); 
    start->next->next->next = newNode(4); 
    start->next->next->next->next = newNode(5); 
  
    // 1's random points to 3 
    start->random = start->next->next; 
  
    // 2's random points to 1 
    start->next->random = start; 
  
    // 3's and 4's random points to 5 
    start->next->next->random = start->next->next->next->next; 
    start->next->next->next->random = start->next->next->next->next; 
  
    // 5's random points to 2 
    start->next->next->next->next->random = start->next; 
  
    cout << "\nCloned list : " << endl; 
    Node *cloned_list = clone(start); 
    printList(cloned_list); 
  
    return 0; 
}