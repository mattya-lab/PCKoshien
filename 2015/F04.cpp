#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; i++)

static const int PMAX = 100000;
int n, T[2*PMAX+20+1];

int main(void){
  int a, b;
  rep(i, 2*PMAX+20+1){ T[i] = 0; }
  cin >> n;
  rep(i, n){
    cin >> a >> b;
    T[a+b]++;
  }
  rep(i, 2*PMAX+20+1){
    T[i+1] += T[i]/2;
    T[i] = T[i]%2;
    if ( T[i] ) cout << i << " " << 0 << endl;
  }
  return 0;
}
