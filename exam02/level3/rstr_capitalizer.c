/*

課題名：rstr_capitalizer
期待されるファイル名 : rstr_capitalizer.c
許可される関数：write
--------------------------------------------------------------------------------

1つ以上の文字列を受け取り、各引数に対して、以下のようなプログラムを書いてください。
各単語の最後の文字を大文字にし、残りの文字を を小文字で表示し、その後に「\n」を表示します。

単語は、スペース/タブまたは文字列の開始/終了で区切られた文字列の一部です。
単語が1文字の場合は、大文字にする必要があります。

文字とは、[a-zA-Z]の集合に含まれる文字である。

パラメータがない場合は、「\n」を表示します。

例:

$> ./rstr_capitalizer | cat -e
$
$> ./rstr_capitalizer "a FiRSt LiTTlE TESt" | cat -e
A firsT littlE tesT$
$> ./rstr_capitalizer "SecONd teST A LITtle BiT   Moar comPLEX" "   But... This iS not THAT COMPLEX" "	 Okay, this is the last 1239809147801 but not	the least	t" | cat -e
seconD tesT A littlE biT   moaR compleX$
   but... thiS iS noT thaT compleX$
	 okay, thiS iS thE lasT 1239809147801 buT noT	thE leasT	T$
$>

*/

#include <unistd.h>

void	rstr_capitalizer(char *str)
{
	int i = 0;

	while (str[i])
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
			str[i] += 32;
		if ((str[i] >= 'a' && str[i] <= 'z') && (str[i + 1] == ' ' \
					|| str[i + 1] == '\t' || str[i + 1] == '\0'))
			str[i] -= 32;
		write(1, &str[i++], 1);
	}
}

int main(int argc, char **argv)
{
	int i;

	if (argc == 1)
		write(1, "\n", 1);
	else
	{
		i = 1;
		while (i < argc)
		{
			rstr_capitalizer(argv[i]);
			write(1, "\n", 1);
			i += 1;
		}
	}
	return (0);
}
