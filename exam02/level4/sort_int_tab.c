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

入力は常に一貫しています。

*/

void	sort_int_tab(int *tab, unsigned int size)
{
	unsigned int	a;
	int				tmp;

	a = 1;
	if (size != 0)
	{
		while (a <= size)
		{
			if (tab[a] < tab[a - 1])
			{
				tmp = tab[a];
				tab[a] = tab[a - 1];
				tab[a - 1] = tmp;
				a = 0;
			}
			++a;
		}
	}
}

#include <stdio.h>

int main(void)
{
    int tab[10];
    int i = 0;

    tab[0] = 9;
    tab[1] = 2;
    tab[2] = 4;
    tab[3] = 3;
    tab[4] = 8;
    tab[5] = 0;
    tab[6] = 1;
    tab[7] = 7;
    tab[8] = 5;
    tab[9] = 6;
    sort_int_tab(tab, 9);
    while (i <= 9)
        printf("%d\n", tab[i++]);
    return (0);
}
