#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for( int i = 0; i < n; i++)

int main(){
  string s; cin >> s;
  int a=0, b=0, c=0, k=0;
  rep( i, s.size() ){
    if( s[i] == '.' ){ k=1; continue; }
    if( s[i] == '(' ){
      while( s[++i] != ')' ) b*=10, c*=10, b+=s[i]-'0', c+=9;
    }
    else k*=10, a*=10, a+=s[i]-'0';
  }
  if( b ) a = b + a*c, k *= c;
  int g = __gcd(a, k);
  cout << a/g << '/' << k/g << endl;

  return 0;
}
