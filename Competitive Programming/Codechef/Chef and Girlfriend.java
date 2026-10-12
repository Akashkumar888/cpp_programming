
import java.util.*;

class Codechef {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int T = sc.nextInt();

        while (T-- > 0) {
            String time1 = sc.next();
            String time2 = sc.next();
            int dist = sc.nextInt();

            int G = Integer.parseInt(time1.substring(0, 2)) * 60
                  + Integer.parseInt(time1.substring(3, 5));

            int C = Integer.parseInt(time2.substring(0, 2)) * 60
                  + Integer.parseInt(time2.substring(3, 5));

            int W = G - C;

            double plan1 = W + dist;
            double plan2;

            if (W >= 2 * dist) {
                plan2 = W;
            } else {
                plan2 = dist + W / 2.0;
            }

            System.out.printf("%.1f %.1f%n", plan1, plan2);
        }

        sc.close();
    }
}
