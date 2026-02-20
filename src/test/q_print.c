#include "../../include/main.h"

void	q_printQueue(t_queue *queue)
{
	if (!queue)
	{
		printf("Empty Queue !\n");
		return ;
	}
	while (queue)
	{
		printf("content : %c, \t x value : %i, \t y value : %i\n",
			queue->content, queue->x, queue->y);
		queue = queue->next;
	}
}

void	q_pushQueue(void)
{
	t_queue	*queue;

	queue = NULL;
	for (int y = 0; y < 3; y++)
	{
		for (int x = 0; x < 3; x++)
		{
			q_push(&queue, q_create(x + y + 65, x, y));
		}
	}
	q_printQueue(queue);
	q_popQueue(&queue);
}

void	q_popQueue(t_queue **queue)
{
	t_queue	out;

	if (!queue)
		return ;
	while (*queue)
	{
		if (q_pop(queue, &out))
			printf(" FIFO : content : %c, \t x value : %i, \t y value : %i\n",
				out.content, out.x, out.y);
	}
}
