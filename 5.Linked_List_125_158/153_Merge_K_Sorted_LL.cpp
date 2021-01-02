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

struct Node{
    public:
    int data;
    Node* next;
};

void printList(Node* node){
    while(node != NULL){ 
        cout << node->data << " "; 
        node = node->next; 
    }
}

Node* merge(Node* a, Node* b){
    if(a == NULL)
        return b;
    if(b == NULL)
        return a;
    
    Node* result = NULL;
    if(a->data < b->data){
        result = a;
        result->next = merge( a->next , b );
    }
    else{
        result = b;
        result->next = merge( a , b->next );
    }
    return result;
}

Node* mergeKLists(Node* arr[] , int last){
    while(last > 0){
        int i = 0 , j = last;
        while( i < j ){
            arr[i] = merge(arr[i] , arr[j]);
            i++;
            j--;
            if(i >= j)
               last = j;
        }
    }
    return arr[0];
}

Node* newNode(int data){
    struct Node* temp = new Node;
    temp->data = data;
    temp->next = NULL;
    return temp;
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while(t--){
        int k = 3; // Number of linked lists
        int n = 4; // Number of elements in each list
    
        // an array of pointers storing the head nodes
        // of the linked lists
        Node* arr[k];
    
        arr[0] = newNode(1);
        arr[0]->next = newNode(3);
        arr[0]->next->next = newNode(5);
        arr[0]->next->next->next = newNode(7);
    
        arr[1] = newNode(2);
        arr[1]->next = newNode(4);
        arr[1]->next->next = newNode(6);
        arr[1]->next->next->next = newNode(8);
    
        arr[2] = newNode(0);
        arr[2]->next = newNode(9);
        arr[2]->next->next = newNode(10);
        arr[2]->next->next->next = newNode(11);
    
        // Merge all lists

        Node* head = mergeKLists(arr, k - 1);
    
        printList(head);
    }
    return 0;
}