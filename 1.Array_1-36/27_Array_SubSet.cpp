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
void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}
int partitionArray(int a[], int low, int high){
    int pivot = a[high] , i = low-1;
    for(int j = low ; j <= high ; j++){
        if(a[j] < pivot){
            i++;
            swap(&a[i], &a[j]);
        }
    }
    swap(&a[i+1] , &a[high]);
    return (i+1);
}
void QuickSort(int a[], int low, int high){
    if(low < high){
        int mid = partitionArray(a,low,high);
        QuickSort(a, low , mid-1);
        QuickSort(a, mid+1 , high);
    }
}
int binarySearch(int a[], int low, int high, int K){
    if(low <= high){
        int mid = low + (high-low)/2;
        if(K == a[mid])
           return mid;
        else if(K < a[mid])
           return binarySearch(a,low,mid-1,K);
        return binarySearch(a,mid+1,high,K);
    }
    return -1;
}
bool solve(int a[],int b[], int N, int M){
    QuickSort(a,0,N-1);
    fo(i,M)
        if(binarySearch(a,0,N-1,b[i]) == -1)
          return false;
    return true;
}

bool solve2(int a[],int b[], int N, int M){

    if(N < M)
        return false;
    int i = 0, j = 0;
    sort(a,a+N);
    sort(b,b+M);
    while( i < N && j < M){
        if(a[i] == b[j]){
            i++;
            j++;
        }else if(a[i] < b[j])
            i++;
        else if(a[i] > b[j])
            return false;
    }
    return (j < M) ? false : true; 
}
int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int N = 20;
    int M = 10;
    int a[N] = {6, 6, 2, 3, 1, 4, 1, 5, 6, 2, 8, 7, 4 ,2, 1, 3, 4, 5, 9, 6};
    int b[M] = {6, 6, 2, 3, 1, 4, 1, 5, 6, 2};
    if(solve(a,b,N,M))                          // Quick Sort is O(n^2) and binary search O(mLogm + nLogm)
        cout << "Yes";
    else
        cout << "No";
    cout << endl;
    if(solve2(a,b,N,M))                          // sorting and merge O(mLogm + nLogn)
        cout << "Yes";
    else
        cout << "No";
    return 0;
}