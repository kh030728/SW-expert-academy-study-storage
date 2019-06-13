# 7792 - 반장 선출

<hr/>

## 1. 문제 설명

**SW Expert 아카데미의 문제를 무단 복제하는 것을 금지합니다.**

문제 설명은 문제 링크로 대체합니다.

[반장 선출](<https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AWsBNHuqMMADFARG&categoryId=AWsBNHuqMMADFARG&categoryType=CODE>)

------

## 2. 문제 풀이

1. [7728 - 다양성 측정](<https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AWq40NEKLyADFARG&categoryId=AWq40NEKLyADFARG&categoryType=CODE>) 과 유사한 문제
2. 알파벳 크기(26) 의 bool 배열을 만듬
3. 다양성을 저장할 변수와 다양성이 가장 큰 글자를 저장할 변수를 설정
4. 이름에 대하여 체크를 하면서 다양성 확인
5. 다양성이 이전보다 높다면 가장 큰 글자와 다양성 변수를 변경
6. 다양성이 이전과 같다면 글자를 서로 비교하여 사전순으로 우선인 것으로 변경
