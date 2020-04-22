import java.io.*;
import java.util.*;

class P03{
    void solve(){
	Scanner sc = new Scanner(System.in);
	int n = sc.nextInt();
	for(int i = 0; i < n; i++){
	    int k = sc.nextInt();
	    int p = sc.nextInt();
	    System.out.println( (k-1)%p+1 );
	}
    }
    public static void main(String[] a){ new P03().solve(); }
}
