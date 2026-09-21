import java.io.*;
import java.util.*;

public class Main {

    static class FastScanner {
        private final InputStream in = System.in;
        private final byte[] buffer = new byte[1 << 16];
        private int ptr = 0, len = 0;

        private int read() throws IOException {
            if (ptr >= len) {
                len = in.read(buffer);
                ptr = 0;

                if (len <= 0)
                    return -1;
            }

            return buffer[ptr++];
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

            long res = 0;

            while (c > ' ') {
                res = res * 10 + (c - '0');
                c = read();
            }

            return negative ? -res : res;
        }

        int nextInt() throws IOException {
            return (int) nextLong();
        }
    }

    public static void main(String[] args) throws Exception {

        FastScanner fs = new FastScanner();
        StringBuilder out = new StringBuilder();

        int t = fs.nextInt();

        while (t-- > 0) {

            int n = fs.nextInt();

            Long[] a = new Long[n];

            for (int i = 0; i < n; i++) {
                a[i] = fs.nextLong();
            }

            // Largest piles first
            Arrays.sort(a, Collections.reverseOrder());

            long chef = 0;

            // Chef gets 1st, 3rd, 5th, ... largest piles
            for (int i = 0; i < n; i += 2) {
                chef += a[i];
            }

            out.append(chef).append('\n');
        }

        System.out.print(out);
    }
}
