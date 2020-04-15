#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for( int i = 0; i < n; i++ )

int main(void){
  int n; cin >> n;
  int in[n], P[n];
  
  rep(i, n){ in[i] = 0; P[i] = 0; }
  rep(i, n){
    int v; cin >> v;
    v = (i+v)%n;
    P[i] = v;
    in[v]++;
  }

  queue<int> Q;
  rep(i, n){
    if(in[i] == 0) Q.push(i);
  }
  int res = 0;
  while( !Q.empty() ){
    int u = Q.front(); Q.pop();
    res++;
    int v = P[u];
    in[v]--;
    if( in[v] == 0) Q.push(v);
  }
  cout << (n - res) << endl;
  return 0;
}
