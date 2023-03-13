/*

課題名：print_hex
想定されるファイル：print_hex.c
許可された関数：write
--------------------------------------------------------------------------------

10進数で表現された正数（またはゼロ）を受け取り、16進数（小文字）で表示し、
その後に改行するプログラムを作成しなさい。

パラメータの数が1でない場合、プログラムは改行を表示する。

例:

$> ./print_hex "10" | cat -e
a$
$> ./print_hex "255" | cat -e
ff$
$> ./print_hex "5156454" | cat -e
4eae66$
$> ./print_hex | cat -e
$

*/

#include <unistd.h>

int	ft_atoi(char *str)
{
	int return_num = 0;
	int	i = 0; 

	while (str[i] >= '0' && str[i] <= '9')
	{
		return_num *= 10;
		return_num += str[i] - '0';
		i++;
	}
	return (return_num);
}

void	print_hex(int n)
{
	char hex_digits[] = "0123456789abcdef";

	if (n >= 16)
		print_hex(n / 16);
	write(1, &hex_digits[n % 16], 1);
}

int		main(int argc, char **argv)
{
	if (argc == 2)
		print_hex(ft_atoi(argv[1]));
	write(1, "\n", 1);
}
