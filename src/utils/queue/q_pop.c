#include "../../../include/main.h"

int	q_pop(t_queue **queue, t_queue *out)
{
	t_queue	*tmp;

	if (!queue || !*queue || !out)
		return (0);
	tmp = *queue;
	out->content = tmp->content;
	out->x = tmp->x;
	out->y = tmp->y;
	out->next = NULL;
	*queue = tmp->next;
	free(tmp);
	return (1);
}
