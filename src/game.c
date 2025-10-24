/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 16:11:23 by mqadah            #+#    #+#             */
/*   Updated: 2025/10/23 10:28:12 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	handle_close(t_game *game)
{
	free_game(game, "window closed\n");
	return (0);
}
void check_argc(int argc,char *argv)
{
	int len;

	if (argc != 2)
	{
		write(2,"Error\nFew arguments\n",21);
		exit(1);
	}
	len = ft_strlen(argv);
	if (len < 4 || ft_strncmp(&argv[len - 4], ".ber", 4))
	{
		write(2,"Error\nWrong extention\n",23);
		exit(1);
	}
}
int	main(int argc, char **argv)
{
	char	**map;
	void	*mlx;
	void	*win;
	t_game	*game;

	check_argc(argc,argv[1]);
	map = read_map(argv[1]);
	mlx = mlx_init();
	if (mlx == NULL)
	{
		free_all(map);
		exit_error("Error\nin init the window\n");
	}
	game = init_data(map, mlx);
	win = mlx_new_window(mlx, game->width * 32, game->height * 32, "so_long");
	if (!win)
		free_game(game, "Error\nin new_window\n");
	game->win = win;
	load_images(game);
	draw_map(game);
	mlx_hook(game->win, 2, 1L << 0, key_movement, game);
	mlx_hook(game->win, 17, 0, handle_close, game);
	mlx_loop(mlx);
	mlx_destroy_window(mlx, win);
	mlx_destroy_display(mlx);
}
