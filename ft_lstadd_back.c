#include "libft.h"
void ft_lstadd_back(t_list **lst, t_list *new)
{
    if (*lst == NULL)
    {
        *lst = new;
        return;
    }
    t_list *end = ft_lstlast(*lst);
    end->next = new;
}