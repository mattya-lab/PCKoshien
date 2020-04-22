import java.io.*;
import java.util.*;

class P04{
    boolean exist[][] = new boolean[24][60];
    
    void solve(){
	for( int i = 0; i < 24; ++i )
	    for( int j = 0; j < 60; ++j)
		exist[i][j] = false;
	
	Scanner sc = new Scanner(System.in);
	for(int i = 0; i < 2; ++i){
	    int n = sc.nextInt();
	    for(int j = 0; j < n; ++j){
		int h = sc.nextInt();
		int m = sc.nextInt();
		exist[h][m] = true;
	    }
	}
	
	for(int i = 0; i < 24; ++i){
	    for(int j = 0; j < 60; ++j ){
		if( exist[i][j] )
		    System.out.printf("%d:%02d ", i, j);
	    }
	}
	System.out.println();
    }
    public static void main(String[] a){ new P04().solve(); }
}
