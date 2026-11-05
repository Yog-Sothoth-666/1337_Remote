#include "libft.h"
#include <stdio.h>
#include <string.h>

void	del(void *content)
{
	free(content);
}

int	main()
{
	t_list *ls1 = ft_lstnew(ft_strdup("alpha"));
	t_list *ls2 = ft_lstnew(ft_strdup("beta"));
	t_list *ls3 = ft_lstnew((ft_strdup("delta")));
	t_list *ls4 = ft_lstnew(ft_strdup("gamma"));
	ft_lstadd_back(&ls1, ls2);
	ft_lstadd_back(&ls1, ls3);
	ft_lstadd_back(&ls1, ls4);
	t_list *current = ls1;
	while (current)
	{
		printf("%s\n", (char *)current->content);
		current = current->next;
	}
	ft_lstclear(&ls1, del);
}
