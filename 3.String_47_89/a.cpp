#include <bits/stdc++.h> 
using namespace std; 
#define INF INT_MAX 

// A utility function to print the solution 
int printSolution (int p[], int n); 

// l[] represents lengths of different words in input sequence. 
// For example, l[] = {3, 2, 2, 5} is for a sentence like 
// "aaa bb cc ddddd". n is size of l[] and M is line width 
// (maximum no. of characters that can fit in a line) 
void solveWordWrap (int l[], int n, int M) 
{ 
	int extras[n+1][n+1]; 

    memset(extras,-1,sizeof(extras));
	int lc[n+1][n+1]; 
	int c[n+1]; 
	int p[n+1]; 

	int i, j; 
	int cost[size][size];
    int sum[size+1] = {0};
    sum[1] = words[0];

    int c[size] ,arrange[size];

    memset(lc, -1 , sizeof(lc));

    for(int i = 0 ; i < size ; i++)
       lc[i][i] =  pow((width - words[i]),2);

    for(int i = 2 ; i <= size ; i++)
       sum[i] = sum[i-1] + words[i-1];

    for(int i = 1 ; i <= size ; i++){
        for(int j = i+1 ; j <= size ; j++){
            if((width - (sum[j]-sum[i-1]) - (j-i)) > 0)
                lc[i-1][j-1] = pow((width - (sum[j]-sum[i-1]) - (j-i)),2);
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
			if (c[i-1] != INF && lc[i][j] != INF && 
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
	if (p[n] == 1) 
		k = 1; 
	else
		k = printSolution (p, p[n]-1) + 1; 
	cout << p[n] <<" "<<n << " "; 
	return k; 
} 

int main() 
{ 
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int size = 6,width = 15;
    //cin >> size;
    int words[size] = {4,4,7,6,2,10};
    //for(int i = 0 ; i < size ; i++)
    //   cin >> words[i];
    //cin >> width;
    solveWordWrap(words, size, width);
    cout << endl;
    return 0;
} 