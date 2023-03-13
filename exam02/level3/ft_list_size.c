/*

割当名：ft_list_size
想定されるファイル：ft_list_size.c, ft_list.h
許可された関数
--------------------------------------------------------------------------------

渡されたリンクリストの要素数を返す関数を書け。

以下のように宣言しなければならない。

int ft_list_size(t_list *begin_list);


以下のような構成で、「ft_list.h」というファイルとして提出する必要があります。

typedef struct s_list
{
	struct s_list *next;
	void *data;
} t_list;

*/

/*
以下、ft_list.hの中身

ifndef FT_LIST_H
#difine FT_LIST_H

typedef struct s_list
{
	struct s_list *next;
	void *data;
} t_list;

endif
*/

#include "ft_list.h"
// typedef struct s_list
// {
//     struct s_list *next;
//     void          *data;
// } t_list;

int	ft_list_size(t_list *begin_list)
{
	int	return_size;

	if (begin_list == (void *)0)
		return (0);
	return_size = 0;
	while (begin_list != (void *)0)
	{
		return_size++;
		begin_list = begin_list->next;
	}
	return (return_size);
}

// #include <stdio.h>
// #include <stdlib.h>
// int	main(void)
// {
// 	int n = 0;

// 	t_list *c = malloc(sizeof(t_list));
// 	c->next = 0;
// 	c->data = &n;

// 	t_list *b = malloc(sizeof(t_list));
// 	b->next = c;
// 	b->data = &n;

// 	t_list *a = malloc(sizeof(t_list));
// 	a->next = b;
// 	a->data = &n;

// 	printf("%d\n", ft_list_size(a));
// }