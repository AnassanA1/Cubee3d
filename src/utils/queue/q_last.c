#include "../../../include/main.h"

t_queue	*q_last(t_queue *queue)
{
	if (!queue)
		return (NULL);
	while (queue)
	{
		if (!queue->next)
			break ;
		queue = queue->next;
	}
	return (queue);
}
