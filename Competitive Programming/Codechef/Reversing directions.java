
import java.util.*;
import java.io.*;

class Codechef {
    public static void main(String[] args) throws java.lang.Exception {
        Scanner sc = new Scanner(System.in);

        int T = Integer.parseInt(sc.nextLine().trim());

        while (T-- > 0) {
            int N = Integer.parseInt(sc.nextLine().trim());
            String[] directions = new String[N];

            for (int i = 0; i < N; i++) {
                directions[i] = sc.nextLine();
            }

            // Reverse route starts on the last road
            String lastRoad = directions[N - 1].substring(
                directions[N - 1].indexOf(" on ") + 4
            );

            System.out.println("Begin on " + lastRoad);

            // Reverse the remaining directions
            for (int i = N - 1; i >= 1; i--) {
                String road = directions[i - 1].substring(
                    directions[i - 1].indexOf(" on ") + 4
                );

                if (directions[i].startsWith("Left")) {
                    System.out.println("Right on " + road);
                } else if (directions[i].startsWith("Right")) {
                    System.out.println("Left on " + road);
                }
            }

            System.out.println();
        }

        sc.close();
    }
}
