# Samsung SW Expert - SW Expert Academy
[Samsung SW Expert](https://www.swexpertacademy.com)
-------------------------------------------
[6109 - 추억의 2048게임 - 삼성 문제 링크](https://www.swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AWbrg9uabZsDFAWQ&categoryId=AWbrg9uabZsDFAWQ&categoryType=CODE)
-------------------------------------------
[코드 링크](https://github.com/kh030728/SW-expert-academy-study-storage/blob/master/kh030728/6109/6109.cpp)
-------------------------------------------
# 풀이 방법
-------------------------------------------
#### 각 up, down, right, left에 대해서 문자 사이의 0 제거와 연속으로 같은 숫자가 나오는 경우의 합산하는 처리를 한다면 성공적으로 해결이 가능하다. 이 코드에서는 우선 문자 사이의 0을 제거(zeroRemover 함수)를 하고 같은 두 숫자를 더한 후 뒤에 숫자를 0으로 치환한다.(sumArray 함수) 그후 다시 문자 사이의 0을 제거한 후에 결과를 출력한다.
