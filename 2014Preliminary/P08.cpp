#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; i++)
typedef long long ll;

#define MAX_N 1000
#define INFTY 99999

class RMQ {
public:
  int n;
  ll D[2*MAX_N-1];
  RMQ(){}
  RMQ(int n_){
    n = 1;
    while(n < n_) n *= 2;
    rep(i, 2*n-1) D[i] = INFTY;
  }
  void update(int k, ll a) {
    k += n - 1;
    D[k] = a;
    while (k > 0) { 
      k = (k - 1) / 2; 
      D[k] = min( D[2*k+1], D[2*k+2] ); 
    }
  }
  ll findMin(int a, int b) { return query(a, b+1, 0, 0, n); }
  ll query(int a, int b, int k, int l, int r) {
    if (r <= a || b <= l) return INFTY;
    if (a <= l && r <= b) return D[k];
    else {
      ll vl = query(a, b, k*2 + 1, l, (l + r) / 2);
      ll vr = query(a, b, k*2 + 2, (l + r) / 2, r);
      return min(vl, vr);
    }
  }
};

class Star {
public:
  ll x, y, l;
  Star() {}
  Star(ll x, ll y, ll l) :x(x), y(y), l(l) {}
  bool operator < (const Star &s) const { return l < s.l; }
};

Star S[MAX_N];
RMQ minXQ = RMQ(MAX_N);
RMQ minYQ = RMQ(MAX_N);
RMQ maxXQ = RMQ(MAX_N);
RMQ maxYQ = RMQ(MAX_N);

int main() {
  int n;
  ll d, x, y, l;
  cin >> n >> d;
  rep(i, n) { cin >> x >> y >> l; S[i] = Star(x, y, l); }
  sort(S, S + n);
  
  rep(i, n) {
    minXQ.update(i, S[i].x);
    minYQ.update(i, S[i].y);
    maxXQ.update(i, S[i].x * (-1));
    maxYQ.update(i, S[i].y * (-1));
  }
  int t = 0;
  ll maxarea = -1;

  rep(s, n) {
    while ( (t < n) && (S[t].l - S[s].l <= d) ) t++;
    t--;
    ll a = ((-1)*maxXQ.findMin(s, t)-minXQ.findMin(s, t)) * ((-1)*maxYQ.findMin(s, t)-minYQ.findMin(s, t));
    maxarea = max(maxarea, a);
  }
  cout << maxarea << endl;

  return 0;
}
