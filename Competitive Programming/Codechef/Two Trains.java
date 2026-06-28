import java.util.*;
import java.lang.*;
import java.io.*;

class Codechef
{
	public static void main (String[] args) throws java.lang.Exception
	{
		Scanner sc = new Scanner(System.in);

		int T = sc.nextInt();

		while(T-- > 0){

			int N = sc.nextInt();

			long trainA = 0;
			long trainB = 0;

			for(int i = 0; i < N - 1; i++){

				int p = sc.nextInt();

				// Train A reaches next station
				trainA += p;

				// Train B can leave only after Train A reaches next station
				trainB = Math.max(trainB, trainA);

				// Travel to next station
				trainB += p;
			}

			System.out.println(trainB);
		}

		sc.close();
	}
}
