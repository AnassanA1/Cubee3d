/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msidry <msidry@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/15 13:14:17 by msidry            #+#    #+#             */
/*   Updated: 2026/02/18 16:53:50 by msidry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/main.h"

static void	leak_check(void);
static void default_init(t_container *ref, int argc, char **argv);

int	main(int argc, char *argv[])
{
	t_container	game;

	default_init(&game, argc, argv);
	game_init(&game);
	game_run(&game);
	game_destroy(&game);
	atexit(leak_check);
	return (0);
}



static void default_init(t_container *ref, int argc, char **argv)
{
	ft_bzero(ref, sizeof(*ref));
	ref->argc = argc;
	ref->datafile.path = argv[1];
	ref->display.width = WIN_WIDTH;
	ref->display.height = WIN_HEIGHT;
	ref->display.title = WIN_TITLE;
}
static void	leak_check(void)
{
	system("leaks -q cube3D");
}
