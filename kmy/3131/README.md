# 3131 - 100만 이하의 모든 소수

<hr/>

## 1. 문제 설명

**SW Expert 아카데미의 문제를 무단 복제하는 것을 금지합니다.**

문제 설명은 문제 링크로 대체합니다.

[100만 이하의 모든 소수](https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AV_6mRsasV8DFAWS&categoryId=AV_6mRsasV8DFAWS&categoryType=CODE)

------

## 2. 문제 풀이

1. 1부터 100만까지의 수에서 모든 소수를 출력하는 문제
2. 처음에는 2중 포문으로 구성 하는 방식을 사용
3. 2부터 100만까지, 그리고 i에 대하여 2부터 sqrt(i) 까지의 수를 모드 연산(% 연산) 하여 중간에 나누어 떨어진다면 break와 소수가 아니라고 표시 하는 방식을 사용
4. 제출해보니 제한시간 초과 오류
5. 그래서 메모리가 많이 들지만 빠른 에라토스테네스의 채 방식을 사용
6. 시간초과 없이 통과

------

## 3. 에라토스테네스의 방법(체) 에 대한 설명

[설명 링크](https://ledgku.tistory.com/61)