/*

課題名：LCM
期待されるファイル名 : lcm.c
許可された関数
--------------------------------------------------------------------------------

2つの符号なしintをパラメータとして受け取り、
それらのパラメータの計算されたLCMを返す関数を書きなさい。

2つの非ゼロ整数のLCM（Lowest Common Multiple）とは、
その2つの整数で割り切れる最小の正の整数のことである。

LCMは2つの方法で計算することができます。
- 各整数の倍数を，0以外の共通の倍数ができるまで計算する方法です。

- この2つの整数のHCF（Highest Common Factor）を使って、次のように計算することができます。

		LCM(x, y) = | x * y | / HCF(x, y)

  | x * y｜は、"xとyの積の絶対値 "という意味です。

少なくとも1つの整数がNULLの場合、LCMは0に等しくなります。

あなたの関数は、次のようにプロトタイプ化されなければならない。

  unsigned int lcm(unsigned int a, unsigned int b);

*/

unsigned int	lcm(unsigned int a, unsigned int b)
{
	unsigned int	n;

	if (a == 0 || b == 0)
		return (0);
	if (a > b)
		n = a;
	else
		n = b;
	while (1)
	{
		if (n % a == 0 && n % b == 0)
			return (n);
		++n;
	}
}

#include <stdio.h>

int main(void)
{
	printf("%u\n", lcm(3, 5));
}