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
int findPivot(int a[], int low, int high){
    if(high < low)
        return -1;
    if(a[high] == a[low])
        return low;
    int mid = (low + high)/2;
    if(a[mid] > a[mid+1] && mid < high)
       return mid;
    if(a[mid-1] > a[mid] && mid > low)
       return mid-1;
    if(a[low] >= a[mid])
       return findPivot(a,low,mid-1);
    return findPivot(a,mid+1,high);
}
int binarySearch(int a[], int low, int high, int key){
    if(high < low)
        return -1;
    int mid = (low + high)/2;
    if(a[mid] == key)
        return mid;
    if(key < a[mid])
        return binarySearch(a,low,mid-1,key);
    return binarySearch(a,mid+1,high,key);
}

int indexUsingPivotAndBinarySearch(int a[], int n, int k){
    int pivot = findPivot(a,0,n-1);
    if(pivot == -1)
       return binarySearch(a,0,n-1,k);
    if(a[pivot] == k)
       return pivot;
    if(a[0] <= k) // 3 && 5
       return binarySearch(a,0,pivot-1,k); 
    return binarySearch(a,pivot+1,n-1,k); // 3 && 1
}

/* Driver code */
int main()  
{  
    int arr[] = {3,4,5,6,1,2};  
    int n = sizeof(arr)/sizeof(arr[0]);
    int k;
    cin >> k;  
    cout << "Index of the element is : " << indexUsingPivotAndBinarySearch(arr, n , k);  
    return 0;  
} 