
import java.util.*;
import java.io.*;

class Codechef
{
    public static void main (String[] args) throws java.lang.Exception
    {
        Scanner sc = new Scanner(System.in);

        int t = sc.nextInt();

        while(t-- > 0)
        {
            int n = sc.nextInt();

            int cnt = 0;
            String ans = "draw";

            for(int i = 0; i < n; i++)
            {
                String s = sc.next();

                if(!ans.equals("draw"))
                    continue;

                if(s.endsWith("man") || s.endsWith("woman"))
                {
                    cnt++;
                }
                else
                {
                    cnt--;
                }

                if(cnt == 2)
                {
                    ans = "superheroes";
                }
                else if(cnt == -3)
                {
                    ans = "villains";
                }
            }

            System.out.println(ans);
        }

        sc.close();
    }
}
