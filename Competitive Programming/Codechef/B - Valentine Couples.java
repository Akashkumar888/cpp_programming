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

            long[] boys = new long[N];
            long[] girls = new long[N];

            for (int i = 0; i < N; i++) {
                boys[i] = fs.nextLong();
            }

            for (int i = 0; i < N; i++) {
                girls[i] = fs.nextLong();
            }

            Arrays.sort(boys);
            Arrays.sort(girls);

            long answer = 0;

            for (int i = 0; i < N; i++) {
                long pairSum = boys[i] + girls[N - 1 - i];
                answer = Math.max(answer, pairSum);
            }

            out.append(answer).append('\n');
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

        int nextInt() throws IOException {
            return (int) nextLong();
        }
    }
}
