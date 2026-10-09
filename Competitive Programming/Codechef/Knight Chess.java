
import java.util.*;
import java.io.*;

class Codechef {
    static int[] dx = {-1, -1, -1, 0, 0, 1, 1, 1};
    static int[] dy = {-1, 0, 1, -1, 1, -1, 0, 1};

    static boolean attacked(long x, long y, long[][] knights) {
        for (long[] k : knights) {
            long dx = Math.abs(k[0] - x);
            long dy = Math.abs(k[1] - y);

            if ((dx == 1 && dy == 2) ||
                (dx == 2 && dy == 1)) {
                return true;
            }
        }
        return false;
    }

    public static void main(String[] args) throws Exception {
        Scanner sc = new Scanner(System.in);
        int T = sc.nextInt();

        while (T-- > 0) {
            int N = sc.nextInt();
            long[][] knights = new long[N][2];

            for (int i = 0; i < N; i++) {
                knights[i][0] = sc.nextLong();
                knights[i][1] = sc.nextLong();
            }

            long A = sc.nextLong();
            long B = sc.nextLong();

            // King must currently be in check
            if (!attacked(A, B, knights)) {
                System.out.println("NO");
                continue;
            }

            boolean checkmate = true;

            // Check all 8 neighboring squares
            for (int i = 0; i < 8; i++) {
                long nx = A + dx[i];
                long ny = B + dy[i];

                if (!attacked(nx, ny, knights)) {
                    checkmate = false;
                    break;
                }
            }

            System.out.println(checkmate ? "YES" : "NO");
        }

        sc.close();
    }
}
