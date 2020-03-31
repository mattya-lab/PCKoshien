import java.io.*;
import java.util.*;

class F04{
    void solve(){
        Scanner sc = new Scanner( System.in );
        int n = sc.nextInt();
        long max_t = 0;
        long[] timing = new long[n];

        for ( int i = 0; i < n; ++i){
           timing[i] = sc.nextLong();
           if ( timing[i] > max_t ) max_t = timing[i]; 
        }

        ArrayList < Long > divisor = new ArrayList < Long >();
        for ( Long i = 1L; i <= max_t>>1; ++i){
            if ( max_t % i == 0) divisor.add( i );
        }
        divisor.add( max_t );
        
        Long adj = 0L;
        for ( Long t : timing ){
            int j = 0;
            for ( ; j < divisor.size(); ++j ){
                if ( divisor.get(j) >= t ) break;
            }
            adj += divisor.get( j ) - t;
        }
        System.out.println( adj ); 
    }
    public static void main(String[] a){ new F04().solve(); }
}