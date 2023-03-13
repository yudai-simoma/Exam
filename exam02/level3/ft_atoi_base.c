/*
割り当て名：ft_atoi_base
期待されるファイル名 : ft_atoi_base.c
許可された関数なし
--------------------------------------------------------------------------------

文字列の引数str（基数N <= 16）を整数（基数10）に変換して返す関数を書け。
入力で認識される文字は 0123456789abcdef これらはもちろん、要求された基底に従ってトリミングされる。
例えば、ベース4では "0123"、ベース16では "0123456789abcdef "が認識される。

大文字も認識されなければならない。"12fdb3 "は "12FDB3 "と同じです。

マイナス記号（'-'）は、文字列の最初の文字である場合のみ解釈されます。

関数は、次のように宣言する必要があります。

int ft_atoi_base(const char *str, int str_base);

*/

int		isvalid(char c, int base)
{
	char digits[17] = "0123456789abcdef";
	char digits2[17] = "0123456789ABCDEF";

	while (base)
	{
		base--;
		if (digits[base] == c || digits2[base] == c)
			return (1);
	}
	return (0);
}

int		value_of(char c)
{
	if (c >= '0' && c <= '9')
		return (c - '0');
	else if (c >= 'a' && c <= 'f')
		return (c - 'a' + 10);
	else if (c >= 'A' && c <= 'F')
		return (c - 'A' + 10);
	return (0);
}

int		ft_atoi_base(const char *str, int str_base)
{
	int return_num;
	char sign = '+';
	int	i= 0;

	return_num = 0;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = '-';
		i++;
	}
	while (isvalid(str[i], str_base))
	{
		return_num = (return_num * str_base) + value_of(str[i]);
		i++;
	}
	if (sign == '-')
		return_num *= -1;
	return (return_num);
}


#include <stdio.h>
int	main()
{
	printf("return9 = %d\n", ft_atoi_base("19", 9));
	printf("return10 = %d\n", ft_atoi_base("19", 10));
	printf("return2 = %d\n", ft_atoi_base("19", 2));
	printf("return16 = %d\n", ft_atoi_base("19", 16));
	printf("return15 = %d\n", ft_atoi_base("19", 15));
	printf("return4 = %d\n", ft_atoi_base("19", 4));
	printf("return16 = %d\n", ft_atoi_base("ff", 16));
}
