T = int(input())

for i in range(1, T+1):
    A, B = input().split()  # input 값을 공백을 기준으로 두 개의 변수에 나눠서 저장해야 함
    S = (int(A) / int(B))  # input이 str이므로 int로 변환 후 연산
    N = 0
    for tier in range(1, int(S)+1):  # 피라미드 위에서부터 한 단 씩 몇 개의 삼각형이 필요한 지 계산
        N += (tier * 2) - 1  # 점화식
    print("#%d " % i + str(N))