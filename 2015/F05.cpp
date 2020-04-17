#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; i++)

int main(void){
  int n; cin >> n;
  int A[n], T[n];
  int ans=0;
  for ( int i = 1; i <= n; i++ ){
    cin >> A[i];
    T[i] = T[i-1] + A[i];
  }
  for(int i = 1; i <= n; i++){
    rep(j, i){
      if( (T[i] - T[j]) == 0 ) ans = max(i - j, ans);
    }
  }
  cout << ans << endl;
  return 0;
}
