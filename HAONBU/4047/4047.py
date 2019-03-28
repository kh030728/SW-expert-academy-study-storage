def slice_king(a):
    sliced = list()
    for i in range(len(a)):
        if i % 3 != 0: continue
        sliced.append(a[i:i + 3])  # 3글자 단위로 자름
    return sliced


def verify_king(sliced_a):
    error_vdeck = set(sliced_a)
    if len(sliced_a) != len(error_vdeck):  # 중복되는 데이터가 있는지 확인
        return "ERROR"
    else:
        a_s, a_d, a_h, a_c = 13, 13, 13, 13
        for card in sliced_a:  # 데이터의 첫 글자로 카드의 문양을 판단함
            if card[0] == 'S':
                a_s -= 1
            elif card[0] == 'D':
                a_d -= 1
            elif card[0] == 'H':
                a_h -= 1
            elif card[0] == 'C':
                a_c -= 1
        return "%d %d %d %d" % (a_s, a_d, a_h, a_c)


T = int(input())
index = 1

for test_case in range(1, 1 + T):
    case_list = str(input())  
    sliced_case = slice_king(case_list)  # 입력받은 값을 카드 한 장 단위로 쪼갬
    print("#{0} ".format(index) + verify_king(sliced_case))  # 검증 후 출력
    index += 1

