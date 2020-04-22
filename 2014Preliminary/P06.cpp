#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for( int i = 0; i < n; i++ )

class Floppy{
public:
  int f[31], cost;
  Floppy(){ cost = 0; }
  bool operator < (const Floppy &p) const{
    for(int i = 1; i <=30; i++){
      if( f[i] == p.f[i] ) continue;
      return f[i] < p.f[i];
    }
    return false;
  }
  bool solved(){
    return eq(1, 9) && eq(10, 12) && eq(13, 15) && eq(16, 18) && eq(19, 21) && eq(22, 30);
  }
  bool eq( int b, int e ){
    for(int i = b; i < e; i++){
      if( f[i] != f[i+1] ) return false;
    }
    return true;
  }
  void sw( int i, int j ){ swap(f[i], f[j]); }
  void roll1(){ sw(10, 12); sw(18, 13); sw( 8, 23); sw( 7, 22); sw( 9, 24); }
  void roll2(){ sw( 1, 28); sw( 3, 30); sw(21, 19); sw( 2, 29); sw(15, 16); }
  void roll3(){ sw(16, 18); sw( 1, 24); sw( 7, 30); sw( 4, 27); sw(10, 21); }
  void roll4(){ sw(13, 15); sw( 9, 28); sw( 3, 22); sw(12, 19); sw( 6, 25); }
};

int bfs(Floppy s){
  queue<Floppy> Q;
  set<Floppy> V;
  Q.push(s);
  V.insert(s);

  Floppy u, v;
  while( !Q.empty() ){
    u = Q.front(); Q.pop();
    if( u.solved() ) return u.cost;
    v = u;
    v.roll1(); v.cost++;
    if( V.find(v) == V.end() ) Q.push(v);

    v = u;
    v.roll2(); v.cost++;
    if( V.find(v) == V.end() ) Q.push(v);

    v = u;
    v.roll3(); v.cost++;
    if( V.find(v) == V.end() ) Q.push(v);

    v = u;
    v.roll4(); v.cost++;
    if( V.find(v) == V.end() ) Q.push(v);
  }
  return -1;
}

int main(){
  Floppy F;
  int n; cin >> n;
  rep(t, n){
    for(int i = 1; i <= 30; i++) cin >> F.f[i];
    int ans = bfs(F);
    cout << ans << endl;
  }
  return 0;
}
