
import java.util.*;
import java.io.*;

class Codechef {
    public static void main(String[] args) throws java.lang.Exception {
        Scanner sc = new Scanner(System.in);

        int n = sc.nextInt();

        StringBuilder sb = new StringBuilder();

        sb.append(2).append('\n');

        // First permutation: Increasing order
        for (int i = 1; i <= n; i++) {
            sb.append(i).append(" ");
        }
        sb.append('\n');

        // Second permutation: Decreasing order
        for (int i = n; i >= 1; i--) {
            sb.append(i).append(" ");
        }
        sb.append('\n');

        System.out.print(sb);
    }
}
