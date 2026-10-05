import java.util.*;
import java.io.*;

class Codechef {
    public static void main(String[] args) throws Exception {
        
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder output = new StringBuilder();

        int T = Integer.parseInt(br.readLine().trim());

        while (T-- > 0) {
            int n = Integer.parseInt(br.readLine().trim());

            StringTokenizer st = new StringTokenizer(br.readLine());

            int minGoals = Integer.MAX_VALUE;
            int maxDifference = 0;

            for (int i = 0; i < n; i++) {
                int goals = Integer.parseInt(st.nextToken());

                // Use a previous match as the first match
                if (minGoals != Integer.MAX_VALUE) {
                    int difference = goals - minGoals;

                    if (difference > maxDifference) {
                        maxDifference = difference;
                    }
                }

                // Minimum goals seen so far
                minGoals = Math.min(minGoals, goals);
            }

            if (maxDifference == 0) {
                output.append("UNFIT\n");
            } else {
                output.append(maxDifference).append('\n');
            }
        }

        System.out.print(output);
    }
}
