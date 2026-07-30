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
			int N = sc.nextInt();

			int[] arr = new int[N];
			int totalOR = 0;

			for(int i = 0; i < N; i++)
			{
				arr[i] = sc.nextInt();
				totalOR |= arr[i];
			}

			int currOR = 0;
			int segments = 0;

			for(int i = 0; i < N; i++)
			{
				currOR |= arr[i];

				if(currOR == totalOR)
				{
					segments++;
					currOR = 0;
				}
			}

			System.out.println(N - segments);
		}

		sc.close();
	}
}
