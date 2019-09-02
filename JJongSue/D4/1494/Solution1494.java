package Solution1494;

import java.util.Scanner;

public class Solution1494 {
	static class pair{
		int x;
		int y;
		public pair(int x, int y) {
			super();
			this.x = x;
			this.y = y;
		}
	}
	static int N, half;
	static pair[] warms;
	static int[][] minus, plus;
	static long ans;
	public static void main(String[] args) {
		
		Scanner sc = new Scanner(System.in);
		int T = sc.nextInt();
		for(int tc=1;tc<=T;tc++)
		{
			N = sc.nextInt();
			warms = new pair[N];
			half = N/2;
			minus = new int[half][2];
			plus = new int [half][2];
			
			for(int i=0;i<N;i++)
			{
				int a = sc.nextInt();
				int b =sc.nextInt();
				warms[i]=new pair(a,b);
			}
			ans = Long.MAX_VALUE;
			select_warm(0,0,0);
			System.out.println("#"+tc+" "+ans);
		}
	}
	
	static void select_warm(int now, int pluscnt, int minuscnt)
	{
		if(now == N) {
			long sumx=0, sumy=0;
			for(int i=0;i<half;i++)
			{
				sumx+=plus[i][0];
				sumy+=plus[i][1];
				sumx-=minus[i][0];
				sumy-=minus[i][1];
			}
			if(ans > sumx*sumx+sumy*sumy) ans = sumx*sumx+sumy*sumy;
			return;
		}
		
		if(pluscnt < half)
		{
			plus[pluscnt][0] = warms[now].x;
			plus[pluscnt][1] = warms[now].y;
			select_warm(now+1, pluscnt+1, minuscnt);
		}
		if(minuscnt < half)
		{
			minus[minuscnt][0] = warms[now].x;
			minus[minuscnt][1] = warms[now].y;
			select_warm(now+1, pluscnt, minuscnt+1);
		}
		
	}
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
}
