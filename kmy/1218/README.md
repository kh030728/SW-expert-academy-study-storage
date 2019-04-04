# 1218 - [S/W 문제해결 기본] 4일차 - 괄호 짝짓기

<hr/>

## 1. 문제 설명

**SW Expert 아카데미의 문제를 무단 복제하는 것을 금지합니다.**

문제 설명은 문제 링크로 대체합니다.

[괄호 짝짓기](<https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AV14eWb6AAkCFAYD&categoryId=AV14eWb6AAkCFAYD&categoryType=CODE>)

------

## 2. 문제 풀이

1. 스택을 이용한 문제
2. 입력으로 들어온 문자열을 하나씩 스택에 쌓으면서 처리
3. 만약 스택의 Top 이 '(', '[', '<', '{' 와 같은 문자이고 다음 입력이 각 괄호에 맞는 문자라면 pop을 이용
4. Ex) 스택의 Top 이 '(' 이고 다음 문자가 ')' 라면 '(' 를 pop만 해줌
5. 이런 과정으로 모든 문자열을 처리한 뒤 스택 사이즈가 0이면 올바른 문자열
6. 0이 아니라면 올바르지 않은 문자열로 볼 수 있음
7. 올바르게 문자가 들어왔다면 이전에 들어온 모든 문자 들이 pop되서 스택에 아무것도 남지 않음
