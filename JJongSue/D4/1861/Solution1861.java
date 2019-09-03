package Solution1861;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

public class Solution1861 {
	static final int dx[] = {0,-1,1,0};
	static final int dy[] = {-1,0,0,1};
	
	static int N, start, ans_cnt, ans_start;
	static int [][] map;
	static PriorityQueue<String> anspq;
	
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		StringBuilder sb = new StringBuilder("");
		int T = Integer.parseInt(st.nextToken());
		for(int tc = 1 ; tc <= T ;tc++)
		{
			st = new StringTokenizer(br.readLine());
			N = Integer.parseInt(st.nextToken());
			map = new int[N][N];
			ans_cnt=1;
			ans_start=1;
			for(int i=0;i<N;i++)
			{
				st = new StringTokenizer(br.readLine());
				
				for(int j=0;j<N;j++)
				{
					map[i][j] = Integer.parseInt(st.nextToken());
				}
			}
			for(int i=0;i<N;i++)
			{
				for(int j=0;j<N;j++)
				{
					do_game(j,i,0);
				}
			}
			sb.append("#").append(tc).append(" ");
			sb.append(ans_start).append(" ").append(ans_cnt);
			/*for(int i=0;i<ans_cnt;i++)
			{
				sb.append((ans_start+i)).append(" ");
			}*/
			sb.append("\n");
			
		}
		System.out.println(sb);
	}
	
	static void do_game(int x, int y, int cnt)
	{
		if(cnt == 0)
		{
			start=map[y][x];
			cnt++;
		}
		boolean is_end = true;
		for(int i=0;i<4;i++)
		{
			if(is_map(x,y,x+dx[i],y+dy[i]))
			{
				do_game(x+dx[i], y+dy[i], cnt+1);
				is_end = false;
				break;
			}
		}
		if(is_end) {
			if(cnt > ans_cnt) {
				ans_cnt = cnt;
				ans_start = start;
			}
			else if(cnt == ans_cnt) {
				if(ans_start > start)
				{
					ans_start = start;
				}
			}
			
		}
		return;
	}
	
	static boolean is_map(int postx, int posty, int x, int y)
	{
		if(x<0 || y<0 || x>=N || y>=N) return false;
		if(map[posty][postx]+1 != map[y][x]) return false;
		return true;
	}
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
}
