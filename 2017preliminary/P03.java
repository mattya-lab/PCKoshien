import java.io.*;
import java.util.*;

class P03 {
    static final String[] wd = {"thu", "fri", "sat", "sun", "mon", "tue", "wed"};
    void solve(){
	Scanner sc = new Scanner (System.in);
	int d = sc.nextInt();
	System.out.println( wd[d%7] );
    }
    public static void main(String[] a){ new P03().solve(); }
}
