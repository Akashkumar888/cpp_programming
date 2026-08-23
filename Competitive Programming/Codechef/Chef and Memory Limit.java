import java.util.*;
import java.lang.*;
import java.io.*;

class Codechef
{
    public static void main(String[] args) throws java.lang.Exception
    {
        Scanner sc = new Scanner(System.in);

        int T = sc.nextInt();

        while (T-- > 0) {

            int N = sc.nextInt();

            long longMemoryAllocated = 0;
            long previousMemory = 0;

            for (int i = 0; i < N; i++) {

                long currentMemory = sc.nextLong();

                // If more memory is needed,
                // allocate the extra memory
                if (currentMemory > previousMemory) {

                    longMemoryAllocated += currentMemory - previousMemory;
                }

                // Update currently allocated memory
                previousMemory = currentMemory;
            }

            System.out.println(longMemoryAllocated);
        }

        sc.close();
    }
}
