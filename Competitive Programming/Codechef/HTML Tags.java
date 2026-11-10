
import java.util.*;
import java.lang.*;
import java.io.*;

class Codechef {
    public static void main(String[] args) throws java.lang.Exception {

        Scanner sc = new Scanner(System.in);

        int t = sc.nextInt();

        while (t-- > 0) {

            String s = sc.next();

            int n = s.length();

            if (n < 4 || !s.startsWith("</") || !s.endsWith(">")) {
                System.out.println("Error");
                continue;
            }

            boolean valid = true;

            for (int i = 2; i < n - 1; i++) {

                char ch = s.charAt(i);

                if (!((ch >= 'a' && ch <= 'z') ||
                      (ch >= '0' && ch <= '9'))) {

                    valid = false;
                    break;
                }
            }

            System.out.println(valid ? "Success" : "Error");
        }

        sc.close();
    }
}
