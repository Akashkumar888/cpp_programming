import java.util.*;
import java.io.*;

class Codechef {
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int T = Integer.parseInt(br.readLine());

        while (T-- > 0) {

            int N = Integer.parseInt(br.readLine());

            int[] freq = new int[26];

            for (int i = 0; i < N; i++) {
                String s = br.readLine();

                for (char ch : s.toCharArray()) {
                    freq[ch - 'a']++;
                }
            }

            int ans = Integer.MAX_VALUE;

            ans = Math.min(ans, freq['c' - 'a'] / 2);
            ans = Math.min(ans, freq['o' - 'a']);
            ans = Math.min(ans, freq['d' - 'a']);
            ans = Math.min(ans, freq['e' - 'a'] / 2);
            ans = Math.min(ans, freq['h' - 'a']);
            ans = Math.min(ans, freq['f' - 'a']);

            System.out.println(ans);
        }
    }
}
