import java.io.*;
import java.util.*;

class P04 {
    void solve(){
	Scanner sc = new Scanner (System.in);
	int a = sc.nextInt();
	int b = sc.nextInt();
	int n = sc.nextInt();
	int ans = 0;
	
	for (int i = 0; i < n; ++i){
	    int s = sc.nextInt();
	    int e = sc.nextInt();
	    if( b > s && a < e){
		ans = 1; 
	    }
	}
	System.out.println(ans);
    }
    public static void main(String[] a){ new P04().solve(); }
}
