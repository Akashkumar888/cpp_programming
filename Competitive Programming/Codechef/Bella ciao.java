import java.util.*;
import java.io.*;

class Codechef {

    public static void main(String[] args) throws Exception {

        FastScanner fs = new FastScanner();

        int T = fs.nextInt();
        StringBuilder out = new StringBuilder();

        while (T-- > 0) {

            long D = fs.nextLong();
            long d = fs.nextLong();
            long P = fs.nextLong();
            long Q = fs.nextLong();

            long groups = D / d;
            long remaining = D % d;

            // Sum of rates of all complete groups
            long sumOfRates =
                    groups * (2 * P + (groups - 1) * Q) / 2;

            long answer = d * sumOfRates;

            // Remaining days
            long remainingRate = P + groups * Q;

            answer += remaining * remainingRate;

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
