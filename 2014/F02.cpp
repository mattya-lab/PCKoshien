#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; i++)
typedef long long ll;

#define DIGIT (12)

int TernaryValue(int* expr) {
	int val = 0;
	int m = 1;
	rep(i, DIGIT) {
		val += expr[i] * m;
		m *= 3;
	}
	return val;
}
void PrintTernaryExpr(int* expr) {
	int j = DIGIT - 1;
	while (expr[j] == 0) --j;
	for (int i = j; i >= 0; --i) {
		if (expr[i] == 1) printf("+");
		else if (expr[i] == 0) printf("0");
		else printf("-");
	}
	printf("\n");
}

int main() {
	int x, val = 0; 
	cin >> x;
	int expr[DIGIT];
	fill(expr, expr + DIGIT, 0);
	while ( x != val ) {
		++expr[0];
		rep(i, DIGIT) {
			if (expr[i] <= 1) break;
			++expr[i + 1];
			expr[i] = -1;
		}
		val = TernaryValue(expr);
	}
	PrintTernaryExpr( expr );
	return 0;
}