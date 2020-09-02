#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; i++)
typedef long long ll;

int main(){
  int n; cin >> n;
  vector<int> a, b, c;
  int ans = 0;
  
  int e;
  int x; cin >> x;
  rep(i, x) { cin >> e; a.push_back(e); }
  
  int y; cin >> y; 
  rep(i, y) { cin >> e; b.push_back(e); }
  
  int z; cin >> z;
  rep(i, z) { cin >> e; c.push_back(e); ans++; }
  
  rep(i, c.size()) {
    bool flag = true;
    rep(j, a.size()) {
      if(c[i] == a[j]){
	rep(k, b.size()){
	  if(c[i] == b[k] && flag){
	    flag = false;;
	  }
	}
	if(flag) ans--; 
      }
    }
  }
  cout << ans << endl;
  return 0;
}
