import java.io.*;
import java.util.*;

class F03{
    void solve(){
        Scanner sc = new Scanner( System.in );

        int[] p1 = new int[3];
        int[] p2 = new int[3];

        for ( int i = 0; i < 3; ++i ) p1[i] = sc.nextInt();
        for ( int i = 0; i < 3; ++i ) p2[i] = sc.nextInt();

        if (  p1[0] > p2[0] || ( p1[0] == p2[0] && (p1[1] > p2[1] || (p1[1] == p2[1] && p1[2] > p2[2]) ) ) ) {
            int t = p1[0]; p1[0] = p2[0]; p2[0] = t;
            t = p1[1]; p1[1] = p2[1]; p2[1] = t;
            t = p1[2]; p1[2] = p2[2]; p2[2] = t;
        }
        if ( p1[1] < p2[1] || (p1[1] == p2[1] && p1[2] < p2[2]) ) 
            System.out.println( p2[0] - p1[0] + 1 );
        else System.out.println( p2[0] - p1[0] );
    }
    public static void main(String[] a){ new F03().solve(); } 
}