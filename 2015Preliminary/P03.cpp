#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; i++)

int main(){
  int d, l; cin >> d >> l;
  int ans = 0;
  int x = 0;
  
  ans = d / l;
  x = d % l;  
  for(int i = 0; i < d % l; i++) ans++;
  cout << ans << endl;
  return 0;
}
