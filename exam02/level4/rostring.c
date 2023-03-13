/*
課題名：rostring
想定されるファイル：rostring.c
許可される関数 : write, malloc, free
--------------------------------------------------------------------------------

文字列を受け取り、この文字列を左に1語ずつ回転させて表示するプログラムを作成しなさい。

このとき、最初の単語が最後になり、他の単語は同じ順序で表示される。

単語」とは、スペースやタブ、あるいは文字列の先頭や末尾で区切られた文字列の一部と定義される。

出力では、単語は1つのスペースで区切られるだけです。

引数が1つ以下の場合、プログラムは"˶"と表示します。

例:

$>./rostring "abc   " | cat -e
abc$
$>
$>./rostring "Que la      lumiere soit et la lumiere fut"
la lumiere soit et la lumiere fut Que
$>
$>./rostring "     AkjhZ zLKIJz , 23y"
zLKIJz , 23y AkjhZ
$>
$>./rostring "first" "2" "11000000"
first
$>
$>./rostring | cat -e
$
$>

*/
