import java.util.*;

class Codechef {
    public static void main(String[] args) throws java.lang.Exception {

        Scanner sc = new Scanner(System.in);

        int T = sc.nextInt();

        while (T-- > 0) {

            int X = sc.nextInt(); // Red
            int Y = sc.nextInt(); // Green
            int Z = sc.nextInt(); // Blue

            int ans = 0;

            // 3 secondary colours:
            // 1 -> Red + Green
            // 2 -> Red + Blue
            // 4 -> Green + Blue

            for (int mask = 0; mask < 8; mask++) {

                int redUsed = 0;
                int greenUsed = 0;
                int blueUsed = 0;

                int secondary = 0;

                // Red + Green
                if ((mask & 1) != 0) {
                    redUsed++;
                    greenUsed++;
                    secondary++;
                }

                // Red + Blue
                if ((mask & 2) != 0) {
                    redUsed++;
                    blueUsed++;
                    secondary++;
                }

                // Green + Blue
                if ((mask & 4) != 0) {
                    greenUsed++;
                    blueUsed++;
                    secondary++;
                }

                // This combination is possible only if
                // enough primary drops are available.
                if (redUsed > X ||
                    greenUsed > Y ||
                    blueUsed > Z) {
                    continue;
                }

                int primary = 0;

                if (X - redUsed > 0)
                    primary++;

                if (Y - greenUsed > 0)
                    primary++;

                if (Z - blueUsed > 0)
                    primary++;

                ans = Math.max(ans, primary + secondary);
            }

            System.out.println(ans);
        }

        sc.close();
    }
}
