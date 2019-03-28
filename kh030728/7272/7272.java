
import java.util.Scanner;
import java.io.FileInputStream;

class Solution
{
	public static void main(String args[]) throws Exception
	{
		Scanner sc = new Scanner(System.in);
		int T;
		T=sc.nextInt();
		for(int test_case = 1; test_case <= T; test_case++)
		{
			String n1 = sc.next();
            String n2 = sc.next();
        	n1 = n1.replaceAll("C|E|F|G|H|I|J|K|L|M|N|S|T|U|V|W|X|Y|Z","1");
        	n1 = n1.replaceAll("A|D|O|P|Q|R","0");
        	n1 = n1.replaceAll("B","2");
            n2 = n2.replaceAll("C|E|F|G|H|I|J|K|L|M|N|S|T|U|V|W|X|Y|Z","1");
        	n2 = n2.replaceAll("A|D|O|P|Q|R","0");
        	n2 = n2.replaceAll("B","2");
            
            if(n1.equals(n2) == true) {
                System.out.println("#"+test_case+" SAME");
            }else {
            	
                System.out.println("#"+test_case+" DIFF");
            }
		}
	}
}