/*

課題名：pgcd
想定されるファイル：pgcd.c
許可される関数 : printf, atoi, malloc, free
--------------------------------------------------------------------------------

intに収まる2つの厳密な正の整数を表す2つの文字列を受け取るプログラムを書きなさい。

それらの最大公約数の後に改行を表示せよ（必ず厳密には正の整数である）。

パラメータの数が2でない場合は、改行を表示する。

例:

$> ./pgcd 42 10 | cat -e
2$
$> ./pgcd 42 12 | cat -e
6$
$> ./pgcd 14 77 | cat -e
7$
$> ./pgcd 17 3 | cat -e
1$
$> ./pgcd | cat -e
$

*/

#include <stdio.h>
#include <stdlib.h>

void	pgcd(int a, int b)
{
	int n = a;

	while (n > 0)
	{
		if (a % n == 0 && b % n == 0)
		{
			printf("%d", n);
			return;
		}
		--n;
	}
}

int		main(int argc, char **argv)
{
	if (argc == 3)
		pgcd(atoi(argv[1]), atoi(argv[2]));

	printf("\n");
	return (0);
}