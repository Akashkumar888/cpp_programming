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

            long baseSum = 0;

            long minimumEven = Long.MAX_VALUE;
            long maximumOdd = Long.MIN_VALUE;

            for (int i = 0; i < N; i++) {

                long value = Math.abs(fs.nextLong());

                if (i % 2 == 0) {
                    baseSum += value;
                    minimumEven = Math.min(minimumEven, value);
                } else {
                    baseSum -= value;
                    maximumOdd = Math.max(maximumOdd, value);
                }
            }

            // If we swap the minimum even-position value
            // with the maximum odd-position value.
            long bestSum = baseSum;

            if (N >= 2) {
                long gain = 2 * (maximumOdd - minimumEven);
                bestSum = Math.max(bestSum, baseSum + gain);
            }

            out.append(bestSum).append('\n');
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

            boolean negative = false;

            if (c == '-') {
                negative = true;
                c = read();
            }

            long number = 0;

            while (c > ' ') {
                number = number * 10 + (c - '0');
                c = read();
            }

            return negative ? -number : number;
        }

        int nextInt() throws IOException {
            return (int) nextLong();
        }
    }
}
