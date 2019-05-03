import java.util.Scanner;
import java.util.Collections;
import java.util.ArrayList;

public class Solution
{
    public static void main(String[] args)
    {
        Scanner sc = new Scanner(System.in);
        int test_case = sc.nextInt();
        
        for(int i = 1 ; i <= test_case; i++)
        {
            int NumOfNodes = sc.nextInt(); int NumOfEdges = sc.nextInt(); // 생성할 노드 수와 연결할 간선의 수
            int a = sc.nextInt(); // 목표 노드 a
            int b = sc.nextInt(); // 목표 노드 b

            ArrayList<Node> nodes = new ArrayList<>(); // 모든 노드를 담아둘 리스트
            //노드 생성
            for(int j = 1 ; j <= NumOfNodes ; j++)
            {
                nodes.add( new Node(j) );
            }
            //간선 연결
            for(int j = 1 ; j <= NumOfEdges; j++)
            {
                int p = sc.nextInt();
                int c = sc.nextInt();
                nodes.get(p-1).insert(nodes.get(c-1));
            }
            // 상위 노드 저장
            ArrayList<Integer> al = nodes.get(a-1).getParents();
            ArrayList<Integer> bl = nodes.get(b-1).getParents();
            int SizeOfal = al.size();
            int SizeOfbl = bl.size();
            int tmp = 0;
            for(int j = 0; j < al.size() ; j++)
            {
                int ai = al.get(SizeOfal-1-j);
                int bi = bl.get(SizeOfbl-1-j);
                if(ai == bi)
                    tmp = ai;
                else
                    break;
            }
            System.out.print("#"+i+" "+tmp);
            System.out.println(" "+nodes.get(tmp-1).subSize());
        }
    }
}

class Node
{
    private Node parent = null;
    private Node left = null;
    private Node right = null;
    public int data = 0;

    private void setParent(Node n){ parent = n; }
    public Node(int data) {
        this.data = data;
    }
    public ArrayList<Integer> getParents(){
        ArrayList<Integer> tmp = new ArrayList<>();
        Node n = parent;
        while(n!=null)
        {
            tmp.add(n.data);
            n= n.getParent();
        }
        return tmp;
    }

    public void insert(Node n)
    {
        if(left == null)
        {
            left = n;
            left.setParent(this);
        }
        else
        {
            right = n;
            right.setParent(this);
        }
    }
    public Node getParent(){ return parent;}
    public Node getLeft() { return left;}
    public Node getRight() { return right;}
    public int subSize() {
        int count = 1;
        if(left != null)
            count += left.subSize();
        if(right != null)
            count += right.subSize();
        return count;
    }
}
