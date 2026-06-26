import java.util.*;

class Codechef {

    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);

        int t = sc.nextInt();

        while (t-- > 0) {

            int pc = sc.nextInt();
            int pr = sc.nextInt();

            int chefDigits = (pc + 8) / 9;
            int rickDigits = (pr + 8) / 9;

            if (chefDigits < rickDigits) {
                System.out.println(0 + " " + chefDigits);
            } else {
                System.out.println(1 + " " + rickDigits);
            }
        }

        sc.close();
    }
}
