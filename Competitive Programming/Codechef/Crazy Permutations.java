import java.util.*;
import java.lang.*;
import java.io.*;

class Codechef {
    public static void main(String[] args) throws Exception {
        FastScanner fs = new FastScanner();

        int T = fs.nextInt();
        StringBuilder out = new StringBuilder();

        while (T-- > 0) {
            int N = fs.nextInt();

            int[] A = new int[N];
            int[] B = new int[N];

            for (int i = 0; i < N; i++) {
                A[i] = fs.nextInt();
            }

            for (int i = 0; i < N; i++) {
                B[i] = fs.nextInt();
            }

            boolean possible = true;

            for (int i = 0; i < N - 1; i++) {
                boolean patternA = A[i] < A[i + 1];
                boolean patternB = B[i] < B[i + 1];

                if (patternA != patternB) {
                    possible = false;
                    break;
                }
            }

            out.append(possible ? "YES\n" : "NO\n");
        }

        System.out.print(out);
    }

    static class FastScanner {
        private final InputStream in = System.in;
        private final byte[] buffer = new byte[1 << 16];
        private int pointer = 0;
        private int length = 0;

        private int read() throws IOException {
            if (pointer >= length) {
                length = in.read(buffer);
                pointer = 0;

                if (length <= 0) {
                    return -1;
                }
            }

            return buffer[pointer++];
        }

        int nextInt() throws IOException {
            int c;

            do {
                c = read();
            } while (c <= ' ');

            int number = 0;

            while (c > ' ') {
                number = number * 10 + (c - '0');
                c = read();
            }

            return number;
        }
    }
}
