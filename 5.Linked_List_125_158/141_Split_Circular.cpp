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
};

void push(Node** head_ref, int data){
    Node *ptr1 = new Node(); 
    Node *temp = *head_ref;  
    ptr1->data = data;  
    ptr1->next = *head_ref;  

    if(*head_ref != NULL)  {  
        while(temp->next != *head_ref){  
            temp = temp->next;
        }      
        temp->next = ptr1;  
    }  
    else
        ptr1->next = ptr1; /*For the first node */
      
    *head_ref = ptr1;
}

void splitList(Node* head, Node** head1_ref, Node** head2_ref){

    Node* slow = head;
    Node* fast = head;

    while(fast->next != head && fast->next->next != head){
        slow = slow->next;
        fast = fast->next->next;
    }

    if(fast->next->next == head)  
        fast = fast->next;

    *head1_ref = head;

    if(head->next != head)
        *head2_ref = slow->next;
    
    fast->next = slow->next;
    slow->next = head;
}
void printList(Node *head)  
{  
    Node *temp = head;  
    if(head != NULL)  
    {  
        cout << endl;  
        do {  
        cout << temp->data << " ";  
        temp = temp->next;  
        } while(temp != head);  
    }  
}

int main() {
        ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
        Node* h = NULL;  
        push(&h , 1);
        push(&h , 2);
        push(&h , 3);
        push(&h , 4);

        printList(h);
        //head1->next->next->next->next = head1;

        Node* head3 = NULL;
        Node* head4 = NULL;
        splitList(h,&head3,&head4);

        printList(head3);
        printList(head4);
        
        return 0;
}
//g++ -g 141_Split_Circular.cpp
