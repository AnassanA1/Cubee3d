/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msidry <msidry@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/15 13:14:17 by msidry            #+#    #+#             */
/*   Updated: 2026/02/12 09:45:06 by msidry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/main.h"

static void	leak_check(void);

int	main(int argc, char *argv[])
{
	t_game	game;

	ft_bzero(&game, sizeof(game));
	game_init(&game, argc, argv);
	game_run(&game);
	game_destroy(&game);
	atexit(leak_check);
	return (0);
}

static void	leak_check(void)
{
	system("leaks -q cube3D");
}
