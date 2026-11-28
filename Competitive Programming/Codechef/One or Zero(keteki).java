
import java.util.*;
import java.lang.*;
import java.io.*;

class Codechef
{
    public static void main (String[] args) throws java.lang.Exception
    {
        Scanner sc = new Scanner(System.in);

        int x = sc.nextInt();
        int y = sc.nextInt();

        char[][] grid = new char[x][y];
        boolean[][] vis = new boolean[x][y];

        for(int i = 0; i < x; i++) {
            String s = sc.next();
            for(int j = 0; j < y; j++) {
                grid[i][j] = s.charAt(j);
            }
        }

        // 4 directions: Up, Down, Left, Right
        int[] dx = {-1, 1, 0, 0};
        int[] dy = {0, 0, -1, 1};

        Queue<int[]> q = new LinkedList<>();

        // Add boundary dots to BFS
        for(int i = 0; i < x; i++) {
            for(int j = 0; j < y; j++) {

                if(i == 0 || i == x-1 || j == 0 || j == y-1) {

                    if(grid[i][j] == '.' && !vis[i][j]) {
                        vis[i][j] = true;
                        q.add(new int[]{i, j});
                    }
                }
            }
        }

        // BFS: Mark all outside dots
        while(!q.isEmpty()) {
            int[] curr = q.poll();

            int r = curr[0];
            int c = curr[1];

            for(int k = 0; k < 4; k++) {
                int nr = r + dx[k];
                int nc = c + dy[k];

                if(nr >= 0 && nr < x &&
                   nc >= 0 && nc < y &&
                   grid[nr][nc] == '.' &&
                   !vis[nr][nc]) {

                    vis[nr][nc] = true;
                    q.add(new int[]{nr, nc});
                }
            }
        }

        // Check for enclosed dots
        for(int i = 0; i < x; i++) {
            for(int j = 0; j < y; j++) {

                if(grid[i][j] == '.' && !vis[i][j]) {
                    System.out.println(0);
                    return;
                }
            }
        }

        System.out.println(1);
    }
}
