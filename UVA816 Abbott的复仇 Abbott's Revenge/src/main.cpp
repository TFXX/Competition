/**
# Abbott的复仇 Abbott's Revenge

## 题面翻译

给出一个箭头迷宫，在每个路口处，如果你从某个方向进入了该路口，那么路口的地面上在靠近你的方向会画有一组箭头，它们相对于你的方向可以是向左，向前，向右，或者是它们的任意组合。

当你从某一方向进入某个入口时，下一步只能在这个入口对应方向上标记的箭头中选一个方向继续行进。在起点时，可以选择任何方向。

给出起点和终点，求它们之间的最短路径。

每条边的长度为1

## 题目描述

[problemUrl]: https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=10&page=show_problem&problem=757

[PDF](https://uva.onlinejudge.org/external/8/p816.pdf)

![](https://cdn.luogu.com.cn/upload/vjudge_pic/UVA816/815d09b7103ad071de9d9f7869315aa2585ea85b.png)

## 输入格式

![](https://cdn.luogu.com.cn/upload/vjudge_pic/UVA816/4939e773b1884a681cdc9dbd1fe1251df58b072b.png)

## 输出格式

![](https://cdn.luogu.com.cn/upload/vjudge_pic/UVA816/9ff2bb3a862e6ca3e356ecb98a558f994c9d7f5d.png)

## 样例 #1

### 样例输入 #1

```
SAMPLE
3 1 N 3 3
1 1 WL NR *
1 2 WLF NR ER *
1 3 NL ER *
2 1 SL WR NF *
2 2 SL WF ELF *
2 3 SFR EL *
0
NOSOLUTION
3 1 N 3 2
1 1 WL NR *
1 2 NL ER *
2 1 SL WR NFR *
2 2 SR EL *
0
END
Figure 1: An Example Walk-Through
Arrow Maz
```

### 样例输出 #1

```
SAMPLE
(3,1) (2,1) (1,1) (1,2) (2,2) (2,3) (1,3) (1,2) (1,1) (2,1)
(2,2) (1,2) (1,3) (2,3) (3,3)
NOSOLUTION
No Solution Possible
```
**/

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <queue>

using namespace std;

int step[9][9][4];
bool edge[9][9][4][3];

int dr[4] = {-1, 0, 1, 0};	// N - E - S - W - N
int dc[4] = {0, 1, 0, -1};

class Node {
public:	
	int m_r, m_c;
	int m_dir;
	Node(int x, int y, int dir)
		: m_r(x), m_c(y), m_dir(dir)
	{
		;
	}

	Node walk(int turn) const
	{
		int dir = m_dir;
		if (turn == 1)	// L
		{
			dir = (dir + 3) % 4;
		}

		if (turn == 2) // R
		{
			dir = (dir + 1) % 4;
		}

		return Node(m_r + dr[dir], m_c + dc[dir], dir);
	}

} father[9][9][4];

int r2, c2;

int to_dir(char c)
{
	static const char *dirs = "NESW";
	return strchr(dirs, c) - dirs;
}

int to_turn(char c)
{
	static const char *turns = "FLR";
	return strchr(turns, c) - turns;
}

void print_ans()
{
	;
}


void bfs(const Node &n1)
{
	queue<Node> q;
	q.push(n1);

	while (!q.empty())
	{
		Node n = q.front();
		q.pop();

		if (n.m_r == r2 && n.m_c == c2)
		{
			print_ans();
			return;
		}
		
		for (int i = 0; i < 3; i++)
		{
			if (!edge[n.m_r][n.m_c][n.m_dir][i])
			{
				continue;
			}

			Node next = n.walk(i);
			
			if (step[next.m_r][next.m_c][next.m_dir] >= 0)
			{
				continue;
			}

			step[next.m_r][next.m_c][next.m_dir] = step[n.m_r][n.m_c][n.m_dir] + 1;
			father[next.m_r][next.m_c][next.m_dir] = n;

			q.push(next);
		}

		printf("No Solution Possible");
	}
}

void add_edge(int r, int c, int dir, int turn)
{
	edge[r][c][dir][turn] = true;
}

int main(int, char **)
{
	memset(step, -1, sizeof(step));
	memset(edge, 0, sizeof(edge));

	int r0, c0;
	char dir;
	scanf("%d %d %s %d %d", &r0, &c0, &dir, &r2, &c2);
	int dir0 = to_dir(dir);
	Node n0(r0, c0, dir0);
	Node n1 = n0.walk(0);



	bfs(n1);

	return 0;
}