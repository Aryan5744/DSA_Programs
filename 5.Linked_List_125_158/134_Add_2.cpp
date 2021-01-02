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
    int data;
    Node* next;
};

void push(Node** head, int data){
    Node* new_node = new Node;
    new_node->data = data;
    new_node->next = *head;
    *head = new_node;
}

int returnSize(Node* head){
    Node* temp = head;
    int count = 0;
    while(temp->next != NULL){
        temp = temp->next;
        count++;
    }
    return count;
}

ll int returnNumber(Node* head, int count){
    ll int number = 0;
    Node* t = head;
    while(count >= 0){
        number += (pow(10,count) * t->data);
        t = t->next;
        count--;
    }
    return number;
}

void addTwo(Node* head1, Node* head2){
    
    int count1 = returnSize(head1);
    int count2 = returnSize(head2);

    ll int number1 = returnNumber(head1,count1);
    ll int number2 = returnNumber(head2,count2);

    cout << number1 + number2;
}

void printList(Node *node)  {  
    while (node != NULL){  
        cout << node->data<<" ";  
        node = node->next;  
    } 
    cout << endl; 
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while(t--){
        Node* head1 = NULL;  
        push(&head1 , 1);
        push(&head1 , 2);
        push(&head1 , 2);
        push(&head1 , 4);

        Node* head2 = NULL;  
        push(&head2 , 1);
        push(&head2 , 2);
        push(&head2 , 2);
        push(&head2 , 4);

        addTwo(head1 , head2);
    }
    return 0;
}