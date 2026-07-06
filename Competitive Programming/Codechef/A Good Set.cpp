import java.util.*;
import java.lang.*;
import java.io.*;

class Codechef
{
    public static void main(String[] args) throws java.lang.Exception
    {
        Scanner sc = new Scanner(System.in);

        int T = sc.nextInt();

        while(T-- > 0){

            int n = sc.nextInt();

            for(int i = 0; i < n; i++){

                System.out.print(251 + i);

                if(i != n - 1){
                    System.out.print(" ");
                }
            }

            System.out.println();
        }

        sc.close();
    }
}
