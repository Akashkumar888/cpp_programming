import java.util.*;

class Codechef {

    public static void main(String[] args) throws Exception {

        Scanner sc = new Scanner(System.in);

        int T = sc.nextInt();

        while (T-- > 0) {

            int N = sc.nextInt();

            HashSet<Long> set = new HashSet<>();

            long nonZero = 0;
            boolean foundNonZero = false;

            for (int i = 0; i < N; i++) {

                long x = sc.nextLong();

                set.add(x);

                if (!foundNonZero && x != 0) {
                    nonZero = x;
                    foundNonZero = true;
                }
            }

            // If every element is 0,
            // 0 + 0 = 0 is always present.
            if (!foundNonZero) {
                System.out.println("-1");
                continue;
            }

            long x = nonZero;

            while (set.contains(2 * x)) {
                x *= 2;
            }

            // 2*x is not present.
            // Both x and x are elements of the array.
            System.out.println(x + " " + x);
        }

        sc.close();
    }
}
