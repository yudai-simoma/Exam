/*
片方のみに記載されていた問題
課題名：sort_list
期待されるファイル名 : sort_list.c
許可された関数
--------------------------------------------------------------------------------

次の関数を書きなさい。

t_list *sort_list(t_list* lst, int (*cmp)(int, int));

この関数は、パラメータとして与えられたリストを、関数ポインタ cmp を使って適用する順序を選択し、
ソートされたリストの最初の要素へのポインタを返さなければならない。

重複は必ず残す。

入力は常に一貫していること。

あなたは、あなたに提供されるファイルlist.hに記述されているt_list型を使用しなければなりません。
あなたはそのファイルをインクルードしなければなりませんが（#include "list.h"）、提出してはいけません。
私たちはあなたの課題をコンパイルするために私たち自身のものを使用します。

cmpとして渡される関数は、a、bが正しい順序であれば常に0とは異なる値を返し、そうでなければ0を返します。

例えば、cmpとして使用される次の関数は、リストを昇順にソートする。

int ascending(int a, int b)
{
	return (a <= b);
}

*/

typedef struct s_list
{
	int     data;
	t_list  *next;
}	t_list;

void	swap_values(t_list *a, t_list *b)
{
	int swap = a->data;
	a->data = b->data;
	b->data = swap;
}

t_list	*sort_list(t_list* lst, int (*cmp)(int, int))
{
	int swapped = 1;
	t_list *cur = lst;

	while (swapped == 1)
	{
		swapped = 0;
		while (cur != 0 && cur->next != 0)
		{
			if (cmp(cur->data, cur->next->data) == 0)
			{
				swap_values(cur, cur->next);
				swapped = 1;
			}
			cur = cur->next;
		}
		cur = lst;
	}
	return (lst);
}