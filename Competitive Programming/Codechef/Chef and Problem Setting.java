import java.util.*;

class Codechef {
    public static void main(String[] args) throws java.lang.Exception {

        Scanner sc = new Scanner(System.in);

        int T = sc.nextInt();

        while (T-- > 0) {

            int N = sc.nextInt();
            int M = sc.nextInt();

            boolean invalid = false;
            boolean weak = false;

            for (int i = 0; i < N; i++) {

                String type = sc.next();
                String result = sc.next();

                if (type.equals("correct")) {

                    // Correct solution must pass every test
                    if (result.contains("0")) {
                        invalid = true;
                    }

                } else { // wrong

                    // Wrong solution should fail at least one test
                    if (!result.contains("0")) {
                        weak = true;
                    }
                }
            }

            // INVALID has higher priority than WEAK
            if (invalid) {
                System.out.println("INVALID");
            } else if (weak) {
                System.out.println("WEAK");
            } else {
                System.out.println("FINE");
            }
        }

        sc.close();
    }
}
