/*
片方のみに記載されていた問題
課題名：ft_list_remove_if
期待されるファイル名 : ft_list_remove_if.c
許可された関数：free
--------------------------------------------------------------------------------

渡されたリストから、そのデータが参照データと「等しい」要素を削除する関数 ft_list_remove_if を作成せよ。

以下のように宣言されます。

void ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)());

cmpは2つのvoid*を取り、両方のパラメータが等しいとき0を返す。

ft_list.hファイルを使用する必要があり、その中には

$>cat ft_list.h
typedef struct      s_list
{
    struct s_list   *next;
    void            *data;
}                   t_list;
$>

*/

#include <stdlib.h>

typedef struct    s_list
{
    struct s_list *next;
    void          *data;
}                 t_list;

void ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)())
{
	if (begin_list == NULL || *begin_list == NULL)
		return;

	t_list *cur = *begin_list;

	if (cmp(cur->data, data_ref) == 0)
	{
		*begin_list = cur->next;
		free(cur);
		ft_list_remove_if(begin_list, data_ref, cmp);
	}
	cur = *begin_list;
	ft_list_remove_if(&cur->next, data_ref, cmp);
}
