#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; i++)
typedef long long ll;

vector<int> AP, AQ, BP, BQ;

bool check(vector<int> vec, int val){
  for(int i = 0; i < vec.size();  i++){ if ( vec[i] == val ){ return true; } }
  return false;  
}

bool dfs(int p, int ap, int aq, int bp, int bq, int l, int r){
  if( p == 1){
    if( ap >= AP.size() && aq >= AQ.size() ) return true;
  }else{
    if( bp >= BP.size() && bq >= BQ.size() ) return false;
  }
  int cnt = 0;
  if( p == 0 ) {
    if( check(AP, l-1) ){
      cnt++;
      if( dfs( (p+1)%2, ap+1, aq, bp, bq, l-1, r) ) return true;
    }
    if( check(AQ, r+1) ){
      cnt++;
      if( dfs( (p+1)%2, ap, aq+1, bp, bq, l, r+1 ) ) return true;
    }
    if(cnt == 0){
      if( dfs( (p+1)%2, ap, aq, bp, bq, l, r) ) return true;
    }
    return false;
  }else{
    bool possible = true;
    if( check(BP, l-1) ){
      cnt++;
      if(!dfs( (p+1)%2, ap, aq, bp+1, bq, l-1, r)) return false;
    }
    if( check(BQ, r+1) ){
      cnt++;
      if(!dfs( (p+1)%2, ap, aq, bp, bq+1, l, r+1 )) return false;
    }
    if(cnt == 0){
      if( !dfs( (p+1)%2, ap, aq, bp, bq, l, r) ) return false;
    }
    return possible;
  }
}

int main(void){
  int n; cin >> n;
  rep(game, n){
    bool mycard[13+1];
    rep(i, 13+1){ mycard[i] = false; }
    int f[7];
    rep(i, 6){ cin >> f[i]; mycard[f[i]] = true; }
  
    AP = {}, AQ = {}, BP = {}, BQ = {};

    for(int i = 1; i <= 13; i++){
      if(i == 7) continue;
      else if(i < 7 && mycard[i]){ AP.push_back(i); } 
      else if(i > 7 && mycard[i]){ AQ.push_back(i); }
      else if(i < 7 && !mycard[i]){ BP.push_back(i); }
      else{ BQ.push_back(i); }
    }
    
    /* p = 0, ap = 0, aq = 0; bp = 0, bq = 0, l = 7, r = 7*/
    if ( dfs(0, 0, 0, 0, 0, 7, 7) ) { cout << "yes" << endl; }
    else { cout << "no" << endl; }
  } 
  return 0;
}
