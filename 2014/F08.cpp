#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; i++)
typedef long long ll;

typedef struct { int w, t; } Book; /* w.. weight, t .. thickness */
typedef struct { int c, b; } Shelf;

#define MAX_M 1000000
#define MAX_N 10

int m, n;
Book book[MAX_M];
Shelf shelf[MAX_N];
int placeable[1 << MAX_N];
int maxPlaceable;

int bookWSum[MAX_M + 1];
int bookTSum[MAX_M + 1];

int BookWeightSum(int i, int j) { return bookWSum[j] - bookWSum[i-1]; }
int BookThickSum(int i, int j) { return bookTSum[j] - bookTSum[i-1]; }

bool IsPlaceable(int i, int s, int e) {
	if (s > e) return false;
	return BookWeightSum(s, e) <= shelf[i - 1].c && BookThickSum(s, e) <= shelf[i - 1].b;
}

int PlaceableBook(int shelf, int book_start) {
	if ( !IsPlaceable(shelf, book_start, book_start) ) return book_start - 1;
	if ( IsPlaceable(shelf, book_start, m )) return m;

	int s = book_start;
	int e = m;
	while (e - s > 1) {
		int mid = (s + e) / 2;
		if (IsPlaceable(shelf, book_start, mid)) s = mid;
		else e = mid;
	}
	if (IsPlaceable(shelf, book_start, e)) return e;
	return s;
}

void check() {
	rep(used, (1 << n)) {
		rep(i, n) {
			if ( !( (used >> i) & 1 ) ) {
				int b = PlaceableBook(i + 1, placeable[used] + 1);
				int used_update = used | (1 << i);
				placeable[used_update] = max(placeable[used_update], b);
				if (placeable[used_update] > maxPlaceable) {
					maxPlaceable = placeable[used_update];
				}
				if (maxPlaceable == m) return;
			}
		}
	}
}

void solve() {
	bookWSum[0] = 0;
	bookTSum[0] = 0;
	rep(i, m) { 
		bookWSum[i + 1] = bookWSum[i] + book[i].w;
		bookTSum[i + 1] = bookTSum[i] + book[i].t;
	}
	fill(placeable, placeable + (1 << n), 0);
	maxPlaceable = 0;
	check();
	cout << maxPlaceable << endl;
}

int main() {
	cin >> m >> n;
	rep(i, m) { cin >> book[i].w >> book[i].t; }
	rep(i, n) { cin >> shelf[i].c >> shelf[i].b; }
	solve();

	return 0;
}