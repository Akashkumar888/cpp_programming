import java.util.*;

class Codechef {

    public static void main(String[] args) throws Exception {

        Scanner sc = new Scanner(System.in);

        int T = sc.nextInt();

        while (T-- > 0) {

            int N = sc.nextInt();

            int low = 1;
            int high = N;

            StringBuilder ans = new StringBuilder();

            for (int i = 0; i < N; i++) {

                if (i % 2 == 0) {
                    ans.append(high);
                    high--;
                } else {
                    ans.append(low);
                    low++;
                }

                if (i + 1 < N) {
                    ans.append(" ");
                }
            }

            System.out.println(ans);
        }

        sc.close();
    }
}
