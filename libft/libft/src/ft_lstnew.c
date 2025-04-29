/* ************************************************************************** */
/**/
/*:::  ::::::::   */
/*   ft_lstnew.c:+:  :+::+:   */
/*+:+ +:+ +:+ */
/*   By: nifromon <marvin@42.fr>+#+  +:+   +#+*/
/*+#+#+#+#+#+   +#+   */
/*   Created: 2024/11/11 12:39:49 by nifromon  #+##+# */
/*   Updated: 2024/11/12 14:13:52 by nifromon ###   ########.fr   */
/**/
/* ************************************************************************** */

//START
#include "../headers/libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*new_node;

	new_node = (t_list *)malloc(sizeof(t_list));
	if (!new_node)
		return (NULL);
	new_node->content = content;
	new_node->next = NULL;
	return (new_node);
}

//END
