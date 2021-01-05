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

/*
1.Simple method is to sort array using O(N*LogN) sorting alogorithm like Merge & Heap sort.
Time Complexity : O(N*LogN)

2.Using Min Heap 
Time Complexity : O(N + K*LogN)

3.Using Max Heap
Time Complexity : O(k + (N-k)*LogN)

4.Using Quick Select(An advance implementation of Quick Sort)
the idea is to place pivot at its correct position using partition method and then recurr 
for either left or right subArray based on the value of K
Time Complexity : O(N^2) (worst case) & O(N) (best case)
*/

void swap(int *x, int *y);

class MaxHeap
{
private:
    int heap_size;
    int *heap_arr;
public:
    MaxHeap(int _arr[], int capacity);
    
    int parent(int i){
        return (i-1)/2;
    }
    int left(int i){
        return 2*i + 1;
    }
    int right(int i){
        return 2*i + 2;
    }
    int getMax(){
        return heap_arr[0];
    }

    int extractMax();

    void maxHeapify(int i);

    void replaceMax(int K) { 
        heap_arr[0] = K; 
        maxHeapify(0);
    }
    void display(){
        for(int i = 0 ; i < heap_size ; i++)
           cout << heap_arr[i] << " ";
        cout << endl;
    } 
};

MaxHeap::MaxHeap(int _arr[], int cap){
    heap_size = cap;
    heap_arr = _arr;

    int i = (heap_size-1)/2;
    while(i >= 0){
        maxHeapify(i);
        i--;
    }
}

int MaxHeap::extractMax(){

    if(heap_size == 0)
       return INT_MAX;
    int root = heap_arr[0]; 

	if (heap_size > 1) { 
		heap_arr[0] = heap_arr[heap_size - 1]; 
		maxHeapify(0); 
	} 
	heap_size--; 

    return root;
}

void MaxHeap::maxHeapify(int i){
    int l = left(i);
    int r = right(i);
    int greatest = i;

    if(l < heap_size && heap_arr[l] > heap_arr[i])
       greatest = l;
    if(r < heap_size && heap_arr[r] > heap_arr[greatest])
       greatest = r;
    
    if(greatest != i){
        swap(&heap_arr[i], &heap_arr[greatest]);
        maxHeapify(greatest);
    }
}

int kthSmallestUsingMaxHeap(int _arr[], int N, int K){
    MaxHeap mh(_arr,K);
    mh.display();
    for(int i = K; i < N ;++i)
        if(_arr[i] < mh.getMax()){
           mh.replaceMax(_arr[i]);
           mh.display();} 
    return mh.getMax();
}

class MinHeap
{
private:
    int heap_size;
    int *heap_arr;
public:
    MinHeap(int _arr[], int capacity);
    
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

    void minHeapify(int i);
};

MinHeap::MinHeap(int _arr[], int cap){
    heap_size = cap;
    heap_arr = _arr;

    int i = (heap_size-1)/2;
    while(i >= 0){
        minHeapify(i);
        i--;
    }
}

int MinHeap::extractMin(){

    if(heap_size == 0)
       return INT_MIN;
    int root = heap_arr[0]; 

	if (heap_size > 1) { 
		heap_arr[0] = heap_arr[heap_size - 1]; 
		minHeapify(0); 
	} 
	heap_size--; 

    return root;
}

void MinHeap::minHeapify(int i){
    int l = left(i);
    int r = right(i);
    int smallest = i;

    if(l < heap_size && heap_arr[l] < heap_arr[i])
       smallest = l;
    if(r < heap_size && heap_arr[r] < heap_arr[smallest])
       smallest = r;
    
    if(smallest != i){
        swap(&heap_arr[i], &heap_arr[smallest]);
        minHeapify(smallest);
    }
}
void swap(int *a, int *b){
    int temp = *a;
    *a =  *b;
    *b = temp;
}

int kthSmallestUsingMinHeap(int _arr[], int N, int K){
    MinHeap mh(_arr,N);
    fo(i,K-1)
       mh.extractMin();
    return mh.getMin();
}

int partition(int _arr[], int low, int high){
    int x = _arr[high];
    int i = low;

    for(int j = low ; j < high ; j++){
        if(_arr[j] <= x){
            swap(&_arr[j],&_arr[i]);
            i++;
        }
    }
    swap(&_arr[i],&_arr[high]);
    return i;
}

int kthSmallestUsingQuickSort(int _arr[], int low, int high, int K){
    if(K > 0 && K <= high-low+1){
        int pos = partition(_arr,low,high);
        if(pos-low == K-1)
           return _arr[pos];
        if(pos-low > K-1)
           return kthSmallestUsingQuickSort(_arr,low,pos-1,K);
        return kthSmallestUsingQuickSort(_arr,pos+1,high,K-pos+low-1);
    }
    return INT_MAX;
}
                    

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while(t--){
        int N,K;
        cin >> N;
        int _arr[N];
        fo(i,N)
           cin >> _arr[i];
        cin >> K;
        //cout << kthSmallestUsingMinHeap(_arr,N,K)<<endl;
        //cout << kthSmallestUsingMaxHeap(_arr,N,K)<<endl;
        cout << kthSmallestUsingQuickSort(_arr,0,N-1,K);
    }
    return 0;
}