#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; i++)

int main(void){
  double t_end, m0; cin >> m0 >> t_end;
  
  double dt = 0.01;
  double t_curr = 0.0;
  double dR = 1800.0;
  double dTm = 380000.0;
  double dTk = dR + 100.0;
  double dWm0 = m0 * M_PI / 180.0;
  double dWm = 2.0 * M_PI / (2500000 / 60.0);
  double dWk = 2.0 * M_PI / (120.0);

  double dRes = 0.0;
  while ( t_curr + 0.5 * dt < t_end ) {
    double cm = cos(dWm * t_curr + dWm0);
    double sm = sin(dWm * t_curr + dWm0);
    double ck = cos(dWk * t_curr);
    double sk = sin(dWk * t_curr);

    double xm = dTm * cm;
    double ym = dTm * sm;
    double zm = 0.0;

    double xk = xm - dTk * sk;
    double yk = ym;
    double zk = zm + dTk*ck;
    
    double xk_leng2 = xk*xk + yk*yk + zk*zk;
    double dot = xk*xm + yk*ym + zk*zm;
    double d = dot*dot - xk_leng2 * (dTm*dTm - dR*dR);

    if ( d > 0.0 ) {
      double s = (dot + sqrt(d)) / xk_leng2;
      if ( s < 1.0 ) dRes += dt;
    }
    t_curr += dt;
  }
  cout << dRes << endl;
  return 0;
}
