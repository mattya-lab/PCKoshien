#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; i++)
typedef long long ll;

#define MAX (1000)
#define INF 99999
struct P{ int c, w; };
int n;
P S[MAX+1];
bool P[MAX+1][MAX+1];
int dp[MAX+1];
int L[MAX+1];

int main(){
  cin >> n;
  for(int i = 1; i <= n; i++){ cin >> S[i].c >> S[i].w; }
  for(int i = 1; i <= n; i++){
    for(int j = 1; j <= n; j++){
      P[i][j] = (i == j)? true : false;
    }
  }
  L[0] = 0;
  for(int i = 1; i <= n; i++ ) L[i] = S[i].w + L[i-1];

  for(int l = 1; l <= n; l++){
    for(int i = 1; i <= n-l+1; i++){
      int j = i + l - 1;
      if( !P[i][j] ) continue;
      if( j + 1 <= n){
	if( L[j] - L[i-1] <= S[j+1].c ){
	  P[i][j+1] = true;
	}
      }
      if( i - 1 >= 1 ){
	if(L[j] - L[i-1] <= S[i-1].c){
	  P[i-1][j] = true;
	}
      }
    }
  }
 
  for(int i = 0; i <= n; i++) dp[i] = INF;
  dp[0] = 0;
  for(int b = 1; b <= n; b++){
    for(int e = 1; e <= n; e++){
      if( !P[b][e] ) continue;
      dp[e] = min(dp[e], dp[b-1]+1);
    }
  }
  cout << dp[n] << endl;
  return 0;
}
