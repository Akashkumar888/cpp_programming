import java.util.*;

class Codechef {
    public static void main(String[] args) throws Exception {

        Scanner sc = new Scanner(System.in);

        int T = sc.nextInt();

        while (T-- > 0) {

            int N = sc.nextInt();

            long answer = 0;
            long large = 0;

            for (int i = 0; i < 2 * N; i++) {

                int x = sc.nextInt();

                if (x > N) {
                    // Large element
                    large++;
                } else {
                    // Small element
                    // Every previous large element
                    // must cross this small element.
                    answer += large;
                }
            }

            System.out.println(answer);
        }

        sc.close();
    }
}
