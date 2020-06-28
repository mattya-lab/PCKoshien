#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; i++)
typedef long long ll;

typedef vector<int> vInt;
typedef unsigned long long ullong;
#define ITER(i, c) for(__typeof((c).begin()) i = (c).begin(); i!= (c).end(); ++i)
#define MAX_N 1000
#define MAX_CHILD 10
#define MOD 1000000007

class Node{
public:
  enum{ELEM, ALT, OR};
  int m_type;
  bool m_opt;
  vInt m_child;
public:
  Node(){
    m_type = ELEM;
    m_opt = false;
  }
};

int Elem(const Node& node);
int Or(const Node& node);
int Alt(const Node& node);
int Sum(const Node& node);

int nNode;
Node aNode[MAX_N];

int Elem(const Node& node){
  ullong res = 1;
  ITER(itN, node.m_child) res = (res * Sum( aNode[*itN] ) ) % MOD;
  return ( node.m_opt ) ? (int)res + 1 : (int)res;
}
int Alt(const Node& node){
  ullong res = 0;
  ITER(itN, node.m_child) res = (res + Sum( aNode[*itN] ) ) % MOD;
  return ( node.m_opt ) ? (int)res + 1 : (int)res;
}
int Or(const Node& node){
  int aChild[MAX_CHILD];
  rep( i, node.m_child.size() ) { aChild[i] = Sum( aNode[node.m_child[i]] ); }
  ullong res = 0;
  int m = 1 << node.m_child.size();
  for(int i = 1; i < m; i++){
    ullong partSum = 1;
    rep(k, node.m_child.size()){
      if( (i >> k) & 1 ) partSum = (partSum * aChild[k]) % MOD;
    }
    res = (res + partSum) % MOD;
  }
  return ( node.m_opt ) ? (int)res + 1 : (int)res; 
}
  
int Sum(const Node& node){
  if(node.m_type == Node::ELEM) return Elem(node);
  else if (node.m_type == Node::OR) return Or(node);
  return Alt(node);
}

void solve(){ cout << Sum( aNode[0] ) << endl; }

int main(){
  int s, t;
  char str[8];
  cin >> nNode;
  rep(i, nNode){
    cin >> str;
    Node& node = aNode[i];
    if(str[0] == 'E') node.m_type = Node::ELEM;
    else if(str[0] == 'A') node.m_type = Node::ALT;
    else if(str[0] == 'R') node.m_type = Node::OR;
    
    if(str[1] == '?') node.m_opt = true;
  }
  rep(i, nNode-1){
    cin >> s >> t; --s; --t;
    aNode[s].m_child.push_back(t);
  }
  solve();
  return 0;
}