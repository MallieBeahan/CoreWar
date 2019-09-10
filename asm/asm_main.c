/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbeahan <mbeahan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 14:16:28 by mbeahan           #+#    #+#             */
/*   Updated: 2019/09/10 18:08:13 by mbeahan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/asm.h"
#include <fcntl.h>

static int  put_error(header_t champ)
{
    int err;

    err = 0;
    if (!champ.is_name)
        err = 0;
    else if (!champ.is_comment)
        err++;
    else if (champ.is_name > 1)
        err++;
    if (champ.is_comment > 1)
        err++;
    if (ft_strlen(champ.name) > PROG_NAME_LENGTH)
        err++;
    if (ft_strlen(champ.comment) > COMMENT_LENGTH)
        err++;
    if (err)
        return (1);
    return (0);
}

static int	assemble(char *av)
{
    int				fd;
    header_t		champ;

	fd = open(av, O_RDONLY);
	ft_bzero(&champ, sizeof(champ));
    if (fd < 0)
        ft_printf("Error open");
    champ = get_champ_info(champ, fd);
    put_error(champ);
    return (0);
}

int			main(int ac, char **av)
{
    if (ac == 2 && check_extension(av[1]))
        assemble(av[1]);
    else
        ft_printf("Error usage");
    return (0);
}