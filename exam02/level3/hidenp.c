/*

課題名：hidenp
想定されるファイル：hidenp.c
許可された関数：write
--------------------------------------------------------------------------------

2つの文字列を受け取り、最初の文字列が2番目の文字列の中に隠れている場合は1に続いて改行を表示し、
そうでない場合は0に続いて改行を表示するプログラムをhidenpと名付け、記述せよ。

s1 と s2 を文字列とする。s1の各文字をs1に現れるのと同じ順序でs2に見つけることが可能な場合、
s1はs2の中に隠されていると言う。また、空文字列はどの文字列にも隠されている。

パラメータの数が2でない場合、プログラムは改行を表示します。

例:

$>./hidenp "fgex.;" "tyf34gdgf;'ektufjhgdgex.;.;rtjynur6" | cat -e
1$
$>./hidenp "abc" "2altrb53c.sse" | cat -e
1$
$>./hidenp "abc" "btarc" | cat -e
0$
$>./hidenp | cat -e
$
$>

*/

#include <unistd.h>

int		main(int argc, char **argv)
{
	int i = 0;
	int	j = 0;

	if (argc == 3)
	{
		while (argv[1][i] != '\0')
		{
			while (argv[1][i] != argv[2][j] && argv[2][j] != '\0')
				j++;
			if (argv[2][j] == '\0')
			{
				write(1, "0", 1);
				return (0);
			}
			j++;
			i++;
		}
		write(1, "1", 1);
	}
	write(1, "\n", 1);
	return (0);
}
