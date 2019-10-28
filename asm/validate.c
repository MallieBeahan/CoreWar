/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbeahan <mbeahan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 15:42:43 by mbeahan           #+#    #+#             */
/*   Updated: 2019/10/28 18:02:00 by mbeahan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/asm.h"

void	extract_comment(char *line, header_t *champ)
{
	int		i;
	int		len;

	len = 0;
	champ->is_comment >= 1 ? champ->is_comment++ : 0;
	if (ft_strchr(line, '"') != ft_strrchr(line, '"') && !champ->is_comment)
	{
		champ->is_comment = 1;
		i = ft_strchr(line, '"') - line + 1;
		while (line[i] != '"' && ++i)
			len++;
		champ->comment = ft_strsub(line, ft_strchr(line, '"') - line + 1, len);
	}
}

void		extract_name(char *line, header_t *champ)
{
	int		len;
	int		i;

	len = 0;
	champ->is_name >= 1 ? champ->is_name++ : 0;
	if (ft_strchr(line, '"') != ft_strrchr(line, '"') && !champ->name)
	{
		champ->is_name = 1;
		i = ft_strchr(line, '"') - line + 1;
		while (line[i] != '"' && ++i)
			len++;
		if (len > 1)
			champ->name = ft_strsub(line, ft_strchr(line, '"') - line + 1, len);
	}
}

header_t	get_champ_info(header_t champ, int fd)
{
    char *line;

    ft_bzero(&champ, sizeof(champ));
    while (get_next_line(fd, &line))
    {
        if (ft_strstr(line, ".name"))
			extract_name(line, &champ);
        else if (ft_strstr(line, ".comment"))
			extract_comment(line, &champ);
		free(line);
    }
	return (champ);
}
