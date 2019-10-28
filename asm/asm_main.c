/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbeahan <mbeahan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 14:16:28 by mbeahan           #+#    #+#             */
/*   Updated: 2019/10/28 17:20:43 by mbeahan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/asm.h"
#include <fcntl.h>

static int	assemble(char *av)
{
    int				fd;
    header_t		champ;

	fd = open(av, O_RDONLY);
	ft_bzero(&champ, sizeof(champ));
    if (fd < 0)
        ft_printf("Error open");
    champ = get_champ_info(&champ, fd);
    put_error(champ);
    return (0);
}

int			check_extension(char *av)
{
	if (!(ft_strcmp(&av[ft_strlen(av) - 2], ".s")))
		return (1);
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