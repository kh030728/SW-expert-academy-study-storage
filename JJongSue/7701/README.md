# 7699 수지의 수지 맞는 여행


[링크](https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AWqUzj0arpkDFARG&categoryId=AWqUzj0arpkDFARG&categoryType=CODE)



### 문제 설명
평소에 여행을 즐기는 수지는 이번에 새로운 섬에 도착했다.

이 섬은 1행, 1열로 시작해서 R행, C열까지 있으며, 총 R*C 칸으로 이루어져 있다.

수지는 지금 1행 1열에 있으며 앞으로 있을 야근을 위하여 기회 있을 때 미리 여행을 떠나려고 한다.

이 섬의 각 칸에는 알파벳이 적혀있다. 이 알파벳은 섬의 명물이고, 같은 알파벳은 같은 명물이다.

이 섬에서는 명물을 볼 때마다 요금을 지급해야 하는데 각 알파벳 명물을 처음 볼 땐 무료로 볼 수 있다.

그리고, 수지는 여행을 할 때 자신이 있는 지점의 명물을 본 후 4방향(상, 하, 좌, 우) 중 한 방향으로 1칸 이동 후 다음 명물을 보는 행동을 반복한다.


올해 SGA사 1년 차인 수지는 현재 대출빚과 카드빚에 허덕이고 있다.

따라서, 명물을 최대한 많이 보되, 요금을 지급하지 않는 방법을 택해야 한다.

수지가 1행 1열에서 여행을 시작했을 때, 같은 알파벳 명물을 두 번 이상 보지 않도록 여행을 떠나는 방법 중에 볼 수 있는 명물의 최대 개수를 구하여라.







### 제약 사항



- 시간 : 32개 테스트케이스를 합쳐서 C의 경우 10초 / C++의 경우 10초 / Java의 경우 20초
- 메모리 : 힙, 정적 메모리 합쳐서 256MB 이내, 스택 메모리 1MB 이내









-------------------------------------------



### 입출력 예



[입력]



첫 번째 줄에 테스트 케이스의 수 T가 주어진다.

각 테스트 케이스의 첫 번째 줄에는 섬의 크기 R,C(1≤R,C≤20)가 주어진다.

이어서 R개의 줄마다 C개의 알파벳 대문자가 빈 칸 없이 주어진다.

 

[출력]

각 테스트 케이스마다 ‘#x’(x는 테스트케이스 번호를 의미하며 1부터 시작한다)를 출력하고,

각 테스트 케이스마다 수지가 여행하면서 볼 수 있는 명물 개수의 최대치를 출력하라.








### 입출력 예 설명



..







-------------------------------------------



### 풀이



- 알파벳의 ㄱ


위의 방법으로 문제를 풀어나가면, 맨 처음에 for문을 통해 10번을 실행하고, 세대수를 입력 받는다. 그 후, 맨 처음에 5개를 각 각 왼쪽 첫번째, 두번째, 가운데, 오른쪽 첫번째, 두번째 순으로 입력 받고, 가운데의 조망권을 구하고 sun변수에 넣는다. 그 후, 각 위치를 왼쪽씩 한 칸으로 옮기고, 오른쪽 두번째에 입력받고 다시, 조망권을 구하는 것을 반복 후, 출력한다.






