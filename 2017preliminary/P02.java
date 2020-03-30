import java.io.*;
import java.util.*;

class P02 {
    void solve(){
	Scanner sc = new Scanner(System.in);
	int m = sc.nextInt();
	int f = sc.nextInt();
	int b = sc.nextInt();
	if (m + b > 0) System.out.println( Math.max( 0, b-m ) );
	else System.out.println("NA");
    }
    public static void main(String[] a){ new P02().solve(); }
}
