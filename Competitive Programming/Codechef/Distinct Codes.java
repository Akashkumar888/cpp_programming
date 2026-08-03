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

			String s = sc.next();

			HashSet<String> set = new HashSet<>();

			for(int i = 0; i < s.length() - 1; i++){
				set.add(s.substring(i, i + 2));
			}

			System.out.println(set.size());
		}
	}
}
