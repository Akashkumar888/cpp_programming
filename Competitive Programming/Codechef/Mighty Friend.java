import java.util.*;

class Codechef {

    public static void main(String[] args) throws Exception {

        Scanner sc = new Scanner(System.in);

        int T = sc.nextInt();

        while (T-- > 0) {

            int N = sc.nextInt();
            int K = sc.nextInt();

            ArrayList<Integer> motu = new ArrayList<>();
            ArrayList<Integer> tomu = new ArrayList<>();

            long motuScore = 0;
            long tomuScore = 0;

            // Separate elements according to their ORIGINAL positions.
            for (int i = 0; i < N; i++) {

                int value = sc.nextInt();

                if (i % 2 == 0) {
                    // Motu gets even indices
                    motu.add(value);
                    motuScore += value;
                } else {
                    // Tomu gets odd indices
                    tomu.add(value);
                    tomuScore += value;
                }
            }

            // Tomu already wins
            if (tomuScore > motuScore) {
                System.out.println("YES");
                continue;
            }

            /*
             * For a useful swap:
             *
             * largest value belonging to Motu
             *          <-->
             * smallest value belonging to Tomu
             */

            // Largest Motu values first
            motu.sort(Collections.reverseOrder());

            // Smallest Tomu values first
            Collections.sort(tomu);

            int maxSwaps = Math.min(K,
                             Math.min(motu.size(), tomu.size()));

            for (int i = 0; i < maxSwaps; i++) {

                int motuValue = motu.get(i);
                int tomuValue = tomu.get(i);

                // Swapping is useless if Motu's value
                // is not greater than Tomu's value.
                if (motuValue <= tomuValue)
                    break;

                // Motu loses the large value
                // and gets the small value.
                motuScore -= motuValue;
                motuScore += tomuValue;

                // Tomu loses the small value
                // and gets the large value.
                tomuScore -= tomuValue;
                tomuScore += motuValue;

                if (tomuScore > motuScore)
                    break;
            }

            System.out.println(
                tomuScore > motuScore ? "YES" : "NO"
            );
        }

        sc.close();
    }
}
