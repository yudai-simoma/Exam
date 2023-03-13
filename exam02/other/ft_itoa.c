#include <stdlib.h>

/*
 * 数値が何桁か判断する関数
 */
static size_t	ft_malloc_size(long n)
{
	size_t	malloc_size;

	malloc_size = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		n *= -1;
		malloc_size = 1;
	}
	while (n)
	{
		n /= 10;
		malloc_size++;
	}
	return (malloc_size);
}

/*
 * 数値を文字列に格納する
 */
static char	*ft_set_itoa(char *return_str, long nn, size_t size, char sign)
{
	size_t	i;

	if (sign == '-')
	{
		size -= 1;
		return_str[size] = '-';
	}
	i = 0;
	while (size > 0)
	{
		return_str[size - 1] = (nn % 10) + '0';
		nn /= 10;
		size--;
	}
	return_str[size - 1] = '\0';
	return (return_str);
}

/*
 * 数値を文字列にして返す関数
 */
char	*ft_itoa(int n)
{
	char	*return_str;
	long	nn;
	char	sign;
	size_t	malloc_size;

	nn = (long)n;
	malloc_size = ft_malloc_size(nn);
	return_str = (char *)malloc(sizeof(char) * (malloc_size + 1));
	if (return_str == NULL)
		return (NULL);
	sign = '+';
	if (nn < 0)
	{
		nn *= -1;
		sign = '-';
	}
	return_str = ft_set_itoa(return_str, nn, malloc_size, sign);
	return (return_str);
}
