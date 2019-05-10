# 3143- 가장 빠른 문자열 타이핑

<hr/>

## 1. 문제 설명

**SW Expert 아카데미의 문제를 무단 복제하는 것을 금지합니다.**

문제 설명은 문제 링크로 대체합니다.

[가장 빠른 문자열 **타이**핑](<https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AV_65wkqsb4DFAWS&categoryId=AV_65wkqsb4DFAWS&categoryType=CODE>)

------

## 2. 문제 풀이

1. 완전 탐색으로 풀면 되는 문제
2. 문자열 A에 대하여 하나의 문자씩 보면서 문자열 B의 첫 문자가 나온다면 B와 같은 지 확인
3. 같다면, B 문자열과 같은 부분은 문자의 개수를 1개로 계산하고 B문자열을 지나서 다시 문자의 개수를 세면 됨

------

## 3. 다른 방법의 문제풀이

1. 뒤늦게 깨달은 다른 풀이
2. 문자열 A에 대하여 B문자열을 찾은 후(**string::finc()** 함수 사용) 그 문자의 위치를 특정 문자(Ex. *이나 A와 같은)로 변경
3. 변경된 문자열의 사이즈를 계산하면 그것이 정답