/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbeahan <mbeahan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 15:14:38 by mbeahan           #+#    #+#             */
/*   Updated: 2019/10/28 17:45:36 by mbeahan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM_H
# define ASM_H
#include "op.h"
#include "../../libft/includes/libft.h"
#include "../../ft_printf/include/ft_printf.h"

typedef enum	e_type
{
	LABEL,
	INSTRUCTION,
	DIRECT,
	DIRLABEL,
	INDIRECT,
	INDIRLABEL,
	REGISTER
}				t_type;

typedef enum	e_op
{
	live,
	ld,
    st,
    add,
    sub,
    and,
    or,
    xor,
    zjmp,
    ldi,
    sti,
    ffork,
    lld,
    lldi,
    lfork,
    aff
}				t_op;

typedef struct	s_file
{
	char				*str;
	t_type				type;
	t_op				op;
    struct s_file 		*next;
}				t_file;

typedef struct	s_asm
{
    char        **split;
    char        **error;
	t_file		*file;
	char		*name;
	char		*comment;
}				t_asm;

#endif
