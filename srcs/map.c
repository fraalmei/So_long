/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fraalmei <fraalmei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 15:44:51 by fraalmei          #+#    #+#             */
/*   Updated: 2023/03/28 10:01:51 by fraalmei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

	// function to read the map
t_prog	read_map(char *argv)
{
	t_prog	data;
	t_size	size_map;
	t_size	size_img;
	int		file;

	size_map = check_map(argv);
	size_img = higher_size_assets();
	size_map.width = size_map.width * size_img.width;
	size_map.height = size_map.height * size_img.height;
	data.win = new_program(size_map, size_img, "So_long");
	file = open(argv, O_RDONLY);
	data.map = create_map(file, &data);
	if (!data.map)
		exit_program(&data.win, 1);
	close (file);
	if (check_path(data) == 1 || !data.map)
		exit_program(&data.win, 1);
	return (data);
}

	// funtion to read a line of the map
int	read_map_line(char *ln, t_prog *dat, t_cords *i, t_location **init)
{
	int			c;
	t_object	*swap_obj;
	t_location	*swap_loc;

	c = 0;
	while (ln[i->x] && ln[i->x] != '\n')
	{
		if (ln[i->x] == 'C')
			c += 1;
		swap_obj = create_object(mlx_xpm_file_to_image(dat->win.mlx_ptr, \
			check_object_image(ln[i->x]), (int *)&dat->win.size_map.width, \
			(int *)&dat->win.size_map.height), *i, ln[i->x], dat);
		swap_loc = new_location(mlx_xpm_file_to_image(dat->win.mlx_ptr, \
			check_map_image(ln[i->x]), (int *)&dat->win.size_map.width, \
			(int *)&dat->win.size_map.height), swap_obj, *i, '0');
		if (!swap_loc)
			exit_program(&dat->win, 4);
		detect_p_e(dat, ln[i->x], swap_obj, swap_loc);
		add_location_back(*&init, swap_loc);
		i->x++;
	}
	i->y++;
	free (ln);
	return (c);
}

	// function to create the map
t_map	*create_map(int file, t_prog *data)
{
	t_location	*init;
	char		*line;
	t_cords		i;
	int			c;

	c = 0;
	init = NULL;
	line = get_next_line(file);
	i.y = 0;
	while (line)
	{
		i.x = 0;
		c += read_map_line(line, data, &i, &init);
		line = get_next_line(file);
	}
	free (line);
	return (new_map(init, i, c));
}

	// funtion to create the map structure
t_map	*new_map(t_location *init, t_cords cords, int collectables)
{
	t_map	*map;

	map = (t_map *)ft_calloc(sizeof(*map), 1);
	map->init = init;
	map->cords = cords;
	map->collectables = collectables;
	return (map);
}
