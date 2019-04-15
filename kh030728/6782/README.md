# Samsung SW Expert - SW Expert Academy
[Samsung SW Expert](https://www.swexpertacademy.com)
-------------------------------------------
[6782 - 현주가 좋아하는 제곱근 놀이 - 삼성 문제 링크](https://www.swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AWgqsAlKr9sDFAW0&categoryId=AWgqsAlKr9sDFAW0&categoryType=CODE)
-------------------------------------------
[코드 링크](https://github.com/kh030728/SW-expert-academy-study-storage/blob/master/kh030728/6782/6782.cpp)
-------------------------------------------
# 풀이 방법
-------------------------------------------
### 기본적으로 문제에 설명된 제곱근 규칙에 따라 동작하도록 설계한다면, 제한 시간을 초과하게 된다. 이를 해결하기 위해서는 불필요한 계산을 덜 해야하는데 제곱근이 정수가 아닌 경우 N값에 1씩 더해가며 제곱근이 나올때 까지 진행되기 때문에 이를 이용하면 시간을 줄일 수 있다. 제곱근이 정수가 아닌 경우 제곱근의 정수부만 추출하여 그 수를 제곱한다. 그 다음 N과 차이나는 값만큼의 횟수를 더해주면 된다.