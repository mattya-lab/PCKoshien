#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; i++)

class Rect {
public:
  int m_w, m_h;
  Rect() { }
  bool operator == (const Rect& r) const {
    return r.m_w == m_w && r.m_h == m_h;
  }
  bool operator < (const Rect& r) const {
    if ( m_w < r.m_w ) return true;
    if ( m_w == r.m_w ) return m_h < r.m_h;
    return false;
  }
};

bool IsCycle( int a1, int a2, int a3, int a4, int a5, int a6)
{
  return a1 == a6 && a2 == a3 && a4==a5;
}

bool IsPossible( const Rect* aRect ){
  if( aRect[0] == aRect[1] && aRect[2] == aRect[3] && aRect[4] == aRect[5]) {
    int c[6] = { aRect[0].m_w, aRect[0].m_h, aRect[2].m_w, aRect[2].m_h,
		 aRect[4].m_w, aRect[4].m_h };

    if( IsCycle(c[0], c[1], c[2], c[3], c[4], c[5]) ||
        IsCycle(c[0], c[1], c[2], c[3], c[4], c[5]) ||
	IsCycle(c[0], c[1], c[2], c[3], c[4], c[5]) ||
	IsCycle(c[0], c[1], c[2], c[3], c[4], c[5]) ||
	IsCycle(c[0], c[1], c[2], c[3], c[4], c[5]) ||
	IsCycle(c[0], c[1], c[2], c[3], c[4], c[5]) ||
	IsCycle(c[0], c[1], c[2], c[3], c[4], c[5]) ||
	IsCycle(c[0], c[1], c[2], c[3], c[4], c[5]) ) {
      return true;
    }
  }
  return false;
}

int main(void){
  Rect aRect[6];
  rep(i, 6)
    if( scanf("%d %d", &aRect[i].m_h, &aRect[i].m_w) != 2 ) return 0;

  Rect aRectTmp[6];
  for( int i = 0; i <= (1<<6); ++i ){
    rep(j, 6){
      aRectTmp[j] = aRect[j];
      if ( i & (1<<j) ) swap( aRectTmp[j].m_h, aRectTmp[j].m_w );
    }
    sort( aRectTmp, aRectTmp+6 );
    if( IsPossible(aRectTmp) ){
      cout << "yes" << endl; return 0;
    }
  }
  cout << "no" << endl;
  return 0; 
}
