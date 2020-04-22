import java.io.*;
import java.util.*;

class P05{
    int n, m, p;
    boolean visit[];
    int aDest[];

    int CWDist( int s, int e ){ return ( e - s < 0 ) ? e - s + n : e - s; }
    int CCWDist( int s, int e ){ return ( s - e < 0 ) ? s - e + n : s - e; }
    int CWNext ( int i ){
	do{
	    if( ++i >= n ) i = 0;
	}while( !visit[i] );
	return i;
    }
    int CCWNext( int i ){
	do{
	    if( --i < 0 ) i = n -1;
	}while( !visit[i] );
	return i;
    }
    
    int CWTurn( int p, int t, int e ){
	return CWDist(p, t) + CCWDist(t, e);
    }
    int CCWTurn(int p, int t, int e){
	return CCWDist(p, t) + CWDist(t, e);
    }
    void solve(){
	Scanner sc = new Scanner(System.in);
	n = sc.nextInt();
	m = sc.nextInt();
	p = sc.nextInt();

	visit = new boolean[n];
	for( int i = 0; i < n; ++i) visit[i] = false;
	for( int i = 0; i < m; ++i){
	    int d = sc.nextInt();
	    visit[d] = true;
	}
	aDest = new int[m];
	for( int i = 0, k = 0; i < n; ++i){
	    if( visit[i] ) aDest[k++] = i;
	}
	int nDist = Math.min( CCWDist(p, CWNext(p)), CWDist(p, CCWNext(p)) );
	for(int i = 0; i < m; ++i){
	    int e = ( i == m-1 ) ? aDest[0] : aDest[i+1];
	    nDist = Math.min( nDist, CWTurn(p, aDest[i], e) );
	    e = ( i == 0 ) ? aDest[m-1] : aDest[i-1];
	    nDist = Math.min(nDist, CCWTurn(p, aDest[i], e));
	}
	System.out.println(100*nDist);
    }
    public static void main(String[] a){ new P05().solve(); }
}
