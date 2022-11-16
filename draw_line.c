/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulayus <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 16:32:03 by ulayus            #+#    #+#             */
/*   Updated: 2022/11/11 20:14:41 by ulayus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dest;

	dest = data->addr + (y * data->line_len + x * (data->bpp / 8));
	*(unsigned int*)dest = color;
}

void	convert_points(t_points *p, int x, int y)
{
    p->x = x * 20;/*ft_abs(x * cos(0.02) - y * sin(0.02));*/
    p->y = y * 20;/*ft_abs(x * sin(0.02) - y * cos(0.02));*/
}

t_points	*parse(int ac, char **av)
{
    t_points    *head;
    int         fd;

    head = NULL;
    if (ac != 2)
        return (NULL);
    fd = open(av[1], O_RDONLY);
    if (fd < 1)
        return (NULL);
    head = coordinates(head, fd);
	close(fd);
	return (head);
}

int	main(int ac, char **av)
{
	void			*mlx;
	void			*mlx_win;
	t_data			img;
	const t_points	*head = parse(ac, av);
	t_points		*tmp;
	t_points		*point;
	int				x;
	int				y;

	if (head == NULL)
		return (1);
	tmp = NULL;
	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, WIDTH, HEIGHT, "Window test...");
	img.img = mlx_new_image(mlx, WIDTH, HEIGHT);
	img.addr = mlx_get_data_addr(img.img, &img.bpp, &img.line_len, &img.endian);
    tmp = (t_points *)head;
    y = 0;
	x = 0;
    while (tmp->next)
    {
        point = tmp;
        if (!point->eol)
        {
			convert_points(point, x, y);
			convert_points(point->next, x + 1, y);
			draw_line_x(point, point->next, img);
			//ft_printf("%d ", point->alt);
			x++;
        }
		else
		{
            ft_printf("Line %d\n", y + 1);
			x = 0;
            y++;
		}
        tmp = tmp->next;
    }
    tmp = (t_points *)head;
    y = 0;
	x = 0;
    while (tmp->next)
    {
        point = tmp;
        if (!point->eol)
        {
			convert_points(point, x, y);
			convert_points(point->next, x, y + 1);
			draw_line_y(point, point->next, img);
			//ft_printf("%d ", point->alt);
			x++;
			free(point);
        }
		else
		{
            ft_printf("Line %d\n", y + 1);
			x = 0;
            y++;
		}
        tmp = tmp->next;
    }
    free(tmp);
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);
}
