/*

課題名：paramsum
期待されるファイル名：paramsum.c
許可された関数：write
--------------------------------------------------------------------------------

渡された引数の数を表示し、その後に改行するプログラムを作成せよ。

引数がない場合は、0を表示し、その後に改行を表示するようにしなさい。

例:

$>./paramsum 1 2 3 5 7 24
6
$>./paramsum 6 12 24 | cat -e
3$
$>./paramsum | cat -e
0$
$>

*/

#include <unistd.h>

void	ft_putnbr(int n)
{
	char	c;

	if (n >= 10)
		ft_putnbr(n / 10);
	c = (n % 10) + '0';
	write(1, &c, 1);
}

int	main(int argc, char **argv)
{
	(void)argv;

	ft_putnbr(argc - 1);
	write(1, "\n", 1);
	return (0);
}
