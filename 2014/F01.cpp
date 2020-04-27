#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; i++)
typedef long long ll;

int CalcID(int r, int t) { return r + 5 * t;  }
int main() {
  	int n, r, t;
	cin >> n;
	rep(i, n) {
		cin >> r >> t;
		bool bOnR = (r % 100 == 0) ? true : false;
		bool bOnT = (t % 30 == 0) ? true : false;
		r = r / 100;
		t = t / 30;
		if ( bOnR && bOnT ) cout << CalcID(r, t) << endl;
		else if ( bOnR ) cout << CalcID(r, t) << CalcID(r, t + 1) << endl;
		else if ( bOnT ) cout << CalcID(r, t) << CalcID(r + 1, t) << endl;
		else cout << CalcID(r, t) << CalcID(r + 1, t) << CalcID(r, t + 1) << CalcID(r+1, t+1) << endl;
	}
	return 0;
}