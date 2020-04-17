#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; i++)

int num[10], used[10], ans, cnt;

void saiki(int kai){
  cnt++;
  if (kai == 9){
    int up = 100*num[3] + 10*(num[1] + num[4]) + (num[0] + num[2] + num[5]);
    int down = 100*num[6] + 10*num[7] + num[8];
    if(up == down) ans++;
  }
  else if (num[kai] != -1) saiki(kai+1);
  else{
    for(int i = 1; i <= 9; i++){
      if (used[i] == 1) continue;
      used[i] = 1, num[kai] = i;
      saiki(kai+1);
      used[i] = 0, num[kai] = -1;
    }
  }
}

int main(void){
  rep(i, 9) { cin >> num[i], used[max(0, num[i])] = 1; }
  saiki(0);
  cout << ans << endl;
  return 0;
}
