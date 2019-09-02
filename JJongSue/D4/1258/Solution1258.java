package Solution1258;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Comparator;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

public class Solution1258 {
	//화학물질을 저장할  map
	static int [][]map;
	//화학물질의 크기 N
	static int N;
	static class matrix{
		int x;
		int y;
		public matrix(int x, int y) {
			super();
			this.x = x;
			this.y = y;
		}
	}
	static Comparator<matrix> C = new Comparator<matrix>() {

		@Override
		public int compare(matrix o1, matrix o2) {
			if(o1.x*o1.y < o2.x*o2.y) return -1;
			else if(o1.x*o1.y > o2.x*o2.y) return 1;
			else {
				if(o1.y < o2.y) return -1;
				else if(o1.y > o2.y) return 1;
				else return 0;
			}
			// TODO Auto-generated method stub
			
		}
	};
	static PriorityQueue<matrix> pq;
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		int T = Integer.parseInt(st.nextToken());
		StringBuilder sb = new StringBuilder("");
		for(int tc=1;tc<=T;tc++)
		{
			//N을 입력받고 map을 선언후 map을 입력받음
			st = new StringTokenizer(br.readLine());
			N = Integer.parseInt(st.nextToken());
			map = new int[N][N];
			pq = new PriorityQueue<>(C);
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
					if(map[i][j] != 0)
					{
						lookmap(j,i);
					}
				}
			}
			sb.append("#").append(tc).append(" ").append(pq.size()).append(" ");
			while(!pq.isEmpty())
			{
				matrix tmp = pq.poll();
				sb.append(tmp.y).append(" ").append(tmp.x).append(" ");
			}
			sb.append("\n");
			//출력시 #tc 행렬의숫자  행 열 형태로 출력
		}
		System.out.println(sb);
		
	}
	
	static void lookmap(int x, int y)
	{
		int max_x=x, max_y=y;
		for(int i=x;i<N;i++)
		{
			if(map[y][i] == 0) break;
			max_x=i;
		}
		for(int i=y;i<N;i++)
		{
			boolean is_ok = true;
			for(int j=x;j<=max_x;j++)
			{
				if(map[i][j] == 0) {
					is_ok = false;
					break;
				}
			}
			if(is_ok) {
				for(int j=x;j<=max_x;j++)
				{
					map[i][j]=0;
					max_y=i;
				}
			}
			else {
				pq.add(new matrix(max_x-x+1, max_y-y+1));
				
				return;
				
			}
		}
		pq.add(new matrix(max_x-x+1, max_y-y+1));
		
	}
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
}
