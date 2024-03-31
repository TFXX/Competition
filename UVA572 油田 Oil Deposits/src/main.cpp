/**
# 油田 Oil Deposits

## 题面翻译

输入多个 $m$ 行 $n$ 列的矩阵，用 `0 0` 表示输入结束。找出有多少块石油区域，用 `@` 代表石油，假如两个 `@` 在横，竖或对角线上相邻，就说它们位于同一区域，对于每个输入，输出一个数表示有几个石油区域。

## 题目描述

[problemUrl]: https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=7&page=show_problem&problem=513

[PDF](https://uva.onlinejudge.org/external/5/p572.pdf)

![](https://cdn.luogu.com.cn/upload/vjudge_pic/UVA572/ce90a5dd1ff852d09612a3d726a859f2f238d409.png)

## 输入格式

![](https://cdn.luogu.com.cn/upload/vjudge_pic/UVA572/e054765bf4e9769be3a53a455e412d62189dbbff.png)

## 输出格式

![](https://cdn.luogu.com.cn/upload/vjudge_pic/UVA572/99ea5e1b8c71aa83bbd6eed7a0e27de87f60a175.png)

## 样例 #1

### 样例输入 #1

```
1 1
*
3 5
*@*@*
**@**
*@*@*
1 8
@@****@*
5 5
****@
*@@*@
*@**@
@@@*@
@@**@
0 0
```

### 样例输出 #1

```
0
1
2
2
```
**/
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>

#define MAX_M 104
#define MAX_N 104

int m, n;

char gra[MAX_M][MAX_N];
int idx[MAX_M][MAX_N];

void dfs(const int r, const int c, const int index)
{
	if (r < 0 || r >= m || c < 0 || c >= n)
	{
		return;
	}

	if (gra[r][c] != '@' || idx[r][c] != 0)
	{
		return;
	}

	idx[r][c] = index;

	for (int i = -1; i <= 1; i++)
	{
		for (int j = -1; j <= 1; j++)
		{
			if (i != 0 || j != 0)
			{
				dfs(r + i, c + j, index);
			}
		}
	}
}

int CC()
{
	int count = 0;

	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (gra[i][j] == '@' && idx[i][j] == 0)
			{
				dfs(i, j, ++count);
			}
		}
	}

	return count;
}

int main(int, char **)
{
	
	while (true)
	{
		scanf("%d %d", &m, &n);

		if(m == 0 && n == 0)
		{
			break;
		}

		for(int i = 0; i < m; i++)
		{
			scanf("%s", gra[i]);
		}

		memset(idx, 0, sizeof(idx));

		printf("%d\n", CC());
	}
}