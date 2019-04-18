# 1208 - [S/W 문제해결 기본] 1일차 - Flatten

# 1. 문제 설명

**SW Expert 아카데미의 문제를 무단 복제하는 것을 금지합니다.**

문제 설명은 문제 링크로 대체합니다.

[Flatten](<https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AV139KOaABgCFAYh&categoryId=AV139KOaABgCFAYh&categoryType=CODE>)

------

## 2. 문제 풀이

1. Priority 큐를 이용하면 쉽게 풀리는 문제
2. 오름차순 큐와 내림차순 큐 2개를 이용하면 됨
3. 내림차순으로 정렬된 큐에서 탑을 꺼내어 1개를 줄이고 다시 푸쉬, 오름차순으로 정렬된 큐에서 탑을 꺼내어 1개를 늘리고 다시 푸쉬 하는 작업을 평탄화가 될때까지 반복
4. 평탄화가 된다는 것은 오름차순으로 정렬한 큐의 탑과 내림차순으로 정렬한 큐의 탑이 **같다는 것**!
5. 그것을 확인하면 덤프 작업을 중지
6. 평탄화가 되지 않았다면 제공된 횟수만큼 반복!!
