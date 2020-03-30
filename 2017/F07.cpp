#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; i++)

int sub(int maxs, int mins){ return (maxs - mins); }
int checkEqual(string S)
{
    string mins, maxs;
    int ans = 8;
  
    for(int k = 1; k < S.size(); k++){
        if(S.size() % k != 0) continue;
        mins = maxs = S.substr(0, k);
        for(int s = 0; s < S.size(); s += k){
            maxs = max(maxs, S.substr(s, k));
            mins = min(mins, S.substr(s, k));
        }
        ans = min(ans, sub(stoi(maxs), stoi(mins)));
    }
    return ans;
}

int check12(string S)
{
    int maxv = 0;
    int minv = 10;
    int p = 0, v;

    while( p < S.size() ){
        v = int(S[p]);
        if(S[p] == '1' && p + 1 < S.size()){
            v = 10 + int(S[p+1]);
            p++;
        }
        p++;
        maxv = max(maxv, v);
        minv = min(minv, v);
    }
    return (maxv - minv);
}

int main()
{
    string s; cin >> s;
    int ans = 8;
  
    ans = min(ans, checkEqual(s));
    ans = min(ans, check12(s));
  
    cout << ans << endl;
    return 0;
}
