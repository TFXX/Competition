/*
�ַ��滻
�ڴ����ƣ�256Mb
ʱ�����ƣ�1000s
�ύ��279
�����109
��Ŀ����
����һ���ַ��� s �� q �β�����ÿ�β����� s �е�ĳһ���ַ�aȫ���滻���ַ�b����� q �β�������ַ���

����
���빲 q+2 ��

��һ��һ���ַ��� s

�ڶ���һ�������� q����ʾ��������

֮�� q ��ÿ�С�a b����ʾ�� s �����е�a�滻��b

���
һ���ַ�������ʾ q �β�������ַ���

��������1
aabbcc
3
a b
b e
c f

�������1
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