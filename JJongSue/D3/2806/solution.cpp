#include <iostream>
#include <vector>
using namespace std;
int find_queen(int y, int x, vector<vector<bool>> &board, int queennum);

int main(void)
{
    int testcase_num = 0;
    scanf("%d", &testcase_num);
    for (int testcase_i = 1; testcase_i <= testcase_num; testcase_i++)
    {
        int queennum = 0;
        scanf("%d", &queennum);
        vector<vector<bool>> board;
        vector<bool> tmp(queennum, true);
        for (int i = 0; i < queennum; i++)
            board.push_back(tmp);
        printf("#%d %d\n", testcase_i, find_queen(0,0,board,queennum));
    }
    return 0;
}
int find_queen(int y, int x, vector<vector<bool>> &board, int queennum)
{
    if (y == queennum - 1 && x == queennum - 1)
    {
        if (board[y][x])
            return 1;
        else
            return 0;
    }
    else if (y == queennum - 1)
    {
        int tmp = 0;
        if (board[y][x])
            tmp = 1;
        return tmp + find_queen(y, x + 1, board, queennum);
    }
    else if (x == queennum - 1)
    {
        if (board[y][x])
        {
            vector<vector<bool>> board2 = board;
            for (int i = y, j=0; i < queennum;i++, j++)
            {
                board2[i][x] = false;
                board2[i][x-j] = false;
            }
            return find_queen(y+1, 0, board2, queennum);
        }
        else return 0;
    }
    else
    {
        if (board[y][x])
        {
            vector<vector<bool>> board2 = board;
            for (int i = y, j=0; i < queennum;i++, j++)
            {
                board2[i][x] = false;
                if(x-j >= 0) board2[i][x-j] = false;
                if(x+j < queennum) board2[i][x+j] = false;
            }
            return find_queen(y, x+1, board, queennum)+find_queen(y+1, 0, board2, queennum);;
        }
        else return find_queen(y, x+1, board, queennum);
    }
    
}