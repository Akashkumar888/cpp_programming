import java.util.*;
import java.lang.*;
import java.io.*;

class Codechef {
    public static void main(String[] args) throws java.lang.Exception {

        Scanner sc = new Scanner(System.in);

        long a = sc.nextLong();

        long rem = a % 6;

        if (rem == 0 || rem == 1 || rem == 3) {
            System.out.println("yes");
        } else {
            System.out.println("no");
        }
    }
}
