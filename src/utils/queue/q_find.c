#include "../../../include/main.h"

t_queue	*q_find(t_queue *queue, int x, int y)
{
	if (!queue)
		return (NULL);
	while (queue)
	{
		if (queue->x == x && queue->y == y)
			return (queue);
		queue = queue->next;
	}
	return (NULL);
}
