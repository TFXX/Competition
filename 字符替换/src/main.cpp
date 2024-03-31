/*
字符替换
内存限制：256Mb
时间限制：1000s
提交：279
解决：109
题目描述
给出一个字符串 s 和 q 次操作，每次操作将 s 中的某一个字符a全部替换成字符b，输出 q 次操作后的字符串

输入
输入共 q+2 行

第一行一个字符串 s

第二行一个正整数 q，表示操作次数

之后 q 行每行“a b”表示把 s 中所有的a替换成b

输出
一个字符串，表示 q 次操作后的字符串

样例输入1
aabbcc
3
a b
b e
c f

样例输出1
eeeeff
*/

#include <iostream>
#include <string>
using namespace std;


int main(int argc, char **argv)
{
	string s;
	cin >> s;
	uint32_t q;
	cin >> q;

	char a, b;
	for (int i = 0; i < q; i++)
	{
		cin >> a >> b;

		for (char &c : s)
		{
			if (c == a)
			{
				c = b;
			}
		}
	}

	cout << s;
}