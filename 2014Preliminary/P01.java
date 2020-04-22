import java.io.*;
import java.util.*;

class P01{
    void solve(){
	Scanner sc = new Scanner( System.in );
	int nDesk = sc.nextInt();
	int nChair = sc.nextInt();
	System.out.println(nDesk * nChair);
    }
    public static void main(String[] a){ new P01().solve(); }
}
