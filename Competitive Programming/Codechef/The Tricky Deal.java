
import java.util.*;
import java.io.*;

class Codechef {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(
            new InputStreamReader(System.in)
        );

        int T = Integer.parseInt(br.readLine().trim());
        StringBuilder sb = new StringBuilder();

        while (T-- > 0) {
            long A = Long.parseLong(br.readLine().trim());

            int D1 = 0;
            int D2 = 0;
            long power = 1;

            for (int D = 1; D <= 60; D++) {
                power *= 2;

                long profit = A * D - (power - 1);

                if (profit > 0) {
                    D1 = D;
                }

                if (D2 == 0 && power >= A) {
                    D2 = D;
                }

                if (power > A * 60L) {
                    break;
                }
            }

            sb.append(D1).append(" ").append(D2).append("\n");
        }

        System.out.print(sb);
    }
}
