/*

課題名：ft_range
想定されるファイル：ft_range.c
許可された関数：malloc
--------------------------------------------------------------------------------

次の関数を書いてください。

int *ft_rrange(int start, int end);

整数の配列を(malloc()で)確保し、その中に連続した値を格納し返す。
endで始まり、startで終わる値（開始と終了を含む！）であれば 配列の最初の値へのポインタを返す。


例:

- (1, 3)と入力すると、3、2、1を含む配列を返します。
- (-1, 2)の場合は、2、1、0、-1を含む配列を返します。
- (0, 0)の場合は、0を含む配列を返します。
- (0, -3)の場合は、-3、-2、-1、0を含む配列が返されます。

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
	if (end < start)
	{
		while (end <= start)
		{
			return_num[i] = end;
			end++;
			i++;
		}
	}
	else
	{
		while (end >= start)
		{
			return_num[i] = end;
			end--;
			i++;
		}
	}
	return (return_num);
}

#include <stdio.h>
int	main()
{
	int	*num;

	num = ft_range(1, 3);
	for (int i = 0; i < 10; i++)
		printf ("num[%d] = %d\n", i, num[i]);
}
