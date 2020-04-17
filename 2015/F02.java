import java.io.*;
import java.util.*;

class StringPair implements Comparable< StringPair >{
    public String first;
    public String second;

    StringPair( String first, String second ){
	this.first = first;
	this.second = second;
    }
    public int compareTo( StringPair other ){
	int cmp = first.compareTo( other.first );
	return cmp == 0 ? second.compareTo( other.second ) : cmp;
    }
}

class F02 {
    static final int MAX_N = 100;
    static final int MAX_M = 100;

    void solve(){
	TreeMap< StringPair, Integer > mapSSN = new TreeMap< StringPair, Integer >();
	Scanner sc = new Scanner( System.in );

	int n = sc.nextInt();
	int f = sc.nextInt();
	int count[] = new int[MAX_M * MAX_M * MAX_M];
	int g = 0;
	for ( int i = 0; i < MAX_M*MAX_M*MAX_M; ++i ) count[i] = 0;
	for ( int i = 0; i < n; ++i){
	    int m = sc.nextInt();
	    String goods[] = new String[m];
	    for ( int j = 0; j < m; ++j ) goods[j] = sc.next();
	    for ( int j = 0; j < m; ++j ) {
		for (int k = j+1; k < m; ++k){
		    StringPair pair = null;
		    if ( goods[j].compareTo( goods[k] ) < 0)
			pair = new StringPair( goods[j], goods[k] );
		    else
			pair = new StringPair( goods[k], goods[j] );
		    if ( mapSSN.containsKey( pair ) ){
			++count[mapSSN.get(pair)];
			if( count[mapSSN.get(pair)] == f) ++g;
		    }
		    else{
			count[mapSSN.size()] = 1;
			mapSSN.put( pair, mapSSN.size() );
			if (f == 1) ++g;
		    }
		}
	    }
	}
        System.out.println( g );
	Iterator<StringPair>  itPair = mapSSN.keySet().iterator();
	while( itPair.hasNext() ){
	    StringPair key = itPair.next();
	    if ( count[mapSSN.get(key)] >= f ){
		System.out.println(key.first + " " + key.second );
	    }
	}
    }
    public static void main ( String[] a ){ new F02().solve(); }
}
