#include <bits/stdc++.h> 
using namespace std; 
#define INF INT_MAX 

int printSolution (int p[], int n); 

void solveWordWrap (int words[], int n, int M) 
{ 
	int extras[n+1][n+1]; 

    memset(extras,-1,sizeof(extras));
	int lc[n+1][n+1]; 
	int c[n+1]; 
	int p[n+1]; 

	int i, j; 
	int cost[n][n];
    int sum[n+1] = {0};
    sum[1] = words[0];

    //int c[n] ,arrange[n];

    memset(lc, -1 , sizeof(lc));

    for(int i = 0 ; i < n ; i++)
       lc[i][i] =  pow((M - words[i]),2);

    for(int i = 2 ; i <= n ; i++)
       sum[i] = sum[i-1] + words[i-1];

    for(int i = 1 ; i <= n ; i++){
        for(int j = i+1 ; j <= n ; j++){
            if((M - (sum[j]-sum[i-1]) - (j-i)) > 0)
                lc[i-1][j-1] = pow((M - (sum[j]-sum[i-1]) - (j-i)),2);
        }
    }
	// Calculate minimum cost and find minimum cost arrangement. 
	// The value c[j] indicates optimized cost to arrange words 
	// from word number 1 to j. 
	c[0] = 0; 
	for (j = 1; j <= n; j++) 
	{ 
		c[j] = INF; 
		for (i = 1; i <= j; i++) 
		{ 
			if (c[i-1] != INF && lc[i][j] != -1 && 
						(c[i-1] + lc[i][j] < c[j])) 
			{ 
				c[j] = c[i-1] + lc[i][j]; 
				p[j] = i; 
			} 
		} 
	} 

	printSolution(p, n); 
} 

int printSolution (int p[], int n) 
{ 
	int k; 
	if (p[n] == n) 
		k = 1; 
	else
		k = printSolution (p, p[n]+1) + 1; 
	cout << p[n] <<" "<<n << " "; 
	return k; 
} 

int main() 
{ 
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n = 6,M = 15;
    //cin >> n;
    int words[n] = {4,4,7,6,2,10};
    //for(int i = 0 ; i < n ; i++)
    //   cin >> words[i];
    //cin >> M;
    solveWordWrap(words, n, M);
    cout << endl;
    return 0;
} 