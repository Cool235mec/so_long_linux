/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sprevot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 11:15:03 by sprevot           #+#    #+#             */
/*   Updated: 2022/01/24 15:56:18 by sprevot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minilibx/mlx.h"
#include <stdio.h>

typedef struct s_vars
{	
	void	*init;
	void	*win;
}	t_vars;

/*int	get_key(int key, void *params)
{
	printf("%d\n", key);
	if (key == 53)
	{
		printf("bonjour");
		mlx_destroy_window(init, win);
		return (1);
	}
	return (0);
}*/

int		blank(int key, t_vars *vars)
{
	if (key == 53)
		mlx_destroy_window(vars->init, vars->win);
	return (0);
}

int	main()
{
	t_vars = vars;

	vars.init = mlx_init();
	vars.win = mlx_new_window(vars.init, 600, 600, "so_long");
	mlx_key_hook(vars.win, blank, &vars)
	mlx_loop(vars.init);
	return 0;
}

//keycode echap = 53
