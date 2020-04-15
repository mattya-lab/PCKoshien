#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; i++)

int main(void){
  int n; cin >> n;
  int s[n];
  rep(i, n){ cin >> s[i]; }
  sort(s, s+n);
  
  double res = 0.0;
  rep(d, n){
    int c = d+1;
    int a = n-1;
    int b = n-2;
    if( d == n-3 ){
      b = d - 1;
    }else if( d == n-2 ){
      a = d - 2;
      b = d - 1;
    }
    res = max(res, 1.0*(s[a]+s[b]) / (s[c]-s[d]));
  }
  cout << res << endl;
  return 0;
}
