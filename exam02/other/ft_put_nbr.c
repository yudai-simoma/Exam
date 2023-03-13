static void	ft_putunbr_fd(unsigned int ln, int fd)
{
	if (ln == 0)
		ft_putchar_fd('0', fd);
	if (ln <= 9 && ln > 0)
		ft_putchar_fd(ln + 48, fd);
	else if (ln > 0)
	{
		ft_putunbr_fd(ln / 10, fd);
		ft_putchar_fd(ln % 10 + 48, fd);
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
