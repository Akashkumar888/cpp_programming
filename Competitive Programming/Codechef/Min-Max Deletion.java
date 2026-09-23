import java.util.*;
import java.io.*;

class Codechef {

    public static void main(String[] args) throws Exception {

        FastScanner fs = new FastScanner();

        int T = fs.nextInt();
        StringBuilder out = new StringBuilder();

        while (T-- > 0) {

            int N = fs.nextInt();
            int Q = fs.nextInt();

            long[] A = new long[N];

            for (int i = 0; i < N; i++) {
                A[i] = fs.nextLong();
            }

            // f(A) = sum of min of every adjacent pair
            long answer = 0;

            for (int i = 0; i < N - 1; i++) {
                answer += Math.min(A[i], A[i + 1]);
            }

            while (Q-- > 0) {

                int index = fs.nextInt() - 1;
                long value = fs.nextLong();

                // Remove old contributions
                if (index > 0) {
                    answer -= Math.min(A[index - 1], A[index]);
                }

                if (index + 1 < N) {
                    answer -= Math.min(A[index], A[index + 1]);
                }

                // Update
                A[index] = value;

                // Add new contributions
                if (index > 0) {
                    answer += Math.min(A[index - 1], A[index]);
                }

                if (index + 1 < N) {
                    answer += Math.min(A[index], A[index + 1]);
                }

                out.append(answer).append('\n');
            }
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
            return (int) nextLong();
        }

        long nextLong() throws IOException {

            int c;

            do {
                c = read();
            } while (c <= ' ');

            long number = 0;

            while (c > ' ') {
                number = number * 10 + (c - '0');
                c = read();
            }

            return number;
        }
    }
}
