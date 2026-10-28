
import java.util.*;
import java.io.*;

class Codechef {
    public static void main(String[] args) throws java.lang.Exception {
        Scanner sc = new Scanner(System.in);
        int T = sc.nextInt();

        while (T-- > 0) {
            int N = sc.nextInt();
            long H = sc.nextLong();

            int[] A = new int[N];
            long sum = 0;

            for (int i = 0; i < N; i++) {
                A[i] = sc.nextInt();
                sum += A[i];
            }

            Arrays.sort(A);

            long damage = sum;
            int X = 0;

            for (int i = 0; i < N; i++) {
                if (damage < H) {
                    break;
                }

                damage -= A[i];
                X = A[i];
            }

            System.out.println(damage < H ? X : 0);
        }

        sc.close();
    }
}
