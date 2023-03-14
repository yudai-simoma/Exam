/*

Assignment name  : ft_range
Expected files   : ft_range.c
Allowed functions: malloc
--------------------------------------------------------------------------------

次の関数を書いてください

int     *ft_range(int start, int end);

整数の配列を(malloc()で)確保し、その中に連続した値を格納し返す。
startで始まり、endで終わる値（開始と終了を含む！）であれば 配列の最初の値へのポインタを返す。

例:

- (1, 3)の場合は、1, 2, 3を含む配列を返します。
- (-1, 2)の場合は、-1, 0, 1, 2を含む配列を返します。
- (0, 0)の場合は、0を含む配列を返します。
- (0, -3)の場合は、0、-1、-2、-3 を含む配列を返します。

*/


#include <stdlib.h>

int	ft_len(int start, int end)
{
	int i = 0;

	if (start < end)
	{
		while (start <= end)
		{
			i++;
			start++;
		}
	} else {
		while (end <= start)
		{
			i++;
			end++;
		}
	}
	return (i);
}

int	*ft_range(int start, int end)
{
	int i = 0;
	int len = 0;
	int *return_num;

	len += ft_len(start, end);
	return_num = (int *)malloc(sizeof(int) * len);
	if (return_num == NULL)
		return (NULL);
	if (start < end)
	{
		while (start <= end)
		{
			return_num[i] = start;
			start++;
			i++;
		}
	}
	else
	{
		while (start >= end)
		{
			return_num[i] = start;
			start--;
			i++;
		}
	}
	return (return_num);
}

// #include <stdio.h>
// int	main()
// {
// 	int	*num;

// 	num = ft_range(0, -3);
// 	for (int i = 0; i < 10; i++)
// 		printf ("num[%d] = %d\n", i, num[i]);
// }
