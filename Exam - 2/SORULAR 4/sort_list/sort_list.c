#include "list.h"

t_list	*sort_list(t_list* lst, int (*cmp)(int, int))
{
    t_list *res = lst;
    int tmp;

    while (lst->next != 0)
    {
        if (((*cmp)(lst->data, lst->next->data)) == 0)
        {
            tmp = lst->data;
            lst->data = lst->next->data;
            lst->next->data = tmp;
            lst = res;
        }
        else
            lst = lst->next;
    }
    lst = res;
    return lst;
}