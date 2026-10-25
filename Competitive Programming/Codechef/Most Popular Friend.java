
import java.util.*;
import java.io.*;

class Codechef {
    public static void main(String[] args) throws java.lang.Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int T = Integer.parseInt(br.readLine().trim());

        while (T-- > 0) {
            int n = Integer.parseInt(br.readLine().trim());

            List<List<Integer>> graph = new ArrayList<>();

            for (int i = 0; i < n; i++) {
                graph.add(new ArrayList<>());
            }

            for (int i = 0; i < n; i++) {
                String line = br.readLine().trim();
                String[] parts = line.split("\\s+");

                for (String p : parts) {
                    int friend = Integer.parseInt(p);
                    graph.get(i).add(friend - 1);
                }
            }

            int bestFriend = 0;
            double bestAverage = Double.MAX_VALUE;

            for (int start = 0; start < n; start++) {
                int[] dist = new int[n];
                Arrays.fill(dist, -1);

                Queue<Integer> queue = new LinkedList<>();
                queue.offer(start);
                dist[start] = 0;

                int totalDistance = 0;

                while (!queue.isEmpty()) {
                    int curr = queue.poll();

                    for (int next : graph.get(curr)) {
                        if (dist[next] == -1) {
                            dist[next] = dist[curr] + 1;
                            totalDistance += dist[next];
                            queue.offer(next);
                        }
                    }
                }

                double average = (double) totalDistance / n;

                if (average < bestAverage) {
                    bestAverage = average;
                    bestFriend = start;
                }
            }

            System.out.printf(
                "%d %.6f%n",
                bestFriend + 1,
                bestAverage
            );
        }
    }
}
