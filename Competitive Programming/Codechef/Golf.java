import java.io.*;

class Codechef
{
    
    static class FastScanner
    {
        private final InputStream in = System.in;
        private final byte[] buffer = new byte[1 << 16];
        
        private int ptr = 0;
        private int len = 0;
        
        
        private int read() throws IOException
        {
            if (ptr >= len)
            {
                len = in.read(buffer);
                ptr = 0;
                
                if (len <= 0)
                {
                    return -1;
                }
            }
            
            return buffer[ptr++];
        }
        
        
        long nextLong() throws IOException
        {
            int ch;
            
            do
            {
                ch = read();
            }
            while (ch <= ' ' && ch != -1);
            
            
            long num = 0;
            
            while (ch > ' ')
            {
                num = num * 10 + (ch - '0');
                ch = read();
            }
            
            return num;
        }
    }
    
    
    public static void main(String[] args) throws Exception
    {
        FastScanner fs = new FastScanner();
        
        StringBuilder ans = new StringBuilder();
        
        
        int T = (int) fs.nextLong();
        
        
        while (T-- > 0)
        {
            long N = fs.nextLong();
            long x = fs.nextLong();
            long k = fs.nextLong();
            
            
            // Forward:
            // 0, k, 2k, 3k...
            boolean forward = (x % k == 0);
            
            
            // Backward:
            // N+1, N+1-k, N+1-2k...
            boolean backward = ((N + 1 - x) % k == 0);
            
            
            if (forward || backward)
            {
                ans.append("YES\n");
            }
            else
            {
                ans.append("NO\n");
            }
        }
        
        
        System.out.print(ans);
    }
}
