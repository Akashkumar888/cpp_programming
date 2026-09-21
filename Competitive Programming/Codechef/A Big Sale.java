import java.util.*;
import java.io.*;

class Codechef {

    public static void main(String[] args) throws Exception {

        Scanner sc = new Scanner(System.in);

        int T = sc.nextInt();

        while (T-- > 0) {

            int N = sc.nextInt();

            double totalLoss = 0.0;

            for (int i = 0; i < N; i++) {

                double price = sc.nextDouble();
                double quantity = sc.nextDouble();
                double discount = sc.nextDouble();

                // Loss = price * quantity * discount^2 / 10000
                totalLoss += (price * quantity * discount * discount) / 10000.0;
            }

            System.out.printf("%.9f%n", totalLoss);
        }

        sc.close();
    }
}
