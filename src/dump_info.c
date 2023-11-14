/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dump_info.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpuig-ma <mpuig-ma@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 16:28:06 by mpuig-ma          #+#    #+#             */
/*   Updated: 2023/11/14 17:00:15 by mpuig-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static void	dump_info_image(char *id, t_list *info_lst, t_imgdata *img);
static void	dump_info_color(char *id, t_list *info_lst, t_color *color);
static char	*extract_info(char *id, t_list *info_lst);

int	dump_info(t_list *info_lst, t_game *game)
{
	t_list	*temp;

	temp = info_lst;
	while (temp != NULL)
	{
		ft_striteri(temp->content, &ft_replace_isspace);
		temp = temp->next;
	}
	dump_info_image("NO ", info_lst, &game->i_north);
	dump_info_image("SO ", info_lst, &game->i_south);
	dump_info_image("EA ", info_lst, &game->i_east);
	dump_info_image("WE ", info_lst, &game->i_west);
	dump_info_color("F ", info_lst, &game->f_color);
	dump_info_color("C ", info_lst, &game->c_color);
	return (EXIT_SUCCESS);
}

static void	dump_info_image(char *id, t_list *info_lst, t_imgdata *img)
{
	char	*image_info;
	char	**values;

	image_info = extract_info(id, info_lst);
	values = ft_split(image_info, 040);
	if (ft_arrlen(values) != 2)
		exit(EXIT_FAILURE + 1);
	img->image_file = ft_strdup(values[1]);
	ft_free_arr(values);
}

static void	dump_info_color(char *id, t_list *info_lst, t_color *color)
{
	char	*color_info;
	char	**values;

	color_info = extract_info(id, info_lst);
	ft_striteri(color_info, &ft_replace_ispunct);
	values = ft_split(color_info, 040);
	if (ft_arrlen(values) != 4)
		exit(EXIT_FAILURE + 2);
	ft_set_rgb_color(values + 1, color);
	ft_free_arr(values);
}

static char	*extract_info(char *id, t_list *info_lst)
{
	char	*info_str;
	int		id_len;

	id_len = (int) ft_strlen(id);
	info_str = NULL;
	while (info_lst != NULL)
	{
		info_str = info_lst->content;
		if (ft_strncmp(id, info_str, id_len) == 0)
			return (info_str);
		info_lst = info_lst->next;
	}
	return (info_str);
}
