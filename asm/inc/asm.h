/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbeahan <mbeahan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 15:14:38 by mbeahan           #+#    #+#             */
/*   Updated: 2019/09/10 16:49:54 by mbeahan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM_H
# define ASM_H
#include "op.h"
#include "../../libft/includes/libft.h"
#include "../../ft_printf/include/ft_printf.h"

typedef struct	s_champ_info
{
    unsigned int	is_name:1;
    char			*champ_name;
    char			*champ_comment;
	char			*champ_extend;
}				t_champ_info;

header_t		get_champ_info(header_t champ, int fd);
int				check_extension(char *av);

#endif
