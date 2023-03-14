#include <limits.h>

int	ft_atoi(const char *str)
{
	int	return_num = 0;
	int	sign = 0;
	int	i = 0;

	// if (ft_error_check(str))
	// 	return (0);
	// ft_sign_check(str, &sign);
	// if (ft_max_check(str) == 1)
	// 	return ((int)LONG_MAX);
	// else if (ft_max_check(str) == 2)
	// 	return ((int)LONG_MIN);
	while ((str[i] != '\0')
		&& (((str[i] == '+' || str[i] == '-')
			|| ((str[i] >= 9 && str[i] <= 13) || str[i] == ' '))))
		i++;
	while (str[i] != '\0' && (str[i] >= '0' && str[i] <= '9'))
	{
		return_num = (return_num * 10) + (str[i] - '0');
		i++;
	}
	if (sign % 2 != 0)
		return_num *= -1;
	return (return_num);
}

#include <stdio.h>
int	main()
{
	printf("atoi = %d\n", ft_atoi("-2345678o"));
}