import java.util.*;

class Codechef {

    public static void main(String[] args) throws Exception {

        Scanner sc = new Scanner(System.in);

        int T = sc.nextInt();

        while (T-- > 0) {

            int N = sc.nextInt();
            String S = sc.next();

            char last = S.charAt(N - 1);

            boolean possible = false;

            // Check whether the last character
            // occurs somewhere before the last position.
            for (int i = 0; i < N - 1; i++) {

                if (S.charAt(i) == last) {
                    possible = true;
                    break;
                }
            }

            System.out.println(possible ? "YES" : "NO");
        }

        sc.close();
    }
}
