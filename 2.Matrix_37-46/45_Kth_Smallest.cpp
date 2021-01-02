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
#define Rows 100
#define Columns 100
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

struct minHeapNode{
    int element;
    int i;
    int j;
};

void swap(minHeapNode *x, minHeapNode *y);

class MinHeap
{
private:
    minHeapNode *harr;
    int heap_size;
public:
    int left(int i){ return i*2+1;}
    int right(int i){ return i*2+2;}
    minHeapNode getMin() { return harr[0];}
    MinHeap(minHeapNode harr[], int heap_size);
    void Heapify(int);
    void replaceMin(minHeapNode x) {harr[0] = x; Heapify(0);}
};
void swap(minHeapNode *x , minHeapNode *y){
    minHeapNode temp = *x;
    *x = *y;
    *y = temp;
}

void MinHeap::Heapify(int i){
    int l = left(i);
    int r = right(i);
    int smallest = i;
    if(l < heap_size && harr[l].element < harr[i].element)
       smallest = l;
    if(r < heap_size && harr[r].element < harr[smallest].element)
       smallest = r;
    if( i != smallest){
        swap(&harr[i], &harr[smallest]);
        Heapify(smallest);
    }
}
MinHeap::MinHeap(minHeapNode arr[], int N){
    harr = arr;
    heap_size = N;
    int i = (heap_size-1)/2;
    while(i >= 0)
       Heapify(i--);
}
int kthSmallest(int mat[Rows][Columns], int M, int N, int K){
    minHeapNode *harr = new minHeapNode[N];
    for(int i = 0; i < N; i++){
        harr[i].element = mat[i][0];
        harr[i].i = i;
        harr[i].j = 1;
    }
    MinHeap mh(harr,N);
    vector<int> v;
    for(int count = 0; count < M*N; count++){
        minHeapNode root = mh.getMin();
        v.push_back(root.element);
        if(root.j < N){
            root.element = mat[root.i][root.j];
            root.j += 1;
        }else
            root.element = INT_MAX;
        mh.replaceMin(root);
    }
    return v[K-1];
}
int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while(t--){
        int M,N;
        cin >> M >> N;
        int mat[Rows][Columns];
        fo(i,M)
            fo(j,N)
               cin >> mat[i][j];
        cout << kthSmallest(mat,M,N,3) << endl;    
/*Using another matrix of same size to keep a track of maximum's*/
    }
    return 0;
}