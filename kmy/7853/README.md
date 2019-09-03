# 7853 -  오타

<hr/>

## 1. 문제 설명

**SW Expert 아카데미의 문제를 무단 복제하는 것을 금지합니다.**

문제 설명은 문제 링크로 대체합니다.

[오타](<https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AWttUKkq5hQDFASy&categoryId=AWttUKkq5hQDFASy&categoryType=CODE>)

------

## 2. 문제 풀이

1. 문자열의 매 자리의 문자마다 앞뒤를 비교하여 경우의 수를 곱해주면 되는 문제
2. 첫번째 문자와 마지막 문자는 경우의 수가 최대 2까지 밖에 안되기때문에 따로 빼줘야함
3. 처음 문제를 풀 때 2개 또는 3개의 문자가 같은지 아닌지를 확인해야해서 vector에 삽입하여 unique 함수를 이용하여 풀음
4. 채점시, 최대 15개의 경우 밖에 풀리지 않아 매 자리마다 문자를 비교하여 계산
