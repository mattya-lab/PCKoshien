import java.io.*;
import java.util.*;

class F01 {
    void solve() {
        Scanner sc = new Scanner( System.in );
        int w = sc.nextInt(), h = sc.nextInt();
        String c = sc.next();

        for ( int i = 1; i <= h; ++i ){
            for ( int j = 1; j <= w; ++j ){
                if ( (i == 1 && j == 1) || ( i == 1 && j == w ) || 
                    (i == h && j == 1) || ( i == h && j == w ) )
                    System.out.print ("+");
                else if (i == 1 || i == h ) System.out.print("-");
                else if (j == 1 || j == w ) System.out.print("|");
                else if ( i == (h+1)/2 && j == (w+1)/2)
                    System.out.print(c);
                else System.out.print(".");
            }
            System.out.println("");
        }
    }
    public static void main(String[] a) { new F01().solve(); }
}