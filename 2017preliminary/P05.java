import java.io.*;
import java.util.*;

class P05 {
    int gcd(int a, int b){
	if (a < b) return b%a == 0 ? a : gcd(a, b%a);
	return a%b == 0 ? b : gcd(b, a%b);
    }
    void solve(){
	Scanner sc = new Scanner( System.in );
	int x = sc.nextInt();
	int y = sc.nextInt();
	System.out.println( (x+1) + (y+1) - (gcd(x, y)-1) - 2);
    }
    public static void main(String[] a){ new P05().solve(); }
}
