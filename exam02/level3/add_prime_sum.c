/*
課題名：add_prime_sum
想定されるファイル：add_prime_sum.c
許可された関数：write, exit
--------------------------------------------------------------------------------

正の整数を引数に取り、引数までの素数の合計を表示するプログラムを書く
表示後に改行を表示する。

例を挙げます。
$>./add_prime_sum 5
10
$>./add_prime_sum 7 | cat -e
17$
$>./add_prime_sum | cat -e
0$
$>

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

void	ft_putnbr(int n)
{
	if (n >= 10)
		ft_putnbr(n / 10);
	char c = (n % 10) + '0';
	write(1, &c, 1);
}

int	num_check(int num)
{
	int	i = 3;

	if (num <= 1)
		return (0);
	if (num % 2 == 0 && num > 2)
		return (0);
	while (i < (num / 2))
	{
		if (num % i == 0)
			return (0);
		i += 1;
	}
	return (1);
}

int main(int argc, char *argv[])
{
	int sum = 0;
	int nb = ft_atoi(argv[1]);

	if (argc != 2)
		write(1, "0", 1);
	while (nb > 0)
	{
		if (num_check(nb))
		{
			sum += nb;
		}
		nb--;
	}
	ft_putnbr(sum);
	write(1, "\n", 1);
	return (0);
}
