/*

課題名：epur_str
想定されるファイル：epur_str.c
許可される関数 : write
--------------------------------------------------------------------------------

文字列を受け取り、この文字列を正確に1つずつ表示するプログラムを作成する。
単語と単語の間にスペースを入れ、先頭と末尾にスペースやタブを入れない。
表示後に"改行"が付きます。

「単語」とは、スペースやタブで区切られた文字列の一部、
または文字列の先頭や末尾で区切られた文字列の一部と定義されます

引数の数が1でない場合、または表示する単語がない場合は改行のみ表示されます。

例
$> ./epur_str "See? It's easy to print the same thing" | cat -e
See? It's easy to print the same thing$
$> ./epur_str " this        time it      will     be    more complex  . " | cat -e
this time it will be more complex .$
$> ./epur_str "No S*** Sherlock..." "nAw S*** ShErLaWQ..." | cat -e
$
$> ./epur_str "" | cat -e
$
$>

*/

#include <unistd.h>

int main(int argc, char const *argv[])
{
	int i;
	int flg;

	if (argc != 2)
	{
		write(1, "\n", 1);
		return (0);
	}
	i = 0;
	while (argv[1][i] == ' ' || argv[1][i] == '\t')
		i += 1;
	while (argv[1][i])
	{
		if (argv[1][i] == ' ' || argv[1][i] == '\t')
			flg = 1;
		if (!(argv[1][i] == ' ' || argv[1][i] == '\t'))
		{
			if (flg)
				write(1, " ", 1);
			flg = 0;
			write(1, &argv[1][i], 1);
		}
		i ++;
	}
	write(1, "\n", 1);
	return (0);
}
