package Solution5653;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class Solution {
	static final int dx[] = {0,-1,1,0};
	static final int dy[] = {-1,0,0,1};
	static int [][][]map;
	static boolean [][]is_start;
	static int N, M, K, cnt, ans;
	static Queue<cell> que;
	static class cell{
		int x;
		int y;
		int time;
		int level;
		public cell(int x, int y, int time, int level) {
			super();
			this.x = x;
			this.y = y;
			this.time = time;
			this.level = level;
		}
		
	}
	
	
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		int T = Integer.parseInt(st.nextToken());
		for(int tc = 1; tc<=T;tc++)
		{
			map = new int[500][500][2];
			is_start = new boolean[500][500];
			st = new StringTokenizer(br.readLine());
			N = Integer.parseInt(st.nextToken());
			M = Integer.parseInt(st.nextToken());
			K = Integer.parseInt(st.nextToken());
			que = new LinkedList<cell>();
			cnt = 0;
			ans =0;
			for(int i=200;i<N+200;i++)
			{
				st = new StringTokenizer(br.readLine());
				for(int j=200;j<M+200;j++)
				{
					map[i][j][0] = Integer.parseInt(st.nextToken());
					if(map[i][j][0] != 0)
					{
						que.add(new cell(j,i,0,map[i][j][0]));
						cnt++;
					}
				}
			}
			dobfs();
			System.out.println("#"+tc+" "+ans);
		}
	}
	static void dobfs()
	{
		int time = 0;
		while(K > time)
		{
			Queue<cell> tmp = new LinkedList<Solution.cell>();
			while(!que.isEmpty())
			{
				cell celltmp = que.poll();
				
				if(celltmp.time == celltmp.level)
				{
					if(map[celltmp.y][celltmp.x][1] == 0) {
						map[celltmp.y][celltmp.x][1]++;
						que.add(celltmp);
						continue;
					}
					//map[celltmp.y][celltmp.x][0] = -1;
					cnt--;
					if(celltmp.level == 1)
					{
						map[celltmp.y][celltmp.x][0] = -1;
						
					}
					else {
						celltmp.time++;
						tmp.add(celltmp);
					}
					
					for(int i=0;i<4;i++)
					{
						int x = celltmp.x+dx[i];
						int y = celltmp.y+dy[i];
						//System.out.println(y+" "+x);
						if(map[y][x][0] == -1) continue;
						if(is_start[y][x] ) continue;
						if(map[y][x][0] == 0 || map[y][x][0] < celltmp.level)
						{
							map[y][x][0] = celltmp.level;
							tmp.add(new cell(x,y,0,celltmp.level));
							cnt++;
						}
					}
					
					
					
					continue;
				}
				if(celltmp.time == celltmp.level*2-1) {
					map[celltmp.y][celltmp.x][0] = -1;
					continue;
				}
				if(celltmp.time > celltmp.level)
				{
					celltmp.time++;
					tmp.add(celltmp);
					continue;
				}
				if(map[celltmp.y][celltmp.x][0] != celltmp.level) continue;
				is_start[celltmp.y][celltmp.x] = true;
				celltmp.time++;
				tmp.add(celltmp);
				
			}
			que.addAll(tmp);
			time++;
			/*System.out.println("\n\n");
			for(int i=0;i<500;i++)
			{
				for(int j=0;j<500;j++)
				{
					System.out.print(map[i][j][0]);
				}
			}*/
		}
		for(int i=0;i<500;i++)
		{
			for(int j=0;j<500;j++)
			{
				if(map[i][j][0]>0) ans++;
			}
		}
	}
	
	
	
	
	
	
	
	
	
	
	
	
	
}
