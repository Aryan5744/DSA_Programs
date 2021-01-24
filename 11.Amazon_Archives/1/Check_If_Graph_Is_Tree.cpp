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
Time Complexity: O(V+E).
Time Complexity of this method is same as time complexity of DFS traversal which is O(V+E).
Space Complexity: O(V).
To store the visited and recursion stack O(V) space is needed.

An undirected graph is tree if it has following properties. 
1) There is no cycle. 
2) The graph is connected.

*/
class Graph{
    int V;
    list<int> *adj;
    bool isCyclicUtil(int v, bool *visited, int parent);
    public : 
    Graph(int v);
    void addEdge(int v, int w);
    bool isTree();
};

Graph :: Graph(int V){
    this->V = V;
    adj = new list<int>[V];
}

void Graph :: addEdge(int v, int w){
    adj[v].push_back(w);
    adj[w].push_back(v);
}

bool Graph :: isCyclicUtil(int v, bool *visited, int parent){
    visited[v] = true;
    list<int> :: iterator i;
    for(i = adj[v].begin() ; i != adj[v].end() ; i++){
        if(!visited[*i]){
            if(isCyclicUtil(*i, visited, v))
                return true;
        }
        else if(*i != parent)
            return true;
    }
    return false;
}
bool Graph :: isTree(){
    bool *visited = new bool[V];

    memset(visited, false, sizeof(visited));

    if(isCyclicUtil(0, visited, -1))
        return false;

    for(int i = 0 ; i < V ; i++)
        if(!visited[i])
            return false;

    return true;
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);      
    Graph g1(5); 
    g1.addEdge(1, 0); 
    g1.addEdge(0, 2); 
    g1.addEdge(0, 3); 
    g1.addEdge(3, 4); 
    g1.isTree()? cout << "Graph is Tree\n": 
                 cout << "Graph is not Tree\n"; 
  
    Graph g2(5); 
    g2.addEdge(1, 0); 
    g2.addEdge(0, 2); 
    g2.addEdge(2, 1); 
    g2.addEdge(0, 3); 
    g2.addEdge(3, 4); 
    g2.isTree()? cout << "Graph is Tree\n": 
                 cout << "Graph is not Tree\n";  
    return 0;
}