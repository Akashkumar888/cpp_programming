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
			int N = sc.nextInt();

			HashMap<String, Character> map = new HashMap<>();

			int score = 0;

			for(int i = 0; i < N; i++)
			{
				String user = sc.next();
				char vote = sc.next().charAt(0);

				// Remove previous vote if exists
				if(map.containsKey(user))
				{
					char prev = map.get(user);

					if(prev == '+')
						score--;
					else
						score++;
				}

				// Add current vote
				if(vote == '+')
					score++;
				else
					score--;

				// Store latest vote
				map.put(user, vote);
			}

			System.out.println(score);
		}

		sc.close();
	}
}
