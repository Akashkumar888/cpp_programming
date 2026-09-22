import java.util.*;
import java.io.*;

class Codechef {

    public static void main(String[] args) throws Exception {

        FastScanner fs = new FastScanner();

        int T = fs.nextInt();
        StringBuilder out = new StringBuilder();

        while (T-- > 0) {

            int N = fs.nextInt();

            boolean oneEven = false;
            boolean oneOdd = false;

            boolean twoEven = false;
            boolean twoOdd = false;

            for (int i = 0; i < N; i++) {

                int strength = fs.nextInt();

                // Using 0-based index.
                // Parity is the same relation as 1-based indexing.
                if (strength == 1) {

                    if (i % 2 == 0) {
                        oneEven = true;
                    } else {
                        oneOdd = true;
                    }

                } else {

                    if (i % 2 == 0) {
                        twoEven = true;
                    } else {
                        twoOdd = true;
                    }
                }
            }

            if ((twoEven && !oneEven) ||
                (twoOdd && !oneOdd)) {

                out.append("Yes\n");

            } else {
                out.append("No\n");
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
