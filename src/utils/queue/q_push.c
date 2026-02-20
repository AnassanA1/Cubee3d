#include "../../../include/main.h"

void	q_push(t_queue **queue, t_queue *item)
{
	t_queue	*last;

	if (!queue || !item)
		return ;
	if (!*queue)
	{
		*queue = item;
		return ;
	}
	last = q_last(*queue);
	if (last)
		last->next = item;
}
