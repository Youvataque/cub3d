/* ************************************************************************** */
/**/
/*:::  ::::::::   */
/*   ft_lstlast.c   :+:  :+::+:   */
/*+:+ +:+ +:+ */
/*   By: nifromon <marvin@42.fr>+#+  +:+   +#+*/
/*+#+#+#+#+#+   +#+   */
/*   Created: 2024/11/11 12:46:43 by nifromon  #+##+# */
/*   Updated: 2024/11/12 14:13:32 by nifromon ###   ########.fr   */
/**/
/* ************************************************************************** */

//START
#include "../headers/libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*tmp_lst;

	if (!lst)
		return (NULL);
	tmp_lst = lst;
	while (tmp_lst->next)
		tmp_lst = tmp_lst->next;
	return (tmp_lst);
}

//END
