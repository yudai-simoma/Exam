/*
課題名：rev_wstr
想定されるファイル：rev_wstr.c
許可される関数 : write, malloc, free
--------------------------------------------------------------------------------

文字列をパラメータとして受け取り、その単語を逆順に表示するプログラムを作成しなさい。

単語とは、空白やタブで囲まれた文字列の一部、または文字列の始まりと終わりのことである。

パラメータの数が1でない場合、プログラムは'\n'を表示します。

テストするパラメータには、「追加」スペースはありません（文字列の先頭や末尾に追加スペースがなく、
単語は常に正確に1つのスペースで区切られることを意味します）。

例:

$> ./rev_wstr "You hate people! But I love gatherings. Isn't it ironic?" | cat -e
ironic? it Isn't gatherings. love I But people! hate You$
$>./rev_wstr "abcdefghijklm"
abcdefghijklm
$> ./rev_wstr "Wingardium Leviosa" | cat -e
Leviosa Wingardium$
$> ./rev_wstr | cat -e
$
$>

*/

#include <unistd.h>

void ft_putchar(char c)
{
	write(1, &c, 1);
}

int ft_strlen(char *str)
{
	int i = 0;
	
	while (str[i])
		i++;
	return (i);
}

int main(int ac, char *av[])
{
	char *tmp;
	char *rev;
	int len;

	if (ac == 2)
	{
		tmp = av[1];
		len = ft_strlen(tmp);
		rev = NULL;
		len--;
		while (tmp[len])
		{
			if (tmp[len - 1] == ' ')
			{
				rev = &tmp[len];
				while (*rev && *rev != ' ')
				{
					ft_putchar(*rev);
					rev++;
				}
				ft_putchar(' ');
			}
			else if (len == 0)
			{
				rev = &tmp[len];
				while (*rev && *rev != ' ')
				{
					ft_putchar(*rev);
					rev++;
				}
			}
			len--;
		}
	}
	ft_putchar('\n');
}