int	main(int ac, char **av)
{
	int flg[300] = 0;
	for (int i = 0; av[1][i] != '\0'; i++)
	{
		if (flg[av[1][i]] == 0)
		{
			write(1, av[1][i], 1);
			flg[av[1][i]] = 1;
		}
	}
	for (int i = 0; av[2][i] != '\0'; i++)
	{
		if (flg[av[2][i]] == 0)
		{
			write(1, av[2][i], 1);
			flg[av[2][i]] = 1;
		}
	}
}
