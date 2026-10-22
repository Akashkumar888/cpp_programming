
import java.util.*;

class Codechef {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int T = sc.nextInt();

        while (T-- > 0) {
            int N = sc.nextInt();
            String P = sc.next();
            String C = sc.next();

            for (int i = 0; i < N; i++) {
                int p = P.charAt(i) - 'A';
                int c = C.charAt(i) - 'A';

                int diff = (c - p + 26) % 26;

                // Find the smallest non-negative K
                // such that (3 * K) % 26 == diff
                int k = 0;
                while ((3 * k) % 26 != diff) {
                    k++;
                }

                if (i > 0) System.out.print(" ");
                System.out.print(k);
            }
            System.out.println();
        }

        sc.close();
    }
}
