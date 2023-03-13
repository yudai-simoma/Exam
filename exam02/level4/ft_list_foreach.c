/*
片方のみに記載されていた問題
割り当て名：ft_list_foreach
期待されるファイル： ft_list_foreach.c, ft_list.h
許可された関数
--------------------------------------------------------------------------------

リストと関数ポインタを受け取り、リストの各要素にこの関数を適用する関数を書いてください。

次のように宣言する必要がある。

void ft_list_foreach(t_list *begin_list, void (*f)(void *));

fが指す関数は、次のように使用されます。

(*f)(list_ptr->data);

以下の構造体を使用し、ft_list.hというファイルとして提出する必要があります。

typedef struct s_list
{
    struct s_list *next;
    void *data;
} t_list;

*/

#include <stdlib.h>

typedef struct    s_list
{
    struct s_list *next;
    void          *data;
}                 t_list;

void	ft_list_foreach(t_list *begin_list, void (*f)(void *))
{
	t_list *list_ptr;

	list_ptr = begin_list;
	while (list_ptr)
	{
		(*f)(list_ptr->data);
		list_ptr = list_ptr->next;
	}
}
