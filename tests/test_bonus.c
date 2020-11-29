
# include <stdio.h>
# include <string.h>

typedef struct      s_list
{
    void            *data;
    struct s_list   *next;
}                   t_list;


void        ft_list_push_front(t_list **begin_list, void *data);
int         ft_list_size(t_list *begin_list);
void        ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)());
void        ft_list_sort(t_list **begin_list, int (*cmp)());


void    print_list(t_list   *list)
{
    int     i = 0;
    while (list)
    {
        printf("%d: data = %s\n", i++, (char*)list->data);
        list = list->next;
    }
}


int main(void) {

    t_list      start;
    t_list      next;
    t_list      last;

    t_list      *current = &start;

    start.data = (void *)strdup("123");
    start.next = &next;
    next.data = (void *)strdup("123");
    next.next = &last;
    last.data = (void *)strdup("321");
    last.next = NULL;

    printf("ft_list_size = %d\n", ft_list_size(&start));
    print_list(&start);

    ft_list_push_front(&current, strdup("qwe"));
    printf("linked list size: %d\n", ft_list_size(current));
    print_list(current);

    printf("linked list size: %d\n", ft_list_size(current));
    ft_list_sort(&current, &strcmp);
    print_list(current);

}
