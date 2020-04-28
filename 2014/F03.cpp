#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; i++)
typedef long long ll;

#define MAX_N (1000)

class Person {
public:
	int m_nCurr;
	int m_nPace;
	Person() {
		int m_nCurr = 0;
		int m_nPace = 0;
	}
};

int nPerson, nRound, nTime;
Person person[MAX_N];

int cup = 0;
int empty[MAX_N];
int filled[MAX_N];

int main() {
	cin >> nPerson >> nRound >> nTime;
	rep(i, nPerson) cin >> person[i].m_nPace;
	fill(empty, empty + nRound, 0);
	fill(filled, filled + nRound, 0);

	for (int t = 1; t <= nTime; t++) {
		rep(i, nPerson) {
			Person& p = person[i];
			p.m_nCurr = (p.m_nCurr + p.m_nPace) % nRound;
			if (t > 1) ++empty[p.m_nCurr];
			if (filled[p.m_nCurr] > 0) --filled[p.m_nCurr];
			else ++cup;
		}
		rep(i, nRound) {
			if (empty[i] > 0) {
				filled[i] += empty[i];
				empty[i] = 0;
			}
		}
	}
	cout << cup << endl;
	return 0;
}