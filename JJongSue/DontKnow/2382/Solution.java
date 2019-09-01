package Solution2382;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;
import java.util.StringTokenizer;

public class Solution {
	//0없음 1상 2하 3좌 4우
	static final int dx[] = {0,0,0,-1,1};
	static final int dy[] = {0,-1,1,0,0};
	
	//map과 이동위치를 저장할 newmap, 합계를 저장할 summap
	static int [][]map, newmap, summap;
	//N : map의 크기, M : 격리시간 K : 군집 수
	static int N, M, K;
	//미생물 큐
	static Queue<germ> germQ;
	static class germ{
		int x;
		int y;
		int cnt;
		int distance;
		public germ(int x, int y, int cnt, int distance) {
			super();
			this.x = x;
			this.y = y;
			this.cnt = cnt;
			this.distance = distance;
		}		
	}
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		int T = Integer.parseInt(st.nextToken());
		for(int tc=1;tc<=T;tc++)
		{
			st = new StringTokenizer(br.readLine());
			N = Integer.parseInt(st.nextToken());
			M = Integer.parseInt(st.nextToken());
			K = Integer.parseInt(st.nextToken());
			map = new int[N][N];
			germQ = new LinkedList<germ>();
			for(int i=0;i<K;i++)
			{
				st = new StringTokenizer(br.readLine());
				int y = Integer.parseInt(st.nextToken());
				int x = Integer.parseInt(st.nextToken());
				map[y][x] = Integer.parseInt(st.nextToken());
				int dis = Integer.parseInt(st.nextToken());
				germQ.add(new germ(x, y, map[y][x], dis));
			}
			
			move();
			int ans=0;
			for(int i=0;i<N;i++)
			{
				for(int j=0;j<N;j++)
				{
					ans+=map[i][j];
				}
			}
			System.out.println("#"+tc+" "+ans);
		}
	}
	static void move()
	{
		int time = 0;
		while(M > time)
		{
			Queue<germ> tmpQ = new LinkedList<germ>();
			Queue<germ> sumQ = new LinkedList<germ>();
			map = new int[N][N];
			newmap = new int[N][N];
			while(!germQ.isEmpty())
			{
				germ tmp = germQ.poll();
				tmp.y+=dy[tmp.distance];
				tmp.x+=dx[tmp.distance];
				if(tmp.x == 0 || tmp.y==0 || tmp.x==N-1 || tmp.y==N-1)
				{
					if(tmp.distance == 1) tmp.distance=2;
					else if(tmp.distance == 2) tmp.distance =1;
					else if(tmp.distance == 3) tmp.distance=4;
					else if(tmp.distance == 4) tmp.distance=3;
					tmp.cnt/=2;
					map[tmp.y][tmp.x]+=tmp.cnt;
					newmap[tmp.y][tmp.x]=tmp.cnt;
					tmpQ.add(tmp);
					continue;
				}
				map[tmp.y][tmp.x]+=tmp.cnt;
				if(newmap[tmp.y][tmp.x]<tmp.cnt)
				{
					newmap[tmp.y][tmp.x]=tmp.cnt;
					tmpQ.add(tmp);
				}
			}
			
			while(!tmpQ.isEmpty())
			{
				germ tmp = tmpQ.poll();
				if(tmp.cnt == newmap[tmp.y][tmp.x])
				{
					tmp.cnt = map[tmp.y][tmp.x];
					germQ.add(tmp);
				}
			}
			
			
			
			
			time++;
		}
	}
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
}
