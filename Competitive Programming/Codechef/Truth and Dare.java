import java.util.*;
import java.lang.*;
import java.io.*;

class Codechef
{
    public static void main(String[] args) throws java.lang.Exception
    {
        Scanner sc = new Scanner(System.in);

        int T = sc.nextInt();

        while(T-- > 0)
        {
            int tr = sc.nextInt();

            HashSet<Integer> truth = new HashSet<>();

            for(int i = 0; i < tr; i++)
            {
                truth.add(sc.nextInt());
            }

            int dr = sc.nextInt();

            HashSet<Integer> dare = new HashSet<>();

            for(int i = 0; i < dr; i++)
            {
                dare.add(sc.nextInt());
            }

            int ts = sc.nextInt();

            boolean ok = true;

            int[] truthAsk = new int[ts];

            for(int i = 0; i < ts; i++)
            {
                truthAsk[i] = sc.nextInt();

                if(!truth.contains(truthAsk[i]))
                {
                    ok = false;
                }
            }

            int ds = sc.nextInt();

            int[] dareAsk = new int[ds];

            for(int i = 0; i < ds; i++)
            {
                dareAsk[i] = sc.nextInt();

                if(!dare.contains(dareAsk[i]))
                {
                    ok = false;
                }
            }

            if(ok)
            {
                System.out.println("yes");
            }
            else
            {
                System.out.println("no");
            }
        }

        sc.close();
    }
}
