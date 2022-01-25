/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sprevot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 14:39:06 by sprevot           #+#    #+#             */
/*   Updated: 2022/01/25 16:52:38 by sprevot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minilibx/mlx.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct	s_vars {
	void	*mlx;
	void	*win;
	void	*img;
}				t_vars;

int	void_func(int keycode, void *vars)
{
	return (0);
}

int	close(int keycode, t_vars *vars)
{
	if (keycode == 53)
		mlx_destroy_window(vars->mlx, vars->win);
	return (0);
}

int	main(void)
{
	t_vars	vars;
	int		a;
	int		b;
	char 	relative_path[] = "/Users/sprevot/Documents/so_long/30.xpm";

	vars.mlx = mlx_init();
	if (vars.mlx == NULL)
		return (0);
	vars.win = mlx_new_window(vars.mlx, 1920, 1080, "Hello world!");
	if (vars.win == NULL)
	{
		free(vars.win);
		return (0);
	}
	vars.img = mlx_xpm_file_to_image(vars.mlx, relative_path, &a, &b);
	mlx_put_image_to_window (vars.mlx, vars.win, vars.img, a, b);
	printf("\n\n\t\t1 -----\n\n");
	mlx_loop_hook(vars.mlx, &void_func, (void *)0);
	printf("\n\n\t\t2 -----\n\n");
	mlx_key_hook(vars.win, &close, &vars);
	mlx_loop(vars.mlx);
	free(vars.mlx);
	exit(0);
	return (0);
}
