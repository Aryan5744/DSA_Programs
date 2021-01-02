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
#define Rows 10
#define Columns 10
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

struct MinHeapNode{
    int element;
    int i;
    int j;
};

void swap(MinHeapNode *x, MinHeapNode *y);

class MinHeap{
    MinHeapNode *harr;
    int heap_size;
    public:
        MinHeap(MinHeapNode harr[], int size);
        MinHeapNode getMin() {return harr[0];}
        void Heapify(int);
        void replaceMin(MinHeapNode x) {harr[0] = x; Heapify(0);}
        int left(int i)  {return (2*i+1);}
        int right(int i) {return (2*i+2);}
};
void MinHeap::Heapify(int i){
    int l = left(i);
    int r = right(i);
    int smallest = i;
    if(l < heap_size && harr[l].element < harr[i].element)
       smallest = l;
    if(r < heap_size && harr[r].element < harr[smallest].element)
       smallest = r;
    if(i!=smallest){
        swap(&harr[i] , &harr[smallest]);
        Heapify(smallest); 
    }
}
void swap(MinHeapNode *x, MinHeapNode *y){
    MinHeapNode temp = *x;
    *x = *y;
    *y = temp;
}
MinHeap::MinHeap(MinHeapNode arr[] , int N){
    heap_size = N;
    harr = arr;
    int i = (heap_size-1)/2;
    while( i >= 0 )
        Heapify(i--);
}
void solve(int a[Rows][Columns], int M, int N){
    MinHeapNode *harr = new MinHeapNode[N];
    fo(i,N){
        harr[i].element = a[i][0];
        harr[i].i = i;
        harr[i].j = 1; 
    } 
    MinHeap mh(harr,N);

    fo(count,M*N){
        MinHeapNode root = mh.getMin();
        cout << root.element << " ";
        if(root.j < N){
            root.element = a[root.i][root.j];
            root.j += 1;
        }else{
            root.element = INT_MAX;
        }
        mh.replaceMin(root);
    }
}
int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while(t--){
        int M,N;
        cin >> M >> N;
        int a[Rows][Columns];
        fo(i,M)
            fo(j,N)
               cin >> a[i][j];
        solve(a,M,N);    // Using Min Heap approach we can sort all elements of a matrix.
    }
    return 0;
}