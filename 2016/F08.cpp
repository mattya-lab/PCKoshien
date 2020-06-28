#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; i++)
typedef long long ll;

int W, H;
ll G[100][100];

ll score(int i, int j){
  if ( (i + j) % 2 == 0 ) return (G[i+1][W] - G[i+1][j]) - G[i+1][j];
  return G[i+1][j] - (G[i+1][W] - G[i+1][j]);
}

int main(){
  cin >> W >> H;
  for (int i = 0; i <= H; i++) { G[i][0] = 0; }
  for (int i = 1; i <= H; i++) {
    for (int j = 1; j <= W; j++) {
      cin >> G[i][j];
      G[i][j] += G[i][j-1];
    }
  }
  
  ll dp[H + 1][W + 1];
  for (int i = H; i >= 0; i--){
    for (int j = W; j >= 0; j--){
      if (i == H) { dp[i][j] = 0; }
      else if (j == W){ dp[i][j] = score(i, j) - dp[i+1][j]; }
      else { dp[i][j] = max( (-1)*dp[i][j+1], score(i, j) - dp[i+1][j] ); }
    }
  }

  cout << abs( dp[0][0] ) << endl;
  
  return 0;
}
