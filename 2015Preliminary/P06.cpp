#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; i++)
using p = pair<int, int>;

using vi = vector<int>;
using vvi = vector<vector<int>>;

bool checkVerticalandHorizontalSymmetry(vvi p, int n) {
	rep(i, n / 2) {
		rep(j, n / 2) {
			if (p[i][j] != p[i][(n - 1) - j]) { return false; }
			if (p[i][j] != p[(n - 1) - i][j]) { return false; }
			if (p[i][j] != p[(n - 1) - i][(n - 1) - j]) { return false; }
		}
	}
	return true;
}

int main(void) {
	int c, n; cin >> c >> n;
	vvi p(n, vi(n)); 
	string s;
	rep(i, n) {
		cin >> s;
		rep(j, n) {
			p[i][j] = (s[j] == '1') ? 1 : 0;
		}
	}
	int ans = 0;
	if (checkVerticalandHorizontalSymmetry(p, n)) ans++;

	rep(i, c - 1) {
		int d; cin >> d;
		rep(j, d) {
			int r, c2; cin >> r >> c2;
			r--; c2--;
			p[r][c2] = (p[r][c2] == 1) ? 0 : 1;
		}
		if (checkVerticalandHorizontalSymmetry(p, n)) ans++;

	}
	cout << ans << endl;

	return 0;
}