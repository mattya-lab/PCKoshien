#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i= 0; i < n; i++)

int n, m, p;
vector<int> D;

int pdist(int s, int t){ return (t >= s) ? (t-s) : ( (t+n)-s ); }
int ndist(int s, int t){ return pdist(t, s); }

int solve(){
  if( D.size() == 1) return min(pdist(D[0], p), ndist(D[0], p));
  int ans = 2 * n;
  rep(i, m){
    int b = D[i];
    int e = D[(i+1)%m];
    int d = min(pdist(b, p), min(pdist(e, p), min(ndist(b, p), ndist(e, p))));
    ans = min(d + (n-pdist(b, e)), ans);
  }
  return ans;
}
int main(void){
  int k;
  cin >> n >> m >> p;
  rep(i, m){ cin >> k; D.push_back(k); }
  sort( D.begin(), D.end() );
  cout << 100*solve() << endl;
  return 0;
}
