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
1. Time Complexity : is O(N).

2. Time Complexity: O(logN).
*/

int findPeak(int arr[], int n){
    if(n == 1) return arr[0];

    if(arr[0] > arr[1]) return arr[0];

    if(arr[n-1] > arr[n-2]) return arr[n-1];

    for(int i = 1 ; i < n - 1 ; i++)
        if(arr[i] >= arr[i-1] && arr[i] >= arr[i+1])
            return arr[i];
}

int findPeakUsingBinarySearch(int arr[], int left, int right, int n){

    int mid = left + (right - left)/2;
    
    if((mid == 0 || arr[mid-1] <= arr[mid]) && (mid == n-1 || arr[mid+1] <= arr[mid]))
        return mid;
    
    else if(mid > 0 && arr[mid-1] > arr[mid])
        return findPeakUsingBinarySearch(arr,left,mid-1,n);

    else   
        return findPeakUsingBinarySearch(arr,mid+1,right,n);   
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int arr[] = { 1, 3, 20, 4, 1, 0 };
    int n = sizeof(arr) / sizeof(arr[0]);
    //cout << "Index of a peak point is " << findPeak(arr, n);
    cout << "Index of a peak point is " << findPeakUsingBinarySearch(arr, 0 , n-1, n);    

    return 0;
}