for i in range(10):
    x = int(input())
    word = input()
    list = []
    for j in word:
        if len(list) == 0:
            list.append(j)
        else:
            if j =='[' or j =='{' or j =='(' or j =='<':
                list.append(j)
            elif j==']':
                if list[-1] == '[':
                    list.pop()
                else:
                    list.append(j)

            elif j=='}':
                if list[-1] == '{':
                    list.pop()
                else:
                    list.append(j)
            elif j==')':
                if list[-1] == '(':
                    list.pop()
                else:
                    list.append(j)
            elif j=='>':
                if list[-1] == '<':
                    list.pop()
                else:
                    list.append(j)
    if len(list) == 0:
        print("#{} 1".format(i+1))
    else:
        print("#{} 0".format(i+1))