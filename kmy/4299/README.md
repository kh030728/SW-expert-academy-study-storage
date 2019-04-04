# 4299 - 태혁이의 사랑은 타이밍

<hr/>

## 1. 문제 설명

**SW Expert 아카데미의 문제를 무단 복제하는 것을 금지합니다.**

문제 설명은 문제 링크로 대체합니다.

[태혁이의 사랑은 타이밍](<https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AWLv6mx6htoDFAVV&categoryId=AWLv6mx6htoDFAVV&categoryType=CODE>)

------

## 2. 문제 풀이

1. 출력은 분 단위로 출력이라는 것을 확인
2. D일 H시 M분이 입력으로 주어진다면 기준 시간인 11일 11시 11분을 각 값에 맞게 빼줌
3. Ex) X = D - 11, Y = H - 11 .... 이런식으로
4. 각 일, 시, 분 을 분 단위로 변환
5. 계산해서 나온 값이 음수라면 11일 11시 11분 이전이기 때문에 -1 출력, 양수라면 분 단위 이기 때문에 그대로 출력
6. 단순한 계산 문제
