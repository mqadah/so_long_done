#include "../includes/so_long.h"

void	free_all(char **d)
{
	int	i;

	i = 0;
	while (d[i])
	{
		free(d[i]);
		i++;
	}
	free(d);
}

void	check_len(char **map)
{
	int			i;
	size_t		initial_len;

	initial_len = ft_strlen(map[0]);
	i = 1;
	while (map[i])
	{
		if (ft_strlen(map[i]) != initial_len)
		{
			free_all(map);
			ft_putstr_fd("Error\nMap must be rectangular\n", 2);
			exit(1);
		}
		i++;
	}
}
