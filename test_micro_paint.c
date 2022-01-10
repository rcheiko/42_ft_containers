/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_micro_paint.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcheiko <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 13:42:00 by rcheiko           #+#    #+#             */
/*   Updated: 2022/01/10 15:15:34 by rcheiko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef	struct s_fill
{
	int		width;
	int		height;
	char	background;
}t_fill;

typedef	struct s_rec
{
	char	rec;
	int		x;
	int		y;
	int		width;
	int		height;
	char	background;
}t_rec;

void	ft_putchar(char c)
{
	write (1, &c, 1);
}

void	ft_putstr(char *str)
{
	int i = 0;
	while (str[i])
	{
		ft_putchar(str[i]);
		i++;
	}
}

int	ft_strlen(char *str)
{
	int i = 0;
	while (str[i])
	{
		i++;
	}
	return (i);
}

char	*get_str(t_fill *a, FILE *f)
{
	char *str;

	if (fscanf(f, "%d %d %c \n", &a->width, &a->height, &a->background) != 3)
		return (NULL);
	if (a->width <= 0 || a->width > 300 || a->height <= 0 || a->height > 300)
		return (NULL);
	if (!(str = malloc(a->width * a->height)))
		return (NULL);
	memset(str, a->background, a->width * a->height);
	return (str);
}

int	check_border(int x, int y, t_rec b)
{
	if (x < b.x || b.x + b.width < x || y < b.y || b.y + b.height < y) // not in rec
		return (1);
	if (x - b.x < 1 || b.x + b.width - x < 1 || y - b.y < 1 || b.y + b.height - y < 1) // border
		return (2);
	return (0); // inside
}

void	modif_rec(t_rec b, t_fill *a, char *str)
{
	int	i = 0;
	int	j;
	int	border;

	while (i < a->height)
	{
		j = 0;
		while (j < a->width)
		{
			border = check_border(j, i, b);
			if (b.rec == 'r' && border == 2)
				str[i * a->height + j] = b.background;
			if (b.rec == 'R' && (border == 2 || border == 0))
				str[i * a->height + j] = b.background;
			j++;
		}
		i++;
	}
}

int	get_rec(t_fill *a, FILE *f, char *str)
{
	t_rec	b;

	while (fscanf(f, "%c %d %d %d %d %c \n", &b.rec, &b.x, &b.y, &b.width, &b.height, &b.background) == 6)
	{
		if (b.width <= 0 || b.height <= 0 || (b.rec != 'r' && b.rec != 'R'))
			return (1);
		modif_rec(b, a, str);
	}
	return (0);
}

void	print_circle(t_fill *a, char *str)
{
	int	i = 0;
	int	j;
	while (i < a->height)
	{
		j = 0;
		while (j < a->width)
		{
			ft_putchar(str[i * a->height + j]);
			j++;
		}
		write(1, "\n", 1);
		i++;
	}

}

int main(int ac, char **av)
{
	FILE	*f;
	t_fill	a;
	char	*str;
	if (ac != 2)
	{
		ft_putstr("Error: argument\n");
		return (1);
	}
	if (!(f = fopen(av[1], "r")))
	{
		ft_putstr("Error: Operation file corrupted\n");
		return (1);
	}
	if (!(str = get_str(&a, f)))
	{
		ft_putstr("Error: Operation file corrupted\n");
		fclose(f);
		return (1);
	}
	if (get_rec(&a, f, str) == 1)
	{
		ft_putstr("Error: Operation file corrupted\n");
		free(str);
		fclose(f);
		return (1);
	}
	print_circle(&a, str);
	free(str);
	fclose(f);
	return (0);
}
