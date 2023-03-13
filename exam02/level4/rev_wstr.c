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
