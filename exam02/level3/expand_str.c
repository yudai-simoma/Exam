/*
課題名：expand_str
想定されるファイル：expand_str.c
許可される関数：write
--------------------------------------------------------------------------------

文字列を受け取り、各単語の間に正確に3つのスペースを入れ、最初も最後もスペースやタブを入れず、
その後に改行を入れて表示するプログラムを書いてください。

「単語」とは、スペースやタブで区切られた文字列の一部、
または文字列の先頭や末尾で区切られた文字列の一部と定義されます

引数の数が1でない場合、または表示する単語がない場合は改行のみ表示されます。

例:

$> ./expand_str "See? It's easy to print the same thing" | cat -e
See?   It's   easy   to   print   the   same   thing$
$> ./expand_str " this        time it      will     be    more complex  " | cat -e
this   time   it   will   be   more   complex$
$> ./expand_str "No S*** Sherlock..." "nAw S*** ShErLaWQ..." | cat -e
$
$> ./expand_str "" | cat -e
$
$>

*/

#include <unistd.h>

int main(int argc, char const *argv[])
{
    int i;
    int flag;

	if (argc != 2)
	{
		write(1, "\n", 1);
		return (0);
	}
	i = 0;
	while (argv[1][i] == ' ' || argv[1][i] == '\t')
		i++;
	while (argv[1][i])
	{
		if (argv[1][i] == ' ' || argv[1][i] == '\t')
			flag = 1;
		if (!(argv[1][i] == ' ' || argv[1][i] == '\t'))
		{
			if (flag)
				write(1, "   ", 3);
			flag = 0;
			write(1, &argv[1][i], 1);
		}
		i++;
	}
    write(1, "\n", 1);
    return (0);
}