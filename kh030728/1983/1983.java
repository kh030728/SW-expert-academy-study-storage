import java.util.Scanner;
import java.util.Collections;
import java.util.ArrayList;
public class Solution {
 	public static void main (String[] args) {
    	Scanner scanner = new Scanner(System.in);
        int test_case = scanner.nextInt(); // 테스트 케이스의 개수를 받아옵니다.
        
        for(int i = 0 ; i < test_case ; i++) { //테스트 케이스의 수만큼 알고리즘을 반복합니다.
            System.out.print("#"+(i+1)+" ");
            int totalNum = scanner.nextInt(); // 전체 학생수
            int targetIndex = scanner.nextInt()-1; // 타겟 학생수 (입력은 인덱스가 아니라 1부터 시작하기 때문에 -1을 해준다.)
            ArrayList<Double> grade = new ArrayList<>();
            for(int j = 0; j < totalNum ; j++) { //각 학생 성적 합 구하기
                double middle = scanner.nextDouble();
                double last = scanner.nextDouble();
                double report = scanner.nextDouble();
                double sum = middle * 0.35 + last*0.45 + report *0.2;
                grade.add(sum);
            }
            //타겟 학생 성적을 기억(등수확인을 할때 사용)
            double targetGrade = grade.get(targetIndex);
            //내림차순정렬
            Collections.sort(grade);
            Collections.reverse(grade);
            int a = grade.indexOf(targetGrade)+1;//등수를 이용하는 것이기 때문에 0부터가아니라 1부터 시작하도록 해준다.
            //다르게 표현하는 방법이 없을까??
            if(totalNum/10>=a) {
                System.out.println("A+");
            } else if(totalNum*2/10>=a) {
            	System.out.println("A0");
            } else if(totalNum*3/10>=a) {
            	System.out.println("A-");
            } else if(totalNum*4/10>=a) {
            	System.out.println("B+");
            } else if(totalNum*5/10>=a) {
            	System.out.println("B0");
            } else if(totalNum*6/10>=a) {
            	System.out.println("B-");
            } else if(totalNum*7/10>=a) {
            	System.out.println("C+");
            } else if(totalNum*8/10>=a) {
            	System.out.println("C0");
            } else if(totalNum*9/10>=a) {
            	System.out.println("C-");
            } else {
                System.out.println("D0");
            }
            
        }
        
    }
}