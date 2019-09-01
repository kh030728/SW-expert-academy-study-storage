package Solution2383;

import java.util.ArrayList;
import java.util.Comparator;
import java.util.LinkedList;
import java.util.PriorityQueue;
import java.util.Queue;
import java.util.Scanner;


public class Solution {
	static int N;
	static ArrayList<human> people = new ArrayList<human>();
	static ArrayList<pair> stair = new ArrayList<Solution.pair>();
	//static pair[] stair = new pair[2];
	static int onedis, twodis;
	static int ans;
	static int map[][];
	
	static PriorityQueue<Integer> []PQ = new PriorityQueue[2];
	
	
	static PriorityQueue<Integer> []inPQ = new PriorityQueue[2];
	
	static Comparator<Integer> comp = new Comparator<Integer>() {

		@Override
		public int compare(Integer o1, Integer o2) {
			// TODO Auto-generated method stub
			if(o1 > o2) return 1;
			if(o1 < o2) return -1;
			return 0;
		}
	};
	
	
	static class pair{
		int x;
		int y;
		public pair(int x, int y) {
			super();
			this.x = x;
			this.y = y;
		}
	}
	static class human{
		pair p;
		int one;
		int two;
		public human(pair p) {
			super();
			this.p = p;
		}
		
	}
	
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int T = sc.nextInt();
		for(int tc=1;tc<=T;tc++)
		{
			N = sc.nextInt();
			map = new int[N][N];
			ans = Integer.MAX_VALUE;
			
			people = new ArrayList<human>();
			stair = new ArrayList<Solution.pair>();
			//static pair[] stair = new pair[2];

			
			for(int i=0;i<N;i++)
			{
				for(int j=0;j<N;j++)
				{
					map[i][j] = sc.nextInt();
					if(map[i][j] == 1) people.add(new human(new pair(j, i)));
					if(map[i][j] > 1) stair.add(new pair(j,i));
				}
			}
			for(int i=0;i<people.size();i++)
			{
				people.get(i).one=
						Math.abs(people.get(i).p.x-stair.get(0).x)+
						Math.abs(people.get(i).p.y-stair.get(0).y);
				people.get(i).two=
						Math.abs(people.get(i).p.x-stair.get(1).x)+
						Math.abs(people.get(i).p.y-stair.get(1).y);
			}
			select_ot(0,new int[people.size()]);
			System.out.println("#"+tc+" "+(ans+1));
			
		}
	}
	
	static void select_ot(int now, int [] select)
	{
		//if(cnt > ans ) return;
		if(now == people.size())
		{
			PQ[0] = new PriorityQueue<Integer>(comp);
			PQ[1] = new PriorityQueue<Integer>(comp);
			inPQ[0] = new PriorityQueue<Integer>(comp);
			inPQ[1] = new PriorityQueue<Integer>(comp);
			for(int i=0;i<now;i++)
			{
				if(select[i] == 0) {
					PQ[0].add(people.get(i).one);
				}
				else {
					PQ[1].add(people.get(i).two);
				}
			}
			find_ans();
			
			return;
		}
		for(int i=0;i<2;i++)
		{
			select[now] = i;
			select_ot(now+1, select);
			
		}
		
		
	}
	static void find_ans()
	{
		int time = 0;
		while(true)
		{
			if(time > ans)
			{
				return;
			}
			if(PQ[0].isEmpty() && PQ[1].isEmpty() && inPQ[0].isEmpty() && inPQ[1].isEmpty()) break;
			
			while(!inPQ[0].isEmpty())
			{
				if(inPQ[0].peek() <= time)
				{
					inPQ[0].poll();
					continue;
				}
				else break;
			}
			while(!PQ[0].isEmpty())
			{
				if(PQ[0].peek() <= time && inPQ[0].size() < 3)
				{
					PQ[0].poll();
					inPQ[0].add(time+map[stair.get(0).y][stair.get(0).x]);
				}
				else
					break;
			}
			
			while(!inPQ[1].isEmpty())
			{
				if(inPQ[1].peek() <= time)
				{
					inPQ[1].poll();
					continue;
				}
				else break;
			}
			while(!PQ[1].isEmpty())
			{
				if(PQ[1].peek() <= time && inPQ[1].size() < 3)
				{
					PQ[1].poll();
					inPQ[1].add(time+map[stair.get(1).y][stair.get(1).x]);
				}
				else
					break;
			}
			if(PQ[0].isEmpty() && PQ[1].isEmpty() && inPQ[0].isEmpty() && inPQ[1].isEmpty()) break;
			time++;
			
			
		}
		if(time < ans) ans = time;
		return;
	}
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
}
