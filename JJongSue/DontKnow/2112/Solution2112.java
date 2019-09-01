package Solution2112;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;


public class Solution2112 {
	//N은 세로길이, M은 가로길이, K는 합격기준
	static int N, M, K;
	//0이면 false 1이면 true인 map
	static boolean [][]map; 
	static boolean []is_change;
	static int ans;
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
			map = new boolean[N][M];
			is_change = new boolean[N];
			for(int i=0;i<N;i++)
			{
				st = new StringTokenizer(br.readLine());				
				for(int j=0;j<M;j++)
				{
					int tmp = Integer.parseInt(st.nextToken());
					if(tmp == 1) map[i][j]=true;
				}
			}
			if(K==1) {
				System.out.println("#"+tc+" 0");
				continue;
			}
			if(look()) {
				System.out.println("#"+tc+" 0");
				continue;
			}
			ans=K+1;
			setMap(0,0);
			System.out.println("#"+tc+" "+ans);
			
			
			
			
		}
	}
	static void setMap(int now, int cnt)
	{
		if(cnt >= ans) return;
		if(look())
		{
			if(cnt < ans)
			{
				ans=cnt;
				/*for(int i=0;i<N;i++)
				{
					for(int j=0;j<M;j++)
					{
						if(map[i][j]) System.out.print(1+" ");
						else System.out.print(0+" ");
					}System.out.println();
				}
				look();*/
				
				return;
			}
		}
		if(now == N) return;
		setMap(now+1, cnt);
		boolean []copymap = new boolean[M];
		//System.arraycopy(map[i], 0, copymap, 0, M);
		for(int j=0;j<M;j++)
		{
			copymap[j]=map[now][j];
			map[now][j]=false;
		}
		setMap(now+1, cnt+1);
		System.arraycopy(copymap, 0, map[now], 0, M);
		for(int j=0;j<M;j++)
		{
			map[now][j]=true;
		}
		setMap(now+1, cnt+1);
		System.arraycopy(copymap, 0, map[now], 0, M);
		
		
//		for(int i=now;i<N;i++)
//		{
//			boolean []copymap = new boolean[M];
//			//System.arraycopy(map[i], 0, copymap, 0, M);
//			for(int j=0;j<M;j++)
//			{
//				copymap[j]=map[i][j];
//				map[i][j]=false;
//			}
//			/*if(look())
//			{
//				if(cnt < ans)
//				{
//					ans=cnt;
//					System.arraycopy(copymap, 0, map[i], 0, M);
//					return;
//				}
//			}*/
//			setMap(now+1, cnt+1);
//			System.arraycopy(copymap, 0, map[i], 0, M);
//			for(int j=0;j<M;j++)
//			{
//				map[i][j]=true;
//			}
//			/*if(look())
//			{
//				if(cnt < ans)
//				{
//					ans=cnt;
//					System.arraycopy(copymap, 0, map[i], 0, M);
//					return;
//				}
//			}*/
//			setMap(now+1, cnt+1);
//			System.arraycopy(copymap, 0, map[i], 0, M);
//			
//		}
	}
	static boolean look()
	{
		boolean is_zero=true;
		for(int j=0;j<M;j++)
		{
			int cnt=1, max=1;
			if(!is_zero) break;
			for(int i=0;i<N;i++)
			{
				cnt=1;
				//if(!is_zero) break;
				boolean now = map[i][j];
				for(int k=i+1;k<N;k++)
				{
					if(now != map[k][j])
					{
						if(cnt > max) max = cnt;
						cnt=1;
						break;
					}
					
					if(now==map[k][j])
					{
						cnt++;
						continue;
						
					}
					/*else if(now !=map[k][j]){
						//System.out.println(j+" "+k);
						i=k-1;
						if(cnt > max) max =cnt;
						cnt=1;
						break;
					}*/
					
				}
				if(cnt > max) max =cnt;
			}
			
			if(max < K) {
				return false;
				/*is_zero=false;
				break;*/
			}
			/*if(ans == 3)
			{
				System.out.println(cnt+" "+max);
			}*/
			
		}
		//if(ans==3) System.out.println("\n\n");
		/*if(is_zero && ans == 3)
		{
			for(int i=0;i<N;i++)
			{
				for(int j=0;j<M;j++)
				{
					if(map[i][j]) System.out.print(1+" ");
					else System.out.print(0+" ");
				}System.out.println();
			}
		}*/
		return true;//is_zero;
	}
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
}
