/*
0 1 0 1 0 0 0 0
1 0 0 0 1 0 0 0
0 0 1 0 0 0 0 0
1 0 0 0 1 0 0 0
0 1 0 1 0 0 0 0
0 0 0 0 0 0 0 0
*/
#include<stdio.h>
#pragma warning(disable:4996)

//八个方向
int move_x[8] = { -2,-1,1,2,2,1,-1,-2 };
int move_y[8] = { -1,-2,-2,-1,1,2,2,1 };

//判断该点是否在棋盘上
int InBoard(int x, int y)
{
	if (x >= 0 && x <= 7 && y >= 0 && y <= 7)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

//判断该点是否被没走过
int NoMarked(int x, int y, int board[8][8])
{
	if (board[x][y])
	{
		return 0;
	}
	else
	{
		return 1;
	}
}

//递归马踏棋盘
int dfs(int board[8][8], int cnt, int x, int y)
{
	board[x][y] = cnt;
	if (cnt == 64)
	{
		for (size_t i = 0; i < 8; ++i)
		{
			for (size_t j = 0; j < 8; ++j)
			{
				printf("%3d ", board[i][j]);
			}
			printf("\n");
		}
		return 1;
	}
	else
	{
		for (size_t i = 0; i < 8; ++i)
		{
			int xx = x + move_x[i];
			int yy = y + move_y[i];
			if (InBoard(xx, yy) && NoMarked(xx, yy, board))
			{
				//如果找到了，就不用dfs了
				if (dfs(board, cnt + 1, xx, yy)) return 1;
			}
		}
	}
	board[x][y] = 0;
	return 0;
}

int main()
{
	int x, y;
	printf("请输入开始坐标x y：");
	scanf("%d %d", &x, &y);
	int board[8][8] = { 0 };
	dfs(board, 1, x, y);
	return 0;
}