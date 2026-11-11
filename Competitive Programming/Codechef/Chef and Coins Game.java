
import java.util.*;
import java.lang.*;
import java.io.*;

class Codechef {
    public static void main(String[] args) throws java.lang.Exception {
        Scanner sc = new Scanner(System.in);

        int T = sc.nextInt();

        while (T-- > 0) {
            int N = sc.nextInt();

            if (N % 6 == 0) {
                System.out.println("Misha");
            } else {
                System.out.println("Chef");
            }
        }

        sc.close();
    }
}
