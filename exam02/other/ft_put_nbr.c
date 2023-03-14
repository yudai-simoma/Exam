#include <unistd.h>
void ft_putchar_fd(char c, int i)
{
	write(i, &c, 1);
}

static void	ft_putunbr_fd(unsigned int ln, int fd)
{
	if (ln > 9)
	{
		ft_putunbr_fd(ln / 10, fd);
		ft_putchar_fd(ln % 10 + '0', fd);
	} else {
		ft_putchar_fd(ln + '0', fd);
	}
}

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int	ln;

	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		ln = -n;
	}
	else
		ln = n;
	ft_putunbr_fd(ln, fd);
}

#include <limits.h>
int	main()
{
	ft_putnbr_fd(10, 1);
}