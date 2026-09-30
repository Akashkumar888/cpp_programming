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
            String S = fs.next();

            int countZero = 0;
            int countOne = 0;

            for (int i = 0; i < N; i++) {
                if (S.charAt(i) == '0') {
                    countZero++;
                } else {
                    countOne++;
                }
            }

            int moves = Math.min(countZero, countOne);

            if (moves % 2 == 1) {
                out.append("Zlatan\n");
            } else {
                out.append("Ramos\n");
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

        String next() throws IOException {

            int c;

            do {
                c = read();
            } while (c <= ' ');

            StringBuilder sb = new StringBuilder();

            while (c > ' ') {
                sb.append((char) c);
                c = read();
            }

            return sb.toString();
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
