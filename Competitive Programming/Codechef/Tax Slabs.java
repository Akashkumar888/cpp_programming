import java.util.*;

class Codechef {
    public static void main(String[] args) throws Exception {

        Scanner sc = new Scanner(System.in);

        int T = sc.nextInt();

        while (T-- > 0) {

            int N = sc.nextInt();

            int tax = 0;

            // Slab 1: 0 - 250000
            if (N > 250000) {

                // Slab 2: 250000 - 500000
                int amount = Math.min(N, 500000) - 250000;
                tax += amount * 5 / 100;
            }

            // Slab 3: 500000 - 750000
            if (N > 500000) {

                int amount = Math.min(N, 750000) - 500000;
                tax += amount * 10 / 100;
            }

            // Slab 4: 750000 - 1000000
            if (N > 750000) {

                int amount = Math.min(N, 1000000) - 750000;
                tax += amount * 15 / 100;
            }

            // Slab 5: 1000000 - 1250000
            if (N > 1000000) {

                int amount = Math.min(N, 1250000) - 1000000;
                tax += amount * 20 / 100;
            }

            // Slab 6: 1250000 - 1500000
            if (N > 1250000) {

                int amount = Math.min(N, 1500000) - 1250000;
                tax += amount * 25 / 100;
            }

            // Slab 7: above 1500000
            if (N > 1500000) {

                int amount = N - 1500000;
                tax += amount * 30 / 100;
            }

            System.out.println(N - tax);
        }

        sc.close();
    }
}
