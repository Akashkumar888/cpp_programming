import java.util.*;
import java.lang.*;
import java.io.*;

class Codechef
{
	public static void main (String[] args) throws java.lang.Exception
	{
		Scanner sc = new Scanner(System.in);

		int T = sc.nextInt();

		while(T-- > 0)
		{
			int N = sc.nextInt(); // Not used
			int Q = sc.nextInt();

			long total = 0;
			int currentFloor = 0;

			while(Q-- > 0)
			{
				int f = sc.nextInt();
				int d = sc.nextInt();

				// Current floor -> Source floor
				total += Math.abs(currentFloor - f);

				// Source floor -> Destination floor
				total += Math.abs(f - d);

				// Lift is now at destination
				currentFloor = d;
			}

			System.out.println(total);
		}

		sc.close();
	}
}
