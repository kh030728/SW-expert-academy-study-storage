# 4261 - 빠른 휴대전화 키패드

<hr/>

## 1. 문제 설명

**SW Expert 아카데미의 문제를 무단 복제하는 것을 금지합니다.**

문제 설명은 문제 링크로 대체합니다.

[빠른 휴대전화 키패드](<https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AWLL7kaaAPsDFAUW&categoryId=AWLL7kaaAPsDFAUW&categoryType=CODE>)

------

## 2. 문제 풀이

1. 일정 문자를 숫자로 변환 후 주어진 문자를 찾으면 되는 문제
2. 입력 받은 문자 (Ex. banana, tomato ....)를 숫자(a, b, c는 숫자 2로, d, e, f는 숫자 3 ....)로 바꿔주면서 벡터 푸쉬
3. 저장된 벡터에 대하여 찾는 숫자(Ex. '6666', '12345' ....)를 find 함수를 통하여 찾아내어 있다면 정답 갯수를 증가, 없다면 증가 X
