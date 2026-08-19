import java.util.*;

class Codechef {

    public static void main(String[] args) throws Exception {

        Scanner sc = new Scanner(System.in);

        int T = sc.nextInt();
        String M = sc.next();

        // mapping[i] = English character corresponding
        // to Bytelandian character ('a' + i)
        char[] mapping = M.toCharArray();

        // Consume the newline after M
        sc.nextLine();

        while (T-- > 0) {

            String S = sc.nextLine();

            StringBuilder result = new StringBuilder();

            for (char ch : S.toCharArray()) {

                // Lowercase letter
                if (ch >= 'a' && ch <= 'z') {
                    result.append(mapping[ch - 'a']);
                }

                // Uppercase letter
                else if (ch >= 'A' && ch <= 'Z') {
                    char lower = Character.toLowerCase(ch);

                    char translated = mapping[lower - 'a'];

                    result.append(Character.toUpperCase(translated));
                }

                // Underscore becomes space
                else if (ch == '_') {
                    result.append(' ');
                }

                // Punctuation remains unchanged
                else {
                    result.append(ch);
                }
            }

            System.out.println(result);
        }

        sc.close();
    }
}
