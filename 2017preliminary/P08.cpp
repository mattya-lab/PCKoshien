#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; i++)

int main(){
  int w, h, num_enemy;
  cin >> w >> h >> num_enemy;

  vector<int> rangeMaxY(w);
  vector<int> maxY(w);

  int x, y;
  rep(i, num_enemy){
    cin >> x >> y;
    if( y > maxY[x] ) maxY[x] = y;
  }
  rangeMaxY[w-1] = 0;
  for(int i = w - 2; i >= 0; --i){
    rangeMaxY[i] = max( maxY[i+1], rangeMaxY[i+1] );
  }
  int min_cost = w;
  rep(i, w){
    min_cost = min(i + rangeMaxY[i], min_cost);
  }
  cout << min_cost << endl;
  return 0;
}
