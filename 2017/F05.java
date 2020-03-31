import java.io.*;
import java.util.*;

class F05{
    void solve(){
        Scanner sc = new Scanner( System.in );
        int n = sc.nextInt();
        int[][][] periods = new int[n][3][2];
        int[][] check_point = new int[3][n];

        for( int i = 0; i < n; ++i ) {
            for( int j = 0; j < 3; ++j ) {
                for ( int k = 0; k < 2; ++k ) {
                    int h = sc.nextInt(), m = sc.nextInt();
                    periods[i][j][k] = h * 60 + m;
                    if ( k == 1 ) check_point[j][i] = periods[i][j][k];
                }
            }
        }

        int max_n = 0;
        for ( int b : check_point[0] ) {
            for ( int l : check_point[1] ) {
                for ( int d : check_point[2] ) {
                    int res = 0;
                    for( int i = 0; i < n; ++i) {
                        if ( b >= periods[i][0][0] && b <= periods[i][0][1] &&
                             l >= periods[i][1][0] && l <= periods[i][1][1] &&
                             d >= periods[i][2][0] && d <= periods[i][2][1] )
                            ++res;
                    }
                    max_n = Math.max(max_n, res);
                }
            }
        } 
        System.out.println( max_n ); 
    }
    public static void main( String[] a ){ new F05().solve(); }
}