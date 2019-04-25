# Samsung SW Expert - SW Expert Academy
[Samsung SW Expert](https://www.swexpertacademy.com)
-------------------------------------------
[6907 - 단위 변환기 프로그램](https://www.swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AWh4GaY6EkEDFAXp&categoryId=AWh4GaY6EkEDFAXp&categoryType=CODE)
-------------------------------------------
[코드 링크](https://github.com/kh030728/SW-expert-academy-study-storage/blob/master/kh030728/6907/6907.cpp)
-------------------------------------------
# 풀이 방법
-------------------------------------------
다음 순서대로 조건을 확인하여 문제를 해결하였다.
### 소수점을 못 찾은 경우
소수점을 두번째 자리에 삽입해 준 후 길이에 맞게 승수를 더해준다.
### 소수점이 맨 끝에 있는 경우
소수점이 맨 끝에 있는 경우 소수점을 지우고 출력해주었다.
### 소수점이 존재하지만 두번째 자리에 위치하지 않은 경우
소수점의 위치를 조정해주고 그에 맞게 승수를 조정한다.
### 소수점이 정상적인 자리에 위치(2번째)에 위치하고 그 다음 수가 0이며 경우 소수점 앞의 수가 0인 경우
소수점 바로 뒤의 0을 제거해주고 그에 맞게 승수를 조정한다.
### 소수점이 정상적인 자리에 위치하고 소수점 앞의 수가 0이며 소수점 뒤의 수가 0이 아닌 경우
"0."을 제거한 후에 맞는 자리에 소수점을 추가해주고 그에 맞게 승수를 조정한다.