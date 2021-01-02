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
#define aint(x) x.begin(), x.end()
#define clr(x) memset(x, 0, sizeof(x))
#define sortaint(x) sort(aint(x))
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

void swap(int *x, int *y);

class MinHeap
{
private:
    int capacity;
    int heap_size;
    int *heap_arr;
public:
    MinHeap(int capacity);
    
    int parent(int i){
        return (i-1)/2;
    }
    int left(int i){
        return 2*i + 1;
    }
    int right(int i){
        return 2*i + 2;
    }
    int getMin(){
        return heap_arr[0];
    }

    int extractMin();

    void heapify(int i);

    void decreaseKey(int i, int K);

    void deleteKey(int i);

    void insertKey(int K);

};

MinHeap::MinHeap(int cap){
    heap_size = 0;
    capacity = cap;
    heap_arr = new int[cap];
}

int MinHeap::extractMin(){

    if(heap_size == 0)
       return INT_MIN;
    if(heap_size == 1){
        heap_size--;
        return heap_arr[0];
    }
    
    int root =  heap_arr[0];
    heap_arr[0] = heap_arr[heap_size-1];
    heap_size--;
    heapify(0);
    
    return root;
}

void MinHeap:: decreaseKey(int i, int K){
    heap_arr[i] = K;
    while(i < heap_size && heap_arr[parent(i)] > heap_arr[i]){
        swap(&heap_arr[i], &heap_arr[parent(i)]);
        i = parent(i);
    }
}

void MinHeap::deleteKey(int i){
    decreaseKey(i,INT_MIN);
    extractMin();
}

void MinHeap::insertKey(int K){
    if(heap_size == capacity){
        cout << "Overflow !!";
        return;
    }
    heap_size++;
    int i = heap_size-1;
    heap_arr[i] = K;
    
    while(i !=0 && heap_arr[parent(i)] > heap_arr[i]){
        swap(&heap_arr[i], &heap_arr[parent(i)]);
        i = parent(i);
    }
}
void MinHeap::heapify(int i){
    int l = left(i);
    int r = right(i);
    int smallest = i;

    if(l < heap_size && heap_arr[l] < heap_arr[i])
       smallest = l;
    if(r < heap_size && heap_arr[r] < heap_arr[smallest])
       smallest = r;
    
    if(smallest != i){
        swap(&heap_arr[i], &heap_arr[smallest]);
        heapify(smallest);
    }
}
void swap(int *a, int *b){
    int temp = *a;
    *a =  *b;
    *b = temp;
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while(t--){
        int N,K;
        cin >> N;
        MinHeap mh(N);
        fo(i,N){
            int a;
            cin >> a;
            mh.insertKey(a);
        }
    }
    return 0;
}