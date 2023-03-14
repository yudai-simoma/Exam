#ifndef TEST_H
# define TEST_H

typedef struct s_list
{
    struct s_list *next;
    void *data;
} t_list;

#endif