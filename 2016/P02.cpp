#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; i++)

int main(void){
  int a[12];
  rep(i, 12){ cin >>a[i]; }
  sort(a, a+12);
  if( a[0]==a[3] && a[4]==a[7] && a[8]==a[11]) cout << "yes" << endl;
  else cout << "no" << endl;

  return 0;
}
