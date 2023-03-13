/*

課題名：str_capitalizer
想定されるファイル：str_capitalizer.c
許可される関数：write
--------------------------------------------------------------------------------

1つまたは複数の文字列を受け取り、各引数に対して、各単語の最初の文字を大文字にするプログラム
を書きなさい。残りを小文字にし、その結果を標準出力に表示し、その後に「\n」を表示します。

「単語」とは、スペースやタブで区切られた文字列の一部、または文字列の先頭や末尾で
区切られた文字列の一部と定義されます。単語が1文字しかない場合は、大文字にしなければならない。

引数がない場合、プログラムは\nを表示しなければなりません。

例:

$> ./str_capitalizer | cat -e
$
$> ./str_capitalizer "a FiRSt LiTTlE TESt" | cat -e
A First Little Test$
$> ./str_capitalizer "__SecONd teST A LITtle BiT   Moar comPLEX" "   But... This iS not THAT COMPLEX" "     Okay, this is the last 1239809147801 but not    the least    t" | cat -e
__second Test A Little Bit   Moar Complex$
   But... This Is Not That Complex$
     Okay, This Is The Last 1239809147801 But Not    The Least    T$
$>

*/

#include <unistd.h>

void	str_capitalizer(char *str)
{
	int i = 0;

	if (str[i] >= 'a' && 'z' >= str[i])
		str[i] -= 32;
	write(1, &str[i], 1);
	while (str[++i])
	{
		if (str[i] >= 'A' && 'Z' >= str[i])
			str[i] += 32;
		if ((str[i] >= 'a' && 'z' >= str[i]) && (str[i - 1] == ' ' || \
		str[i - 1] == '\t'))
			str[i] -= 32;
		write(1, &str[i], 1);
	}
}

int main(int argc, char *argv[])
{
	int i;

	if (argc == 1)
		write(1, "\n", 1);
	else
	{
		i = 1;
		while (i < argc)
		{
			str_capitalizer(argv[i]);
			write(1, "\n", 1);
			i += 1;
		}
	}
	return (0);
}
