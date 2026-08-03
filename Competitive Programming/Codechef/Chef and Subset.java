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
			int[] arr = new int[4];

			for(int i = 0; i < 4; i++)
			{
				arr[i] = sc.nextInt();
			}

			boolean found = false;

			// Check all non-empty subsets
			for(int mask = 1; mask < (1 << 4); mask++)
			{
				int sum = 0;

				for(int i = 0; i < 4; i++)
				{
					if((mask & (1 << i)) != 0)
					{
						sum += arr[i];
					}
				}

				if(sum == 0)
				{
					found = true;
					break;
				}
			}

			if(found)
				System.out.println("Yes");
			else
				System.out.println("No");
		}

		sc.close();
	}
}
