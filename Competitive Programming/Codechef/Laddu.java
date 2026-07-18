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
			int activities = sc.nextInt();
			String origin = sc.next();

			int laddus = 0;

			for(int i = 0; i < activities; i++)
			{
				String activity = sc.next();

				if(activity.equals("CONTEST_WON"))
				{
					int rank = sc.nextInt();

					laddus += 300;

					if(rank <= 20)
					{
						laddus += (20 - rank);
					}
				}
				else if(activity.equals("TOP_CONTRIBUTOR"))
				{
					laddus += 300;
				}
				else if(activity.equals("BUG_FOUND"))
				{
					int severity = sc.nextInt();
					laddus += severity;
				}
				else if(activity.equals("CONTEST_HOSTED"))
				{
					laddus += 50;
				}
			}

			if(origin.equals("INDIAN"))
			{
				System.out.println(laddus / 200);
			}
			else
			{
				System.out.println(laddus / 400);
			}
		}

		sc.close();
	}
}
