import java.util.*;

class Codechef {

    static class Pair {
        long value;
        int index;

        Pair(long value, int index) {
            this.value = value;
            this.index = index;
        }
    }

    public static void main(String[] args) throws Exception {

        Scanner sc = new Scanner(System.in);

        int T = sc.nextInt();

        while (T-- > 0) {

            int N = sc.nextInt();

            Pair[] arr = new Pair[N];

            for (int i = 0; i < N; i++) {
                long x = sc.nextLong();
                arr[i] = new Pair(x, i);
            }

            // Sort by value
            Arrays.sort(arr, (a, b) ->
                Long.compare(a.value, b.value)
            );

            long[] ans = new long[N];

            // Smallest and largest values have infinitely
            // many X values.
            ans[arr[0].index] = -1;
            ans[arr[N - 1].index] = -1;

            // Process interior elements
            for (int i = 1; i < N - 1; i++) {

                long leftMid =
                    (arr[i - 1].value + arr[i].value) / 2;

                long rightMid =
                    (arr[i].value + arr[i + 1].value) / 2;

                ans[arr[i].index] =
                    rightMid - leftMid;
            }

            // Print in original order
            for (int i = 0; i < N; i++) {

                System.out.print(ans[i]);

                if (i + 1 < N)
                    System.out.print(" ");
            }

            System.out.println();
        }

        sc.close();
    }
}
