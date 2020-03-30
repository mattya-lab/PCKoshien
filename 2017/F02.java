import java.io.*;
import java.util.*;

class F02 {
    void solve(){
        Scanner sc = new Scanner( System.in );
        int n = sc.nextInt();
        double t = sc.nextDouble();
        double max_slope = 0.0;
        for ( int i = 0; i < n; ++i ){
            double xi = sc.nextDouble();
            double hi = sc.nextDouble();
            double slope = hi / xi;
            if ( slope > max_slope ) max_slope = slope;
        }
        System.out.println( max_slope * t );
    }
    public static void main( String[] a){ new F02().solve(); }
}
