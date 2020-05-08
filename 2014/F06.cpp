#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; i++)

#define MAX 300

int nSize;
int frame[MAX][MAX];

int maxSum;
int rowSum[MAX][MAX+1];
int colSum[MAX][MAX+1];

int RowSum(int i, int s, int e){ return rowSum[i][e+1] - rowSum[i][s]; }
int ColSum(int j, int s, int e){ return colSum[j][e+1] - colSum[j][s]; }

void InitSum(){
  rep(i, nSize){
    rowSum[i][0] = 0;
    colSum[i][0] = 0;
    for(int k = 1; k <= nSize; ++k){
      rowSum[i][k] = rowSum[i][k-1] + frame[i][k-1];
      colSum[i][k] = colSum[i][k-1] + frame[k-1][i];
    }
  }
}

void solve(){
  InitSum();
  rep(i, nSize){
    for(int j = i; j < nSize; ++j){
      maxSum = max( RowSum(i, i, j), maxSum);
      if(j == i) continue;

      int colMax = ColSum(0, i, j);
      for( int k = 1; k < nSize; ++k ){
	int col = ColSum(k, i, j);
	maxSum = max( maxSum, max(colMax+col, col) );
	colMax = max( colMax + frame[i][k] + frame[j][k], col);
      }
    }
  }
  cout << maxSum << endl;
}
				  
int main(void){
  cin >> nSize;
  rep(i, nSize){ rep(j, nSize){ cin >> frame[i][j]; } }
  solve();
  return 0;
}
