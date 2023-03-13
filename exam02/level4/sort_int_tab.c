/*
片方のみに記載されていた問題
割り当て名：sort_int_tab
期待されるファイル名 : sort_int_tab.c
許可された関数
--------------------------------------------------------------------------------

次の関数を書きなさい。

void sort_int_tab(int *tab, unsigned int size);

この関数は、'size'を正確に含むint配列'tab'を昇順にソートしなければならない（in-place）。

倍数は保存されなければならない。

入力は常にコヒーレントである。

*/

void	sort_int_tab(int *tab, unsigned int size)
{
	unsigned int	i = 0;
	int	temp;

	while (i < (size - 1))
	{
		if (tab[i] > tab[i + 1])
		{
			temp = tab[i];
			tab[i] = tab[i+ 1];
			tab[i + 1] = temp;
			i = 0;
		}
		else
			i++;
	}
}