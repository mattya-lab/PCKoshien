#include"bits/stdc++.h"
using namespace std;
#define rep(i, n) for(int i = 0; i < n; i++)

#define MAX 200000
int n, m, q;

struct node { int prev, next; bool f; };
node S[MAX];
int A[MAX];

void simulate() {
	int cur = 0;
	int a;
	rep(i, m) {
		a = A[i];
		if (a % 2 == 0) {
			rep(c, a) cur = S[cur].next;
		}
		else {
			rep(c, a) cur = S[cur].prev;
		}
		S[cur].f = false;
		S[S[cur].prev].next = S[cur].next;
		S[S[cur].next].prev = S[cur].prev;
		cur = S[cur].next;
	}
}


int main() {
	cin >> n >> m >> q;
	rep(i, n) {
		S[i].f = true;
		S[i].next = (i + 1) % n;
		S[i].prev = (i + n - 1) % n;
	}
	rep(i, m) { cin >> A[i]; }
	simulate();
	rep(i, q) {
		int x;
		cin >> x;
		cout << S[x].f << endl;
	}
	return 0;
}
