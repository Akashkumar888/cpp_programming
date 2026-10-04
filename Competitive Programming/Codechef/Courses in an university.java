import java.util.*;
import java.lang.*;
import java.io.*;

class Codechef {
    public static void main(String[] args) throws java.lang.Exception {
        
        Scanner sc = new Scanner(System.in);
        
        int T = sc.nextInt();
        
        while (T-- > 0) {
            int n = sc.nextInt();
            
            int maxA = 0;
            
            for (int i = 0; i < n; i++) {
                int x = sc.nextInt();
                maxA = Math.max(maxA, x);
            }
            
            System.out.println(n - maxA);
        }
        
        sc.close();
    }
}
