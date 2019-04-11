# 6719 - 성수의 프로그래밍 강좌 시청

<hr/>

## 1. 문제 설명

**SW Expert 아카데미의 문제를 무단 복제하는 것을 금지합니다.**

문제 설명은 문제 링크로 대체합니다.

[성수의 프로그래밍 강좌 시청](<https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AWd7sgDatsMDFAUh&categoryId=AWd7sgDatsMDFAUh&categoryType=CODE>)

------

## 2. 문제 풀이

1. 강좌를 본 후, 성수의 실력은 이전 실력과 강좌 난이도의 평균이 된다는 것
2. 평균으로 계산을 진행할 때, 이후에 들어온 값이 평균보다 클 수록 평균이 커진다는 점이 핵심
3. 강좌들을 정렬한 이후, 가장 큰 수부터 K개 만큼 선택
4. 선택된 수에서 작은 수부터 평균을 구해간 값이 가장큰 평균
5. Ex) N = 5, K = 3, 강좌점수가 9 5 5 3 2 일 경우, 9, 5, 5 를 선택
   (0 + 5) / 2 = 2.5
   (2.5 + 5) / 2 = 3.75
   (3.75 + 9) / 2 = 6.375 
