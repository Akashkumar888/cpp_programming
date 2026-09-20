import java.util.*;
import java.io.*;

class Codechef {

    static boolean hasOddDigit(int number) {
        while (number > 0) {
            int digit = number % 10;

            if (digit % 2 == 1) {
                return true;
            }

            number /= 10;
        }

        return false;
    }

    public static void main(String[] args) throws Exception {
        FastScanner fs = new FastScanner();

        int T = fs.nextInt();
        StringBuilder out = new StringBuilder();

        while (T-- > 0) {
            int N = fs.nextInt();

            // Already odd
            if (N % 2 == 1) {
                out.append(0).append('\n');
                continue;
            }

            String s = String.valueOf(N);

            // Check whether N contains an odd digit
            boolean hasOdd = false;

            for (int i = 0; i < s.length(); i++) {
                int digit = s.charAt(i) - '0';

                if (digit % 2 == 1) {
                    hasOdd = true;
                    break;
                }
            }

            // Even number containing an odd digit
            // N - odd = odd
            if (hasOdd) {
                out.append(1).append('\n');
                continue;
            }

            // All digits are even.
            // Try one subtraction.
            boolean possibleInTwo = false;

            for (int i = 0; i < s.length(); i++) {
                int digit = s.charAt(i) - '0';

                if (digit == 0) {
                    continue;
                }

                int newNumber = N - digit;

                if (hasOddDigit(newNumber)) {
                    possibleInTwo = true;
                    break;
                }
            }

            if (possibleInTwo) {
                out.append(2).append('\n');
            } else {
                // Single digit even number -> impossible
                // Multi-digit even number -> possible in 3 operations
                if (N < 10) {
                    out.append(-1).append('\n');
                } else {
                    out.append(3).append('\n');
                }
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
