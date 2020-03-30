#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; i++)

int main(){
    int w, h;
    string s[1000];
    set<string> st;
    char c;
    cin >> w >> h;

    for(int i = 0; i < h; st.insert(s[i++]))
        rep(j, w) cin >> c, s[i] += c; 
    sort(s, s+h);
    bool ans = 1;
    int cnt = 0;
    rep(i, w){
        if(s[0][i] == '1') cnt++;
        if(s[h/2-1][i] == s[(h+1)/2][i]) ans = 0;
    }
    if((cnt != w/2 && cnt != (w+1)/2) || st.size() != 2) ans = 0;
    cout << (ans? "yes":"no") << endl;
    return 0;
}
