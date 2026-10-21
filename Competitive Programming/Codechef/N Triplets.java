
import java.util.*;
import java.io.*;

class Codechef {
    public static void main(String[] args) throws IOException {
        Scanner sc = new Scanner(System.in);
        int T = sc.nextInt();

        while (T-- > 0) {
            long N = sc.nextLong();

            boolean found = false;

            ArrayList<Long> divisors = new ArrayList<>();

            for (long i = 1; i * i <= N; i++) {
                if (N % i == 0) {
                    divisors.add(i);

                    if (i != N / i) {
                        divisors.add(N / i);
                    }
                }
            }

            Collections.sort(divisors);

            for (long A : divisors) {
                for (long B : divisors) {
                    if (A == B || A * B > N || N % (A * B) != 0) {
                        continue;
                    }

                    long base = N / (A * B);
                    long limit = Math.min(A, B);

                    for (long k = 1; k <= limit; k++) {
                        long C = base * k;

                        if (C == A || C == B) {
                            continue;
                        }

                        if (N % (A * C) == 0 &&
                            N % (B * C) == 0 &&
                            (A * B * C) % N == 0) {

                            System.out.println(A + " " + B + " " + C);
                            found = true;
                            break;
                        }
                    }

                    if (found) break;
                }

                if (found) break;
            }

            if (!found) {
                System.out.println(-1);
            }
        }

        sc.close();
    }
}
