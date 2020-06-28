#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; i++)

typedef vector<int> vInt;
#define ITER(i, c) for(__typeof((c).begin()) i=(c).begin(); i!=(c).end(); ++i)
#define MAX_U 100
#define MAX_D 100
#define MAX_N ( MAX_U + MAX_D )

class Node {
public:
  int m_id;
  vInt m_child;
public:
  Node() { m_id = -1; }
};

Node aNode[MAX_N];
bitset<MAX_N> visit;
vInt::iterator itN;

bool IsCycle(int root,  const  Node& node) 
{
  if (node.m_id < 0 || visit.test(node.m_id)) return false;
  visit.set(node.m_id, true);
  if (node.m_id == root) return true;
  ITER(itN, node.m_child) {
    if ( IsCycle(root, aNode[*itN]) ) return true;
  }
  return false;
}

void Solve() 
{
  rep(i, MAX_N) {
    visit.reset();
    ITER(itN, aNode[i].m_child) {
      if ( IsCycle(aNode[i].m_id, aNode[*itN]) ) {
	    cout << "1" << endl; return;
      }
    }
  }
  cout << "0" << endl;
}

int main() {
  int nLine; cin >> nLine;
  int u, d;
  char str[8];
  rep(i, nLine) { 
    cin >> u >> str >> d;
    --u; --d; d += MAX_U;
    aNode[u].m_id = u;
    aNode[d].m_id = d;
    if (strncmp(str, "lock", 4) == 0) aNode[d].m_child.push_back(u);
    else if (strncmp(str, "wait", 4) == 0) aNode[u].m_child.push_back(d);
  }
  Solve();
  return 0;
}
