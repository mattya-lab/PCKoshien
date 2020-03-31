import java.io.*;
import java.util.*;

class P06 {
    ArrayList<Integer> m_bounce = new ArrayList<Integer>();
    boolean IsPossibleToReach(){
	int current = 0;
	for (int i = 0; i < m_bounce.size(); ++i){
	    if (current < 10 * i) return false;
	    current = Math.max(current, 10*i + m_bounce.get(i));
	}
	return current >= 10*m_bounce.size() ? true : false;
    }
    void solve(){
	Scanner sc = new Scanner(System.in);
	int n = sc.nextInt();
	for( int i = 0; i < n; ++i) m_bounce.add( sc.nextInt() );

	if( !IsPossibleToReach() ){ System.out.println("no"); return; }
	Collections.reverse( m_bounce );
	if( IsPossibleToReach() ) System.out.println("yes");
	else System.out.println("no");
    }
    public static void main(String[] a){ new P06().solve(); } 
}
