# B12871 -  무한 문자열

<hr/>

## 1. 문제 설명

문자열 s가 있을 때, f(s)는 s를 무한번 붙인 문자열로 정의한다. 예를 들어, s = "abc" 인 경우에 f(s) = "abcabcabcabc..."가 된다.

다른 문자열 s와 t가 있을 때, f(s)와 f(t)가 같은 문자열인 경우가 있다. 예를 들어서, s = "abc", t = "abcabc"인 경우에 f(s)와 f(t)는 같은 문자열을 만든다.

s와 t가 주어졌을 때, f(s)와 f(t)가 같은 문자열을 만드는지 아닌지 구하는 프로그램을 작성하시오.

[무한 문자열](<https://www.acmicpc.net/problem/12871>)

------

## 2. 문제 풀이

1. 문자열 s와 t의 최소공배수를 구한다
2. 구한만큼 문자열을 이어 붙인다
3. 최대로 이어붙인 문자열끼리 비교한다