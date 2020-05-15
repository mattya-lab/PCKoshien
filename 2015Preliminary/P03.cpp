#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; i++)

int main(){
  int d, l; cin >> d >> l;
  
  int ans = d / l;
  for(int i = 0; i < d % l; i++) ans++;
  cout << ans << endl;
  return 0;
}
