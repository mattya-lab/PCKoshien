#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; i++)

int main(){
  int h[2], k[2];
  int a, b, c, d;
  
  rep(i, 2){ cin >> h[i]; }
  rep(i, 2){ cin >> k[i]; }
  cin >> a >> b >> c >> d;


  int score_a = (h[0] % 10) * a;
  int score_b = (h[1] % 20) * b;
  int score_c = (h[0] / 10) * c;
  int score_d = (h[1] / 20) * d;
  int sum_h = score_a + score_b + score_c + score_d;

  score_a = (k[0] % 10) * a;
  score_b = (k[1] % 20) * b;
  score_c = (k[0] / 10) * c;
  score_d = (k[1] / 20) * d;
  int sum_k = score_a + score_b + score_c + score_d;
  
  if (sum_h > sum_k) cout << "hiroshi" << endl;
  else if (sum_h < sum_k) cout << "kenjiro" << endl;
  else cout << "even" << endl;
  
  return 0;
}
